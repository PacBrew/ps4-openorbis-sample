//
// Created by cpasjuste on 03/01/2022.
//

#ifndef PS4_OPENORBIS_TEST_TEST_FFMPEG_H
#define PS4_OPENORBIS_TEST_TEST_FFMPEG_H

extern "C" {
int ffmpeg_video_decode(const char *filename, const char *outfilename);
}

#endif //PS4_OPENORBIS_TEST_TEST_FFMPEG_H
