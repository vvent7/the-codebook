#include <bits/stdc++.h>
#define _io ios_base::sync_with_stdio(false); cin.tie(0);
#define endl '\n'
#define eb emplace_back
#define fi first
#define sec second
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll,ll> pll;
typedef tuple<int,int,int> ti;

constexpr int MAX_N = 2e5+5;

int n,m, k;
vector<pair<int,int>> g[MAX_N]; // {v, time}

int limW;

bool visited[MAX_N];
int dfs(int u){
  visited[u]=true;

  int ans=1;
  for(auto [v, w]:g[u]){
    if(visited[v] || w>limW) continue; //cant take this edge
    ans+=dfs(v);
  }

  return ans;
}

signed main(){_io
  cin>>n>>m>>k;

  int mxW=0;
  while(m--){
    int u, v, w;
    cin>>u>>v>>w;
    g[u].eb(v, w);
    g[v].eb(u, w);
    mxW=max(mxW, w);
  }

  int l=0, r=mxW, ans=mxW;
  while(l<=r){
    limW = l+(r-l)/2;
    fill(visited, visited+n+1, false);
    if(dfs(1)>=k) ans=limW, r=limW-1;
    else l=limW+1;
  }

  cout<<ans<<endl;
}
