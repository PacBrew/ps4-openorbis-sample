cmake_minimum_required(VERSION 3.0)
set(CMAKE_VERBOSE_MAKEFILE ON)

project(ps4_openorbis_test)

file(GLOB SOURCES source/*.c*)

add_executable(ps4_openorbis_test ${SOURCES})
add_self(ps4_openorbis_test)
add_pkg(ps4_openorbis_test "PACB00001" "pacbrew openorbis test" "01.00")

target_link_libraries(ps4_openorbis_test
        SceSysUtil
        SceSysmodule
        SceNet
        c++
        curl mbedtls mbedx509 mbedcrypto
        swscale swresample avformat avfilter avcodec avutil
        z
        )
