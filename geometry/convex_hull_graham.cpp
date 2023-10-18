#include <bits/stdc++.h>
#include "point2d.cpp"
using namespace std;

int orientation(point2d a, point2d b, point2d c) {
  double v = a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y);
  if (v < 0) return -1; // clockwise
  if (v > 0) return +1; // counter-clockwise
  return 0;
}

bool cw(point2d a, point2d b, point2d c, bool include_collinear) {
  int o = orientation(a, b, c);
  return o < 0 || (include_collinear && o == 0);
}
bool collinear(point2d a, point2d b, point2d c) { return orientation(a, b, c) == 0; }

void convex_hull(vector<point2d> &a, bool include_collinear = false) {
  point2d p0 = *min_element(a.begin(), a.end(), [](point2d a, point2d b) {
    return make_pair(a.y, a.x) < make_pair(b.y, b.x);
  });
  sort(a.begin(), a.end(), [&p0](const point2d& a, const point2d& b) {
    int o = orientation(p0, a, b);
    if (o == 0)
      return (p0.x-a.x)*(p0.x-a.x) + (p0.y-a.y)*(p0.y-a.y)
            < (p0.x-b.x)*(p0.x-b.x) + (p0.y-b.y)*(p0.y-b.y);
    return o < 0;
  });
  if (include_collinear) {
    int i = (int)a.size()-1;
    while (i >= 0 && collinear(p0, a[i], a.back())) i--;
    reverse(a.begin()+i+1, a.end());
  }

  vector<point2d> st;
  for (int i = 0; i < (int)a.size(); i++) {
    while (st.size() > 1 && !cw(st[st.size()-2], st.back(), a[i], include_collinear))
      st.pop_back();
    st.push_back(a[i]);
  }

  a = st; //overwriting ans
}