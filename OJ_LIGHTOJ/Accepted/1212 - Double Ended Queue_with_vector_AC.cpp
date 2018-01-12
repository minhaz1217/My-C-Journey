#include<bits/stdc++.h>
using namespace std;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;

int main(){
    vector<int>::iterator it;
    int tc,m,n,a,caseCounter =1;
    string str;
    cin >> tc;
    while(tc--){
        cin >> n >> m;

        vector<int>v;
        v.empty();
        cout << "Case "<< caseCounter++ << ":" << endl;

        while(m--){
            cin >> str;
            if(str=="pushLeft"){
                cin >> a;
                if(v.size() >= n){
                    cout << "The queue is full" << endl;
                }else{
                    cout << "Pushed in left: " << a << endl;
                    v.insert(v.begin(), a);
                }
            }else if(str=="pushRight"){
                cin >> a;
                if(v.size() >= n){
                    cout << "The queue is full" << endl;
                }else{
                    cout << "Pushed in right: " << a << endl;
                    v.insert(v.end(), a);
                }
            }else if(str=="popLeft"){
                if(v.size() == 0){
                    cout << "The queue is empty" << endl;
                }else{
                    it = v.begin();
                    cout << "Popped from left: " << *it << endl;
                    v.erase(v.begin());
                }

            }else if(str=="popRight"){
                if(v.size() == 0){
                    cout << "The queue is empty" << endl;
                }else{
                    it = v.begin() + v.size()-1;
                    cout << "Popped from right: " << *it << endl;
                    v.erase(it);
                }

            }
        }
    }



    return 0;
}
