void insertion_sort(int arr[], int n){
  for(int i=1, j, aux;i<n;i++){
    aux=arr[i];
    for(j=i-1;j>=0 && arr[j]>aux;j--)
      arr[j+1]=arr[j];
    arr[j+1]=aux;
  }
}