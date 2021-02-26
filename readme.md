# matrix-multiply-benchmark

## Dependencies

- Eigen3;
- OpenMP.

## Build

```bash
mkdir build
cd build
cmake .. -GNinja -DCMAKE_BUILD_TYPE=Release
cmake --build .
```

## Run

```bash
$ OMP_NUM_THREADS=1 ./a 10 5000
world = 1
[6.76205 6.70781 6.70911 6.71378 6.71853 6.7152 6.76076 6.72719 6.73049 6.73127 ] s
min = 6.70781
results.back = 1246.83

$ OMP_NUM_THREADS=1 ./a 10 10000
world = 1
[54.2929 54.11 54.156 54.0591 54.1273 54.3578 54.3513 54.1814 53.8642 54.0934 ] s
min = 53.8642
results.back = 2499.35

$ OMP_NUM_THREADS=16 ./a 10 10000
world = 16
[7.53394 7.89038 7.91947 7.91657 7.91836 7.91648 7.95506 7.95845 8.09204 8.0504 ] s
min = 7.53394
results.back = 2488.48
```
