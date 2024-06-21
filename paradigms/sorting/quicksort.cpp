#include <bits/stdc++.h>
using namespace std;

int partition(int arr[], int l, int r , int pivot){
  while(l<=r){
    while(arr[l]<pivot) l++;
    while(arr[r]>pivot) r--;
    if(l<=r) swap(arr[l++],arr[r--]);
  }
  return l;
}
void quick_sort(int arr[], int l , int r){
    if(l>=r) return;
    int pivot = arr[l+(r-l)/2];
    int partition_index = partition(arr,l,r,pivot);
    quick_sort(arr,0,partition_index-1);
    quick_sort(arr,partition_index,r);
}