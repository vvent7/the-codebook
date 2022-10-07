#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX_N 55
#define MOD 1000000009LL

// base           baseCopy(maintain base intact)    aux                res
ll base[MAX_N][MAX_N], baseCp[MAX_N][MAX_N], aux[MAX_N][MAX_N], ans[MAX_N][MAX_N];
int n; //n lines|columns

ll mod(ll a, ll m){
  return ((a%m)+m)%m;
}

//multiply square matrix
void mat_mul(ll a[MAX_N][MAX_N], ll b[MAX_N][MAX_N], ll res[MAX_N][MAX_N]){
  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
      res[i][j]=0;
  
  for(int i=0;i<n;i++){
    for(int k=0;k<n;k++){
      if(a[i][k]==0) continue; //optimization
      for(int j=0;j<n;j++){
        res[i][j]+=mod(a[i][k],MOD)*mod(b[k][j],MOD);
        res[i][j]=mod(res[i][j],MOD);
      }
    }
  }
}

void mat_pow(ll p){
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      baseCp[i][j]=base[i][j];
      ans[i][j] = (i==j?1:0);
    }
  }
  
  while(p){
    if(p&1){ mat_mul(ans, baseCp, aux); swap(ans, aux); }
    mat_mul(baseCp,baseCp,aux); swap(baseCp,aux);
    p>>=1;
  }
}