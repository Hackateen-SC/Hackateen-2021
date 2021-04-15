#include <iostream>
#include <cmath>
using namespace std;

int zuundeed[3],baruundeed[3],baruundood[3],zuundood[3];
int main(){
	int dots[300][300][3];
	for(int i = 0 ; i < 300 ; i++){
        for(int j = 0 ; j < 300 ; j++){
            for(int k = 0 ; k < 3 ; k++){
                cin >> dots[i][j][k];
            }
        }
    }
    
    int helbelzel = 15, hedbe=10;
    int shirheg = (hedbe*(hedbe+1))/2;
    
    for(int i = 0; i < hedbe; i++){
    	for(int j = 0; j < hedbe-i; j++)
			for(int k = 0; k < 3; k++){
				zuundeed[k]+=dots[i][j][k];	
				baruundeed[k]+=dots[i][299-j][k];
				baruundood[k]+=dots[299-i][299-j][k];
				zuundood[k]+=dots[299-i][j][k];	
			}
				
	}
    
    bool top=false,right=false,bottom=false,left=false;
    
	if(abs(zuundeed[0] - baruundeed[0])<helbelzel*shirheg && abs(zuundeed[1] - baruundeed[1])<helbelzel*shirheg && abs(zuundeed[2] - baruundeed[2])<helbelzel*shirheg){
		top = true;
	}
	if(abs(baruundeed[0] - baruundood[0])<helbelzel*shirheg && abs(baruundeed[1] - baruundood[1])<helbelzel*shirheg && abs(baruundeed[2] - baruundood[2])<helbelzel*shirheg){
		right = true;
	}
	if(abs(baruundood[0] - zuundood[0])<helbelzel*shirheg && abs(baruundood[1] - zuundood[1])<helbelzel*shirheg && abs(baruundood[2] - zuundood[2])<helbelzel*shirheg){
		bottom = true;
	}
	if(abs(zuundeed[0] - zuundood[0])<helbelzel*shirheg && abs(zuundeed[1] - zuundood[1])<helbelzel*shirheg && abs(zuundeed[2] - zuundood[2])<helbelzel*shirheg){
		left = true;
	}
	
	if(top && bottom){
		if(right && left) 	cout << "radial";
		else 				cout << "vertical";				
	}
	else{
		if(right && left) 	cout << "horizontal";
		else 				cout << "angled";
	}
}		

