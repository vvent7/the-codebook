typedef long long ll;
#define N 105
#define M 105
#define LSB(x) ((x)&-(x))

ll bit[N][M];

ll sum_single(int x, int y){ //[(x,y)]
  ll res=0;
  for(int i=x;i>=1;i-=LSB(i))
    for(int j=y;j>=1;j-=LSB(j))
      res+=bit[i][j];
  return res;
}

void add(int x, int y, ll v, int n, int m){
  for(int i=x;i<=n;i+=LSB(i))
    for(int j=y;j<=m;j+=LSB(j))
      bit[i][j]+=v;
}

//[(x1,y1),(x2,y2)]
void add_range(int x1, int y1, int x2, int y2, ll v, int n, int m){
  add(x1, y1, v, n, m);
  add(x1, y2+1, -v, n, m);
  add(x2+1, y1, -v, n, m);
  add(x2+1, y2+1, v, n, m);
}