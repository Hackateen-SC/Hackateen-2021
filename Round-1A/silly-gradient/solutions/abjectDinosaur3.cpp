#include <bits/stdc++.h>
#define FR(i, n) for(int i = 0; i < n; i++)
#define ifor(i, j, k) FR(i, 300) FR(j, 300) FR(k, 3)
#define VI vector<int>
#define VII vector<VI>
#define ijk img[i][j][k]

using namespace std;
string answers[4] = { "radial", "horizontal", "vertical", "angled" };

bool radia(int img[300][300][3]){
	VII h(3, VI(300, 0));
	ifor(i, j, k){
		h[k][i] += ijk;
	}
	FR(k, 3){
		FR(i, 300){
			int sm = abs(h[k][i] - h[k][299-i]);
			if(sm > 3000) return false;
		}
	}
	VII v(3, VI(300, 0));
	ifor(i, j, k){
		v[k][j] += ijk;
	}
	FR(k, 3){
		FR(j, 300){
			int sm = abs(v[k][j] - v[k][299-j]);
			if(sm > 3000) return false;
		}
	}
	return true;
}

bool horiz(int img[300][300][3]){
	VII h(3, VI(300, 0));
	ifor(i, j, k){
		h[k][i] += ijk;
	}
	FR(k, 3){
		FR(i, 300){
			int sm = abs(h[k][i] - h[k][0]);
			if(sm > 3000) return false;
		}
	}
	return true;
}
bool verti(int img[300][300][3]){
	VII v(3, VI(300, 0));
	ifor(i, j, k){
		v[k][j] += ijk;
	}
	FR(k, 3){
		FR(j, 300){
			int sm = abs(v[k][j] - v[k][0]);
			if(sm > 3000) return false;
		}
	}
	return true;
}

//solution for 15 points assuming no noise
string solve(int img[300][300][3]){
	if(radia(img)) return answers[0];
	if(horiz(img)) return answers[1];
	if(verti(img)) return answers[2];
	return answers[3];
}

int main(){
    int dots[300][300][3];
    string result;
	ifor(i, j, k){
		cin>>dots[i][j][k];
	}
    result = solve(dots);    
    cout << result << endl;

    return 0;
}
