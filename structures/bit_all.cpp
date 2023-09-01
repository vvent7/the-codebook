typedef long long ll;
const int MAX_N = 200005;
#define LSB(x) ((x)&-(x))

ll bit1[MAX_N], bit2[MAX_N];

ll sum(ll *b, int i){
  ll res=0;
  for(;i>=1;i-=LSB(i)) res+=b[i];
  return res;
}

ll sum_pre(int i){ //[1,i]
  return sum(bit1, i)*ll(i) - sum(bit2, i);
}

ll sum_range(int l, int r){ //[l,r]
  return sum_pre(r) - sum_pre(l-1);
}

void add(ll *b, int i, ll v, int n){
  for(;i<=n;i+=LSB(i)) b[i]+=v;
}

void add_range(int l, int r, ll v, int n){ //[l,r]
  add(bit1, l, v, n);
  add(bit1, r+1, -v, n);
  add(bit2, l, v*(l-1), n);
  add(bit2, r+1, -v*r, n);
}