#include <bits/stdc++.h>
using namespace std;

string A, B;

string parse(const string& s) {
  string res = "";

  vector<char> st, tmp;
  int xcnt = 0;
  for (int i = 0; i < s.length(); i++) {
    char c = s[i];

    if (c == '(') {
      if (xcnt || (!st.empty() && st.back() != '(')) {
        for (char t : tmp) res += t;
        tmp.clear();
        st.clear();
      }
      xcnt = 0;
      tmp.push_back('(');
      st.push_back('(');

    } else if (c == ')') {
      if (xcnt == 2 && !st.empty() && st.back() == '(') {
        st.pop_back();
        if (st.empty() || (i + 1 < s.length() && s[i + 1] != ')') ||
            i + 1 == s.length()) {
          int si = i;
          while (s[si] == ')') si--;
          int len = i - si;

          for (int i = 0; i < len + 2; i++) tmp.pop_back();
          tmp.push_back('x');
          tmp.push_back('x');
        }
      } else {
        st.push_back(c);
        tmp.push_back(c);
      }

    } else {
      xcnt++;
      tmp.push_back(c);
    }
  }
  for (char t : tmp) res += t;
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int T;
  cin >> T;
  while (T--) {
    cin >> A >> B;
    if (parse(A) == parse(B))
      cout << "Yes\n";
    else
      cout << "No\n";
  }
}