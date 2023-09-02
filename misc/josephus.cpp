//recursive josephus (1-based): O(n) 
int josephus_rec(int n, int k) {
  return n > 1 
    ? (josephus_rec(n-1, k) + k - 1) % n + 1
    : 1;
}

//iterative josephus (1-based): O(n)
int josephus_iter(int n, int k) {
  int ans = 0;
  for (int i = 1; i <= n; i++)
    ans = (ans + k) % i;
  return ans + 1;
}

//O(n log k) josephus (0-based)
int josephus_nlogk(int n, int k) {
  if(n == 1) return 0;
  if(k == 1) return n-1;
  if(k > n) return (josephus_nlogk(n-1, k) + k) % n;
  int cnt = n / k;
  int res = josephus_nlogk(n - cnt, k);
  res -= n % k;
  if (res < 0) res += n;
  else res += res / (k - 1);
  return res;
}

//josephus k=2 (1-based): O(1)
#define LOG2(x)(sizeof(int)*__CHAR_BIT__-__builtin_clzll(x)-1)
int josephus_k2(int n){
  return 1 + 2 * (n - (1LL << LOG2(n)));
}