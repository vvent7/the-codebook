#include <bits/stdc++.h>
#define eb emplace_back
using namespace std;

#define MAX_N 300005

struct MSTree{
  vector<int> values[2*MAX_N];
  int n, nx;

  int unite(int v1, int v2){
    return v1+v2;
  }

  void build(int *a, int x, int lx, int rx){
    if(lx==rx){ values[x].eb(a[lx]); return; }

    int mid=(lx+rx)/2, x1=x+1, x2=x+2*(mid-lx+1);
    build(a, x1, lx, mid); build(a, x2, mid+1, rx);

    merge(values[x1].begin(), values[x1].end(),
      values[x2].begin(), values[x2].end(),
      back_inserter(values[x]));
  }
  void build(int *a, int n){
    this->n=n; nx=2*n-1;
    build(a, 0, 0, n-1);
  }

  int query(int vL, int vR, int l, int r, int x, int lx, int rx){
    if(rx<l || r<lx) return 0;
    if(l<=lx && rx<=r) //values>=x (lower_bound)
      return upper_bound(values[x].begin(), values[x].end(), vR)-lower_bound(values[x].begin(), values[x].end(), vL);

    int mid=(lx+rx)/2, x1=x+1, x2=x+2*(mid-lx+1);
    int v1=query(vL, vR, l, r, x1, lx, mid), v2=query(vL, vR, l, r, x2, mid+1, rx);

    return unite(v1, v2);
  }
  int query(int vL, int vR, int l, int r){
    if(l>r) return 0;
    return query(vL, vR, l, r, 0, 0, n-1);
  }
};