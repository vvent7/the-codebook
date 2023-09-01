#include <bits/stdc++.h>
#define fi first
#define sec second
using namespace std;
typedef pair<int, int> pi;

//st1: add, st2: remove
stack<pi> st1, st2; //{x, min/max}

void add_back(int x){
  st1.emplace(x, st1.empty()?x:min(x, st1.top().sec));
}

int find_min(){
  return !(st1.empty() || st2.empty())
    ? min(st1.top().sec, st2.top().sec)
    : !st1.empty()
      ? st1.top().sec
      : !st2.empty()
        ? st2.top().sec
        : INT_MAX; //neutro (ambas vazias)
}

void rm_front(){
  if(!st2.empty()){
    st2.pop(); return;
  }
  if(st1.empty()) return;

  while(!st1.empty()){
    int x=st1.top().fi; st1.pop();
    st2.emplace(x, st2.empty()?x:min(x, st2.top().sec));
  }
  st2.pop();
}

//sempre limpar para reutilizar
void clear_all(){
  while(!st1.empty()) st1.pop();
  while(!st2.empty()) st2.pop();
}