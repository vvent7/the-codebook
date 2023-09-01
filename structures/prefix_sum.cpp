typedef long long ll;
const int MAX_N = 200005;

ll pre[MAX_N];

void unbuild(int n){ //unbuild in-place
  for(int i=n-1;i>0;i--)
    pre[i]-=pre[i-1];
}

void build(int n){ //build in-place
  for(int i=1;i<n;i++)
    pre[i]+=pre[i-1];
}

ll sum_range(int l, int r){
  if(l==1) return pre[r];
  return pre[r]-pre[l-1];
}