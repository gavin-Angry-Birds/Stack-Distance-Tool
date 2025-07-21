#include <stdio.h>
#include "stack_distance_tool.h"

static unsigned int stack[MAX_STACK_SIZE];
static int stack_len = 0;

static unsigned int access_log[MAX_ACCESSES];
static int access_count = 0;

static int histogram[HISTOGRAM_BINS] = {0};

int find_in_stack(unsigned int addr) {
    for (int i = 0; i < stack_len; i++) {
        if (stack[i] == addr) return i;
    }
    return -1;
}

void remove_at(int pos) {
    for (int i = pos; i < stack_len - 1; i++) {
        stack[i] = stack[i + 1];
    }
    stack_len--;
}

void push(unsigned int addr) {
    if (stack_len == MAX_STACK_SIZE) {
        remove_at(stack_len - 1);
    }
    for (int i = stack_len; i > 0; i--) {
        stack[i] = stack[i - 1];
    }
    stack[0] = addr;
    if (stack_len < MAX_STACK_SIZE) stack_len++;
}

void log_access(unsigned int addr) {
    if (access_count < MAX_ACCESSES) {
        access_log[access_count++] = addr;
    }
}

void compute_stack_distance_histogram() {
    stack_len = 0; // reset stack
    for (int i = 0; i < access_count; i++) {
        unsigned int addr = access_log[i];
        int dist = find_in_stack(addr);
        if (dist == -1) {
            histogram[HISTOGRAM_BINS - 1]++;
        } else {
            histogram[dist < HISTOGRAM_BINS ? dist : HISTOGRAM_BINS - 1]++;
            remove_at(dist);
        }
        push(addr);
    }
}

void print_histogram() {
    printf("\n=== 栈距离分布柱状图（时间局部性） ===\n");
    for (int i = 0; i < HISTOGRAM_BINS; i++) {
        printf("距离%3d: %4d | ", i, histogram[i]);
        for (int j = 0; j < histogram[i] && j < 50; j++) {
            printf("*");
        }
        printf("\n");
    }
}

