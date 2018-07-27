#include<bits/stdc++.h>
using namespace std;
#define cc(a) cout << a << endl;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b  << " : " << c << endl;
void print(vector<long long int>vec ){
    for(int i=0;i<vec.size();i++){
        cout << vec[i] << " " ;
    }
    cout << endl;

}


int main(){
    long long int sz, a, p,qq,i,j, caseCounter =1;
    while(1){
        cin >> p >> qq;
        if(p == 0 && qq == 0){
            break;
        }
        cout << "Case " << caseCounter++ << ":" << endl;
        char c;
        vector<long long int>vec;
        vec.clear();
        if(p > 1000){
            for(i=1;i<=1000;i++){
                vec.push_back(i);
            }
        }else{
            for(i=1;i<=p;i++){
                vec.push_back(i);
            }
        }
        for(i=1;i<=qq;i++){
            cin >> c;
            //print(vec);
            if(c == 'E'){
                cin >> a;
                //cout << a << endl;
                sz = vec.size();
                for(j=0;j<sz;j++){
                    if(vec[j] == a){
                        vec.erase( vec.begin() + j);
                        break;
                    }
                }
                vec.insert(vec.begin(), a);

            }else{
                a = vec[0];
                cout << a << endl;
                vec.erase( vec.begin() + 0);
                vec.push_back(a);

            }
        }
    }


    return 0;
}
