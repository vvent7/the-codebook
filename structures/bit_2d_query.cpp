typedef long long ll;

#define N 1000
#define M 1000
#define LSB(x) ((x)&-(x))

ll bit[N][M];

ll sum_pre(int x, int y){
  ll res=0;
  for(int i=x;i>=1;i-=LSB(i))
    for(int j=y;j>=1;j-=LSB(j))
      res+=bit[i][j];
  return res;
}

ll sum_range(int x1, int y1, int x2, int y2){
  return sum_pre(x2, y2)-sum_pre(x1-1, y2)-sum_pre(x2, y1-1)+sum_pre(x1-1, y1-1);
}

void add(int x, int y, ll v, int n, int m){
  for(int i=x;i<=n;i+=LSB(i))
    for(int j=y;j<=m;j+=LSB(j))
      bit[i][j]+=v;
}