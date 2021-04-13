#include <map>
#include <set>
#include <vector>
#include <iostream>
 
using namespace std;

 
int p[10], digits[10];
map < vector < int >, vector < int > > M;

int main() {
  int n, k;
  cin >> n >> k;
  vector<string> guesses(n);
  vector<int> nums(n);
  for (int i = 0; i < n; i++)
    cin >> guesses[i] >> nums[i];
  
  int k1 = k / 2;
  int k2 = k - k1;
 
  p[0] = 1;
  for (int i = 1; i < 10; ++i) {
    p[i] = p[i - 1] * 10;
  }
 
  M.clear();
 
  for (int i = 0; i < p[k1]; ++i) {
    vector < int > a(n, 0);
    int x = i;
    for (int j = 0; j < k1; ++j) {
      digits[j] = x % 10;
      x /= 10;
    }
    reverse(digits, digits + k1);
    for (int j = 0; j < n; ++j) {
      for (int l = 0; l < k1; ++l) {
        if (guesses[j][l] == digits[l] + '0') {
          ++a[j];
        }
      }
    }
    M[a].push_back(i);
  }
 
  set < int > S;
  for (int i = 0; i < p[k2]; ++i) {
    vector < int > a = nums;
    int x = i;
    for (int j = 0; j < k2; ++j) {
      digits[j] = x % 10;
      x /= 10;
    }
    reverse(digits, digits + k2);
 
    bool nice = true;
    for (int j = 0; j < n; ++j) {
      for (int l = k1; l < k; ++l) {
        if (guesses[j][l] == digits[l - k1] + '0') {
          --a[j];
        }
      }
      if (a[j] < 0) {
        nice = false;
      }
    }
    if (!nice) {
      continue;
    }
 
    if (M.count(a) != 0) {
      if (S.size() > 1) {
        break;
      }
      vector < int > b = M[a];
      for (int j = 0; j < b.size(); ++j) {
        S.insert(b[j] * p[k2] + i);
        if (S.size() > 1) {
          break;
        }
      }
      if (S.size() > 1) {
        break;
      }
    }
  }
 
  if (S.size() == 1) {
    int x = * S.begin();
    string res = "";
    for (int i = 0; i < k; ++i) {
      res += x % 10 + '0';
      x /= 10;
    }
    reverse(res.begin(), res.end());
    cout << res << endl;
  } else if (S.size() == 0) {
    cout << "Liar\n";
  } else {
    cout << "Ambiguity\n";
  }

  return 0;
}
 