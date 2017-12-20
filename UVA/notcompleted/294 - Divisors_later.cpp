#include<iostream>
using namespace std;
#define check(a) cout<<a<< endl;
int main(){
    long long int tk,a,b,i,counter = 0,bigCounter[2] ={0,0},j;
    cin >> tk;
    //cout << tk << endl;
    while(tk--){
    	//cout << tk << endl;
        cin >> a >> b;
        bigCounter[0] = 0;
        bigCounter[1] = 0;
        for(i=a;i<=b;i++){
            counter = 0;
            for(j=1;j<=i;j++){
                if(i%j ==0){
                    counter ++;
                }
            }
            if(counter > bigCounter[1]){
                bigCounter[1] = counter;
                bigCounter[0] = i;
            }
        }
        cout << "Between " << a << " and "<< b << ", "<< bigCounter[0] << " has a maximum of "<<bigCounter[1]<<" divisors." << endl;
        if(cin.eof()){
        	break;
        }
    }

	return 0;
}
