
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int n; cin >> n;
	vector<pair<int, char> > a(n + 1);
	a[0] = make_pair(0, 'G');
	string s;
	for (int i = 1; i <= n; i++)
		cin >> a[i].first;
	cin >> s;

	int l = 0, g = 1;
	for (int i = 1; i <= n; i++) {
		a[i].second = s[i - 1];
		if (s[i - 1] == 'G') g++;
	}

	sort(a.begin(), a.end());
	
	int x = 0, y = n + 1;
	for (int i = 0; i <= n; i++) {
		if (a[i].second == 'G') g--;
		else l++;
		if (i == n || a[i].first + 1 != a[i + 1].first) {
			int temp = l + g;
			if (temp < y) {
				y = temp;
				x = a[i].first + 1;
			}
		}
	}

	cout << x << " " << y << endl;

	return 0;
}