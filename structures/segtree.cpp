typedef long long ll;

const int MAX_N = 100005;

ll a[MAX_N];

//RSQ e update_set - (podem ser alterados)
struct SegTree{
  ll values[2*MAX_N+5];
  ll n, nx, NEUTRAL_ELEMENT=0;

  ll single(ll v){
    return v;
  }
  ll combine(ll v1, ll v2){
    return v1+v2;
  }

  void build(ll vx, ll lx, ll rx){
    if(lx==rx){values[vx]=single(a[lx]); return;}
    ll mid=(lx+rx)/2, x1=vx+1, x2=vx+2*(mid-lx+1);

    build(x1, lx, mid); build(x2, mid+1, rx);
    
    values[vx]=combine(values[x1], values[x2]);
  }
  void build(ll n){
    this->n=n; nx=2*n-1;
    build(0, 0, n-1);
  }

  void update_set(ll vx, ll lx, ll rx, ll i, ll new_val){
    if(lx==rx){values[vx]=single(new_val); return;}
    ll mid=(lx+rx)/2, x1=vx+1, x2=vx+2*(mid-lx+1);

    if(i<=mid) update_set(x1, lx, mid, i, new_val);
    else update_set(x2, mid+1, rx, i, new_val);

    values[vx]=combine(values[x1], values[x2]);
  }
  void update_set(ll i, ll new_val){
    update_set(0, 0, n-1, i, new_val);
  }

  ll query_sum(ll vx, ll lx, ll rx, ll l, ll r){
    if(rx<l || r<lx) return NEUTRAL_ELEMENT;
    if(l<=lx && rx<=r) return values[vx];

    ll mid=(lx+rx)/2, x1=vx+1, x2=vx+2*(mid-lx+1);
    ll v1=query_sum(x1, lx, mid, l, r), v2=query_sum(x2, mid+1, rx, l, r);

    return combine(v1, v2);
  }
  ll query_sum(ll l, ll r){
    return query_sum(0, 0, n-1, l, r);
  }
};