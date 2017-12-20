//Presentation ERROR
// UVA 10189
#include<iostream>
using namespace std;
#define check(a) cout<<a<< endl;
int main(){
    char n,c;
    int a,b,i,j,p,q,caseCounter = 1;
    while(1){
        cin >> a >> b;
        if(a ==0 && b==0){
            break;
        }




        int mine[a][b];
        int field[a][b];



        for(i=0;i<a;i++){
            for(j=0;j<b;j++){
                field[i][j] = 48;
            }
        }

        for(i=0;i<a;i++){
            for(j=0;j<b;j++){
                cin >> n;
                if(n == '*'){
                    field[i][j] = 42;

                    if(i+1 < a && field[i+1][j] != 42){
                        field[i+1][j]++;
                    }
                    if(i-1 >=0 && field[i-1][j] != 42){
                        field[i-1][j]++;
                    }
                    if(j+1 < b && field[i][j+1] != 42){
                        field[i][j+1]++;
                    }
                    if(j-1 >=0 && field[i][j-1] != 42){
                        field[i][j-1]++;
                    }
                    if(j+1 <b && i+1 < a  && field[i+1][j+1] != 42){
                        field[i+1][j+1]++;
                    }
                    if(j+1 <b && i-1 >= 0 && field[i-1][j+1] != 42){
                        field[i-1][j+1]++;
                    }
                    if(j-1 >=0 && i-1 >= 0 && field[i-1][j-1] != 42){
                        field[i-1][j-1]++;
                    }
                    if(j-1>=0 && i+1 < a && field[i+1][j-1] != 42){
                        field[i+1][j-1]++;
                    }
                }
            }
        }
        cout << "Field #" << caseCounter++ <<":" << endl;
        for(i=0;i<a;i++){
            for(j=0;j<b;j++){
                c = field[i][j];
                cout << c;
            }
            cout << endl;
        }
        cout << endl;
    }
	return 0;
}
