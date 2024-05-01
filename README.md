# PacBrew openorbis sample

- Install openorbis ps4 toolchain and portlibs
  - see [pacbrew-packages](https://github.com/PacBrew/pacbrew-packages) readme
- Build
  ```
  mkdir cmake-build && cd cmake-build
  source /opt/pacbrew/ps4/openorbis/ps4vars.sh
  openorbis-cmake -G "Unix Makefiles" ../
  make ps4_openorbis_test_pkg
  ```
