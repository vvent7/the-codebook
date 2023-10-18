#include "point2d.cpp"
#include "point3d.cpp"
#include "cross.cpp"

//======LINE PARAMETRIC======
const double EPS=1e-9;

struct line_param{ //2d only
  double a, b, c;
  line_param(double a, double b, double c): a(a), b(b), c(c) {}
  line_param(point2d p, point2d q){
    a = p.y - q.y;
    b = q.x - p.x;
    c = - a*p.x - b*p.y;
  }
  //ax + by + c = 0
};
double det(double a, double b, double c, double d) {
  return a*d - b*c;
}
bool intersect(line_param m, line_param n, point2d &res) {
  double zn = det(m.a, m.b, n.a, n.b);
  if(abs(zn) < EPS) return false;
  res.x = -det(m.c, m.b, n.c, n.b) / zn;
  res.y = -det(m.a, m.c, n.a, n.c) / zn;
  return true;
}
bool parallel(line_param m, line_param n) {
  return abs(det(m.a, m.b, n.a, n.b)) < EPS;
}
bool equivalent(line_param m, line_param n) {
  return abs(det(m.a, m.b, n.a, n.b)) < EPS
      && abs(det(m.a, m.c, n.a, n.c)) < EPS
      && abs(det(m.b, m.c, n.b, n.c)) < EPS;
}


//======LINE VECTOR======
struct line_vector{ //can be 2d or 3d
  point3d a, d; //point, direction
  line_vector(point3d a, point3d d): a(a), d(d) {}
  //r = a + t * d
};

//r1 = a1 + t1 * d1, r2 = a2 + t2 * d2 
point2d intersectLines(point2d a1, point2d d1, point2d a2, point2d d2) {
  return a1 + cross(a2 - a1, d2) / cross(d1, d2) * d1;
}


//======PLANE======

struct plane{ //can be 2d or 3d
  point3d a, n; //point, normal
  plane(point3d a, point3d n): a(a), n(n) {}
  //dot(n, r - a) = 0
};

//p1: dot(n1, r - a1) = 0, p2: dot(n2, r - a2) = 0, p3: dot(n3, r - a3) = 0
point3d intersectPlanes(point3d a1, point3d n1, point3d a2, point3d n2, point3d a3, point3d n3) {
    point3d x(n1.x, n2.x, n3.x);
    point3d y(n1.y, n2.y, n3.y);
    point3d z(n1.z, n2.z, n3.z); 
    point3d d(dot(a1, n1), dot(a2, n2), dot(a3, n3));
    return point3d(triple(d, y, z),
                   triple(x, d, z),
                   triple(x, y, d)) / triple(n1, n2, n3);
}