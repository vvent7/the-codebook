#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define MAX_N 100005
#define MSBI(x)(sizeof(int)*__CHAR_BIT__-__builtin_clz(x)-1)

const int K=MSBI(MAX_N);
int table[K+1][MAX_N];

int merge(int x, int y){
  return min(x, y); //RMQ
  //x+y para RSQ
}

void build(int *a, int n){
  for(int i=0;i<n;i++) table[0][i]=a[i];
  for(int i=1;i<=K;i++)
    for(int j=0;j+(1<<i)<=n;j++)
      table[i][j]=merge(table[i-1][j], table[i-1][j+(1<<(i-1))]);
}

int query_rmq(int l, int r){
  int k=MSBI(r-l+1);
  return merge(table[k][l], table[k][r-(1<<k)+1]);
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