#include<stdio.h>
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
    big = arr[0];
    secondbig = arr[0];
    bigPos = 0;
    secondBigPos = 0;
    for(i=0;i<k;i++){
        if(arr[i] > big){
            secondbig = big;
            secondBigPos = bigPos;
            big = arr[i];
            bigPos = i;
        }
    }
    //msg(big,secondbig);
    currLast = arr[0];
    printf("%d ", big);
    //cout << big << " ";
    for(i=k;i<n;i++){
        //msg2(arr[i],big,secondbig)
        if(arr[i] >= big){
            //cc("HI")
            secondbig = big;
            secondBigPos = bigPos;
            big = arr[i];
            bigPos = i;
        }
        if(i-k == bigPos){
            big=arr[i];
            bigPos = i;
            secondbig = arr[i];
            secondBigPos = i;

            for(j=i;j<i+k;j++){
                if(arr[j] > big){
                    secondbig = big;
                    secondBigPos = bigPos;
                    big = arr[j];
                    bigPos = j;
                }
            }
        }
        //cout << big << " " <<endl << endl;
    printf("%d ", big);

    }
    printf("\n");
    return 0;
}
