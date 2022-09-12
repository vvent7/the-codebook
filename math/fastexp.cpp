typedef long long ll;

ll fast_exp(ll b, ll exp){
  if(exp==0) return 1LL;
  if(b&1) return b*fast_exp(b, exp-1);
  ll x=fast_exp(b, exp/2);
  return x*x;
}