#include "point2d.cpp"
#include "dot.cpp"
#include "cross.cpp"
using namespace std;

bool lexComp(const point2d &l, const point2d &r) {
  return l.x < r.x || (l.x == r.x && l.y < r.y);
}
int sgn(long long val) { return val > 0 ? 1 : (val == 0 ? 0 : -1); }

vector<point2d> seq;
point2d translation;
int n;

bool pointInTriangle(point2d a, point2d b, point2d c, point2d point) {
  long long s1 = abs(a.cross(b, c));
  long long s2 = abs(point.cross(a, b)) + abs(point.cross(b, c)) + abs(point.cross(c, a));
  return s1 == s2;
}

void prepare(vector<point2d> &points) {
  n = points.size();
  int pos = 0;
  for (int i = 1; i < n; i++) {
    if (lexComp(points[i], points[pos]))
      pos = i;
  }
  rotate(points.begin(), points.begin() + pos, points.end());

  n--;
  seq.resize(n);
  for(int i = 0; i < n; i++)
    seq[i] = points[i + 1] - points[0];
  translation = points[0];
}

bool pointInConvexPolygon(point2d point) {
  point = point - translation;
  if(seq[0].cross(point) != 0 &&
    sgn(seq[0].cross(point)) != sgn(seq[0].cross(seq[n - 1])))
      return false;
  if(seq[n - 1].cross(point) != 0 &&
    sgn(seq[n - 1].cross(point)) != sgn(seq[n - 1].cross(seq[0])))
      return false;

  if(seq[0].cross(point) == 0)
    return seq[0].sqrLen() >= point.sqrLen();

  int l = 0, r = n - 1;
  while (r - l > 1) {
    int mid = (l + r) / 2;
    int pos = mid;
    if (seq[pos].cross(point) >= 0)
      l = mid;
    else
      r = mid;
  }
  int pos = l;
  return pointInTriangle(seq[pos], seq[pos + 1], point2d(0, 0), point);
}