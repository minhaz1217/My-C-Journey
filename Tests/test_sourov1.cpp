#include<iostream>
using namespace std;

main()
{

    int arr[5][6]={{34,56,4,10,45,3},{77,51,93,30,3,4},{5,52,87,76,5,34},{93,45,4,66,100,99},{89,39,85,79,75,76}};
    int ar[30][2]={0};
    int i,j,p,n,k=0,m=0;
    for(p=0;;p++)
    {
        k=0;
        cout<<endl<<"Enter Integer search key: ";
        cin>>n;
        for(i=0;i<5;i++)
        {
            for(j=0;j<6;j++)
            {
                if(arr[i][j]==n)
                {
                    ar[k][0]=i;
                    ar[k][1]=j;
                    k++;
                }
            }
        }
        if(k==0)
            cout<<"Value not found"<<endl;
        else
        {
            cout<<"Found in "<<k <<" locations: ";
            for(int a=0;a<k;a++){
                cout<< "["<<arr[a][0]<<"," <<arr[a][1]<<"]" << "  " ;
            }
            cout << endl;
        }

    }
}

