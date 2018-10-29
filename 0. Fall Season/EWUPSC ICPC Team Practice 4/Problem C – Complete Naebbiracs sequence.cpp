#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;
#define msg3(a,b,c,d) cout << a << " : " << b << " : " << c << " : " << d << endl;

int main(){
    int k,n,a,zeros=1, gotZero=1,maxFreq,l,flag,counter=0,myFound = 0,u,mx,mn;
    cin >> k >> n;
    int arr[k+1];
    vector<int>ins, del;
    for(int i=1;i<=k;i++){
        arr[i] = 0;
    }
    //freq.assign(104004,0);
    for(int i=0;i<n;i++){
        cin >> a;
        arr[a]++;
    }

    zeros = 0;
    for(int i=1;i<=k;i++){
        if(arr[i] == 0){
            zeros++;
            gotZero = i;
        }
        //freq[arr[i]]++;
    }

    if(zeros >= 2){
        cout << "*" << endl;
        return 1;
    }else if(zeros == 1){
        if(arr[1] == k-1){
            cout << "+" << gotZero << endl;
            return 1;
        }else{
            cout << "*" << endl;
            return 1;
        }
    }else{

        mx = INT_MIN;
        mn = INT_MAX;

        for(int i=1;i<=k;i++){
            mx = max(arr[i], mx);
            mn = min(arr[i], mn);
        }
        //msg(mx,mn)
        for(int i=1;i<=k;i++){
            //msg(i,arr[i])
            if(arr[i] < mx){
                //cc("HI")
                ins.push_back(i);
            }
            if(arr[i] > mn){
                del.push_back(i);
            }

        }

        if(ins.size() == 1){
            arr[ins.back()]++;
            l = arr[1];
            flag = 1;
            for(int i=1;i<=k;i++){
                if(arr[i] != l){
                    flag = 0;
                    break;
                }
            }
            if(flag == 1){
                cout << "+" << ins.back() << endl;
                return 1;
            }else{
                cout << "*" << endl;
                return 1;
            }
        }
        if(del.size() == 1){
            arr[del.back()]--;
            l = arr[1];
            flag = 1;
            for(int i=1;i<=k;i++){
                if(arr[i] != l){
                    flag = 0;
                    break;
                }
            }
            if(flag == 1){
                cout << "-" << del.back() << endl;
                return 1;
            }else{
                cout << "*" << endl;
                return 1;
            }
        }

        counter= 0;
        myFound = 0;
        for(int i=0;i<del.size() && !myFound ;i++){
            u = del[i];
            for(int j=0;j<ins.size();j++){
                if( ins[j] == u){
                    flag = 0;
                    myFound =  u;
                    break;
                }
            }
        }
        for(int i=0;i<ins.size();i++){
            if(ins[i] != myFound){
                arr[ins[i]]++;
                counter++;
            }
        }
        for(int i=0;i<del.size();i++){
            if(del[i] != myFound){
                arr[del[i]]--;
                counter++;
            }
        }
        if(counter > 2){
            cout << "*" << endl;
            return 1;
        }else{
            l = arr[1];
            flag = 1;
            for(int i=1;i<=k;i++){
                if(arr[i] != l){
                    flag = 0;
                    break;
                }
            }
            if(flag == 1){
                for(int i=0;i<del.size();i++){
                    if(del[i] != myFound){
                        cout << "-" << del[i] << " ";
                    }
                }
                for(int i=0;i<ins.size();i++){
                    if(ins[i] != myFound){
                        cout << "+" << ins[i] << " ";
                    }
                }
                cout << endl;


                return 1;
            }else{
                cout << "*" << endl;
                return 1;
            }

        }


    }


    return 0;
}
