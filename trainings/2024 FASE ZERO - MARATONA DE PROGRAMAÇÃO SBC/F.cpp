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

constexpr int MAX_N = 5e3+50, MOD=998244353;
constexpr int INF = -MOD;

int n;
string s;
int sOpen, sClosing;
int dp[2][MAX_N][MAX_N]; //[i][N] -> balance==0

signed main(){_io
  cin>>n>>s;

  for(char c:s){
    if(c=='(') ++sOpen;
    if(c==')'){
      if(sOpen>0) --sOpen;
      else ++sClosing;
    }
  }
  
  for(int i=n;i>=0;--i){
    for(int b=0;b<=n;++b){
      for(int inserted=0;inserted<2;++inserted){
        int &cur = dp[inserted][i][b];
        if(i>=n) {cur = (b==0 ? inserted : 0); continue;}
        cur=(cur+dp[inserted][i+1][b+1])%MOD;
        if(b>0)
          cur=(cur+dp[inserted][i+1][b-1])%MOD;
        if( inserted==0 &&
            (i+(int)s.size())<=n &&
            b>=sClosing) //put s
          cur=(cur+dp[true][i+s.size()][b-sClosing+sOpen])%MOD;
      }
    }
  }

  cout<<dp[0][0][0]<<endl;
}