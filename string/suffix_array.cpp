#include <bits/stdc++.h>
using namespace std;

#define MSBI(x) (sizeof(int)*__CHAR_BIT__ - __builtin_clz(x) - 1)

constexpr int MAX_N = 4e5+5; //LOG_N = MSBI(MAX_N) + 5

struct SufflxArray{
  int n, p[MAX_N], c[MAX_N], lcp[MAX_N], invP[MAX_N];
  // int p[LOG_N][MAX_N], c[LOG_N][MAX_N];

  void counting_sort(int mxC){
    static int cnt[MAX_N], p2[MAX_N];
    fill(cnt, cnt+mxC+1, 0);

    for(int i=0;i<n;++i) ++cnt[c[p[i]]];
    for(int i=1;i<=mxC;++i) cnt[i]+=cnt[i-1];
    for(int i=n-1;i>=0;--i) p2[--cnt[c[p[i]]]] = p[i];

    copy(p2, p2+n, p); // copy(p2, p2+n, p[curLog])
  }

  int update_c(int k){ //len = 2*k
    static int c2[MAX_N];
    c2[p[0]]=0;
    pair<int,int> pre(c[p[0]], c[(p[0]+k)%n]), cur;
    for(int i=1;i<n;++i){
      cur = {c[p[i]], c[(p[i]+k)%n]};
      c2[p[i]]=c2[p[i-1]];
      if(pre!=cur) ++c2[p[i]], pre=cur;
    }
    
    copy(c2, c2+n, c); // copy(c2, c2+n, c[nextLog])
    return c2[p[n-1]]; //mxC
  }

  void build(string &s){
    // s+=' '; // if needed (not cyclic)
    n = (int) s.size();
    int mxC=0;
    for(int i=0;i<n;++i)
      p[i]=i, c[i]=s[i], mxC=max(mxC, (int)s[i]);
    counting_sort(mxC);
    mxC = update_c(0);

    for(int k=1;k<n;k<<=1){ //len = 2*k
      for(int i=0;i<n;++i) p[i]=(p[i]-k+n)%n;
      counting_sort(mxC);
      mxC = update_c(k);
    }
    //LCP:
    lcp[0]=0;
    for(int i=0;i<n;++i) invP[p[i]]=i;
    for(int i=0, k=0;i<n;++i){
      int ip = invP[i];
      if(ip==0) continue; //ignore first
      int j = p[ip-1];
      while(s[i+k]==s[j+k]) ++k;
      lcp[ip] = k;
      k = max(k-1, 0);
    }
  }

  //need matrix c[LOG_N][MAX_N]
  int cmp(int i, int iLen, int j, int jLen){
    int len = min(iLen, jLen);
    int log = MSBI(len);
    pair<int,int> ival(c[log][i], c[log][(i+len-(1<<log))%n]),
      jval(c[log][j], c[log][(j+len-(1<<log))%n]);

    if(ival!=jval) return ival<jval ? -1 : 1;
    if(iLen!=jLen) return iLen<jLen ? -1 : 1;
    return 0;
  }
};