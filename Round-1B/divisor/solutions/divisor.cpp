#include <iostream>
#include <cmath>

using namespace std;

int main(){
    long long n;

    cin >> n;

    long long m = sqrt(n);

    if(m*m == n){
        cout << "Bazar" << endl;
    }
    else {
        cout << "Orgio" << endl;
    }

    return 0;
}