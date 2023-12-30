#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define LSB(x) ((x)&-(x))
#define MSBI(x) (sizeof(int) * __CHAR_BIT__ - __builtin_clz(n) - 1)

struct FenwickTree{
  int n;
  vector<ll> bit; //or ll a[N]; (faster)

  FenwickTree(){}
  FenwickTree(int n, ll v=0)
    : n(0), bit(n, v){}

  ll& operator [](int i){
    return bit[i];
  }

  void build(){ //build in-place
    for(int i=1, next;i<n;i++){
      next=i+LSB(i);
      if(next<=n) bit[next]+=bit[i];
    }
  }
  void unbuild(){ //unbuild in-place
    for(int i=n, next; i>0; i--){
      next=i+LSB(i);
      if(next<=n) bit[next]-=bit[i];
    }
  }

  void add(int i, ll v){
    for(;i<=n;i+=LSB(i)) bit[i]+=v;
  }
  void set(int i, ll v){ //[i]
    add(i, v-sum_single(i));
  }

  ll sum_single(int i){  //[i] faster
    ll res=bit[i];
    if(i<=1) return res;

    int z=i-LSB(i); i--;
    for(; i>z; i-=LSB(i)) res-=bit[i];
    return res;
  }
  ll sum_pre(int i){ //[1,i]
    ll res=0;
    for(; i>0; i-=LSB(i)) res+=bit[i];
    return res;
  }
  ll sum_range(int l, int r){ //[l,r]
    return sum_pre(r)-sum_pre(l-1);
  }

  int lower_bound(ll v){
    int pos = 0, LOGN = MSBI(n);
    ll sum = 0;

    for(int i=LOGN; i>=0; i--){
      if(pos + (1 << i) < n && sum + bit[pos + (1 << i)] < v){
        sum += bit[pos + (1 << i)];
        pos += (1 << i);
      }
    }

    return pos + 1; // 'pos' is largest value less than 'v'
  }
  int upper_bound(ll v){
    return lower_bound(v+1);
  }
};