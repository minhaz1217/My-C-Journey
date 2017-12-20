#include<iostream>
using namespace std;
int main(){
    int n,d,counter = 0,i,maxCounter = 0,day;
    cin >> n>> d;
    string str;
    while(d--){
        cin >>str;
        for(i=0;str[i];i++){
            if(str[i] =='0'){
                day = d;
                counter++;
                if(counter > maxCounter){
                    maxCounter = counter;
                }
                break;
            }
        }
        if(day!=d){
            counter = 0;
        }
    }
    cout << maxCounter;
	return 0;
}
