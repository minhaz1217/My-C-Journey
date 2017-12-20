#include <bits/stdc++.h>
using namespace std;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;


#define MX 1000
#define INFINITY 999999.00


double e[MX][MX] = {0}, w[MX][MX] = {0};
int root[MX][MX] = {0};
double q[MX];
double p[MX];
int keys[MX];
FILE *fwp;
void OBSTwithDecoys(int n)
{
    cout << "\nOptimal Binary Search Tree With Decoys." << endl;
    fprintf(fwp, "\nOptimal Binary Search Tree With Decoys.\n");
    int i,j,k,l,r;
    double temp;

    for(i=0;i< n+2;i++){
        for(j=0;j<n+1;j++){
            e[i][j] = 0;
            w[i][j] = 0;
        }
    }
    for(i=0;i< n+1;i++){
        for(j=0;j<n+1;j++){
            root[i][j] = 0;
        }
    }

    //Construct weight matrix W
    for(i = 1; i <= n+1; i++)
    {
        e[i][i-1] = q[i-1];
        w[i][i-1] = q[i-1];
    }
    for(l=1;l<= n;l++){
        for(i=1;i<=n-l+1;i++){
            j = i+l-1;
            e[i][j] = INFINITY;
            w[i][j] = w[i][j-1] + p[j] + q[j];
            for(r=i;r<=j;r++){
                temp = e[i][r-1] + e[r+1][j] + w[i][j];
                if(temp < e[i][j]){
                    e[i][j] = temp;
                    root[i][j] = r;
                }
            }
        }
    }
    cout << "The cost matrix: " << endl;
    fprintf(fwp, "The cost matrix: \n");
    for(i=0;i<=n+1;i++){
        for(j=0;j<=n;j++){
            printf("%3.2lf ", e[i][j]);
            fprintf(fwp, "%3.2lf ", e[i][j]);
            //cout << cost[i][j];
        }
        cout << endl;
        fprintf(fwp, "\n");
    }
    cout << "The root matrix: " << endl;
    fprintf(fwp, "The root matrix: \n");
    for(i=0;i<=n;i++){
        for(j=0;j<=n;j++){
            printf("%3d ", root[i][j]);
            fprintf(fwp,"%3d ", root[i][j]);
            //cout << cost[i][j];
        }
        cout << endl;
        fprintf(fwp, "\n");
    }
    cout << "Total cost of this OBST: " << e[1][n] << endl;
    fprintf(fwp,"\nTotal cost of this OBST: %3.2lf\n",e[1][n] );
}

void OBSTwithoutDecoys(int n){
    cout << "\nOptimal Binary Search Tree Without Decoys." << endl;
    fprintf(fwp, "\nOptimal Binary Search Tree Without Decoys.\n");
    int i,j,k,l,r;
    double temp;
    //Initialize all to zeros
    for(i=0;i< n+2;i++){
        for(j=0;j<n+1;j++){
            e[i][j] = 0;
            w[i][j] = 0;
        }
    }
    for(i=0;i< n+1;i++){
        for(j=0;j<n+1;j++){
            root[i][j] = 0;
        }
    }
    for(i=1;i<=n+1;i++){
        e[i][i-1] = 0;
        //e[i][i-1] = q[i-1];
        w[i][i-1] = 0;
        //w[i][i-1] = q[i-1];
    }
    for(l=1;l<= n;l++){
        for(i=1;i<=n-l+1;i++){
            j = i+l-1;
            e[i][j] = INFINITY;
            w[i][j] = w[i][j-1] + p[j] + q[j];
            for(r=i;r<=j;r++){
                temp = e[i][r-1] + e[r+1][j] + w[i][j];
                if(temp < e[i][j]){
                    e[i][j] = temp;
                    root[i][j] = r;
                }
            }
        }
    }
    cout << "The cost matrix: " << endl;
    fprintf(fwp, "The cost matrix: \n");
    for(i=0;i<=n+1;i++){
        for(j=0;j<=n;j++){
            printf("%3.2lf ", e[i][j]);
            fprintf(fwp, "%3.2lf ", e[i][j]);
            //cout << cost[i][j];
        }
        cout << endl;
        fprintf(fwp, "\n");
    }
    cout << "The root matrix: " << endl;
    fprintf(fwp, "The root matrix: \n");
    for(i=0;i<=n;i++){
        for(j=0;j<=n;j++){
            printf("%3d ", root[i][j]);
            fprintf(fwp,"%3d ", root[i][j]);
            //cout << cost[i][j];
        }
        cout << endl;
        fprintf(fwp, "\n");
    }
    cout << "Total cost of this OBST: " << e[1][n] << endl;
    fprintf(fwp,"Total cost of this OBST: %3.2lf\n",e[1][n] );
}
int main()
{
    int i, k, numberOfKeys, choice1;
    char fileName[]= "data4.txt";
    char outputFileName[] = "output.txt";
    FILE *fp;
    fp = fopen(fileName, "r");
    fwp = fopen(outputFileName , "w");

    while(1){
        cout << "\nSelect Option: " << endl;
        cout << "1. Build OBST with decoys(wrong searches)." << endl;
        cout << "2. Build OBST without decoys(wrong searches)." << endl;
        cout << "3. Exit." << endl;
        fscanf(fp, "%d", &choice1);
        cout << "Choice: " << choice1 << endl;
        //cin >> choice1;


        if(choice1 == 1){
            cout << "\nEnter the number of keys: ";
            fscanf(fp, "%d", &numberOfKeys);
            cout << numberOfKeys << endl;
            //cin >> numberOfKeys;

            for(i = 1; i <= numberOfKeys; i++)
            {
                printf("Enter Key[%d]= ",i);
                fscanf(fp, "%d", &keys[i]);
                cout << keys[i] << endl;
                //cin >> keys[i];
                printf("Enter frequency for %d = ", keys[i]);
                fscanf(fp, "%lf", &p[i]);
                cout << p[i] << endl;
                //cin >> p[i];
            }
            for(i = 0; i <= numberOfKeys; i++){
                printf("Enter Dummy Key[%d] = ", i);
                fscanf(fp, "%lf", &q[i]);
                cout << q[i] << endl;
                //cin >> q[i];
            }
            OBSTwithDecoys(numberOfKeys);

        }else if(choice1 == 2){
            cout << "\nEnter the number of keys: ";
            fscanf(fp, "%d", &numberOfKeys);
            cout << numberOfKeys << endl;
            for(i = 1; i <= numberOfKeys; i++)
            {
                printf("Enter Key[%d]= ",i);
                fscanf(fp, "%d", &keys[i]);
                cout << keys[i] << endl;
                //cin >> keys[i];
                printf("Enter frequency for %d = ", keys[i]);
                fscanf(fp, "%lf", &p[i]);
                cout << p[i] << endl;
                //cin >> p[i];
            }
            OBSTwithoutDecoys(numberOfKeys);
        }else if(choice1 ==3){
            fclose(fp);
            fclose(fwp);
            system("PAUSE");
            exit(0);
        }else{
            cout << "Please enter a valid number" << endl;
            continue;
        }
    }
    system("PAUSE");
}
