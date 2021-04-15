#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define nl '\n'
#define ff first
#define ss second

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;

tuple <int,int,int> pixel;

string answers[4] = { "radial", "horizontal", "vertical", "angled" };

int filtered[300][300][3];

void med(int img[300][300][3]){

	for(int i=0;i<=295;i++){
		for(int j=0;j<=295;j++){
			vi r,g,b;
			for(int x=i;x<i+5;x++){
				for(int y=j;y<j+5;y++){
					r.pb(img[x][y][0]);
					g.pb(img[x][y][1]);
					b.pb(img[x][y][2]);
				}
			}
			sort(r.begin(), r.end());
			sort(g.begin(), g.end());
			sort(b.begin(), b.end());
			filtered[i+2][j+2][0]=r[12];
			filtered[i+2][j+2][1]=g[12];
			filtered[i+2][j+2][2]=b[12];
		}
	}

}

bool close(int p1[3], int p2[3]){
	int d1=p1[0]-p2[0];
	int d2=p1[1]-p2[1];
	int d3=p1[2]-p2[2];
	int ac=30;
	if(d1 <=ac and d1>=-ac and d2<=ac and d2>=-ac and d3<=ac and d3>=-ac){
		return 1;
	}
	else return 0;
}

string solve(int img[300][300][3]){

	//ofstream mf;
	//mf.open("oout.txt");

    int tl[3]={img[2][2][0],img[2][2][1],img[2][2][2]};
    int tr[3]={img[2][297][0],img[2][297][1],img[2][297][2]};
    int bl[3]={img[297][2][0],img[297][2][1],img[297][2][2]};
    int br[3]={img[297][297][0],img[297][297][1],img[297][297][2]};
    //cout << tl[0] << " " << tl[1] << " " << tl[2] << nl;
    //cout << tr[0] << " " << tr[1] << " " << tr[2] << nl;
    //cout << bl[0] << " " << bl[1] << " " << bl[2] << nl;
   // cout << br[0] << " " << br[1] << " " << br[2] << nl;
    //rd
    if(close(tl,tr) and close(tl,br) and close(tl,bl)){
    	return answers[0];
    }
    //ag
    if(close(tl,br) or close(bl,tr)){
    	return answers[3];
    }
    //hz
    if(close(bl,tl) or close(tr,br)){
    	return answers[1];
    }
    if(close(tl,tr) or close(bl,br)){
    	return answers[2];
    }
    

    return "0";

   // mf.close();
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	ofstream mf;
	mf.open("oout.txt");
	
    int dots[300][300][3];
    string result;

    
    for(int i = 0 ; i < 300 ; i++){
        for(int j = 0 ; j < 300 ; j++){
            for(int k = 0 ; k < 3 ; k++){
                cin >> dots[i][j][k];
            }
        }
    }
    med(dots);

    result = solve(filtered);
    cout << result << nl;
    mf << result << endl;
    mf.close();

    return 0;
}