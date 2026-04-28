#include <bits/stdc++.h>
using namespace std;

struct Point {
  long long x, y;
};

bool is_colinear(const Point& a, const Point& b, const Point& c) {
  return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x) == 0;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<Point> points(n);
  for (auto& p : points) cin >> p.x >> p.y;

  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  uniform_int_distribution<int> dist(0, n - 1);

  for (int i = 0; i < 150; ++i) {
    int p1_idx = dist(rng);
    int p2_idx = dist(rng);
    while (p1_idx == p2_idx) {
      p2_idx = dist(rng);
    }

    Point p1 = points[p1_idx], p2 = points[p2_idx];

    int count = ranges::count_if(
        points, [&](const Point& p) { return is_colinear(p1, p2, p); });

    if (count > n / 2) {
      println("Yes");
      println("{} {} {}", p2.y - p1.y, p1.x - p2.x, p2.x * p1.y - p1.x * p2.y);
      return 0;
    }
  }
  cout << "No";
}