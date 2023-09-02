#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e5+5;

int a[MAX_N]; //array

int p[MAX_N], L[MAX_N], L_id[MAX_N];
//p[i] = index of predecessor of a[i] in LIS
//L[i] = value of last element in LIS of length i+1
//L_id[i] = index of last element in LIS of length i+1

//i = L_id[k-1] will print the LIS of size k
void print_LIS(int i) { 
  if (p[i] == -1){ cout<<a[i]; return; }
  print_LIS(p[i]);
  cout<<" "<<a[i];
}

int lis(int n){
  int k = 0;
  fill(L, L+n, 0); fill(L_id, L_id+n, 0);
  fill(p, p+n, -1);

  for (int i = 0; i < n; ++i) {
    //change for upper if non-decreasing
    int pos = lower_bound(L, L+k, a[i]) - L;
    L[pos] = a[i]; L_id[pos] = i;
    p[i] = pos ? L_id[pos-1] : -1;
    if(pos == k) k++;
  }
  return k; //size of LIS
}