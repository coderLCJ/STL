#include <bits/stdc++.h>
using namespace std;
int main() {
  int n,q;
  cin >> n;
  vector<int> v;
  for (int i=0;i<n;i++) {
       cin>>q;
       v.push_back(q);
  }
  cin >> q;
  while (q--) {
    int k;
    cin >> k;
    cout << lower_bound(v.begin(), v.end(), k) - v.begin() << endl;
  }
}
