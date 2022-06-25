#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

//maior soma em subsequências contíguas
ll kadane(int v[], size_t n){
	ll best=0, acum=0;
	for(size_t i=0;i<n;i++){
		acum=max(ll(v[i]), acum+v[i]);
		best=max(acum, best);
	}
	return best;
}