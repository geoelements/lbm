# Multiphase LBM

[![License](https://img.shields.io/badge/license-MIT-blue.svg)](https://raw.githubusercontent.com/geoelements/lbm/develop/license.md)
[![CircleCI](https://circleci.com/gh/geoelements/lbm.svg?style=svg)](https://circleci.com/gh/geoelements/lbm)


## Compile and run

0. Run `mkdir build && cd build && cmake ..`.

1. Run `make clean && make -jN` (where N is the number of cores).

2. Run `./lbm`

## TACC Maverick 2

Load required modules

```
module load cmake/3.16.1
module load gcc/7.3.0
module load cuda/11.0
```

Then compile following the instructions above.
