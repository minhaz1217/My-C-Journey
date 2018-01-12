#include<iostream>
#include<math.h>
using namespace std;
int main(){
    int choice,i,arrCounter = 0;
    double u,v,a, t,s,arr[1000][2];
    for(;;){
        cin >> choice;
        if(choice ==0){
            break;
        }
        switch(choice){
        case 1:
            cin >> u >> v >> t;//s,a
            arr[arrCounter][1] = (v-u)/t;
            arr[arrCounter][0] = u*t + (.5*arr[arrCounter][1]*t*t);
            break;
        case 2:
            cin >> u >> v >>a;//s,t
            arr[arrCounter][1] = (v-u)/a;
            arr[arrCounter][0] = (u*arr[arrCounter][1]) + (0.5*a*arr[arrCounter][1]*arr[arrCounter][1]);
            break;
        case 3:
            cin >> u >> a  >> s;//v,t
            arr[arrCounter][0] = sqrt( (u*u) + (2*a*s) );
            arr[arrCounter][1] = (arr[arrCounter][0] - u )/a;

        break;
        case 4:
            cin >> v >> a >>s;//;u,t
            arr[arrCounter][0] = sqrt( (v*v) - (2*a*s) );
            arr[arrCounter][1] = (v - arr[arrCounter][0])/a;
            break;
        }
        arrCounter++;
    }

    for(i=0;i<arrCounter;i++){
        cout.precision(3);
        cout << "Case " << i+1 << ": " <<fixed << arr[i][0] << " " << arr[i][1] << endl;
    }


    return 0;
}
