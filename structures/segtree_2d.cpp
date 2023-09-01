// TO BE TESTED
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX_N = 2500, MAX_M = 2500;
ll a[MAX_N][MAX_M];

//RSQ e update_set - (podem ser alterados)
struct SegTree2D{
  ll values[2*MAX_N+5][2*MAX_M+5];
  int n, m;
  ll NEUTRAL_ELEMENT=0;

  ll single(ll v){
    return v;
  }
  ll combine(ll v1, ll v2){
    return v1+v2;
  }

  void build_y(int vx, int lx, int rx, int vy, int ly, int ry){
    if(ly==ry){
      if(lx==rx) values[vx][vy] = single(a[lx][ly]);
      else{
        int midX=(lx+rx)/2, vx1=vx+1, vx2=vx+2*(midX-lx+1);
        values[vx][vy] = combine(values[vx1][vy], values[vx2][vy]);
      }
    }
    else{
      int midY=(ly+ry)/2, vy1=vy+1, vy2=vy+2*(midY-ly+1);
      build_y(vx, lx, rx, vy1, ly, midY);
      build_y(vx, lx, rx, vy2, midY+1, ry);
      values[vx][vy] = combine(values[vx][vy1], values[vx][vy2]);
    }
  }
  void build_x(int vx, int lx, int rx){
    if(lx!=rx){
      int midX=(lx+rx)/2, vx1=vx+1, vx2=vx+2*(midX-lx+1);
      build_x(vx1, lx, midX);
      build_x(vx2, midX+1, rx);
    }
    build_y(vx, lx, rx, 0, 0, m-1);
  }
  void build(int n, int m){
    this->n=n; this->m = m;
    build_x(0, 0, n-1);
  }

  void update_set_y(int vx, int lx, int rx, int vy, int ly, int ry, int x, int y, ll new_val) {
    if(ly == ry){
      if(lx == rx) values[vx][vy] = single(new_val);
      else{
        int midX=(lx+rx)/2, vx1=vx+1, vx2=vx+2*(midX-lx+1);
        values[vx][vy] = combine(values[vx1][vy], values[vx2][vy]);
      }
    }
    else{
      int midY=(ly+ry)/2, vy1=vy+1, vy2=vy+2*(midY-ly+1);
      if(y <= midY)
        update_set_y(vx, lx, rx, vy1, ly, midY, x, y, new_val);
      else
        update_set_y(vx, lx, rx, vy2, midY+1, ry, x, y, new_val);
      values[vx][vy] = combine(values[vx][vy1], values[vx][vy2]);
    }
  }
  void update_set_x(int vx, int lx, int rx, int x, int y, ll new_val) {
    if(lx != rx){
      int midX=(lx+rx)/2, vx1=vx+1, vx2=vx+2*(midX-lx+1);
      if(x <= midX)
        update_set_x(vx1, lx, midX, x, y, new_val);
      else
        update_set_x(vx2, midX+1, rx, x, y, new_val);
    }
    update_set_y(vx, lx, rx, 0, 0, m-1, x, y, new_val);
  }
  void update_set(int x, int y, ll new_val){
    // i (line), j (column)
    update_set_x(0, 0, n-1, x, y, new_val);
  }

  ll query_sum_y(int vx, int vy, int ly, int ry, int qly, int qry) {
    if(qly > qry) return NEUTRAL_ELEMENT;
    if(qly == ly && ry == qry) return values[vx][vy];
    int midY=(ly+ry)/2, vy1=vy+1, vy2=vy+2*(midY-ly+1);
    ll v1 = query_sum_y(vx, vy1, ly, midY, qly, min(qry, midY)),
      v2 = query_sum_y(vx, vy2, midY+1, ry, max(qly, midY+1), qry);
    return combine(v1, v2);
  }
  ll query_sum_x(int vx, int lx, int rx, int qlx, int qrx, int qly, int qry) {
    if(qlx > qrx) return NEUTRAL_ELEMENT;
    if(qlx == lx && rx == qrx)
      return query_sum_y(vx, 0, 0, m-1, qly, qry);
    int midX=(lx+rx)/2, vx1=vx+1, vx2=vx+2*(midX-lx+1);
    ll v1 = query_sum_x(vx1, lx, midX, qlx, min(qrx, midX), qly, qry),
      v2 = query_sum_x(vx2, midX+1, rx, max(qlx, midX+1), qrx, qly, qry);
    return combine(v1, v2);
  }
  ll query_sum(int qlx, int qrx, int qly, int qry){
    //qlx<=qrx (lines), qly<=qry (columns)
    return query_sum_x(0, 0, n-1, qlx, qrx, qly, qry);
  }
};