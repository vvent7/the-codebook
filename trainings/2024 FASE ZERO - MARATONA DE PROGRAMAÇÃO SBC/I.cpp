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

constexpr int MAX_N = 1e3+5, MAX_M = 1e3+5;

int n, m;
string s;
int freqOne[MAX_N], tableCollision[MAX_M], collisionCnt=0; 

signed main(){_io
  cin>>n>>m>>s;

  for(int i=0;i<n;++i){
    freqOne[i]=0;
    for(int j=i*m;j<(i+1)*m;++j)
      freqOne[i] += (s[j]=='1');
    if(++tableCollision[freqOne[i]]==2)
      ++collisionCnt;
  }

  if(collisionCnt>0){cout<<"N\n"; return 0;}

  int sz=(int)s.size();
  for(int j=0;j<m;++j){ //toRm
    for(int i=0;i<n;++i){
      int toRm = i*m+j, toAdd = (toRm+m)%sz;
      if(--tableCollision[freqOne[i]]==1) --collisionCnt;
      freqOne[i]+=(int)(s[toAdd]=='1') - (int)(s[toRm]=='1');
      if(++tableCollision[freqOne[i]]==2) ++collisionCnt;
    }
    if(collisionCnt>0){
      cout<<"N\n";
      return 0;
    }
  }

  cout<<"S\n";
}