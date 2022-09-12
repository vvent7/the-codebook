typedef long long ll;
#define N 105
#define M 105
#define LSB(x) ((x)&-(x))

ll bit[N][M];

ll sum_single(int i1, int j1){ //[(x,y)]
  ll res=0;
  for(int i=i1;i>=1;i-=LSB(i))
    for(int j=j1;j>=1;j-=LSB(j))
      res+=bit[i][j];
  return res;
}

void add(int i1, int j1, ll v, int n, int m){
  for(int i=i1;i<=n;i+=LSB(i))
    for(int j=j1;j<=m;j+=LSB(j))
      bit[i][j]+=v;
}

void add_range(int i1, int j1, int i2, int j2, ll v, int n, int m){
  add(i1, j1, v, n, m);
  add(i1, j2+1, -v, n, m);
  add(i2+1, j1, -v, n, m);
  add(i2+1, j2+1, v, n, m);
}