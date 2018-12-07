#include<bits/stdc++.h>
using namespace std;
#define cc(a) cout << a << endl;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b  << " : " << c << endl;

int main(){
    long long int sum, curr, target,a,flag,n,i;
    sum =1;
    curr= 1;
    target = pow(2,31);
    //msg("TARGET", target)
    vector<long long int > vec;
    while(1){
        if(sum > target){
        //if(sum >= 1000){
            //cc(sum)
            break;
        }
        vec.push_back(sum);
        //msg(sum, curr)
        sum = sum + curr;
        curr++;
    }
    cin >> n;
    for(i=0;i<n;i++){
        cin >> a;
        flag = binary_search(vec.begin(), vec.end(),a);
        cout << flag << " ";
    }
    cout << endl;

    return 0;
}
