#include <bits/stdc++.h>

#include<ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

using namespace std;

#define f first
#define s second
#define pb push_back

typedef long long ll;
typedef pair<int, int> pii;

typedef tree<int, null_type, less<int>, rb_tree_tag,
            tree_order_statistics_node_update> indexed_set;

const int INF = 1e9+7;
const ll LINF = ((ll)1e18) + 9;


int n, m, dist;
int u, v;

vector<int> g[5010];
int d[5010];
queue<int> q;

int bfs(int v) {
  for (int i = 0; i <= n; i++) {
    d[i] = INF;
  }
  
  d[v] = 0;
  while (!q.empty()) q.pop();
  q.push(v);
  int melhor = v;

  while (! q.empty()) {
    u = q.front();
    q.pop();

    if (d[u] > d[melhor]) melhor = u;

    for (auto x: g[u]) {
      if (d[x] == INF) {
        d[x] = d[u] + 1;
        q.push(x);
      }
    }
  }

  return melhor;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m >> dist;
  for (int i = 0; i < m; i++) {
    cin >> u >> v;
    g[u].pb(v);
    g[v].pb(u);
  }
  

  //int a = bfs(1);
  //int b = bfs(a);
  
  int longe = 0;
  for (int i = 1; i <= n; i++) {
    v = bfs(i);
    longe = max(longe, d[v]);
  }

  int ans = max(0, 2*dist-longe+1);
  //cerr << ans << ' ' << a << ' ' << b << ' ' << d[b] << '\n';
  cout << ans << ' ' << ans << '\n';


  return 0;
}