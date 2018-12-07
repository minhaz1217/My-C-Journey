#include<bits/stdc++.h>
using namespace std;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;

int counter;
void makeSum(int arr[], int pos, int curr, int ssize, int num, int currDiv){
    //msg(pos, currDiv)

    if(currDiv > 3){
        return;
    }
    int mySum = curr,i;
    int part = num/3;
    for(i=pos;i<ssize;i++){
        mySum += arr[i];
        //check(mySum)
        if(mySum == num && i == ssize-1){
            counter++;
        }else if(mySum == part*currDiv){
            //mySum += arr[i];
            if(mySum + arr[i+1] == part * currDiv){
                makeSum(arr, i+2, mySum, ssize, num, currDiv);
            }
            currDiv++;
        }
    }
}
void display(int arr[], int n){
    int i;
        for(i=0;i<n;i++){
            cout << arr[i] << " ";
        }
        cout << endl;
}


int main(){
    counter = 0;
    int n, sum, i,a;
    cin >> n;
    int arr[n];
    sum = 0;
    for(i=0;i<n;i++){
        cin >> arr[i];
        sum += arr[i];
    }

    if(n< 3){
        cout << 0 << endl;
    }else if(sum % 3 == 0 ){
        a = sum / 3;
        makeSum(arr, 0,0, n, sum, 1);
        display(arr, n);
        next_permutation(arr, arr+n);
        display(arr, n);
        next_permutation(arr, arr+n);
        display(arr, n);
    }else{
        cout << 0 << endl;
    }


    return 0;
}
