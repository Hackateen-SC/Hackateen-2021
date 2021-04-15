#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define int long long
#define inf (int)1e18+7

int n, whole;
int a[17][17];

int cost[(1LL << 17) + 1LL];

void preprocess () {
  memset(cost, 0, sizeof cost);
  for (int mask = 0; mask <= whole; mask ++) {
    for (int i = 0; i < n; i ++) {
      if ((mask & (1 << i)) != 0) {
        for (int j = i + 1; j < n; j ++) {
          if ((mask & (1 << j)) != 0) {
            cost[mask] += a[i][j];
          }
        }
      }
    }
  }
}
int dp[(1LL << 17) + 1LL];

void solve() {
  dp[0] = 0;
  for (int mask = 1; mask <= whole; mask ++) {
    vector<int > target;
    for (int i = 0; i < n; i ++) {
      if ((mask & (1 << i)) != 0) {
        target.push_back(i);
      }
    }
    for (int sub = 0; sub < (1 << (int)(target.size())); sub ++) {
      int submask = 0;
      for (int i = 0; i < (int)target.size(); i ++) {
        if ((sub & (1 << i)) != 0) {
          submask |= (1 << target[i]);
        }
      }
      dp[mask] = max(dp[mask], cost[submask] + dp[mask ^ submask]);
    }
  }
}


string toStr(int k) {
    string s = "";
    while (k) {
         s += (k % 10) + '0';
         k /= 10;
    }
    reverse(s.begin(), s.end());
    return s;
}


signed main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(0);

  cin >> n;
  whole = (1LL << n) - 1LL;
  for (int i = 0; i < n; i ++) {
    for (int j = 0; j < n; j ++) {
      cin >> a[i][j];
    }
  }

  preprocess();

  solve();

  cout << dp[whole] << endl;
  
  return 0;
}


// dp[mask] = for (cur 0 to mask) calc(cur) + dp[mask ^ cur];