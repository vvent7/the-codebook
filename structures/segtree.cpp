typedef long long ll;

#define MAX_N 100005

struct SegTree{
  ll values[2*MAX_N+5];
  ll n, nx, NEUTRAL_ELEMENT=0;

  ll single(ll v){
    return v;
  }
  ll unite(ll v, ll w){
    return v+w;
  }

  void build(ll *a, ll x, ll lx, ll rx){
    if(lx==rx){values[x]=single(a[lx]); return;}
    ll mid=(lx+rx)/2, x1=x+1, x2=x+2*(mid-lx+1);

    build(a, x1, lx, mid); build(a, x2, mid+1, rx);
    
    values[x]=unite(values[x1], values[x2]);
  }
  void build(ll *a, ll n){
    this->n=n; nx=2*n-1;
    build(a, 0, 0, n-1);
  }

  void update_set(ll i, ll v, ll x, ll lx, ll rx){
    if(lx==rx){values[x]=single(v); return;}
    ll mid=(lx+rx)/2, x1=x+1, x2=x+2*(mid-lx+1);

    if(i<=mid) update_set(i, v, x1, lx, mid);
    else update_set(i, v, x2, mid+1, rx);

    values[x]=unite(values[x1], values[x2]);
  }
  void update_set(ll i, ll v){
    update_set(i, v, 0, 0, n-1);
  }

  ll query_sum(ll l, ll r, ll x, ll lx, ll rx){
    if(rx<l || r<lx) return NEUTRAL_ELEMENT;
    if(l<=lx && rx<=r) return values[x];

    ll mid=(lx+rx)/2, x1=x+1, x2=x+2*(mid-lx+1);
    ll v1=query_sum(l, r, x1, lx, mid), v2=query_sum(l, r, x2, mid+1, rx);

    return unite(v1, v2);
  }
  ll query_sum(ll l, ll r){
    return query_sum(l, r, 0, 0, n-1);
  }
};