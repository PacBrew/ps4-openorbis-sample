# openorbis toolchain testing

- Install openorbis toolchain and portlibs
  - `sudo pacbew-pacman -S ps4-openorbis ps4-openorbis-portlibs`
- Build
    - `mkdir build && cd build`
    - `source /opt/pacbrew/ps4/openorbis/ps4vars.sh`
    - `orbis-cmake -G "Unix Makefiles" ../`
    - `make ps4_openorbis_test_pkg`
