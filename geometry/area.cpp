#include<bits/stdc++.h>
#include "point2d.cpp"
#include "cross.cpp"
using namespace std;

double area_trapez(const vector<point2d> &fig){
  double res = 0;
  for(int i = 0; i < fig.size(); i++){
    point2d p = i ? fig[i - 1] : fig.back();
    point2d q = fig[i];
    res += (p.x - q.x) * (p.y + q.y);
    //neg: esq<-dir, pos: esq->dir
  }
  return abs(res) / 2;
}

double area_triangle(const point2d o, const vector<point2d> &fig){
  double res = 0;
  for(int i = 0; i < fig.size() - 2; i++){
    point2d p = i ? fig[i - 1] : fig.back();
    point2d q = fig[i];
    res += signed_area_parallelogram(o, p, q);
    //neg: clockwise, pos: counterclockwise
  }
  return abs(res) / 2;
}