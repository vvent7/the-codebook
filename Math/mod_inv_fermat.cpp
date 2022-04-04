#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);
using namespace std;

// Funciona apenas quando MOD for primo;
long long int fast_exp(int base,int exp,int mod){
    long long int x;
    if(exp==0) return 1;
    if(exp==1) return base;

    if(exp%2==0){
      x=fast_exp(base,exp/2,mod);
      return (x*x)%mod;
    }
    else return (fast_exp(base,exp-1,mod)*base)%mod;
}

long long int invMFermat(int m,int n){_
    return fast_exp(m,n-2,n);
}
