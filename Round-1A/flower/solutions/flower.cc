#include <ctime>
#include <vector>
#include <cstdlib>
#include <iostream>

using namespace std;

vector<long long> h = {0LL, 1LL, 2LL, 4LL, 7LL, 14LL, 27LL, 50LL, 97LL, 194LL, 387LL, 770LL, 1539LL, 3070LL, 6137LL, 12270LL, 24539LL, 49072LL, 98141LL, 196270LL, 392517LL, 785020LL, 1570037LL, 3140044LL, 6280085LL, 12560152LL, 25120299LL, 50240588LL, 100481175LL, 200962342LL, 401924669LL, 803849308LL, 1607698611LL, 3215397194LL, 6270511293LL, -1LL};

int main() {
	int T;
	cin >> T;
	while (T--) {
		long long a, b;
		cin >> a >> b;
		int i = 1;
		while (h[i] <= a && h[i] != -1) {
			a += b;
			i++;
		}
		cout << i << " " << h[i] << " " << a << endl;
	}

	return 0;
}