#include <bits/stdc++.h>
#define fi first
#define eb emplace_back
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int,int>> vpi;

#define MAX_N 100005

vpi g[MAX_N]; //DAG (directed acyclic graph)
bool visited[MAX_N]; //all 0 before toposort
vi ts;

void toposort_dfs(int u){
  visited[u]=true;
  for(auto &p:g[u])
    if(!visited[p.fi])
      toposort_dfs(p.fi);
  ts.eb(u);
}

void toposort(int n){
  fill(visited, visited+n, 0); //0-based
  ts.clear();

  for(int u=0;u<n;u++)
    if(!visited[u])
      toposort_dfs(u);

  //can be ignored if printed in reverse:
  reverse(ts.begin(), ts.end());
}

int inDegree[MAX_N]; //processed beforehand
bool check_toposort(vi &ts){
  for(auto &u:ts){
    if(inDegree[u]>0) return false;
    for(auto &p:g[u]) inDegree[p.fi]--;
  }
  return true;
}