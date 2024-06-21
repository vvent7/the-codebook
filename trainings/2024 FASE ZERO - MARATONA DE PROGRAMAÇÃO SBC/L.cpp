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

map<string,int> indCrianca; 
set<pair<int,string>> ord;

signed main(){_io
  int n;
  string s;
  cin>>n;
  vector<string> nomes(n);
  for(int i=0;i<n;i++) cin>>nomes[i];
  for(int i=0;i<n;i++){
    cin>>s;
    ord.insert({i,s});
    indCrianca[s]=i;
  }
  for(int i=0;i<n;i++){
    auto it = ord.begin();
    //cout<<(*it).second<<" crianca irritante"<<endl;
    cout<<(*it).second;
    if(i+1<n) cout<<" "; 
    int indice = indCrianca[nomes[i]];
    ord.erase({indice,nomes[i]});
  }
  cout<<endl;
}