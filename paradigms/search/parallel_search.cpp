#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

//dummy functions
void reset(){}
void apply(int mid){}
bool check(int i){return true;}
//===============

const int MAX_N=1e5+5, MAX_Q=1e5+5;

ll lo[MAX_N], hi[MAX_N]; // [0,q]
stack<int, vector<int>> toCheck[MAX_Q];

void parallel_bin_search(int n, int q){
  fill(lo, lo+n+1, 0);
  fill(hi, hi+n+1, q);
  //ans = [0,q-1], q is fail
 
  bool changed=true;
  while(changed){
    changed=false;
    for(int i=0;i<n;i++)
      if(lo[i]<hi[i]) toCheck[(lo[i]+hi[i])/2].emplace(i);
 
    reset(); //reseta a estrutura (nenhuma query aplicada)
 
    for(int mid=0;mid<q;mid++){
      apply(mid); //aplica query 'mid' na estrutura
 
      while(!toCheck[mid].empty()){
        changed=true;
        int i = toCheck[mid].top(); toCheck[mid].pop();

        //checa se a resposta está em [lo[i],mid]
        bool ans = check(i);
        if(ans) hi[i]=mid; //lower_bound
        else lo[i]=mid+1;
      }
    }
  }
}