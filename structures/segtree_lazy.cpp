#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define MAX_N 100005

pair<ll,bool> operator+(pair<ll,bool> old, pair<ll,bool> updt){
  if(updt.second) return updt;
  old.first+=updt.first;
  return old;
}

//Seg RSQ com lazy update em range (+v e set 0)
struct SegTree{
  ll values[2*MAX_N], n, nx;
  pair<ll,bool> lz[2*MAX_N];
  //   sum set0
  const ll NEUTRAL_ELEMENT=0;

  ll unite(ll v1, ll v2){
    return v1+v2;
  }

  void build(ll *a, ll x, ll lx, ll rx){
    if(lx==rx){values[x]=a[lx]; return;}
    ll mid=(lx+rx)/2, x1=x+1, x2=x+2*(mid-lx+1);

    build(a, x1, lx, mid); build(a, x2, mid+1, rx);
    
    values[x]=unite(values[x1], values[x2]);
  }
  void build(ll *a, ll n){
    this->n=n; nx=2*n-1;
    build(a, 0, 0, n-1);
  }

  void propagate(int x, int lx, int rx){
    int mid=(lx+rx)/2, x1=x+1, x2=x+2*(mid-lx+1);

    if(lx!=rx){
      lz[x1]=lz[x1]+lz[x];
      lz[x2]=lz[x2]+lz[x];
    }

    if(lz[x].second) values[x]=lz[x].first*(rx-lx+1);
    else values[x]+=lz[x].first*(rx-lx+1);

    lz[x]={0,0};
  }

  void update(pair<ll,bool> v, int l, int r, int x, int lx, int rx){
    propagate(x, lx, rx);
    if(rx<l || r<lx) return; //out of bounds
    if(l<=lx && rx<=r){lz[x]=lz[x]+v; propagate(x, lx, rx); return;}

    int mid=(lx+rx)/2, x1=x+1, x2=x+2*(mid-lx+1);

    update(v, l, r, x1, lx, mid); update(v, l, r, x2, mid+1, rx);

    values[x]=unite(values[x1], values[x2]);
  }
  void update(pair<ll,bool> v, int l, int r){
    update(v, l, r, 0, 0, n-1);
  }

  ll query_sum(int l, int r, int x, int lx, int rx){
    propagate(x, lx, rx);
    if(rx<l || r<lx) return NEUTRAL_ELEMENT; //out of bounds
    if(l<=lx && rx<=r) return values[x];

    int mid=(lx+rx)/2, x1=x+1, x2=x+2*(mid-lx+1);
    ll v1=query_sum(l, r, x1, lx, mid), v2=query_sum(l, r, x2, mid+1, rx);

    return unite(v1, v2);
  }
  ll query_sum(int l, int r){
    return query_sum(l, r, 0, 0, n-1);
  }
};