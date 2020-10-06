# matrix-multiply-benchmark

## Dependencies

- Eigen3;
- OpenMP.

## Build

```bash
mkdir build
cmake .. -GNinja -DCMAKE_BUILD_TYPE=Release
cmake --build .
```

## Run

```bash
OMP_NUM_THREADS=4 ./a 10 7000
```
