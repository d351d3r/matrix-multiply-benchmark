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
$ OMP_NUM_THREADS=1 ./a 10 10000
world = 1
[5.43272 5.40236 5.39825 5.40143 5.40799 5.41512 5.41476 5.40888 5.40783 5.40497 ] s
min = 5.39825
results.back = 2481.56

$ OMP_NUM_THREADS=16 ./a 10 10000
world = 16
[0.757449 0.790658 0.797686 0.797143 0.795911 0.797824 0.7968 0.798788 0.797919 0.801287 ] s
min = 0.757449
results.back = 2483.82
```
