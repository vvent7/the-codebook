#include <bits/stdc++.h>
#define fi first
#define eb emplace_back
using namespace std;
typedef vector<int> vi;

#define MAX_N 100005

typedef enum{UNVISITED, EXPLORED, VISITED}State;

vi g[MAX_N];
State vState[MAX_N];
int parent[MAX_N]; //dfs tree (can print found cycle)

void cycle_check2(int u){
  vState[u]=EXPLORED;

  for(auto v:g[u]){
    if(vState[v]==UNVISITED){ //EXPLORED->UNVISITED(Tree Edge)
      cout<<"Tree Edge "<<u<<"->"<<v<<"\n";
      parent[v]=u;
      cycle_check2(v);
    }
    else if(vState[v]==EXPLORED){ //EXPLORED->EXPLORED (Cycle)
      if(parent[u]==v) cout<<"Bidirectional Edge "; //trivial
      else cout<<"Back Edge "; //non-trivial
      cout<<u<<"->"<<v<<endl;
    }
    else //EXPLORED->VISITED (Forward/Cross Edge)
      cout<<"Forward/Cross Edge "<<u<<"->"<<v<<"\n";
  }

  vState[u]=VISITED;
}

void cycle_check1(int n){
  fill(vState, vState+n, UNVISITED); //0-based

  for(int u=0;u<n;u++)
    if(vState[u]==UNVISITED){
      parent[u]=u;
      cycle_check2(u);
    }
}