#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(false);
typedef long long ll;
using namespace std;

ll combs[55][55];

ll comb(int n, int m){
  if(n<m || m<0) return 0;
  if(m==0 || n==m) return 1;
  if(combs[n][m]!=-1) return combs[n][m];
  return combs[n][m] = comb(n-1, m-1) + comb(n-1, m);
  //não esquecer de setar o vetor combs como -1
}