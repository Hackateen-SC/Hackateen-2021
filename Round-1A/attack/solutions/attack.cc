#include <iostream>

using namespace std;

int n, a[1000001];
long long dp[1000001], sum = 0;

int main() {	
	cin >> n;
	for (int i = 2; i <= n; i++) {
		cin >> a[i];
		sum += a[i];
	}
	dp[1] = 0;
	dp[2] = a[2];
	dp[3] = a[2] + a[3];

	for (int i = 4; i <= n; i++) {
		dp[i] = min(dp[i - 1], dp[i - 2]) + a[i];
	}
	cout << sum - dp[n] << endl;
	return 0;
}