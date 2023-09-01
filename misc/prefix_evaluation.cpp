// C++ program to evaluate a prefix expression.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll evaluatePrefix(string &eq){
  stack<ll> st;

  for(int i=eq.size()-1;i>=0;i--){
    if(isblank(eq[i])) continue;
    if(isdigit(eq[i])){
      while (i>=0 && isdigit(eq[i])) i--;
      i++;
      ll num=strtoll(eq.c_str()+i, NULL, 10);
      st.push(num);
    }
    else{
      ll v1 = st.top(); st.pop();
      ll v2 = st.top(); st.pop();

      if(eq[i]=='+') st.push(v1 + v2);
      else if(eq[i]=='-') st.push(v2 - v1);
      else if(eq[i]=='*') st.push(v1 * v2);
      else if(eq[i]=='/') st.push(v2 / v1);
      else if(eq[i]=='^') st.push(pow(v2, v1));
    }
  }

  return st.top();
}