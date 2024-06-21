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
#define MAXN 505
#define oo 1'000'000'123

int pont[MAXN][MAXN];
char tabu[MAXN][MAXN];
int k,l;
int n,m;
void marcar(int i,int j){
  set<pair<int,int>> mov;
  mov.insert({i-k,j-l});
  mov.insert({i-k,j+l});
  mov.insert({i+k,j-l});
  mov.insert({i+k,j+l});
  mov.insert({i-l,j-k});
  mov.insert({i-l,j+k});
  mov.insert({i+l,j-k});
  mov.insert({i+l,j+k});
  for(auto point: mov){
    if(point.first>=0 && point.first<n && point.second>=0 && point.second<m){
      //cout<<"marcando "<<point.first<<" "<<point.second<<endl;
      pont[point.first][point.second]++;
    }
  }

}
signed main(){_io
  
  cin>>n>>m>>k>>l;
  k--;l--;
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      cin>>tabu[i][j];
      if(tabu[i][j]=='*'){
        marcar(i,j);
      }
    }
  }
  int ri=1,rj=1,pontAtual=-1;
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      if(pont[i][j]>pontAtual && tabu[i][j]=='.'){
        ri=i+1;
        rj=j+1;
        pontAtual=pont[i][j];
      }
      //cout<<pont[i][j]<<" ";
    }
    //cout<<endl;
  }
  cout<<ri<<" "<<rj<<endl;
}