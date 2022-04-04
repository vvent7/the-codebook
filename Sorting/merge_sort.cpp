#include <bits/stdc++.h>
using namespace std;
#define MAXN 500005

int aux[MAXN];

void merge_sort(int arr[], size_t l, size_t r){
  if(l>=r) return;
  size_t mid=(l+r)/2;
  
  merge_sort(arr,l,mid);
  merge_sort(arr,mid+1,r);
  
  merge(arr+l, arr+mid+1, arr+mid+1, arr+r+1, aux);
  copy(aux, aux+(r-l)+1, arr+l);
}