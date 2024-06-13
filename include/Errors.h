#pragma once
#include "MST.h"
#include <stdbool.h>

bool NoSpanningError(int *p, int p_index);

bool VerticesError(int n);

bool EdgeError(int n, int m);

bool VertexError(int node_1, int node_2, int n);
