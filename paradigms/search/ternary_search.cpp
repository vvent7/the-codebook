#include <bits/stdc++.h>
using namespace std;

const double EPS = 1e-9;

//example function
double f(double x) {
  return x*x - 2*x + 1;
}

//searching minimum of a unimodal function f(x)
double ternary_search_continuous(double l, double r) {
  while (r - l > EPS) {
    double delta = (r-l)/3.0;
      double m1 = l + delta, m2 = r - delta;
      (f(m1) > f(m2) ? l=m1 : r=m2);    // minimum
      // (f(m1) < f(m2) ? l=m1 : r=m2); // maximum
  }
  return f(l);
}

double ternary_search_discrete(int l, int r){
  while((r - l)>=3){
    int delta = (r-l)/3;
    int m1 = l + delta, m2 = r - delta;
    (f(m1) > f(m2) ? l=m1 : r=m2);    // minimum
    // (f(m1) < f(m2) ? l=m1 : r=m2); // maximum
  }

  double ans=f(l);
  for(int i=l+1;i<=r;i++){
    ans=min(ans, f(i));    // minimum
    // ans=max(ans, f(i)); // maximum
  }

  return ans;
}