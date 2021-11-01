#include<bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);
#define inf 1000000123
using namespace std;

//maior soma em subsequências contíguas
int kadane(int v[],int n){
	int maior=0, acumulador=0;
	for(int i=0;i<n;i++){
		acumulador=max(v[i], acumulador+v[i]);
		maior=max(acumulador, maior);
	}
	return maior;
}
