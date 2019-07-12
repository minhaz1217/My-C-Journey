    /*
    Minhazul Hayat Khan
    minhaz1217.github.io
    Website: www.minhazul.com
    EWU, Bangladesh
    Problem Name:
    Problem Link: https://vjudge.net/contest/308147#problem/D
    Date : 05 / July / 2019
    Comment: bisection problem, easy to grasp once you understand the 10^5 nLog(n) complexity of it.
    */
    #include<bits/stdc++.h>
    //#include<iostream>
    using namespace std;
    #define DEBUG 1
    #define check(a) DEBUG==1?(cout << a << endl):null;
    #define cc(a) DEBUG==1?(cout << a << endl):cout<<"";
    #define msg(a,b) DEBUG==1?(cout << a << " : " << b << endl):cout<<"";
    #define msg2(a,b,c) DEBUG==1?(cout << a << " : " << b << " : " << c << endl):cout<<"";
    #define msg3(a,b,c,d) DEBUG==1?(cout << a << " : " << b << " : " << c << " : " << d << endl):cout<<"";
    #define msg4(a,b,c,d,e) DEBUG==1?(cout << a << " : " << b << " : " << c << " : " << d << " : " << e << endl):cout<<"";
    #define _INIT ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);


    int main(){
        long long int tc,n,c,a,currMx, counter, sum , found,l,r,mid;
        cin >> tc;
        while(tc--){
            cin >> n >> c;
            vector<long long int> vec;
            for(int i=0;i<n;i++){
                cin >> a;
                vec.push_back(a);
            }
            sort(vec.begin(),vec.end());
            l = 0;
            r = vec[n-1] - vec[0];
            currMx = INT_MIN;
            c--;
            while(l-r != 0){
                mid = (l+r ) /2;
                sum = 0;
                found = 0;
                counter = 0;
                for(int i=1;i<vec.size();i++){
                    sum += vec[i] - vec[i-1];
                    if(sum>=mid){
                        counter++;
                        sum = 0;
                    }
                    if(counter == c){
                        found = 1;
                        currMx = mid;
                        break;
                    }
                }

                //msg("FN", sum)

                //msg3(l,r,mid,found)
                if(found == 0){
                    r = mid;
                }else{
                    l = mid+1;
                }
            }
            cout << currMx << endl;
        }

        return 0;
    }
