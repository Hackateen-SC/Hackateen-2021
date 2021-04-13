#include <bits/stdc++.h>
using namespace std;


vector<string > grid;
int n, m, limit;
ofstream fout;    

string toStr(int k) {
    string s = "";
    while (k) {
         s += (k % 10) + '0';
         k /= 10;
    }
    reverse(s.begin(), s.end());
    return s;
}

string getSubNo(int no) {
    if (no <= 3) return "1";
    if (no <= 6) return "2";
    return "3";
}

void test_generate(int no) {

    string row = "";
    for (int i = 0 ; i < m; i ++) {
        row += '.';
    }
    grid.clear();
    for (int i = 0; i < n; i ++) {
        grid.push_back(row);
    }

    int sx = rand() % n;
    int sy = rand() % m;

    grid[sx][sy] = 'S';

    while ( limit -- ) {
        int tx, ty;
        do {
            tx = rand() % n;
            ty = rand() % m;
        } while (grid[tx][ty] != '.');
        grid[tx][ty] = 'T';
    }

    fout.open("inputs/sub" +getSubNo(no)+"/"+ "in." + toStr(no) + ".txt");

        fout << n << " " << m << endl;
        for (int i = 0; i < n; i ++) {
            fout << grid[i] << endl;
        } fout << endl;
        
    fout.close();
};

signed main() {

    ios_base:: sync_with_stdio(false);
    cin.tie(0);
    
    srand (time(NULL));

    ifstream fin;
    fin.open("in");

    int no = 0;
    while (fin >> n >> m >> limit) {
        test_generate(++no);
    }
    fin.close();
    return 0;
}