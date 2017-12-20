#include<iostream>
using namespace std;
int main(){
    int m,n,i,j, rowSum = 0, columnSum =0 , totalSum = 0;
    cout << "Enter Row: ";
    cin >> m;
    cout << "Enter Column: ";
    cin >> n;
    int a[m][n];
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            cout << "Enter for: [" << i << "][" << j << "]: ";
            cin >> a[i][j];
        }
    }
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            rowSum += a[i][j];
            totalSum += a[i][j];
        }
        cout << "Sum of row " << i+1 << " is: " <<  rowSum << endl;
        rowSum =0;
    }
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            columnSum += a[j][i];
        }
        cout << "Sum of Column " << i+1 << " is: " << columnSum << endl;
        columnSum = 0;
    }
    cout << "Total sum is: " << totalSum << endl;
    return 0;
}
