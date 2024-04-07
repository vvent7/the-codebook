#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define MSBI(x)(sizeof(ll)*__CHAR_BIT__-__builtin_clzll(x)-1)
constexpr int MAX_N = 1e5 + 5, K = MSBI(MAX_N);

struct SparseTable{
  ll table[K+1][MAX_N];

  ll combine(ll x, ll y){
    return min(x, y); //RMQ
    //x+y para RSQ
  }

  void build(ll *a, int sz){
    for(int i=0;i<sz;i++) table[0][i]=a[i];
    for(int i=1;i<=K;i++)
      for(int j=0;j+(1<<i)<=sz;j++)
        table[i][j]=combine(table[i-1][j], table[i-1][j+(1<<(i-1))]);
  }

  ll query_rmq(int l, int r){
    int k=MSBI(r-l+1);
    return combine(table[k][l], table[k][r-(1<<k)+1]);
  }

  ll query_rsq(int l, int r){
    ll res=0;
    for(int i=MSBI(r-l+1);i>=0;i--){
      if((1<<i)<=(r-l+1)){
        res+=table[i][l];
        l+=(1<<i);
      }
    }
    return res;
  }
};