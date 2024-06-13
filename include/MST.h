#pragma once

typedef struct Edge
{
    int start;
    int end;
} Edge;

typedef struct MinimalSpanningTree
{
    int last_index;
    int size;
    Edge *edges;

} MinimalSpanningTree;

MinimalSpanningTree* CreateMinimalSpanningTree(int size);

void AddEdge(MinimalSpanningTree *mst, int start, int end);

void PrintMST(MinimalSpanningTree *mst);

void DestroyMinimalSpanningTree(MinimalSpanningTree *mst);
