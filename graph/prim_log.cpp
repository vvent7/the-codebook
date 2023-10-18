#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
const ll INF = 1e9, MAX_N = 1e5+5;

ll n; //vertexes
vector<pll> adj[MAX_N];

void prim() {
  ll total_weight = 0;
  vector<bool> selected(n, false);
  vector<pll> min_e(n, {INF, -1});
  set<pll> q;

  min_e[0].first = 0;
  q.insert({0, 0});

  for (int i = 0; i < n; ++i) {
    if (q.empty()) {
      cout << "No MST!" << endl;
      exit(0);
    }

    int v = q.begin()->second;
    selected[v] = true;
    total_weight += q.begin()->first;
    q.erase(q.begin());

    if (min_e[v].second != -1)
      cout << v << " " << min_e[v].second << endl;

    for (pll e : adj[v]) {
      if (!selected[e.second] && e.first < min_e[e.second].first) {
        q.erase({min_e[e.second].first, e.second});
        min_e[e.second] = {e.first, v};
        q.insert({e.first, e.second});
      }
    }
  }

  cout << total_weight << endl;
}