#include <orbis/libkernel.h>

int main() {

    sceKernelDebugOutText(0, "Hello World\n");

    while (1) {
        sceKernelUsleep(2 * 1000000);
    }
}
