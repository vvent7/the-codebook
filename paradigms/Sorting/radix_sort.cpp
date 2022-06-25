#include <bits/stdc++.h>
using namespace std;

#define BASE 10
#define RAD_DIG(x,place) (((x)/place)%BASE)

void counting_radix_sort(int arr[], int n, int place){
  int count[BASE]={0}, output[n];

  for(int i=0;i<n;i++) count[RAD_DIG(arr[i], place)]++;
  for(int i=1;i<BASE;i++) count[i]+=count[i-1];
  for(int i=n-1;i>=0;i--) output[--count[RAD_DIG(arr[i], place)]]=arr[i];
  copy(output, output+n, arr);
}

void radix_sort(int arr[], int n){
  if(n<=0) return;
  int maxX=arr[0];
  for(int i=1;i<n;i++) maxX=max(maxX, arr[i]);

  for(int i=1;i<=maxX;i*=BASE)
    counting_radix_sort(arr, n, i);
}