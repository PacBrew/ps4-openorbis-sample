#include <orbis/libkernel.h>

int main() {

    sceKernelDebugOutText(0, "Hello World\n");

    while (1) {
        sceKernelUsleep(1000000);
    }

    return 0;
}
