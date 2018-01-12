#include<iostream>
using namespace std;
int main(){
    int a,b,counter=0, bigSeries[2]={0,0},i,temp;
    for(;;){
        cin >> a >> b;
        if(a==0 && b==0){
            break;
        }
        if(a>b){
            temp = a;
            a = b;
            b = temp;
        }
        for(i=a;i<=b;i++){
            temp = i;
            counter = 0;
            while(temp!=1){
                if(temp%2==0){
                    temp = temp/2;
                }else{
                    temp = 3*temp+1;
                }
                counter++;
            }
            if(counter >bigSeries[1]){
                bigSeries[1] = counter;
                bigSeries[0] = i;
            }
        }
        cout << "Between " << a <<" and "<< b<<", "<<bigSeries[0] <<" generates the longest sequence of "<< bigSeries[1] <<" values." << endl;
    }

	return 0;
}
