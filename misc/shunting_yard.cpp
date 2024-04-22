#include <bits/stdc++.h>
using namespace std;

string shunting_yard(string &infix){
  stack<char> st;
  string ops="-+/*n^", postfix;
  int opVal[ops.size()]={1,1,2,2,3,4}, cVal[128]={0};
  //opVal[i]>0
  for(size_t i=0;i<ops.size();i++) cVal[ops[i]]=opVal[i];

  char lastToken='(';
  bool negUnary=false;

  for(size_t i=0;i<infix.size();++i){
    if(infix[i]=='('){ // (
      if(negUnary) st.push('n'), negUnary=false;
      st.push(infix[i]);
      lastToken=infix[i];
    } 
    else if(isdigit(infix[i])){ //number
      if(negUnary) st.push('n'), negUnary=false;
      size_t j=find_if_not(infix.begin()+i, infix.end(), [](const char c){return isdigit(c);}) - infix.begin();
      postfix.append(infix, i, j-i).append(" ");
      i=j-1;
      lastToken=infix[i];
    }
    else if(infix[i]==')'){ // )
      while(st.top()!='('){
        postfix.append(1, st.top()).append(" ");
        st.pop();
      }
      st.pop();
      lastToken=infix[i];
    }
    else if(cVal[infix[i]]>0){ //operator
      if(lastToken=='(' || ops.find(lastToken)!=string::npos){
        negUnary^=(infix[i]=='-');
        continue;
      }
      while(!st.empty() && cVal[st.top()]>=cVal[infix[i]]){
        postfix.append(1, st.top()).append(" ");
        st.pop();
      }
      st.push(infix[i]);
      lastToken=infix[i];
    }
  }

  while(!st.empty()){
    postfix.append(1, st.top()).append(" ");
    st.pop();
  }
  if(postfix.size()>0) postfix.pop_back();

  return postfix;
}