# openorbis toolchain testing

- Install openorbis toolchain and portlibs
  - `sudo pacbew-pacman -S ps4-openorbis ps4-openorbis-portlibs`
- Build
    - `mkdir cmake-build && cd cmake-build`
    - `source /opt/pacbrew/ps4/openorbis/ps4vars.sh`
    - `openorbis-cmake -G "Unix Makefiles" ../`
    - `make ps4_openorbis_test_pkg`
