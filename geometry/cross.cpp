#include "point2d.cpp"
#include "point3d.cpp"
#include "dot.cpp"

typedef long long ftype; //example

point3d cross(point3d a, point3d b) {
  return point3d(a.y * b.z - a.z * b.y,
                a.z * b.x - a.x * b.z,
                a.x * b.y - a.y * b.x);
}
ftype triple(point3d a, point3d b, point3d c) {
  return dot(a, cross(b, c));
}
ftype cross(point2d a, point2d b) {
  return a.x * b.y - a.y * b.x;
}

//AREA and ORIENTATION
int signed_area_parallelogram(point2d p1, point2d p2, point2d p3) {
  return cross(p2 - p1, p3 - p2);
  //p1->p2->p3 (neg: clockwise, pos: counterclockwise)
}
double triangle_area(point2d p1, point2d p2, point2d p3) {
  return abs(signed_area_parallelogram(p1, p2, p3)) / 2.0;
}
bool clockwise(point2d p1, point2d p2, point2d p3) {
  return signed_area_parallelogram(p1, p2, p3) < 0; //left
}
bool counter_clockwise(point2d p1, point2d p2, point2d p3){
  return signed_area_parallelogram(p1, p2, p3) > 0; //right
}