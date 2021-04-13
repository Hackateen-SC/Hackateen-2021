#include <iostream>

using namespace std;

int main(){
    int n, q;
    int points[5] = {0};
    int dividers[5];
    string answers[5] = {"A", "U", "G", "C", "Z"};

    cin >> n;

    for(int i = 0 ; i < 5 ; i++){
        cin >> dividers[i];
    }

    for(int i = 0 ; i < n ; i++){
        cin >> q;

        for(int j = 0 ; j < 5 ; j++){
            if(q % dividers[j] == 0){
                points[j] += q;
                break;
            }
        }
    }

    int current_max = -1;
    int answer_index = -1;

    for(int i = 0 ; i < 5 ; i++){
        if(points[i] > current_max){
            current_max = points[i];
            answer_index = i;
        }
    }

    cout << answers[answer_index] << endl;

    return 0;
}