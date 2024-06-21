#include <bits/stdc++.h>
using namespace std;
#define MAX_NUMBER 100 //max number in array [0,MAX_NUMBER]

void counting_sort(int arr[], int n){
  int cnt[MAX_NUMBER+1]={0}, output[n];

  for(int i=0;i<n;i++) cnt[arr[i]]++;
  for(int i=1;i<=MAX_NUMBER;i++) cnt[i]+=cnt[i-1];
  for(int i=n-1;i>=0;i--) output[--cnt[arr[i]]]=arr[i];
  copy(output, output+n, arr);
}