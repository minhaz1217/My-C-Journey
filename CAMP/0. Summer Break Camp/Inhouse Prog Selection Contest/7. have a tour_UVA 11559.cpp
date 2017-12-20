#include<iostream>
#include<algorithm>
using namespace std;
// maximum possible weekend at different hotels
int main(){
    int person, budget, hotels, w,currSmall, hotelCost, hotelFound = 0,i,a,b,j,k,currCost, goUpto,totalCost;
    while(1){
        cin >> person;
        if(cin.eof()){
            break;
        }
        cin >> budget >> hotels >> w;
        hotelFound = 0;
        totalCost = 0;
        totalCost = budget;
        while(hotels--){
            cin >> a;
            for(i=0;i<w;i++){
                cin >> b;
                if(b >= person){
                    if(a * person <= totalCost){
                        totalCost = a*person;
                        hotelFound = 1;
                    }
                }
            }
        }
        /*
        for(i=0;i<hotels;i++){
            cin >> a;
            arr[i][0] = a;
            arr2[i] = arr[i][0];
            for(j=1;j<w+1;j++){
                cin >> b;
                arr[i][j] = b;
                if(b >= person){
                    if(a * person <= totalCost){
                        totalCost = a*person;
                        hotelFound = 1;
                    }
                }
            }
        }
        */
        if(hotelFound == 1){
            cout << totalCost << endl;
        }else{
            cout << "stay home" << endl;
        }

    }
    return 0;
}
