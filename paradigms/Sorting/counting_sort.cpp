#include <bits/stdc++.h>
using namespace std;
#define MAX_NUMBER 100 //max number on array [0,MAX_NUMBER]

void counting_sort(int arr[], int n){
  int count[MAX_NUMBER+1]={0}, output[n];

  for(int i=0;i<n;i++) count[arr[i]]++;
  for(int i=1;i<=MAX_NUMBER;i++) count[i]+=count[i-1];
  for(int i=n-1;i>=0;i--) output[--count[arr[i]]]=arr[i];
  copy(output, output+n, arr);
}