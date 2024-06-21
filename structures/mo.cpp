// Problem: https://codeforces.com/gym/105164/problem/A

#include <bits/stdc++.h>
using namespace std;

void remove(int i);  // TODO: remove value at idx from data structure
void add(int i);     // TODO: add value at idx from data structure
int get_answer();    // TODO: extract the current answer of the data structure

int block_size;  // use const if possible (faster divisions)

struct Query {
  int l, r, idx;
  bool operator<(const Query &b) const {
    int xBlock = l / block_size, yBlock = b.l / block_size;
    return xBlock != yBlock ? l < b.l
           : (xBlock & 1)   ? r > b.r  // odd (descending)
                            : r < b.r; // even (ascending)
  }
};

vector<int> mo_s_algorithm(vector<Query> &queries) {
  vector<int> answers(queries.size());
  sort(queries.begin(), queries.end());

  // TODO: initialize data structure

  int cur_l = 0, cur_r = -1;
  // invariant: data structure will always reflect the range [cur_l, cur_r]
  for (Query q : queries) {
    while (cur_l > q.l) add(--cur_l);
    while (cur_r < q.r) add(++cur_r);
    while (cur_l < q.l) remove(cur_l++);
    while (cur_r > q.r) remove(cur_r--);
    answers[q.idx] = get_answer();
  }
  return answers;
}