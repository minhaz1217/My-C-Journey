#include<stdio.h>
#include<math.h>
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;

int main(){
    int n,i,k,big,secondbig,j,bigPos, secondBigPos,currLast;
    scanf("%d", &n);
    //cin >> n;
    int arr[n];
    for(i=0;i<n;i++){
        //cin >> arr[i];
        scanf("%d", &arr[i]);
    }
    //cin >> k;
    scanf("%d", &k);



    for(i=0;i<n-k+1;i++){
        big = arr[i];
        //printf("%d",big);
        for(j=i;j<i+k;j++){
            if(arr[j] > big){
                big = arr[j];
            }
        }
        printf("%d ", big);
    }


    printf("\n");
    return 0;
}
