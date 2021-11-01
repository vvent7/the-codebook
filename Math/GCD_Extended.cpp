#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);
using namespace std;

//funciona para m não primo
int modInverse(int a, int m){
    int m0 = m;
    int y = 0, x = 1;
    if (m == 1)
      return 0;
    while (a > 1){
        int q = a / m;
        int t = m;
        m = a % m, a = t;
        t = y;
        y = x - q * y;
        x = t;
    }
    if (x < 0)
       x += m0;
    return x;
} 
