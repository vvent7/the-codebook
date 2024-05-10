#include <bits/stdc++.h>
using namespace std;

vector<int> pi_function(string &s){
  int n=s.size();
  vector<int> pi(n);
  for(int i=1, j=0;i<n;++i){
    while(j>0 && s[i]!=s[j]) j=pi[j-1];
    if(s[i]==s[j]) ++j;
    pi[i] = j;
  }
  return pi;
}

void kmp_search(string &t, string &p, vector<int> &pi){
  int n=t.size(), m=p.size();
  for(int i=0, j=0;i<n;++i){
    while(j>0 && t[i]!=p[j]) j = pi[j-1];
    if(t[i]==p[j]) ++j;
    if(j==m){
      cout<<"P is found at "<<i-j+1<<" in T\n";
      j = pi[j-1];
    }
  }
}