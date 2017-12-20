#include<iostream>
#include<math.h>
using namespace std;
int main(){
    int num = 21,i,remain=0,oneCounter = 0,j;
    for(;;){
        cin >> num;
        if(num==0){
            break;
        }
        oneCounter = 0;
        remain = 0;
        for(i=0;pow(2,i) <= num;i++){}
        j=0;
        char arr[i+1];
        arr[j++] = '1';
        oneCounter++;
        remain = num - pow(2,i-1);
        for(i=i-2;i>=0;i--){
            if(pow(2,i) > remain){
                arr[j++] = '0';
            }else{
                arr[j++] = '1';
                oneCounter++;
                remain -= pow(2,i);
            }
        }
        arr[j] = NULL;
        cout << "The parity of " << arr << " is " << oneCounter << " (mod 2)." << endl;
    }
	return 0;
}
