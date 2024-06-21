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

bool a[3];

signed main(){_io
  for(int i=0, x;i<3;++i){
    cin>>x;
    if(x==0) continue;
    a[x-1]=true;
  }

  for(int i=0;i<3;++i){
    if(!a[i]){
      cout<<i+1<<endl;
      break;
    }
  }

}