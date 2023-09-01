#include <bits/stdc++.h>
#define eb emplace_back
using namespace std;

const int MAX_N = 300005;
int a[MAX_N];

struct MSTree{
  vector<int> values[2*MAX_N];
  int n, nx;

  int combine(int v1, int v2){
    return v1+v2;
  }

  void build(int vx, int lx, int rx){
    if(lx==rx){ values[vx].eb(a[lx]); return; }

    int mid=(lx+rx)/2, x1=vx+1, x2=vx+2*(mid-lx+1);
    build(x1, lx, mid); build(x2, mid+1, rx);

    merge(values[x1].begin(), values[x1].end(),
      values[x2].begin(), values[x2].end(),
      back_inserter(values[vx]));
  }
  void build(int n){
    this->n=n; nx=2*n-1;
    build(0, 0, n-1);
  }

  int query(int vx, int lx, int rx, int l, int r, int vL, int vR){
    if(rx<l || r<lx) return 0;
    if(l<=lx && rx<=r) //vL<=values<=vR
      return upper_bound(values[vx].begin(), values[vx].end(), vR) - lower_bound(values[vx].begin(), values[vx].end(), vL);

    int mid=(lx+rx)/2, x1=vx+1, x2=vx+2*(mid-lx+1);
    int v1=query(x1, lx, mid, l, r, vL, vR), v2=query(x2, mid+1, rx, l, r, vL, vR);

    return combine(v1, v2);
  }
  int query(int l, int r, int vL, int vR){
    if(l>r) return 0;
    return query(0, 0, n-1, l, r, vL, vR);
  }
};