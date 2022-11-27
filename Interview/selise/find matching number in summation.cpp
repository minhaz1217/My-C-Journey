#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> inputNumbers;
    map<int,int> present;
    int desiredNumber = 5,a;

    cin >> desiredNumber;

    for(int i=0;i<10;i++){
        cin >> a;
        inputNumbers.push_back(a);
    }

    for(int i=0;i<inputNumbers.size();i++){
        present[ inputNumbers[i] ] = i;
    }

    for(int i=0;i<inputNumbers.size();i++){
        int remaining = desiredNumber - inputNumbers[i];
        if(present.find(remaining) != present.end()){
            // cout << inputNumbers[i] << " " << remaining << endl;
            cout << "Indexes are " << i << " " << present[remaining] << endl;
            break;
        }
    }


    return 0;
}
