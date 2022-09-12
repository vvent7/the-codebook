typedef long long ll;
#define N 1005
#define M 1005
#define LSB(x) ((x)&-(x))

ll bit[N][M];

ll sum_pre(int i1, int j1){
  ll res=0;
  for(int i=i1;i>=1;i-=LSB(i))
    for(int j=j1;j>=1;j-=LSB(j))
      res+=bit[i][j];
  return res;
}

ll sum_range(int i1, int j1, int i2, int j2){
  return sum_pre(i2, j2)-sum_pre(i1-1, j2)-sum_pre(i2, j1-1)+sum_pre(i1-1, j1-1);
}

void add(int i1, int j1, ll v, int n, int m){
  for(int i=i1;i<=n;i+=LSB(i))
    for(int j=j1;j<=m;j+=LSB(j))
      bit[i][j]+=v;
}