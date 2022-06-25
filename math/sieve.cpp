#include<bits/stdc++.h>
using namespace std;

vector<bool> primes;
void sieve(int n){
  primes=vector<bool>(n+1,true);
  int limit = sqrt(n);
  primes[0]=primes[1]=false;
  for(int i=2;i<=limit;i++){
    if(primes[i]){
      for(int j=i*i;j<=n;j+=i) primes[j]=false;
    }
  }
  //primos estarão como true no vector primes
}