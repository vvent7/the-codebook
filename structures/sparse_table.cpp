#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAX_N = 100005;
#define MSBI(x)(sizeof(ll)*__CHAR_BIT__-__builtin_clzll(x)-1)

const int K=MSBI(MAX_N);
ll table[K+1][MAX_N];

ll combine(ll x, ll y){
  return min(x, y); //RMQ
  //x+y para RSQ
}

void build(ll *a, int n){
  for(int i=0;i<n;i++) table[0][i]=a[i];
  for(int i=1;i<=K;i++)
    for(int j=0;j+(1<<i)<=n;j++)
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