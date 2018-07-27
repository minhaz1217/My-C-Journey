#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;

int f[10];
int fact(int n){
    if(n==0 || n == 1){
        return 1;
    }
    return n * fact(n-1);
}

int main(){



    /*
    long long int sum=1,nw;
    string str = "999999999";
    long long int a = 999999999999999;

    int i,j,k,v,n,origin;

    for(i=0;i<10;i++){
        f[i] = fact(i);
        msg(i,fact(i))
    }
    vector<int>vec[10];
    vector<int>tempq[10];
    for(j=0;j<10;j++){
        vec[j].push_back(0);
    }
    for(i = 2; i<10; i++){
        queue<pair<int,long long int> >q;
        map<int,int>visited;
        q.push( make_pair(f[i], 0) );

        while(!q.empty()){
            n = q.front().first;
            nw = q.front().second;
            //msg(n,nw)
            q.pop();
            if(n ==1){
                if(vec[i][0] < nw){
                    vec[i][0] = nw;
                }
            }
            for(v = 2;v<10;v++){
                if(n%f[v] == 0 && n >= f[v]){
                    //msg2("V", n, f[v])
                   //msg(nw,v)
                    q.push( make_pair(n / f[v], nw*10 +v ) );
                }
            }
        }
    }
    for(i=0;i<10;i++){
        msg(i, vec[i][0])
    }
    */
    vector<int>num[10],my;
    long long int a,n,k,i;

    num[2].push_back(2);
    num[3].push_back(3);
    num[5].push_back(5);
    num[7].push_back(7);
    num[4].push_back(3);
    num[4].push_back(2);
    num[4].push_back(2);
    num[6].push_back(5);
    num[6].push_back(3);
    num[8].push_back(7);
    num[8].push_back(2);
    num[8].push_back(2);
    num[8].push_back(2);
    num[9].push_back(7);
    num[9].push_back(3);
    num[9].push_back(3);
    num[9].push_back(2);

    cin >> a;
    cin >> n;
    while(n!=0){
        k = n%10;
        if(k>1){
            for(i=0;i<num[k].size();i++){
                my.push_back(num[k][i]);
            }
        }
        n = n/10;
    }
    sort(my.begin(), my.end());
    for(i=my.size()-1;i>=0;i--){
        cout << my[i];
    }
    cout << endl;

    return 0;
}
