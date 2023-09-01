typedef long long ll;

ll combs[55][55]; //all zero

ll comb(int n, int m){
  if(n<m || m<0) return 0;
  if(m==0 || n==m) return 1;
  if(combs[n][m]!=0) return combs[n][m];
  return combs[n][m] = comb(n-1, m-1) + comb(n-1, m);
}