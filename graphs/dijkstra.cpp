#include<bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);
#define pii pair<int,int>
#define inf 1000000123
#define MAXN 100005
using namespace std;

int n;
vector<pii> g[MAXN];
vector<int> dist;

void dijkstra(int origin){
  dist = vector<int>(n+2,inf);
  priority_queue<pii,vector<pii>,greater<pii>> pq;

  vector<bool> verificado(n+2,false);

  dist[origin]=0;
  pq.push(pii(0,origin));

  while(!pq.empty()){
    int v1=pq.top().second; pq.pop();

    if(verificado[v1]) continue;
    verificado[v1]=true;

    for(auto x : g[v1]){
      int v2 = x.second;
      int p2=x.first, aux=dist[v1]+p2;

      if(dist[v2]>aux){
        dist[v2]=aux;
        pq.push(pii(aux,v2));
      }
    }
  }
}
