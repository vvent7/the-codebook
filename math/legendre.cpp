typedef long long ll;
ll fact_pow (ll n, ll k) {
  ll res = 0;
  while (n) {
    n /= k;
    res += n;
  }
  return res;
}