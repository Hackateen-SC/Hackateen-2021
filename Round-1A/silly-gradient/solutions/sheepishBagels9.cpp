#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define pp pop_back
#define mp make_pair
#define bb back
#define ff first
#define ss second

using namespace std;

/*
 ____     __    _______    _______   __________
|     \  |  |  |  _____|  /  _____) |____  ____|
|  |\  \ |  |  | |__     (  (_____      |  |
|  | \  \|  |  |  __|     \_____  \     |  | 
|  |  \     |  | |_____    _____)  )    |  | 
|__|   \____|  |_______|  (_______/     |__| 
*/

vector<string> ans = { "radial", "horizontal", "vertical", "angled" };
ll dif(vector<ll>a, vector<ll>b) {
    int ans = 0;
    for (int i = 0; i < 3; i++) ans += abs(a[i] - b[i]);
    return ans;
}

ll avefinder(vector<vector<ll> > a) {
    vector<ll> avr(3, 0), ans(3, 0);
    for (int i = 0; i < a.size(); i++) {
        avr[0] += a[i][0];
        avr[1] += a[i][1];
        avr[2] += a[i][2];
    }
    avr[0] /= a.size();
    avr[1] /= a.size();
    avr[2] /= a.size();
    for (int i = 0; i < a.size(); i++) {
        ans[0] += abs(avr[0] - a[i][0]);
        ans[1] += abs(avr[1] - a[i][1]);
        ans[2] += abs(avr[2] - a[i][2]);
    }
    ans[0] /= a.size();
    ans[1] /= a.size();
    ans[2] /= a.size();
    return (ans[0] + ans[1] + ans[2]) / 3;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // freopen("in3.txt", "r", stdin);
    vector<vector<vector<ll> > > ave(3, vector<vector<ll>>(3, vector<ll>(3)));
    int a, b, c;
    for (int i = 0; i < 300; i++)
    for (int j = 0; j < 300; j++) {
        cin >> a >> b >> c;
        ave[i/100][j/100][0] += a;
        ave[i/100][j/100][1] += b;
        ave[i/100][j/100][2] += c;
    }
    for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
    for (int k = 0; k < 3; k++) 
        ave[i][j][k] /= 10000;
    
    // for (int i = 0; i < 3; i++) {
    //     for (int j = 0; j < 3; j++) {
    //         for (int k = 0; k < 3; k++) {
    //             cout << ave[i][j][k] << ",";
    //         }
    //         cout << ' ';
    //     }
    //     cout << '\n';
    // }
    vector<ll> tmp = ave[0][0];
    bool Y = 1;
    for (int j = 0; j < 3; j++) {
        tmp = ave[0][j];
        for (int i = 0; i < 3; i++) {
            if (dif(ave[i][j], tmp) > 5) Y = 0;
        }
    }
    if (Y) {
        cout << ans[1] << '\n';
        return 0;
    }
    Y = 1;
    for (int j = 0; j < 3; j++) {
        tmp = ave[j][0];
        for (int i = 0; i < 3; i++) {
            if (dif(ave[j][i], tmp) > 5) Y = 0;
        }
    }
    if (Y) {
        cout << ans[2] << '\n';
        return 0;
    }

    ll radialism = max(dif(ave[0][1], ave[2][1]), dif(ave[0][1], ave[2][1]));
    if (radialism > 3)
        cout << ans[3] << '\n';
    else 
        cout << ans[0] << '\n';
    return 0;
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?)
    * do smth instead of nothing and stay organized
    * WRITE STUFF DOWN
    * DON'T GET STUCK ON ONE APPROACH
*/