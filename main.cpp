#include <Eigen/Core>
#include <Eigen/Dense>
#include <chrono>
#include <cstdlib>
#include <iostream>
#include <random>

using namespace Eigen;
void setRandom(MatrixXf &a, Index size) {
  a.resize(size, size);
  static std::random_device rd;
  static std::mt19937 gen{rd()};
  std::uniform_real_distribution<float> dist{0, 1};
  const Index rows = a.rows(), cols = a.cols();
  for (Index i = 0; i != rows; i++)
    for (Index j = 0; j != cols; j++)
      a(i, j) = dist(gen);
}

int main(int argc, const char **argv) {
  Eigen::initParallel();
  const int n = Eigen::nbThreads();
  std::cout << "world = " << n << '\n';

  int repeat = 10;
  Index size = 200;
  if (argc > 1)
    repeat = std::atoi(argv[1]);
  if (argc > 2)
    size = std::atoi(argv[2]);
  MatrixXf a, b;
  setRandom(a, size);
  setRandom(b, size);
  auto t1 = std::chrono::steady_clock::now();
  for (int i = 0; i < repeat; i++) {
    volatile MatrixXf c = a * b;
  }
  auto t2 = std::chrono::steady_clock::now();
  const double s = std::chrono::duration<double>(t2 - t1).count() / repeat;
  std::cout << s << " s" << std::endl;
}
