# Multiphase LBM

[![License](https://img.shields.io/badge/license-MIT-blue.svg)](https://raw.githubusercontent.com/geoelements/lbm/develop/license.md)
[![CircleCI](https://circleci.com/gh/geoelements/lbm.svg?style=svg)](https://circleci.com/gh/geoelements/lbm)
[![codecov](https://codecov.io/gh/geoelements/lbm/branch/develop/graph/badge.svg?token=LT1P12Q6LW)](https://codecov.io/gh/geoelements/lbm)
[![Project management](https://img.shields.io/badge/projects-view-ff69b4.svg)](https://github.com/orgs/geoelements/projects/1)
[![Discussion forum](https://img.shields.io/badge/forum-lbm-blueviolet.svg)](https://github.com/geoelements/lbm/discussions)

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
