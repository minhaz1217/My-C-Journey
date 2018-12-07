#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;

int main(){
    int tc, n, currMax, currMin, sum,a,flag=0;
    cin >> tc;
    while(tc--){
        cin >> n;
        sum = 0;
        flag = 0;
        while(n--){
            cin >> a;
            if(flag == 0){
                currMax = a;
                currMin = a;
                flag = 1;
            }
            sum = sum^a;
            currMax = max(sum , currMax);
            currMin = min(sum , currMin);
        }
        cout << currMax << " " << currMin << endl;
    }

    return 0;
}
