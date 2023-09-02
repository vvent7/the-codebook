#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAX_N = 1e3+5, MAX_M = 1e3+5;

ll a[MAX_N][MAX_M], preSum[MAX_N][MAX_M];

ll kadane_2d(int n, int m){
  for(int i=0;i<n;i++) preSum[i][0]=a[i][0];
  for(int i=0;i<n;i++)
    for(int j=1;j<m;j++)
      preSum[i][j] = a[i][j] + preSum[i][j-1];
  
  ll ans=0;
  for(int l=0;l<m;l++){
    for(int r=l;r<m;r++){
      ll sum=0;
      for(int i=0;i<n;i++){
        sum += preSum[i][r] - (l ? preSum[i][l-1] : 0);
        ans = max(ans, sum);
        if(sum < 0) sum=0;
      }
    }
  }

  return ans;
}