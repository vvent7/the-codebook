#include <bits/stdc++.h>
#include "point2d.cpp"
#include "point3d.cpp"

//R = |cos(O) -sin(O)| |x|
//    |sin(O)  cos(O)| |y|
point2d rotate(point2d p, double theta) {
  return point2d(
    p.x * cos(theta) - p.y * sin(theta),
    p.x * sin(theta) + p.y * cos(theta));
}

//R = |1   0       0   | |x|
//    |0 cos(O) -sin(O)| |y|
//    |0 sin(O)  cos(O)| |z|
point3d rotateX(point3d p, double theta) {
  return point3d(p.x,
    p.y * cos(theta) - p.z * sin(theta),
    p.y * sin(theta) + p.z * cos(theta));
}

//R = | cos(O) 0 sin(O)| |x|
//    |   0    1   0   | |y|
//    |-sin(O) 0 cos(O)| |z|
point3d rotateY(point3d p, double theta) {
  return point3d(
    p.x * cos(theta) + p.z * sin(theta),
    p.y,
    -p.x * sin(theta) + p.z * cos(theta));
}

//R = |cos(O) -sin(O) 0| |x|
//    |sin(O)  cos(O) 0| |y|
//    |  0       0    1| |z|
point3d rotateZ(point3d p, double theta) {
  return point3d(
    p.x * cos(theta) - p.y * sin(theta),
    p.x * sin(theta) + p.y * cos(theta),
    p.z);
}
