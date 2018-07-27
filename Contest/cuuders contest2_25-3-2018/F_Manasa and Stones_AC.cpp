#include<bits/stdc++.h>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a  << " : " << b << endl;
#define msg2(a,b,c) cout << a  << " : " << b << " : " << c << endl;
int main(){
    int tc,a,b,n,sz,valA,valB,i;
    cin >> tc;
    set<int>::iterator it;
    while(tc--){
        set<int>st;
        cin >> n>> a >> b;
        //msg2(a,b,n)
        //return 0;
        if(n==1){
            st.insert(a);
            st.insert(b);
        }else{
            valA = n-1;
            valB = 0;
            while(valB!=n){
                //msg(valA, valB)
                //cout << valA*a + valB*b << " ";
                st.insert(valA*a+ valB*b);
                valA--;
                valB++;
            }
        }
        //sort(vec.begin(), vec.end());
        for(it= st.begin();it!=st.end();it++){
            cout << *it<< " ";
        }
        cout << endl;

/*
        sz = vec.size();
        cout << vec[0];
        for(i=1;i<sz;i++){
            cout << " "<< vec[i];
        }
        cout << endl;
*/
    }
    return 0;
}
