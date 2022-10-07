#include <bits/stdc++.h>
#define fi first
#define eb emplace_back
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int,int>> vpi;

#define MAX_N 100005

vpi g[MAX_N]; //DAG (directed acyclic graph)
bool visited[MAX_N]; //toposort_dfs
int inDegree[MAX_N]; //toposort_kahn, toposort_check
vi ts; //result

void toposort_dfs2(int u){
  visited[u]=true;
  for(auto &p:g[u])
    if(!visited[p.fi])
      toposort_dfs2(p.fi);
  ts.eb(u);
}
void toposort_dfs1(int n){
  fill(visited, visited+n, 0); //0-based
  ts.clear();

  for(int u=0;u<n;u++)
    if(!visited[u])
      toposort_dfs2(u);

  //can be ignored if printed in reverse:
  reverse(ts.begin(), ts.end());
}

void toposort_kahn(int n){
  priority_queue<int,vi,greater<int>> pq; //min pq
  ts.clear();

  for(int u=0;u<n;u++)
    if(inDegree[u]==0)
      pq.emplace(u);

  while(!pq.empty()){
    int u=pq.top(); pq.pop(); ts.eb(u);
    for(auto &p:g[u])
      if((--inDegree[p.fi])==0)
        pq.emplace(p.fi);
  }
}

bool toposort_check(vi &ts){
  for(auto &u:ts){
    if(inDegree[u]!=0) return false;
    for(auto &p:g[u]) inDegree[p.fi]--;
  }
  return true;
}