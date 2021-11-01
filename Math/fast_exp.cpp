#include<bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);
using namespace std;

long long int fastexp(int a,int n){
	long long int x;
	if(n==0) return 1;
	if(n==1) return a;

	if(n%2==0){
		x = fastexp(a,n/2);
		return x*x;
	}
	else return fastexp(a,n-1)*a;
}
