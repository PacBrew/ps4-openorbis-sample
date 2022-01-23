#include <cstdio>
#include <cstdarg>
#include <cstring>
#include <string>

#include <orbis/libkernel.h>
#include <orbis/Sysmodule.h>

#include <zlib.h>
#include <curl/curl.h>
#include "test_ffmpeg.h"

void orbis_printf(const char *fmt, ...) {
    va_list args;
    char str[1024];
    va_start(args, fmt);
    vsnprintf(str, sizeof(str), fmt, args);
    va_end(args);
    sceKernelDebugOutText(0, str);
}

void test_zlib() {
    orbis_printf("testing zlib...\n");

    gzFile fi = gzopen("/data/file.gz", "wb");
    int ret = gzwrite(fi, "ps4-openorbis-zlib-test", strlen("ps4-openorbis-zlib-test"));
    gzclose(fi);

    orbis_printf("zlib: wrote %i bytes\n", ret);
}

static size_t write_string_cb(void *buf, size_t len, size_t count, void *stream) {
    ((std::string *) stream)->append((char *) buf, 0, len * count);
    return len * count;
}

void test_curl() {
    CURL *curl;
    CURLcode res;
    std::string data;

    orbis_printf("testing curl...\n");

    // init sceNet for sceNetGetDnsInfo
    if (sceSysmoduleLoadModuleInternal(ORBIS_SYSMODULE_INTERNAL_NET) < 0) {
        orbis_printf("curl: could not load net module");
        return;
    }

    curl_global_init(CURL_GLOBAL_ALL);
    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, "https://www.google.com/robots.txt");
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_string_cb);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &data);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, false);
        res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            orbis_printf("curl: failed: %s\n", curl_easy_strerror(res));
        } else {
            orbis_printf("curl: %s\n", data.c_str());
        }
        curl_easy_cleanup(curl);
    } else {
        orbis_printf("curl: curl_easy_init failed\n");
    }

    curl_global_cleanup();
}

void test_ffmpeg() {
    ffmpeg_video_decode("/app0/test.mpg", "/data/test.pgm");
}

int main() {

    // test zlib
    test_zlib();

    // test curl
    test_curl();

    // test ffmpeg
    test_ffmpeg();

    while (1) {
        sceKernelUsleep(2 * 1000000);
    }
}
