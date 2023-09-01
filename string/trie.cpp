#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 100005; 

struct Trie{
  struct TrieNode{
    int cnt, wrd;
    map<char, int> m;
    TrieNode(){
      cnt = 0; wrd = 0;
      m.clear();
    }
  } t[MAX_N];

  int en; //node count

  int new_node(){
    t[en].cnt = t[en].wrd = 0;
    t[en].m.clear();
    return en++; //new node index
  }

  void init(){
    en = 0;
    new_node();
  }

  // Adiciona string na Trie
  void add(int node, string &s, int i){
    t[node].cnt++;
    if(i == s.size()){
      t[node].wrd++; return;
    }
    if(!t[node].m.count(s[i]))
      t[node].m[s[i]] = new_node();
    add(t[node].m[s[i]], s, i + 1);
  }

  // Retorna true se s estava na trie
  bool remove(int node, string &s, int i){
    if(i == s.size()){
      if(t[node].wrd){
        t[node].wrd--;
        t[node].cnt--;
        return true;
      }
      return false;
    }

    if(!t[node].m.count(s[i])) return false;
    int son = t[node].m[s[i]];
    if(remove(son, s, i + 1)){
      t[node].cnt--;
      if(t[son].cnt == 0) t[node].m.erase(s[i]);
      return true;
    }
    return false;
  }

  //Retorna true se s está na trie
  bool find(int node, string &s, int i){
    if(i == s.size()){
      if(t[node].wrd) return true;
      return false;
    }
    if(!t[node].m.count(s[i])) return false;
    return find(t[node].m[s[i]], s, i + 1);
  }
};