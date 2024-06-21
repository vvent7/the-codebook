#include <bits/stdc++.h>
using namespace std;

void merge_sort(int arr[], int aux[], size_t l, size_t r){
  if(l>=r) return;
  size_t mid=(l+r)/2;
  
  merge_sort(aux,arr,l,mid);
  merge_sort(aux,arr,mid+1,r);
  
  merge(aux+l, aux+mid+1, aux+mid+1, aux+r+1, arr+l);
}

void merge_sort(int arr[], size_t n){
  int aux[n];
  copy(arr, arr+n, aux);
  merge_sort(arr, aux, 0, n-1);
}