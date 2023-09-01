#include <bits/stdc++.h>
using namespace std;

void bubble_sort(int arr[], int n){
  bool swapped=true;
  while(swapped){
    swapped=false;
    for(int i=1;i<n;i++){
      if(arr[i-1]>arr[i]){
        swap(arr[i-1], arr[i]);
        swapped=true;
      }
    }
  }
}