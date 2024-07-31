#include <bits/stdc++.h>
using namespace std;

constexpr int MAX_NM = 2e5+5, UNVISITED=-1, STACKED=-2;

int n, m;
vector<int> g[MAX_NM];

int dfsNumberCounter, numSCC;
int dfs_num[MAX_NM], dfs_low[MAX_NM];
stack<int, vector<int>> st;
int component[MAX_NM];

void tarjanSCC(int u) {
  dfs_low[u] = dfs_num[u] = dfsNumberCounter++;
  st.push(u); component[u] = STACKED; //in stack

  for(auto v : g[u]) {
    if(component[v] == UNVISITED)
      tarjanSCC(v);
    if(component[v] == STACKED) // condition for update
      dfs_low[u] = min(dfs_low[u], dfs_low[v]);
  }

  // a root/start of an SCC
  if (dfs_low[u] == dfs_num[u]) {
    while (1) { //pop until u (current SCC)
      int v = st.top(); st.pop();
      component[v] = numSCC;
      if (u == v) break;
    }
    ++numSCC;
  }
}

void tarjan(int V){
  fill(dfs_num, dfs_num+V+1, UNVISITED);
  fill(dfs_low, dfs_low+V+1, UNVISITED);
  fill(component, component+V+1, UNVISITED);
  
  while (!st.empty()) st.pop();

  dfsNumberCounter = numSCC = 0;
  for(int u = 1; u <= V; ++u)
    if(dfs_num[u] == UNVISITED)
      tarjanSCC(u);
}