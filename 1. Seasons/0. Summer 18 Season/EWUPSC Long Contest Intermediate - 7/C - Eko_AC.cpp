#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;
#define msg3(a,b,c,d) cout << a << " : " << b << " : " << c << " : " << d << endl;

vector<long long int>vec,vec2;
long long int sz,n,m,a;
long long int calc(long long int val){
    long long int sum = 0,myPos,mySum;
    vector<long long int>::iterator it = upper_bound(vec.begin(), vec.end(), val);
    //msg2("LOW",it- vec.begin(), *it)
    //long long int val = vec[index];
    for(int i=it-vec.begin();i<sz;i++){
        if(vec[i] > val){
            myPos = i;
            break;
        }
    }
    a = sz - myPos;
    //msg2("Pos", myPos, a)
    mySum = vec2[sz] - vec2[myPos];
    //msg(a,mySum)
    mySum = mySum - a*val;
    return mySum;

}

long long int binarySearch(){
    long long int l = 0, r = vec[sz-1];
    long long int mid, prev = l;

    while(l<r && mid!= prev){
        //msg3(l, r,mid, prev)

        mid = (l+r)/ 2;
        long long int sum = calc(mid);
        //long long int sum2 = calc(l), sum3 = calc(r);
        if(sum == prev){
            return l;
        }
        if(sum == m){
            return mid;
        }else if(sum > m){
            l = mid;
        }else{
            r = mid;
        }
        prev = sum;
        /*
        if(sum == m){
            return mid;
        }else if(calc(l) == m){
            return l;
        }else if(calc(r) == m){
            return r;
        }else if(sum>m){
            l = mid;
        }else{
            r = mid;
        }
        */
        //msg("SUM", sum)
    }
    return l;
}
int main(){

    scanf("%lld%lld", &n, &m);
    //cin >> n >> m;
    long long int sm = 0;
    for(int i=0;i<n;i++){
        scanf("%lld", &a);
        //cin >> a;
        vec.push_back(a);
    }
    sort(vec.begin(),vec.end());
    sz = n;
    vec2.push_back(0);
    for(int i=0;i<sz;i++){
        sm += vec[i];
        vec2.push_back(sm);
    }
    printf("%lld\n", binarySearch());
    //cout << binarySearch() << endl;
    //cc(binarySearch());
    return 0;
}
