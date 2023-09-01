#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll evaluate_postfix(string &eq){
  stack<ll> st;

  for(int i=0;i<eq.size();i++){
    if(isblank(eq[i])) continue;
    else if(isdigit(eq[i])){
      char *endPtr;
      ll num=strtoll(eq.c_str()+i, &endPtr, 10);
      i=endPtr-eq.c_str()-1;
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