#ifndef STRUCTURE_H_GUARD
#define STRUCTURE_H_GUARD

#include <limits.h>
#include <stdio.h>

#define V 100

typedef struct dNode{
    int ok;
    int distance;
    int index;
    struct dNode *previous;
    int distances_to[V];
}dNode;

dNode *list[V][V];
int source_y;
int count_v;

void init();
void dijkstra();
int dist_between(dNode *a, dNode *b);
int smallest_distance_q();
void min_route();

#endif
