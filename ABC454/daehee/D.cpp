#include <bits/stdc++.h>
using namespace std;

string convert(string s) {
  stack<char> st;
  int cnt_x = 0;
  for (int i=0 ; i<s.length() ; i++) {
    if (s[i] == '(') {
      while (cnt_x) {
        --cnt_x;
        st.push('x');
      }
      st.push('(');
    } else if (s[i] == ')') {
      if (cnt_x == 2 && !st.empty() && st.top() == '(') {
        st.pop();
      } else {
        while (cnt_x) {
          --cnt_x;
          st.push('x');
        }
        st.push(')');
      }
    } else {
      ++cnt_x;
    }
  }
  while (cnt_x) {
    --cnt_x;
    st.push('x');
  }

  string ret = "";
  while (!st.empty()) {
    ret += st.top();
    st.pop();
  }

  return ret;
}

void solve() {
  string a, b; cin >> a >> b;
  if (convert(a) == convert(b)) cout << "Yes";
  else cout << "No";
  cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int T; cin >> T;
  while (T--) solve();

}