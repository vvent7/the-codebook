#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll kadane(ll arr[], int n){
  ll sum=0, ans=0;
  for(int i=0;i<n;i++){
    sum += arr[i];
    ans = max(ans, sum);
    if(sum < 0) sum=0;
  }
  return ans;
}