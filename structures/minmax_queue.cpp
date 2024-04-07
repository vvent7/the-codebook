#include <bits/stdc++.h>
using namespace std;
#define fi first
#define sec second
typedef long long ll;
typedef pair<ll, ll> pll;

struct MinQueue{
  stack<pll> st1, st2; //add, remove {x, min/max}

  void push_back(ll x){
    st1.emplace(x, st1.empty() ? x :min(x, st1.top().sec));
  }

  ll minimum(){
    return !(st1.empty() || st2.empty())
      ? min(st1.top().sec, st2.top().sec)
      : !st1.empty()
        ? st1.top().sec
        : !st2.empty()
          ? st2.top().sec
          : INT_MAX; //neutro (ambas vazias)
  }

  void pop_front(){
    if(!st2.empty()){
      st2.pop(); return;
    }
    if(st1.empty()) return;

    while(!st1.empty()){
      ll x=st1.top().fi; st1.pop();
      st2.emplace(x, st2.empty() ? x : min(x, st2.top().sec));
    }
    st2.pop();
  }

  void clear(){ // clear to reuse
    while(!st1.empty()) st1.pop();
    while(!st2.empty()) st2.pop();
  }
};
