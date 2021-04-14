#include <cstdio>
#include <vector>

using namespace std;

const int maxn = 2e5+100;
const int maxlogv = 19;

vector<pair <int, int> > adj[maxn];

int id[maxn];
long long cost[maxn], dist[maxn];
int vs[maxn*2], depth[maxn*2];
int dp[maxn*2][maxlogv];
bool isPost[maxn];

void dfs(int v, int p, int d, int &k) {
    id[v] = k;
    vs[k] = v;
    depth[k++] = d;
    for(auto it : adj[v]) {
        if(it.first == p) continue;
        if(!isPost[it.first]) cost[it.first] = cost[v]+it.second;
        else cost[it.first] = 0;
        dist[it.first] = dist[v] + it.second;
        dfs(it.first,v,d+1,k);
        vs[k] = v;
        depth[k++] = d;
    }
}

void init_rmq(int n) {
    for(int i = 0; i < n ; ++i)
        dp[i][0] = i;
    for(int j = 1;(1<<j) <= n; ++j) {
        for(int i = 0;i + (1<<j)-1 < n; ++i) {
            if(depth[dp[i][j-1]] < depth[dp[i+(1<<(j-1))][j-1]])
                dp[i][j] = dp[i][j-1];
            else dp[i][j] = dp[i+(1<<(j-1))][j-1];
        }
    }
}

int query(int l,int r) {
    int k = 0;
    while((1<<(k+1)) <= r-l+1) k++;
    if(depth[dp[l][k]] < depth[dp[r-(1<<k)+1][k]])
        return dp[l][k];
    else return dp[r-(1<<k)+1][k];
}

int lca(int u,int v) {
    return vs[query(min(id[u],id[v]),max(id[u],id[v]))];
}
int b[maxn];
bool check(int kk,long long mid) {
    bool flag = true;
    int fa;
    for(int i = 1;i <= kk; ++i) {
        if(cost[b[i]] > mid) {
            if(flag) {
                flag = false;
                fa = b[i];
            } else fa = lca(fa,b[i]);
        }
    }
    if(flag) return true;
    for(int i = 1;i <= kk; ++i) {
        if(cost[b[i]] > mid) {
            if(dist[b[i]] - dist[fa] > mid) return false;
        }
    }
    return true;
}

int main() {
    int n, m, q;
    scanf("%d%d%d", &n, &m, &q);
    isPost[0] = true;
    for(int i = 0;i < m; ++i) {
        int a;
        scanf("%d", &a);
        isPost[a] = true;
    }
    for(int i = 1;i < n; ++i) {
        int u, v, w;
        scanf("%d%d%d",&u, &v, &w);
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }
    int k = 0;
    dfs(0, -1, 0, k);
    init_rmq(2 * n - 1);
    while(q--) {
        int kk;
        scanf("%d", &kk);
        for(int i = 1;i <= kk;++i) {
            scanf("%d", &b[i]);
        }
        long long l = 0, r = 1e14;
        while(r >= l) {
            long long mid = (r + l)>>1;
            if(check(kk, mid)) r = mid - 1;
            else l = mid + 1;
        }
        printf("%lld\n", l);
    }
    return 0;
}
