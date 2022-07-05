#define MAX_N 200005
#define LSB(x) ((x)&-(x))

int bit[MAX_N];

int sum_single(int i){ //[i] faster
  int res=bit[i];
  if(i<=1) return res;

  int z=i-LSB(i); i--;
  for(;i>z;i-=LSB(i)) res-=bit[i];
  return res;
}

int sum_pre(int i){ //[1,i]
  int res=0;
  for(;i>0;i-=LSB(i)) res+=bit[i];
  return res;
}

int sum_range(int l, int r){ //[l,r]
  return sum_pre(r)-sum_pre(l-1);
}

void add(int i, int v, int n){
  for(;i<=n;i+=LSB(i)) bit[i]+=v;
}

void set(int i, int v, int n){ //[i]
  add(i, v-sum_single(i), n);
}

void unbuild(int n){ //unbuild in-place
  for(int i=n, next;i>0;i--){
    next=i+LSB(i);
    if(next<=n) bit[next]-=bit[i];
  }
}

void build(int n){ //build in-place
  for(int i=1, next;i<n;i++){
    next=i+LSB(i);
    if(next<=n) bit[next]+=bit[i];
  }
}