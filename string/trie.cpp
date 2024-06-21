#include <bits/stdc++.h>
using namespace std;

constexpr int MAX_C = 1e6 + 5; 

struct Trie{
  struct TrieNode{
    int cnt, wrd;
    map<char, int> m;
    TrieNode(){
      cnt = 0; wrd = 0;
      m.clear();
    }
  } t[MAX_C];

  int en; //node count

  Trie(){ clear(); }

  int new_node(){
    t[en].cnt = t[en].wrd = 0;
    t[en].m.clear();
    return en++; //new node index
  }

  void clear(){
    en = 0;
    new_node();
  }

  // Add string 's' to Trie
  void add(string &s, int i = 0, int node = 0){
    t[node].cnt++;
    if(i == s.size()){
      t[node].wrd++; return;
    }
    if(!t[node].m.count(s[i]))
      t[node].m[s[i]] = new_node();
    add(s, i + 1, t[node].m[s[i]]);
  }

  // Returns true if 's' is in Trie
  bool remove(string &s, int i = 0, int node = 0){
    if(i == s.size()){
      if(t[node].wrd){
        t[node].wrd--;
        t[node].cnt--;
        return true;
      }
      return false;
    }

    if(!t[node].m.count(s[i])) return false;
    int child = t[node].m[s[i]];
    if(remove(s, i+1, child)){
      t[node].cnt--;
      if(t[child].cnt == 0) t[node].m.erase(s[i]);
      return true;
    }
    return false;
  }

  // Returns true if 's' is in Trie
  bool find(string &s, int i = 0, int node = 0){
    if(i == s.size()){
      if(t[node].wrd) return true;
      return false;
    }
    if(!t[node].m.count(s[i])) return false;
    return find(s, i + 1, t[node].m[s[i]]);
  }
};