#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;

pair<string, int> mp(string ss, int ii){
    return pair<string,int>(ss,ii);
}

int main(){
    int i,n,a,cost,myCost,flag;

    //cout << str.size() << endl;
    cin >> n;
    string str("", 2*n), tempStr;
    for(i=0;i<2*n;i++){
        cin >> a;
        str[i] = '0'+a;
    }
    str[i+1] = '\0';

    queue< pair<string,int> >q;
    map<string, int>visited;
    n = n*2;
    char c1,c2,prev;
    int pf;
    q.push(mp(str,0));
    visited[str] = 1;
    while(!q.empty()){
        //msg(cost,str)
        str = q.front().first;
        cost = q.front().second;
        q.pop();
        flag = 1;
        prev = str[0];
        pf = 0;
        for(i=0;i<n-1;i++){
            if(pf){
                prev = str[i];
                pf = 0;
            }
            if(str[i+1]!= prev){
                flag = 0;
                break;
            }else{
                pf = 1;
                i++;
            }
        }
        if(flag == 1){
            //msg("HI", cost)
            myCost = cost;
            break;
        }
        for(i=0;i<n-1;i++){
            if(str[i] != str[i+1]){
            tempStr = str;
            c1 = tempStr[i];
            c2 = tempStr[i+1];
            tempStr[i] = c2;
            tempStr[i+1]= c1;
            //swap(tempStr[i],tempStr[i+1]);

            if(!visited[tempStr]){
                q.push( mp(tempStr, cost+1) );
                visited[tempStr] = 1;
            }
            }
        }
    }
    cout << myCost << endl;


    cout << str << endl;

    return 0;
}
