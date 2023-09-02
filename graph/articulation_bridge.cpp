#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int,int> pi;
enum{UNVISITED=-1};
const int MAX_N = 100005;

vi g[MAX_N];

int dfs_num[MAX_N], dfs_low[MAX_N], dfs_parent[MAX_N];
bool articulation_vertex[MAX_N];
vector<pi> bridges;
int dfsNumberCounter, dfsRoot, rootChildren;

void articulationPointAndBridge(int u){
  dfs_num[u] = dfsNumberCounter++;
  dfs_low[u] = dfs_num[u];

  for(int v: g[u]){
    if(dfs_num[v] == UNVISITED){
      dfs_parent[v] = u;

      if(u == dfsRoot) ++rootChildren; 
      // if root has more than one
      // child it is an articulation point

      articulationPointAndBridge(v);
      if(dfs_low[v] >= dfs_num[u]) //articulation point (u)
        articulation_vertex[u] = 1;
      if(dfs_low[v] > dfs_num[u])  //bridge (u->v)
        bridges.emplace_back(u,v);
      
      dfs_low[u] = min(dfs_low[u], dfs_low[v]);  // subtree, always update
    }
    else if(v != dfs_parent[u])
      dfs_low[u] = min(dfs_low[u], dfs_num[v]);
  }
}