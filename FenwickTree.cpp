#include <iostream>
using namespace std;
const int N = 10;
int tree[N];
// add v to value at x
void set(int x, int v) {
  while(x <= N) {
    tree[x] += v;
    x += (x & -x);
  }
}
// get cumulative sum up to and including x
int get(int x) {
  int res = 0;
  while(x) {
    res += tree[x];
    x -= (x & -x);
  }
  return res;
}

int main(){
  set(1,1);
  set(4,3);
  set(7,-4);
  for(int i=1;i<=N;i++){
    printf("%d ",get(i));
  }
}
