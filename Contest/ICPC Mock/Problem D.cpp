#include<iostream>
using namespace std;

long long int totalBoxNeeded = 0;
void merge(long long int arr[], long long int l, long long int m, long long int r)
{
    long long int i, j, k;
    long long int n1 = m - l + 1;
    long long int n2 =  r - m;

    /* create temp arrays */
    long long int L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
/* l is for left index and r is right index of the
   sub-array of arr to be sorted */
void mergeSort(long long int arr[], long long int l, long long int r)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        long long int m = l+(r-l)/2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);

        merge(arr, l, m, r);
    }
}
void printArray(long long int A[], long long int size)
{
    long long int i;
    for (i=0; i < size; i++)
        cout << A[i] << endl;
}
int howMany(long long int arr[],long long int ending){
        long long int secondBox[ending],i;
        long long int secondBoxCounter = 0;
        for(i=1;i<ending-1;i++){
            if(arr[i] == arr[i-1]){
                secondBox[secondBoxCounter++] = arr[i];
            }
        }
        if(secondBoxCounter == 0){
            return 0;
        }
        totalBoxNeeded++;
        howMany(secondBox, secondBoxCounter);
}
int main(){
    long int tc,n, num,i,secondBoxCounter =0,caseCounter = 1;
    cin >> tc;
    while(tc--){
        cin >> n;
        long long int box[n];
        for(i=0;i<n;i++){
            cin >> num;
            box[i] = num;
        }
        mergeSort(box, 0, sizeof(box)/sizeof(box[0])-1);
        howMany(box, sizeof(box)/sizeof(box[0]));
        cout << "Case " << caseCounter++ <<": "<< totalBoxNeeded << endl;
        totalBoxNeeded=0;
    }
	return 0;
}
