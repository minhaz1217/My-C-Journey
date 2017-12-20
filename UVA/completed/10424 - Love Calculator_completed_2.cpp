#include<iostream>
using namespace std;
int main(){
    int sum =0,num=0,len,t1,t2, arrCounter = 0;
    double arr[10000];
    string name1, name2;
    for(;;){
        sum = 0;
        getline(cin, name1);
        getline(cin, name2);
        if(cin.eof()){
            break;
        }
        for(len=0;name1[len];len++){
            if(name1[len]+0 >=65 && name1[len]+0 <= 90){
                sum += (name1[len]-64);
            }else if(name1[len]+0 >=97 && name1[len]+0 <= 122){
                sum += (name1[len]-96);
            }
        }
        while(sum>=10){
            num = sum;
            sum = 0;
            for(;num!=0;){
                sum += num%10;
                num /= 10;
            }
        }
        t1 = sum;
        sum = 0;
        for(len=0;name2[len];len++){
            if(name2[len]+0 >=65 && name2[len]+0 <= 90){
                sum += (name2[len]-64);
            }else if(name2[len]+0 >=97 && name2[len]+0 <= 122){
                sum += (name2[len]-96);
            }
        }
        while(sum>=10){
            num = sum;
            sum = 0;
            for(;num!=0;){
                sum += num%10;
                num /= 10;
            }
        }
        t2 = sum;
        arr[arrCounter] = t2 < t1 ? (static_cast<double>(t2)/static_cast<double>(t1))*100 : (static_cast<double>(t1)/static_cast<double>(t2))*100;
        //arr[arrCounter] = t2 < t1 ? (t2/t1)*100 : (t1/t2)*100;
        arrCounter++;
    }

    for(len=0;len<arrCounter;len++){
        cout.precision(2);
        cout<< fixed <<arr[len]<< " %" << endl;
    }
	return 0;
}
