#define MAX_N 200005
#define LSB(x) ((x)&-(x))

int bit[MAX_N];

int sum_single(int i){ //[i]
  int res=0;
  for(;i>=1;i-=LSB(i)) res+=bit[i];
  return res;
}

void add(int i, int v, int n){
  for(;i<=n;i+=LSB(i)) bit[i]+=v;
}

void add_range(int l, int r, int v, int n){ //[l,r]
  add(l, v, n); add(r+1, -v, n);
}

void set(int i, int v, int n){ //[i]
  add(i, v-sum_single(i), n);
}