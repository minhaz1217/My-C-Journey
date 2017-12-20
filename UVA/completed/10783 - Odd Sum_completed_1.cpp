#include<iostream>
using namespace std;
int main(){
    int i, num1, num2, limit,j,result=0,trCounter = 0;
    cin >> limit;
    int totalResult[limit];
    for(i=1;i<=limit;i++){
        cin >> num1;
        cin >> num2;
        result = 0;
        for(j=num1;j<=num2;j++){
            if(j%2 != 0){
                result += j;
            }
        }
        totalResult[trCounter] = result;
        trCounter++;
    }
    for(i=1;i<=trCounter;i++){
        cout << "Case " << i << ": " << totalResult[i-1]<<endl;
    }
    return 0;
}
