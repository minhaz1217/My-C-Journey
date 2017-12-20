#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;

int main(){
    int n, lights[3][3],i,j;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            lights[i][j] = 1;
        }
    }
    check("HI1")
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            cin >> n;
            //cout << n << endl;
            check(1)
            //msg(i,j)
            if(n%2 == 1){
                if(i-1 >=0){
                    lights[i-1][j] = !lights[i-1][j];
                    if(j-1 >=0){
                        lights[i-1][j-1] = !lights[i-1][j-1];
                    }
                    if(j+1 <=3){
                        lights[i-1][j+1] = !lights[i-1][j+1];
                    }
                }
            check(2)
            //msg(i,j)
                if(i+1 <=3){
                    lights[i+1][j] = !lights[i+1][j];
                    if(j-1 >=0){
                        lights[i+1][j-1] = !lights[i+1][j-1];
                    }
                    if(j+1 <=3){
                        lights[i+1][j+1] = !lights[i+1][j+1];
                    }
                }
            check(3)
            //msg(i,j)
                if(j-1 >=0){
                    lights[i][j-1] = !lights[i][j-1];
                }
                if(j+1 <=3){
                    lights[i][j+1] = !lights[i][j+1];

                }
            check(4)
            //msg(i,j)

                lights[i][j] = !lights[i][j];
            }
        }
    }
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            cout << lights[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
