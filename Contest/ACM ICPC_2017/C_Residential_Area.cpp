# include <iostream>
# include <cstdio>
using namespace std;


int arr[15][15];

int findAll(int a, int b, int y, int x){
  ////    cout << "Iam" << a << " ,"  << y << " : " << x << endl;
    int abb[11],i,j;
    for(i=0;i<11;i++){
        abb[i] = 0;
    }

    for(i=a;i<a+y;i++){
        for(j=b;j<b+x;j++){
            if(abb[arr[i][j]] == 1){
                return 0;
            }else{
                abb[arr[i][j]]=1;
            }
        }
    }


    return 1;
}

int main()
{
    int tc, n,i,j, caseCounter =1, sum;
    scanf("%d", &tc);

    while(tc--)
    {
        scanf("%d", &n);
        sum = 0;
        for(i=0; i<n; i++)
        {
            for(j=0; j<n; j++)
            {
                scanf("%d", &arr[i][j]);
            }
        }
        if(n < 5){
            printf("Case %d: %d\n", caseCounter++, sum);
        }else{
            for(i=0; i<n; i++){
                for(j=0; j<n; j++){

                    if(n-i >=2 && n-j >= 5){
                        //c(1)
                        sum += findAll(i,j, 2,5);
                    }

                    if(n-i >= 5 && n-j >= 2){
                        //c(2)
                        sum += findAll(i,j, 5,2);
                    }

                    if(n-i >= 10 && n-j >= 1){
                        //c(3)
                        sum += findAll(i,j, 10,1);

                    }

                    if(n-i >= 1 && n-j >= 10){
                        //c(4)
                        sum += findAll(i,j, 1,10);
                    }
                }
            }
            printf("Case %d: %d\n", caseCounter++, sum);
        }
        //cout << sum << endl;


    }


    return 0;
}
