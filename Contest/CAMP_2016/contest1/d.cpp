#include<bits/stdc++.h>
using namespace std;
int main(){
    int tc,a,cabs = 0,needed=0,oneCounter = 0, twoCounter = 0, threeCounter = 0, fourCounter = 0;
    cin >> tc;
    while(tc--){
        cin >> a;
        if(a == 1){
            oneCounter++;
        }else if(a == 2){
            twoCounter++;
        }else if(a == 3){
            threeCounter++;
        }else{
            fourCounter++;
        }
    }

    if(threeCounter >= oneCounter){
           oneCounter = 0;
           if(twoCounter %2 == 0){
                cabs = fourCounter + twoCounter/2  + threeCounter;
            }else{
                cabs = fourCounter + ((twoCounter-1)/2) + threeCounter + 1;
            }
    }else{
          oneCounter -= threeCounter;
           if(twoCounter %2 == 0){
                    cabs = fourCounter + twoCounter/2  + (oneCounter/4) + threeCounter + 1;
            }else{
                 if(oneCounter > 2){
                     oneCounter -=2;
                     cabs = fourCounter + (twoCounter-1)/2  + (oneCounter/4) + threeCounter + 2;
                }
                else{


                     cabs = fourCounter + (twoCounter-1)/2  + (oneCounter/4) + threeCounter + 1;

                }
            }
    }

        cout<<cabs<<endl;



    return 0;
}
