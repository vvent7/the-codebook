#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
const ll INF = 1e9, MAX_N = 1e5+5;

ll n; //vertexes
vector<pll> adj[MAX_N]; //weight, vertex

void dijkstra(ll s, vector<ll> &d, vector<ll> &p) {
  d.assign(n, INF);
  p.assign(n, -1);
  vector<bool> u(n, false);

  d[s] = 0;
  for (ll i = 0; i < n; i++) {
    ll v = -1;
    for (ll j = 0; j < n; j++) {
      if (!u[j] && (v == -1 || d[j] < d[v]))
        v = j;
    }

    if(d[v] == INF) break;

    u[v] = true;
    for (auto &[to,len] : adj[v]) {
      if (d[v] + len < d[to]) {
        d[to] = d[v] + len;
        p[to] = v;
      }
    }
  }
}