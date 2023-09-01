#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 100005;

string T, P;
int n, m, b[MAX_N];

void kmpPreprocess(){
  int i=0, j=-1; b[0] = -1;

  while(i<m){
    while((j>=0) && (P[i] != P[j])) j = b[j];
    i++;j++;
    b[i] = j;
  }
}

void kmpSearch(){
  int i = 0, j =0;
  while(i < n){
    while((j>=0) && (T[i] != P[j])) j = b[j];
    i++; j++;

    if(j == m){
      cout << "P is found at index " << i-j << " in T\n";
      j = b[j];
    }
  }
}