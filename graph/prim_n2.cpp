#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
const ll MAX_N = 1e5+5;
const ll INF = 1e9; // weight INF means there is no edge

ll n; // vertexes
ll adj[MAX_N][MAX_N]; //adj[u][v] = weight of edge u-v

void prim() { //0-based
  ll total_weight = 0;
  vector<bool> selected(n, false);
  vector<pll> min_e(n, {INF, -1});
  min_e[0].first = 0;

  for (int i=0; i<n; ++i){
    int v = -1;
    for(int j = 0; j < n; ++j){
      if(!selected[j] &&
        (v == -1 || min_e[j].first < min_e[v].first))
        v = j;
    }

    if (min_e[v].first == INF) {
      cout << "No MST!" << endl;
      exit(0);
    }

    selected[v] = true;
    total_weight += min_e[v].first;
    if(min_e[v].second != -1)
      cout << v << " " << min_e[v].second << endl;

    for (int to = 0; to < n; ++to){
      if (adj[v][to] < min_e[to].first)
        min_e[to] = {adj[v][to], v};
    }
  }

  cout << total_weight << endl;
}