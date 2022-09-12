#include <bits/stdc++.h>
#define fi first
#define sec second
using namespace std;
typedef pair<int, int> pi;

void counting_suffs_sort(int p[], int rank[], int n){
  int count[n]={0}, output[n];

  for(int i=0;i<n;i++) count[rank[p[i]]]++;
  for(int i=1;i<n;i++) count[i]+=count[i-1];
  for(int i=n-1;i>=0;i--) output[--count[rank[p[i]]]]=p[i];
  copy(output, output+n, p);
}

void build_suffs(string &s, int p[]){ //'$' no final de s
  int n=s.size(), rank[n], newRank[n];
  pair<char, int> aux[n];

  for(int i=0;i<n;i++) aux[i]={s[i], i};
  sort(aux, aux+n);

  p[0]=aux[0].sec; rank[p[0]]=0;
  for(int i=1;i<n;i++){
    p[i]=aux[i].sec;
    rank[p[i]]=rank[p[i-1]];
    if(aux[i].fi!=aux[i-1].fi) rank[p[i]]++;
  }

  pi pre, cur;
  for(int k=1;k<n;k<<=1){
    for(int i=0;i<n;i++) //ordenando pela metade 2
      p[i]=(p[i]-k+n)%n;
    counting_suffs_sort(p, rank, n); //ordenando pela metade 1

    //Atualizando ranks de sufixos em p
    newRank[p[0]]=0; pre={rank[p[0]], rank[(p[0]+k)%n]};
    for(int i=1;i<n;i++, pre=cur){
      cur={rank[p[i]], rank[(p[i]+k)%n]};
      newRank[p[i]]=newRank[p[i-1]];
      if(pre!=cur) newRank[p[i]]++;
    }
    copy(newRank, newRank+n, rank);
  }
}