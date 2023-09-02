#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e2;

int AM[MAX_N][MAX_N], p[MAX_N][MAX_N];

void floyd_warshall(int V){
  for (int i = 0; i < V; i++)
    for (int j = 0; j < V; j++)
      p[i][j] = i;
  
  for (int k = 0; k < V; ++k)
    for (int i = 0; i < V; ++i)
      for (int j = 0; j < V; ++j)
        if (AM[i][k]+AM[k][j] < AM[i][j]) {
          AM[i][j] = AM[i][k]+AM[k][j];
          p[i][j] = p[k][j];
        }
}

void printPath(int i, int j) {
  if (i != j) printPath(i, p[i][j]);
  cout<<i<<" ";
}