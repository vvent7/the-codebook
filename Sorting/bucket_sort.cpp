#include <bits/stdc++.h>
#define pb push_back
using namespace std;

#define N_BUCKETS 10
#define INTERVAL 10
//total range: [0, N_BUCKET*INTERVAL)

void bucket_sort(int arr[], int n){
  vector<int> buckets[N_BUCKETS];

  for(int i=0;i<n;i++) //Distribuindo nos buckets
    buckets[arr[i]/INTERVAL].pb(arr[i]);

  //Ordenando buckets (escolher melhor método)
  for(int i=0;i<N_BUCKETS;i++)
    sort(buckets[i].begin(), buckets[i].end());

  //Concatenando buckets ordenados no array original
  for(int i=0, j=0;i<n && j<N_BUCKETS;i+=buckets[j].size(), j++)
    copy(buckets[j].begin(), buckets[j].end(), arr+i);
}