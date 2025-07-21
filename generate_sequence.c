#include <stdio.h>
#include <stdlib.h>

#define SEQ_LEN 100

int main() {
    unsigned int base = 0x1000;
    unsigned int addr;

    printf("unsigned int addresses[] = {\n");
    for (int i = 0; i < SEQ_LEN; i++) {
        if (i % 10 < 7) {
            addr = base + (rand() % 8) * 4;
        } else {
            addr = 0x2000 + (rand() % 50) * 4;
        }
        printf("0x%X, ", addr);
        if ((i + 1) % 8 == 0) printf("\n");
    }
    printf("};\n");
    return 0;
}
