#include <iostream>

using namespace std;

string answers[4] = { "radial", "horizontal", "vertical", "angled" };

int c[3][3][3];
int d = 10;

bool equal(int x1, int y1, int x2, int y2){
    if(abs(c[x1][y1][0] - c[x2][y2][0]) > d)
        return 0;
    if(abs(c[x1][y1][1] - c[x2][y2][1]) > d)
        return 0;
    if(abs(c[x1][y1][2] - c[x2][y2][2]) > d)
        return 0;
    return 1;
}

string solve(int img[300][300][3]){

    for(int i = 0; i < 300; ++i)
        for(int j = 0; j < 300; ++j)
            for(int k = 0; k < 3; ++k)
                c[i / 100][j / 100][k] += img[i][j][k];
    for(int i = 0; i < 3; ++i)
        for(int j = 0; j < 3; ++j)
            for(int k = 0; k < 3; ++k)
                c[i][j][k] /= 10000;
    if(equal(0, 0, 1, 0) && equal(1, 0, 2, 0) &&
        equal(0, 1, 1, 1) && equal(1, 1, 2, 1) &&
        equal(0, 2, 1, 2) && equal(1, 2, 2, 2))
        return answers[1];
    if(equal(0, 0, 0, 1) && equal(0, 1, 0, 2) &&
        equal(1, 0, 1, 1) && equal(1, 1, 1, 2) &&
        equal(2, 0, 2, 1) && equal(2, 1, 2, 2))
        return answers[2];
    if(equal(1, 0, 0, 1) && equal(1, 2, 2, 1) &&
        equal(2, 0, 1, 1) && equal(1, 1, 0, 2))
        return answers[3];
    if(equal(0, 1, 1, 2) && equal(1, 0, 2, 1) && 
        equal(0, 0, 1, 1) && equal(1, 1, 2, 2))
        return answers[3];
    return answers[0];
}

int main(){
    int dots[300][300][3];
    string result;
    
    for(int i = 0 ; i < 300 ; i++){
        for(int j = 0 ; j < 300 ; j++){
            for(int k = 0 ; k < 3 ; k++){
                scanf("%d",&dots[i][j][k]);
            }
        }
    }

    result = solve(dots);
    
    cout << result << endl;

    return 0;
}