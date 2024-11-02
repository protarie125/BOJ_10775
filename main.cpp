#include <algorithm>
#include <bit>
#include <chrono>
#include <cmath>
#include <cstdint>
#include <deque>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <ranges>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

using ll = int64_t;
using vl = vector<ll>;

ll g, p;
vl par;

ll GetRoot(ll x) {
  if (par[x] == x) return x;

  return par[x] = GetRoot(par[x]);
}

void Joint(ll x, ll y) {
  x = GetRoot(x);
  y = GetRoot(y);

  par[max(x, y)] = min(x, y);
}

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  cin >> g >> p;
  par = vl(g + 1);
  for (auto i = 0; i <= g; ++i) {
    par[i] = i;
  }

  ll ans = 0;
  for (auto i = 0; i < p; ++i) {
    ll x;
    cin >> x;

    x = GetRoot(x);
    if (0 == x) {
      cout << ans;
      return 0;
    }

    Joint(x, x - 1);

    ++ans;
  }

  cout << ans;

  return 0;
}