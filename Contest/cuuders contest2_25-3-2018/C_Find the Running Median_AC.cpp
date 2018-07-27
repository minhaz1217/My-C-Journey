#include<bits/stdc++.h>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a  << " : " << b << endl;
#define msg2(a,b,c) cout << a  << " : " << b << " : " << c << endl;



int main(){
    double i,n,l,r,mid,p,a,pos,sum;
    int mid1,mid2;
    int sz;



    vector<double>vec;
    /*
    vector<int>::iterator lt;
    vec.push_back(5);
    vec.push_back(6);
    vec.push_back(7);
    vec.insert(vec.begin(),10);
    lt = upper_bound(vec.begin(),vec.end(),4);
    vec.insert(lt, 500);
    cout << *lt << endl;
    for(i=0;i<vec.size();i++){
        cout << vec[i] << endl;
    }
    */

    cin >> n;
    for(p=0;p<n;p++){
        cin >> a;
        sz = vec.size();
        if(sz == 0){
            vec.push_back(a);
        }else if(vec.size()> 0){
            if(vec[sz-1] <= a){
                //cc("END")
                vec.push_back(a);
            }else if(vec[0] >= a){
                //cc("BEG")
                vec.insert(vec.begin(), a);
            }else{
                l = 0;
                r = sz-1;
                while(l<r){
                    mid = (l+r)/2;
                    if(vec[mid] <= a && vec[mid+1]>=a){
                        //cc("HI")
                        //pos = mid;
                        r = mid+1;
                        break;
                    }

                    if(a > vec[mid]){
                        l = mid;
                    }else{
                        r = mid;
                    }
                }
                pos = r;
                vec.insert(vec.begin()+pos, a);
                //msg(l,r)
            }
        }
        /*
        cc("DISPLAY")
        for(i=0;i<vec.size();i++){
            cout << vec[i] << " ";
        }
        cout << endl;
        */
        sz = vec.size();
        //msg("SIZE", sz)
        if(sz % 2==1){
            mid1 = floor(sz/2) + 1;
            //msg("MID1", mid1)
            sum = vec[mid1-1];
        }else{
            //sz = sz-1;
            mid1 = sz/2;
            mid2 = (sz/2) + 1;
            mid1--;
            mid2--;
            sum = (vec[mid1]+ vec[mid2])/2.00;
        }
       // msg("SUM", sum)
        printf("%.1lf\n", sum);


        continue;
    }

    return 0;
}
