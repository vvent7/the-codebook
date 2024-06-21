#include <bits/stdc++.h>
#define _io ios_base::sync_with_stdio(false); cin.tie(0);
#define endl '\n'
#define eb emplace_back
#define pb push_back
#define fi first
#define sec second
#define PI (acos(-1))
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pi;
typedef pair<pi,int> pii;
typedef pair<ll,ll> pll;
typedef vector<pll> vpll;
typedef tuple<ll, ll, ll> tll;
#define eb emplace_back
#define MAXN 200'005
#define oo 1'000'000'123

bool isPrime(ll x){
  if(x<2) return false;
  for(ll div=2;div*div<=x;++div)
    if(x%div==0) return false;
  return true;
}

signed main(){_io
  int t; cin>>t;

  while(t--){
    ll x;
    cin>>x;

    ll l = x/2, r=l+1;
    bool ok=false;
    while(l>0){
      // cout<<l<<"("<<isPrime(l)<<") "<<r<<"("<<isPrime(r)<<")\n";
      if(isPrime(l) || isPrime(r)) {--l; ++r; continue;}
      ok=true;
      cout<<l<<" "<<r<<endl;
      break;
    }
    if(!ok) cout<<-1<<endl;
  }
}