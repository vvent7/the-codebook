#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

const ll MAX_W = 1e9, MAX_N = 2e5, MAX_M = 2e5, INF = MAX_W * MAX_M;
int V;
vector<pll> g[MAX_N];

ll dist[MAX_N];

void dijkstra(int s){
  fill(dist, dist+V+2, INF); dist[s] = 0;
  priority_queue<pll, vector<pll>, greater<pll>> pq;
  pq.emplace(0, s);
  
  while (!pq.empty()) {
    auto [d, u] = pq.top(); pq.pop();
    
    if (d > dist[u]) continue;

    for (auto &[w, v] : g[u]) {
      if (dist[u]+w >= dist[v]) continue;
      dist[v] = dist[u]+w;
      pq.emplace(dist[v], v);
    }
  }
}
