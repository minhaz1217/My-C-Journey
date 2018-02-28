#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;

int main(){
    priority_queue<pair<int,int>, vector<pair<int,int> >, greater< pair<int,int> > >vec;
    int i,n,temp1,j,temp2;
    cin >> n;
    if(n%2 == 0){
        vec.push(make_pair(n/2,n/2));
    }else{
        vec.push(make_pair(n/2+1,n/2));
    }
    for(i=1;i<=n/2+1;i++){
        temp1 = i+1;
        temp2 = i;
        if(n%i == 0 && i!= 1){
            vec.push(make_pair(i,i));
        }
        for(j=2;;j++){


            if(temp1*j + temp2*(j-1) > n){
                break;
            }
            if(temp1 * j + temp2*j == n){
                    //cc("HI1")
                    //msg(temp1, temp2)
                vec.push(make_pair(temp1,temp2));
            }else if(temp1 *j + temp2 * (j-1) == n){
                //cc("HI2")
                //msg(temp1, temp2)
                vec.push(make_pair(temp1,temp2));
            }
        }
    }

    cout << n << ":" << endl;
    /*
    for(i=0;i<vec.size();i++){
        printf("%d,%d\n", vec[i].first, vec[i].second);
    }
    */
    pair<int,int> u,last;
    while(!vec.empty()){
        u = vec.top();
        vec.pop();
        if(u == last){
            continue;
        }
        printf("%d,%d\n", u.first, u.second);
        last = u;
    }


    return 0;
}
