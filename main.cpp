#include <Eigen/Core>
#include <Eigen/Dense>
#include <algorithm>
#include <chrono>
#include <cstdlib>
#include <iostream>
#include <random>
#include <vector>

float randomFloat() {
  static std::random_device rd;
  static std::mt19937 gen{rd()};
  std::uniform_real_distribution<float> dist{0, 1};
  return dist(gen);
}

using namespace Eigen;
void setRandom(MatrixXf &a, Index size) {
  a.resize(size, size);
  const Index rows = a.rows(), cols = a.cols();
  for (Index i = 0; i != rows; i++)
    for (Index j = 0; j != cols; j++)
      a(i, j) = randomFloat();
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
  std::vector<double> resultSecs;
  std::vector<double> results;
  resultSecs.reserve(repeat);
  results.reserve(repeat);
  for (int i = 0; i < repeat; i++) {
    auto t1 = std::chrono::steady_clock::now();
    const MatrixXf c = a * b;
    auto t2 = std::chrono::steady_clock::now();
    const double s = std::chrono::duration<double>(t2 - t1).count() / repeat;
    resultSecs.push_back(s);
    results.push_back(c(size - 1, size - 1));
    a(size - 1, size - 1) = randomFloat();
  }
  std::cout << '[';
  for (auto a : resultSecs)
    std::cout << a << ' ';
  std::cout << "] s" << std::endl;
  std::cout << "min = "
            << *std::min_element(resultSecs.begin(), resultSecs.end())
            << std::endl;
  std::cout << "results.back = " << results.back() << std::endl;
}
