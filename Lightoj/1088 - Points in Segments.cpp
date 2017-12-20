#include<iostream>
#include<stdio.h>
#include<math.h>
#define msg(a,b) cout << a << " : " << b << endl;

using namespace std;
int main(){
    long long int tc,n,q,i,j,a,b,mid;
    cin >> tc;
    while(tc--){
        scanf("%lld %lld", &n, &q);
        long long int arr[n];
        for(i=0;i<n;i++){
            scanf("%lld", &arr[i]);
        }
        while(q--){
            scanf("%lld %lld", &a, &b);
            i=0;
            j= n;
            mid = i + (j-i)/2;
            while(i<=j){
                if(arr[mid]== a){
                      i= mid;
                        j= mid;
                      break;
                }
                if(arr[mid] < a){
                    i = mid+1;
                }
                if(arr[mid] > a){
                    j = mid -1;
                }
            mid = i + (j-i)/2;
            }
            a= mid;

            i=0;
            j= n;
            mid = i + (j-i)/2;
            while(i<=j){
                if(arr[mid]== a){
                      i= mid;
                    j= mid;
                      break;
                }
                if(arr[mid] < a){
                    i = mid+1;
                }
                if(arr[mid] > a){
                    j = mid -1;
                }
            mid = i + (j-i)/2;
            }
            b = mid;
            msg("a", a)
            msg("b", b)
        }
    }
}
