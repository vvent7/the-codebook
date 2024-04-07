#include <bits/stdc++.h>
using namespace std;

constexpr int MAX_N = 1e5 + 5;

vector<int> g[MAX_N];
int depth[MAX_N], first[MAX_N], euler[2*MAX_N], eulerSz;

void dfs(int u, int p){
  first[u]=eulerSz;
  euler[eulerSz++]=u;
  for(int v:g[u]){
    if(v==p) continue;
    depth[v] = depth[u]+1;
    dfs(v, u);
    euler[eulerSz++]=u;
  }
}
void buildEuler(int root){
  depth[root] = eulerSz = 0;
  dfs(root, root);
}

/* RMQ structure on euler (Sparse Table, SegTree)
 * single(v): return v
 * merge(v1, v2): return depth[v1] < depth[v2] ? v1 : v2
 * lca(u,v): query(first[u], first[v]) // fU < fV */