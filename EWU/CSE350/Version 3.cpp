#include<bits/stdc++.h>
#include<windows.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;
#define msg3(a,b,c,d) cout << a << " : " << b << " : " << c << " : " << d << endl;

#define SYSTEM_BITS 1000

string fileName = "test.txt";
int generatedBitRange = SYSTEM_BITS;
int arr[SYSTEM_BITS+4];
void generateRandomBitsInFile(){
    int n;

    ofstream myFile;
    myFile.open(fileName);
    for(int i=1;i<=generatedBitRange;i++){
        n = rand()%100;
        if(n<50){
            n = 0;
        }else{
            n = 1;
        }
        myFile << n;
        if(i == 1){
            cout << "First: " << n << endl;
        }else if(i==generatedBitRange){
            cout << "Last: " << n << endl;
        }
    }
    myFile.close();
}

void loadFromFile(){
    ifstream inFile;
    char c;
    int arrIndex = 0,data;
    inFile.open(fileName);
    if(!inFile){
        cout << "File opening error" << endl;
    }else{
        while(inFile >> c){
            if(c == '1'){
                data = 1;
            }else if(c == '0'){
                data = 0;
            }
            arr[arrIndex++] = data;

        }
        inFile.close();
    }

}

void senderMsg(int index, int value){
    cout << " --> Sender sends: " << value << " data" << index << endl;
}
void receiverMsg(int index, int success){
    if(success == 1){
        cout << " <-- Receiver Sends: RR" << index << endl;
    }else{
        cout << " <-- Receiver Sends: RR" << index << endl;
    }
}


int main(){
    int n,senderIndex =1, receiverIndex = 0,data,loopIndex = 1, arrIndex = 0,allOk,success;
    char c;
    srand(time(0));
    generateRandomBitsInFile();
    loadFromFile();

    allOk = 1;
    while(receiverIndex <= generatedBitRange){
            data = arr[senderIndex];
            loopIndex++;
            senderMsg(senderIndex++ ,data);


            if(allOk){
                success = (rand()%100 < 50) ? 1 : 0;
                if(!success){
                    allOk = 0;
                }else{
                    receiverIndex++;
                }

            }
            if(loopIndex %3 == 0){
                if(allOk == 1){
                    receiverMsg(receiverIndex,allOk);
                }else{
                    receiverMsg(receiverIndex,allOk);
                    senderIndex = receiverIndex;
                    allOk = 1;
                }
            }
            //Sleep(5);
    }

    if(loopIndex %3 != 0){
        receiverMsg(receiverIndex,allOk);
    }



    return 0;
}
/// outsourced the messages and added the last message check

