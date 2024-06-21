#include <bits/stdc++.h>
#define _io ios_base::sync_with_stdio(false); cin.tie(0);
#define endl '\n'
#define eb emplace_back
#define pb push_back
#define fi first
#define sec second
#define PI (acos(-1))
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pi;
typedef pair<pi,int> pii;
typedef pair<ll,ll> pll;
typedef vector<pll> vpll;
typedef tuple<ll, ll, ll> tll;

const ll MAX_N = 1e5+5, MAX_K=MAX_N, INF=MAX_N*2;
ll a[MAX_N], b[MAX_N], dp[MAX_N];

//RSQ e update_set - (podem ser alterados)
struct SegTree{
  ll values[2*MAX_N+5];
  ll n, nx, NEUTRAL_ELEMENT=INF;

  ll single(ll v){ return v; }
  ll combine(ll v1, ll v2){ return min(v1,v2); }

  // void build(ll vx, ll lx, ll rx){
  //   if(lx==rx){values[vx]=single(dp[lx]); return;}
  //   ll mid=(lx+rx)/2, x1=vx+1, x2=vx+2*(mid-lx+1);
  //   build(x1, lx, mid); build(x2, mid+1, rx);
  //   values[vx]=combine(values[x1], values[x2]);
  // }
  void build(ll nn){
    this->n=nn; nx=2*nn-1;
    // build(0, 0, n-1);
    fill(values, values+nx+1, NEUTRAL_ELEMENT);
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

  ll query(ll vx, ll lx, ll rx, ll l, ll r){
    if(rx<l || r<lx) return NEUTRAL_ELEMENT;
    if(l<=lx && rx<=r) return values[vx];
    ll mid=(lx+rx)/2, x1=vx+1, x2=vx+2*(mid-lx+1);
    ll v1=query(x1, lx, mid, l, r), v2=query(x2, mid+1, rx, l, r);
    return combine(v1, v2);
  }
  ll query(ll l, ll r){
    if(l>r) return NEUTRAL_ELEMENT;
    return query(0, 0, n-1, l, r);
  }
} seg;

signed main(){_io
  ll n, k; cin>>n>>k;

  ++n; //first == k
  a[0]=0, b[0]=k;
  for(ll i=1;i<n;++i) cin>>a[i];
  for(ll i=1;i<n;++i) cin>>b[i];

  fill(dp, dp+n, INF);
  seg.build(n);

  seg.update_set(n-1, (dp[n-1]=0));
  for(ll i=n-2;i>=0;--i){
    ll curA = a[i], curB = b[i];
    ll maxNextA = curA+curB;
    ll j = upper_bound(a+i, a+n, maxNextA) - a - 1;

    // cout<<i<<": "<<j<<endl;
    seg.update_set(i, dp[i]=1+seg.query(i+1, j));
  }

  // cout<<dp[n-1]<<endl;
  // for(int i=0;i<n;++i) cout<<dp[i]<<" "<<endl;

  if(dp[0] <= n) cout<<(dp[0]-1)<<endl;
  else cout<<(-1)<<endl;
}