#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

const int MAX_N = 100005;
enum{UNVISITED=-1};

vector<pair<int,int>> g[MAX_N];

int dfsNumberCounter, numSCC;
vi dfs_num, dfs_low, visited;
stack<int> St;

void tarjanSCC(int u) {
  dfs_low[u] = dfs_num[u] = dfsNumberCounter;
  dfsNumberCounter++;
  St.push(u);
  visited[u] = 1; //in stack

  for(auto &[w, v] : g[u]) {
    if(dfs_num[v] == UNVISITED)
      tarjanSCC(v);
    if(visited[v]) // condition for update
      dfs_low[u] = min(dfs_low[u], dfs_low[v]);
  }

  // a root/start of an SCC
  if (dfs_low[u] == dfs_num[u]) {
    ++numSCC;
    while (1) { //pop until u (current SCC)
      int v = St.top(); St.pop();
      visited[v] = 0;
      if (u == v) break;
    }
  }
}

void tarjan(int V){
  dfs_num.assign(V, UNVISITED); dfs_low.assign(V, 0); visited.assign(V, 0);
  while (!St.empty()) St.pop();
  dfsNumberCounter = numSCC = 0;
  for (int u = 0; u < V; ++u)
    if (dfs_num[u] == UNVISITED)
      tarjanSCC(u);
}