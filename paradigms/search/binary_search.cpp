int bin_s_find(int arr[], int n, int x){
  int l=0, r=n-1;
  while(l<=r){
    int mid = l + (r-l)/2;
    if(arr[mid]==x) return mid;
    else if(arr[mid]<x) l=mid+1;
    else r=mid-1;
  }
  return -1;
}

int bin_s_bound(int arr[], int n, int x){
  int l=0, r=n-1;
  while(l<=r){
    int mid = l + (r-l)/2;
    if(arr[mid]>=x) r=mid-1;    // lower bound
    // if(arr[mid]>x) r=mid-1;  // upper bound
    else l=mid+1;
  }
  return l;
}