#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll fast_exp(ll a, ll exp){
	if(exp==0) return 1;
	if(exp==1) return a;
	if((exp&1)==0){ //par
		ll x = fast_exp(a, exp/2);
		return x*x;
	}
	return fast_exp(a, exp-1)*a;
}