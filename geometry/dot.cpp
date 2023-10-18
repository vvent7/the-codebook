#include <bits/stdc++.h>
#include "point2d.cpp"
#include "point3d.cpp"
typedef long long ftype; //example

ftype dot(point2d a, point2d b) {
  return a.x * b.x + a.y * b.y;
}
ftype dot(point3d a, point3d b) {
  return a.x * b.x + a.y * b.y + a.z * b.z;
}

//2D, 3D (just change the structure)
ftype sqrLen(point2d a) { 
  return dot(a, a); //abs^2
}
double abs(point2d a) { //length
  return sqrt(sqrLen(a));
}
double proj(point2d a, point2d b) {
  return dot(a, b) / abs(b); //a on b
}
double angle(point2d a, point2d b) {
  return acos(dot(a, b) / abs(a) / abs(b));
}