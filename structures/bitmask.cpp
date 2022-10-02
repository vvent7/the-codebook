bool bm_is_set(int mask, int i){
  return mask&(1<<i);
}
int bm_set_n(int n){
  return (1<<n)-1;
}
int bm_set(int mask, int i){
  return mask|=(1<<i);
}
int bm_unset(int mask, int i){
  return mask&(~(1<<i));
}
int bm_toggle(int mask, int i){
  return mask^(1<<i);
}
int bm_lsb(int mask, int i){
  return mask&(-mask);
}
void bm_subsets(int mask){
  for(int subset=mask;subset;subset=(subset-1)&mask){
    //do something...
  }
}