#ifndef STACK_DISTANCE_TOOL_H
#define STACK_DISTANCE_TOOL_H

#define MAX_STACK_SIZE 100
#define MAX_ACCESSES 1000
#define HISTOGRAM_BINS 20

void log_access(unsigned int addr);
void compute_stack_distance_histogram();
void print_histogram();

#endif // STACK_DISTANCE_TOOL_H
