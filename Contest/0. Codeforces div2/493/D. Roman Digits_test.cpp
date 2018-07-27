#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;

    int arr[] = {1,5,10,50};



int counter,dup = 0;
map<int,int>mp;
void print(stack<int>vec){
    //counter++;
    int a,sum =0;
    while(!vec.empty()){
        a= vec.top();
        sum += a;
        //cout << vec.top();
        vec.pop();
    }
    //cout << ": " << sum;
    if(!mp[sum]){
        mp[sum] = 1;
    }else{
        dup++;
        //cout << "DUPLICATE FOUND" << endl;
    }
    //cout << endl;
}
int n;
int dfs(stack<int>st){
    //msg(st.size(), n)
    if(st.size() == n){

        print(st);
        counter++;
        return 0;
        //st.pop();
    }
    int i;
    for(i=0;i<4;i++){
        if(st.size()==0){
            //msg("PUSHED", arr[i])
            st.push(arr[i]);
            dfs(st);
            st.pop();
        }
        if(st.size() > 0 && st.top() <= arr[i]){
            //msg(st.top(), arr[i])
            st.push(arr[i]);
            dfs(st);
            st.pop();
            //dfs(st, n);
            //st.pop();
        }
    }

}


int main(){
    int i,j;
    while(cin >> n){

        //cin >> n;
        stack<int>ll;
        counter=0;
        dup = 0 ;
        mp.clear();
        //ll.push(1);
        dfs(ll);
        msg("HOLLA", counter)
        msg("DUPLICATE", dup)
    }
    //cout << counter << endl;
    return 0;
}
