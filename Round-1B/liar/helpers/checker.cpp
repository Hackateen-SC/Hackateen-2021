#include <vector>
#include <string>
#include <iostream>

using namespace std;

int n;
vector<int> a, b;
string s;
int x, y;

void check(int t) {
	int temp = 0;

	for (int i = 0; i < n; i++) {
		if (a[i] < t && s[i] == 'L') temp++;
		else if (a[i] > t && s[i] == 'G') temp++;
	}

	if (temp < y) {
		y = temp;
		x = t;
	}
	if (t == 2) {
		cout << temp << endl;
	}
}

int main() {
	bool flag = true;
	cin >> n;
	a.resize(n);
	b.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i]; b[i] = a[i];
		flag = flag || (a[i] == 1);
	}
	cin >> s;

	sort(b.begin(), b.end());

	x = 0; y = n + 1;

	if (!flag) check(0);

	for (int i = 0; i < n; i++) {
		if (i == n - 1 || b[i] + 1 != b[i + 1])
			check(b[i] + 1);
	}

	cout << x << " " << y << endl;

	return 0;
}