typedef long long ll;
const int MAX_N =1005, MAX_M = 1005;

ll pre[MAX_N][MAX_M];

void unbuild(int n, int m){ //unbuild in-place
  for(int i=n-1;i>0;i--)
    for(int j=m-1;j>0;j--)
      pre[i][j]-=pre[i][j-1]+pre[i-1][j]-pre[i-1][j-1];
  
  for(int i=n-1;i>0;i--) pre[i][0]-=pre[i-1][0];
  for(int j=m-1;j>0;j--) pre[0][j]-=pre[0][j-1];
}

void build(int n, int m){ //build in-place
  for(int i=1;i<n;i++) pre[i][0]+=pre[i-1][0];
  for(int j=1;j<m;j++) pre[0][j]+=pre[0][j-1];

  for(int i=1;i<n;i++)
    for(int j=1;j<m;j++)
      pre[i][j]+=pre[i][j-1]+pre[i-1][j]-pre[i-1][j-1];
}

ll sum(int i, int j){
  if(i<0 && j<0) return 0;
  if(i<0) return pre[0][j];
  if(j<0) return pre[i][0];
  return pre[i][j];
}

ll sum_range(int i, int j, int k, int l){
  return sum(k,l)-sum(k, j-1)-sum(i-1, l)+sum(i-1, j-1);
}