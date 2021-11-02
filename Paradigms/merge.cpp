#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(false); \
  cin.tie(NULL);
#define MAXN 100009
using namespace std;

int aux[MAXN]; 


//array, limite inicial padrao por 0, limite final padrao por tamanho do vetor-1
void mergesort(int arr[],int l,int r){
    if(l==r) return;
    int m=(l+r)/2;
    mergesort(arr,l,m);
    mergesort(arr,m+1,r);
    int i=l,j=m+1,k=l;

    while(i<=m && j<=r){
        if(arr[i]>arr[j]){
            aux[k++]=arr[j++];
        }
        else aux[k++] = arr[i++];
    }

    while(i<=m) aux[k++] = arr[i++];

    for (i=l;i<k;i++) arr[i]=aux[i];
}