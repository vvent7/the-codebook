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

ll e,v;

signed main(){_io
  cin>>e>>v;
  ll l=0,r=1e11;
  ll ans=r;
  while(l<=r){
    ll mid = (l+r)/2;
    if(v*mid>=60*e){
        ans = mid;
        r=mid-1;
    }
    else l=mid+1;
  }
  //47997  //48000
  if(v*ans>60*e) --ans;
  // cout<<ans<<endl;
  ll horas = ((ans/60)+19)%24;
  ll minutos = ans%60;
  if(horas<10) cout<<"0";
  cout<<horas<<":";
  if(minutos<10) cout<<"0";
  cout<<minutos<<endl;
}