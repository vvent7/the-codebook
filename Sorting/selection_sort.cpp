#include <bits/stdc++.h>
using namespace std;

void selection_sort(int arr[], int n){
  for(int i=n-1;i>0;i--){
    int greaterInd=i;
    for(int j=0;j<i;j++)
      if(arr[greaterInd]<arr[j]) greaterInd=j;
    swap(arr[greaterInd], arr[i]);
  }
}