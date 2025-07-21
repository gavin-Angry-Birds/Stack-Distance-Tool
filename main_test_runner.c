#include <stdio.h>
#include "stack_distance_tool.h"

int main() {
    // 生成模拟的地址访问序列
    unsigned int addresses[] = {
        0x1000, 0x1004, 0x1008, 0x1000, 0x1004, 0x2000, 0x1000, 0x3000,
        0x1000, 0x1004, 0x1008, 0x1010, 0x2000, 0x1000, 0x5000, 0x6000
    };
    int len = sizeof(addresses) / sizeof(addresses[0]);

    for (int i = 0; i < len; i++) {
        log_access(addresses[i]);
    }

    compute_stack_distance_histogram();
    print_histogram();
    return 0;
}
