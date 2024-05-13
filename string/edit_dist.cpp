#include<bits/stdc++.h>
using namespace std;

constexpr int MAX_N = 1e2+5;

int dp[MAX_N][MAX_N], mxN=0, mxM=0;

int solve(string &a, string &b){
  int n=a.size(), m=b.size(); //a:line, b:column
  for(int i=mxN+1;i<=n;++i) dp[i][0]=i; //1
  for(int j=mxM+1;j<=m;++j) dp[0][j]=j; //2
  mxN = max(mxN, n); mxM = max(mxM, m);

  for(int i=1;i<=n;++i){
    for(int j=1;j<=m;++j){
      if(a[i-1]==b[j-1]) dp[i][j] = dp[i-1][j-1]; //3
      else dp[i][j] = 1 + min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}); //4
    }
  }

  return dp[n][m];
}