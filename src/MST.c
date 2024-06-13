#include "MST.h"
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

MinimalSpanningTree *CreateMinimalSpanningTree(int size)
{
    MinimalSpanningTree *mst = malloc(sizeof(MinimalSpanningTree));
    assert(mst != NULL);
    mst->last_index = 0;
    mst->size = size;
    mst->edges = calloc(size, sizeof(Edge));
    assert(mst->edges != NULL);
    return mst;
}

void AddEdge(MinimalSpanningTree *mst, int start, int end)
{
    mst->edges[mst->last_index].start = start;
    mst->edges[mst->last_index].end = end;
    mst->last_index++;
}

void PrintMST(MinimalSpanningTree *mst)
{
    for (int i = 0; i < mst->last_index; i++)
    {
        printf("%d %d", mst->edges[i].start, mst->edges[i].end);
        printf("\n");
    }

}

void DestroyMinimalSpanningTree(MinimalSpanningTree *mst)
{
    free(mst->edges);
    free(mst);
}
