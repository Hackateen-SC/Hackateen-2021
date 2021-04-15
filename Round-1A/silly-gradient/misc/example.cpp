#include <iostream>

using namespace std;

string answers[4] = { "radial", "horizontal", "vertical", "angled" };

string solve(int img[300][300][3]){
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