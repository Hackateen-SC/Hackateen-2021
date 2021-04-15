#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    string s;
    
    cin >> n;
    vector <int> tmp(n);
    for (int i = 0; i < n; i++) {
        cin >> tmp[i];
    }
    cin >> s;
    
    vector <pair <int, char> > nums(1, {0, 'G'});
    for(int i = 0; i < n; i++) {
        nums.push_back({tmp[i], s[i]});
    }

    sort(nums.begin(), nums.end());
    
    nums.push_back({nums.back().first + 2, 'L'});
    vector <int> great(n+2, 0), low(n+2, 0);
    
    for (int i = 1; i < n + 2; i++) {
        low[i] = low[i-1];
        if (nums[i].second == 'L') low[i]++;
    }
    
    for (int i = n; i >= 0; i--) {
        great[i] = great[i+1];
        if (nums[i].second == 'G') great[i]++;
    }
    
    int ans = INT_MAX, pos = -1;
    for (int i = 1; i < n + 2; i++) {
        if (nums[i].first - nums[i-1].first < 2) continue;
        int curAns = low[i-1] + great[i], curNum = nums[i-1].first+1;
        if (curAns < ans) {
            ans = curAns;
            pos = curNum;
        }
    }

    cout << pos << ' ' << ans << '\n';
	
    return 0;
}