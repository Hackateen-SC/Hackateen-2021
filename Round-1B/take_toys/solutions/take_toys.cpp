#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf (int)1e18+7

int n, m;

vector <pair <int, int> > coords;
pair<int, int > beg;
int begid;

int dist[20][20];

int calc(int i, int j) {
    int x = abs(coords[i].first - coords[j].first);
    int y = abs(coords[i].second - coords[j].second);
    return max(x, y);
}

int dp[1 << 16][16];
int solve(int visited, int last) {
    if (__builtin_popcount(visited) == coords.size()) {
        return dist[last][begid];
    }
    int &res = dp[visited][last];
    if (res != -1) return res;
    res = inf;
    for (int i = 0; i < coords.size(); i ++) {
        if ((visited & (1 << i)) == 0) {
            res = min(res, solve(visited | ( 1 << i), i) + dist[last][i]);
        } 
    }
    return res;
}

signed main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> n >> m;
    coords.clear();
    for (int i = 0; i < n; i ++) {
        cin >> s;
        for (int j = 0; j < m; j ++) {
            if (s[j] != '.') {
                coords.push_back(make_pair(i, j));
            }
            if (s[j] == 'S') {
                beg.first = i;
                beg.second = j;
                begid = coords.size() - 1;
            }
        }
    }
    
    memset(dist, 0, sizeof dist);
    for (int i = 0; i < coords.size(); i ++) {
        for (int j = i + 1; j < coords.size(); j ++) {
            dist[i][j] = dist[j][i] = calc(i, j);
        }
    }
    memset(dp, -1, sizeof dp);
    int ans = solve(1 << begid, begid);
    cout << ans << endl;

    return 0;
}