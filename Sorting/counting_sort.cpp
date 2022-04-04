#include <bits/stdc++.h>
using namespace std;
#define MAXX 100 //max number on array [0,MAXX]

void counting_sort(int arr[], int n){
  int count[MAXX+1]={0}, output[n];

  for(int i=0;i<n;i++) count[arr[i]]++;
  for(int i=1;i<=MAXX;i++) count[i]+=count[i-1];
  for(int i=n-1;i>=0;i--) output[--count[arr[i]]]=arr[i];
  copy(output, output+n, arr);
}