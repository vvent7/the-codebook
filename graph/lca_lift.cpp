#include <bits/stdc++.h>
using namespace std;

#define LOG(x) (sizeof(int) * __CHAR_BIT__ -  __builtin_clz(x))
constexpr int MAX_N = 2e5+5, LOG_N = LOG(MAX_N);

vector<int> g[MAX_N];
int depth[MAX_N], up[MAX_N][LOG_N];

void lca_dfs(int u){
  for(int v:g[u]){
    if(up[u][0]==v) continue;
    
    depth[v] = depth[u]+1;
    up[v][0] = u;
    for(int i=1; i<LOG_N; ++i)
      up[v][i] = up[up[v][i-1]][i-1];
    
    lca_dfs(v);
  }
}
void lca_build(int root){
  fill(up[root], up[root]+LOG_N, root); //self-parent
  depth[root] = 0;
  lca_dfs(root);
}

int lca(int u, int v){
  if(depth[u] < depth[v]) swap(u, v);

  int k = depth[u] - depth[v];
  for(int i=LOG_N-1; i>=0; --i)
    if(k & (1<<i)) u = up[u][i];
  
  if(u==v) return u;

  for(int i=LOG_N-1; i>=0; --i){
    if(up[u][i]!=up[v][i]){
      u = up[u][i];
      v = up[v][i];
    }
  }

  return up[u][0];
}