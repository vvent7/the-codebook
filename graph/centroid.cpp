#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MAX_N = 1e5+5;

ll n; //vertexes
vector<ll> g[MAX_N]; //graph

struct CD{
  bool removed[MAX_N]; //removed v
  ll treeSz[MAX_N]; //subtree sizes

  //RESET before new decomposition
  void reset(ll n){ 
    fill(removed, removed+n+1, false);
  }
  
  ll get_tree_size(ll u, ll parent){
    treeSz[u]=1;
    for(auto v:g[u]){
      if(v==parent || removed[v]) continue;
      treeSz[u]+=get_tree_size(v, u);
    }
    return treeSz[u];
  }

  ll get_centroid(ll u, ll parent, ll sz){
    for(auto v:g[u]){
      if(v==parent || removed[v]) continue;
      if(treeSz[v] > sz/2)
        return get_centroid(v, u, sz);
    }
    return u;
  }

  void decompose(ll u, ll parent){
    get_tree_size(u, parent);
    ll c = get_centroid(u, parent, treeSz[u]);

    //do something starting in c...

    removed[c] = true;
    for(auto v:g[c]){
      if(removed[v]) continue;
      decompose(v, c);
    }
  }

  //PROBLEM CODE...
} cd;