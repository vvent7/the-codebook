#include<bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);
#define ii pair<int,int>
#define vii vector<ii>
#define vi vector<int>
#define oo 1000000123
using namespace std;

vector<bool> primes;
void sieve(int n){
    primes=vector<bool>(n+5,true);
    int limit = sqrt(n);
    primes[0]=primes[1]=false;
    for(int i=2;i<=limit;i++){
        if(primes[i]){
          for(int j=i*i;j<=n;j+=i) primes[j]=false;
        }
    }
    //primos estarão como true no vector primes
}
