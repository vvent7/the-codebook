#include <bits/stdc++.h>
using namespace std;

//dOdd[i] = (x+1)/2, onde x é o tamanho do palíndromo centralizado em i
vector<int> manacher_odd(string s) {
  int n = s.size();
  s = "$" + s + "^"; // sentinelas
  vector<int> p(n + 2);
  int l = 1, r = 1;
  for(int i = 1; i <= n; i++) {
    p[i] = max(0, min(r - i, p[l + (r - i)]));
    while(s[i - p[i]] == s[i + p[i]]) {
      p[i]++;
    }
    if(i + p[i] > r) {
      l = i - p[i], r = i + p[i];
    }
  }
  return vector<int>(begin(p) + 1, end(p) - 1);
}

//apenas para pares (# entre letras e nas pontas para ficar impar)
vector<int> manacher(string s) {
  string t;
  for(auto c: s) {
    t += string("#") + c;
  }
  auto res = manacher_odd(t + "#");
  return vector<int>(begin(res) + 1, end(res) - 1);
}