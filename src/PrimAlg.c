#include "PrimAlg.h"
#include "AdjacencyMatrix.h"
#include "MST.h"
#include "BinaryHeap.h"
#include "Errors.h"
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <stdbool.h>

static int *CreateParentsNodesArr(AdjMatrix *matrix)
{
    int *p = calloc(matrix->n, sizeof(int));
    assert(p != NULL);
    return p;
}

static bool *CreateVisitedArr(AdjMatrix *matrix)
{
    bool *visited = calloc(matrix->n, sizeof(int));
    assert(visited != NULL);
    return visited;
}

static int FindVertexIndex(int vertex, Heap *heap)
{
    for (int i = 0; i < heap->last_index; i++)
    {
        if (heap->tree[i] == vertex)
        {
            return i;
        }
    }
    return -5;
}

void PrimAlg(AdjMatrix *matrix)
{
    int *p = CreateParentsNodesArr(matrix);
    bool *visited = CreateVisitedArr(matrix);
    Heap *heap = CreateHeap(matrix->n);
    MinimalSpanningTree *mst = CreateMinimalSpanningTree(matrix->n);
    heap->keys[0] = 0;
    int vertex = HeapExtract(heap);
    visited[vertex - 1] = 1;
    while (!IsEmpty(heap))
    {
        for (int j = 0; j < matrix->n; j++)
        {
            if (visited[j] == true)
            {
                continue;
            }
            if (matrix->matrix_src[vertex - 1][j] == 0)
            {
                continue;
            }
            if (matrix->matrix_src[vertex - 1][j] < heap->keys[j])
            {
                p[j] = vertex;
                heap->keys[j] = matrix->matrix_src[vertex - 1][j];
                int vertex_index = FindVertexIndex(j + 1, heap);
                assert(vertex_index >= 0);
                ElementUp(heap, vertex_index);
            }
        }
        vertex = HeapExtract(heap);
        visited[vertex - 1] = true;
        if (NoSpanningError(p, vertex - 1) == false)
        {
            free(p);
            free(visited);
            DestroyMatrix(matrix);
            DestroyHeap(heap);
            DestroyMinimalSpanningTree(mst);
            printf("no spanning tree");
            return;
        }
        AddEdge(mst, vertex, p[vertex - 1]);
    }
    PrintMST(mst);
    free(p);
    free(visited);
    DestroyMatrix(matrix);
    DestroyHeap(heap);
    DestroyMinimalSpanningTree(mst);
}
