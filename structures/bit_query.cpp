typedef long long ll;
const int MAX_N = 200005;
#define LSB(x) ((x)&-(x))

ll bit[MAX_N];

ll sum_single(int i){ //[i] faster
  ll res=bit[i];
  if(i<=1) return res;

  int z=i-LSB(i); i--;
  for(;i>z;i-=LSB(i)) res-=bit[i];
  return res;
}

ll sum_pre(int i){ //[1,i]
  ll res=0;
  for(;i>0;i-=LSB(i)) res+=bit[i];
  return res;
}

ll sum_range(int l, int r){ //[l,r]
  return sum_pre(r)-sum_pre(l-1);
}

void add(int i, ll v, int n){
  for(;i<=n;i+=LSB(i)) bit[i]+=v;
}

void set(int i, ll v, int n){ //[i]
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