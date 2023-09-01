#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAX_N = 100005;
ll a[MAX_N];

//Seg RSQ e range update (lazy)
struct SegTree{
  ll values[2*MAX_N], lz[2*MAX_N], n, nx;
  const ll NEUTRAL_ELEMENT=0;

  ll combine(ll v1, ll v2){
    return v1+v2;
  }

  void build(ll vx, ll lx, ll rx){
    if(lx==rx){values[vx]=a[lx]; return;}
    ll mid=(lx+rx)/2, x1=vx+1, x2=vx+2*(mid-lx+1);

    build(x1, lx, mid); build(x2, mid+1, rx);
    
    values[vx]=combine(values[x1], values[x2]);
  }
  void build(ll n){
    this->n=n; nx=2*n-1;
    build(0, 0, n-1);
  }

  void propagate(int vx, int lx, int rx){
    int mid=(lx+rx)/2, x1=vx+1, x2=vx+2*(mid-lx+1);

    if(lx!=rx){ // not a leaf (propagate lazy under)
      lz[x1]=lz[x1]+lz[vx];
      lz[x2]=lz[x2]+lz[vx];
    }

    values[vx]+=lz[vx]; //update with lazy
    lz[vx]=0; //reset lazy
  }

  void update_add(int vx, int lx, int rx, int l, int r, ll new_val){
    propagate(vx, lx, rx);
    if(rx<l || r<lx) return; //out of bounds
    if(l<=lx && rx<=r){lz[vx]+=new_val; propagate(vx, lx, rx); return;}

    int mid=(lx+rx)/2, x1=vx+1, x2=vx+2*(mid-lx+1);

    update_add(x1, lx, mid, l, r, new_val); update_add(x2, mid+1, rx, l, r, new_val);

    values[vx]=combine(values[x1], values[x2]);
  }
  void update_add(int l, int r, ll new_val){
    update_add(0, 0, n-1, l, r, new_val);
  }

  ll query_sum(int vx, int lx, int rx, int l, int r){
    propagate(vx, lx, rx);
    if(rx<l || r<lx) return NEUTRAL_ELEMENT; //out of bounds
    if(l<=lx && rx<=r) return values[vx];

    int mid=(lx+rx)/2, x1=vx+1, x2=vx+2*(mid-lx+1);
    ll v1=query_sum(x1, lx, mid, l, r), v2=query_sum(x2, mid+1, rx, l, r);

    return combine(v1, v2);
  }
  ll query_sum(int l, int r){
    return query_sum(0, 0, n-1, l, r);
  }
};