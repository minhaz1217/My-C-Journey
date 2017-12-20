#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;

int main(){
    int n, lights[3][3],i,j,arr[3][3],p,q;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            lights[i][j] = 1;
        }
    }

    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            cin >> arr[i][j];
        }
    }
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            n = arr[i][j];

            if(n%2 != 0){
    for(p=0;p<3;p++){
        for(q=0;q<3;q++){
            cout << lights[p][q];
        }
        cout << endl;
    }
    check(endl)
                if(i-1 >=0){
                    lights[i-1][j] = !lights[i-1][j];
                    if(j-1 >=0){
                        lights[i-1][j-1] = !lights[i-1][j-1];
                    }
                    if(j+1 <=3){
                        lights[i-1][j+1] = !lights[i-1][j+1];
                    }
                }
    for(p=0;p<3;p++){
        for(q=0;q<3;q++){
            cout << lights[p][q];
        }
        cout << endl;
    }
                if(i+1 <=3){
                    lights[i+1][j] = !lights[i+1][j];
                    if(j-1 >=0){
                        lights[i+1][j-1] = !lights[i+1][j-1];
                    }
                    if(j+1 <=3){
                        lights[i+1][j+1] = !lights[i+1][j+1];
                    }
                }
    for(p=0;p<3;p++){
        for(q=0;q<3;q++){
            cout << lights[p][q];
        }
        cout << endl;
    }
                if(j-1 >=0){
                    lights[i][j-1] = !lights[i][j-1];
                }
                if(j+1 <=3){
                    lights[i][j+1] = !lights[i][j+1];

                }
    for(p=0;p<3;p++){
        for(q=0;q<3;q++){
            cout << lights[p][q];
        }
        cout << endl;
    }
                lights[i][j] = !lights[i][j];
            }

        }
    }


   for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            cout << lights[i][j];
        }
        cout << endl;
    }


    return 0;
}
