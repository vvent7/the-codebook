#include <bits/stdc++.h>
using namespace std;

void heap_sort(int a[], int n){
  make_heap(a, a+n);
  do{
    pop_heap(a, a+n);
  }while(--n>0);
}