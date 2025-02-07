#include<bits/stdc++.h>
#include<windows.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;
#define msg3(a,b,c,d) cout << a << " : " << b << " : " << c << " : " << d << endl;

#define SYSTEM_BITS 30

string fileName = "test.txt";
int generatedBitRange = SYSTEM_BITS;
vector<int>datalist;


void generateRandomBitsInFile(){
    int n;
    ofstream myFile;
    myFile.open(fileName);

    for(int i=1;i<=generatedBitRange;i++){
        n = rand()%100; /// 0 - 99
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
        cout << "File Doesn't Exists" << endl;
    }else{

        datalist.clear();
        while(inFile >> c){
            if(c == '1'){
                data = 1;
            }else if(c == '0'){
                data = 0;
            }
            datalist.push_back(data);
            //arr[arrIndex++] = data;

        }
        inFile.close();
    }

}


int main(){
    int n,senderIndex =1, receiverIndex = 0,data,loopIndex = 1, arrIndex = 0,allOk,success,windowSize = 3,rejectFlag, fullRejectFlag;
    char c;

    srand( time(0) );
    generateRandomBitsInFile();
    loadFromFile();

    allOk = 1;
    deque<pair<int,int> >myQ;
    vector<pair<int,int> > receiver;
    int sendNext,qSize,nextItem, rej =0, maxReceive,receiveCount ;

    sendNext = 0;
    while(receiverIndex < generatedBitRange){

        if(senderIndex == datalist.size()){
            cout << ">> EOT" << endl;
            break;
        }

        qSize = myQ.size();
        //sender interface
        cout << "Sender Sending: \t";
        //msg("SEND NEXT", sendNext)
        /// each time sending windsize = windowSize amount of data in myQ
        for(int i=0;i<windowSize - qSize;i++){
            if(senderIndex + i + qSize < datalist.size()){
                myQ.push_back( make_pair(datalist[ senderIndex + i + qSize ], (sendNext+myQ.size())%windowSize ) );
                /// if the
            }
        }

        for(int i=0;i<myQ.size();i++){
            if(i>0){
                cout << ", ";
            }
            cout << "(" << myQ[i].first << "," << myQ[i].second<< ")";
        }
        cout << endl;

        //receiver interface
        receiver.clear();

        maxReceive = min( int(myQ.size()), windowSize);

        rejectFlag = 0;
        fullRejectFlag = 0;
        deque<pair<int,int> > tempDataStream = myQ;
        receiveCount = 0;


        cout << "Receiver Receiving: \t";
        for(int i=0;i<maxReceive;i++){
            success = ( ( (rand()%100) < 75 )? 1: 0); // 75% chance of success
            if(i>0){
                cout << ", ";
            }
            if(success){
                if(rejectFlag == 0){
                    cout << "(" << tempDataStream.front().first << "," << tempDataStream.front().second << ")";
                    receiveCount++;
                    sendNext = myQ.front().second;
                    myQ.pop_front();
                    senderIndex++;
                    receiverIndex++;
                }else{
                    receiveCount++;
                    //receiver.push_back( myQ.front() );
                    cout << "(" << tempDataStream.front().first << "," << tempDataStream.front().second << ")";
                    fullRejectFlag = 1;
                }
            }else{
                cout << "( , )";
                if(rejectFlag == 0){
                    sendNext= myQ.front().second;
                }
                rejectFlag = 1;
            }
            tempDataStream.pop_front();
        }
        cout << endl;

        /*
        if(receiver.size() != 0){
            cout << "Receiver Receiving: \t";
            for(int i=0;i<receiver.size();i++){
                if(i>0){
                    cout << ", ";
                }
                cout << "(" << receiver[i].first << "," << receiver[i].second << ")";
            }
            cout << endl;
        }
        */


        if(receiveCount   == 0){
            cout << "Timeout" << endl;
            cout << ">> Pbit()" << endl;
            cout << "<< RR" << (sendNext)%windowSize << endl;
            //cout << "Receiver TIMEOUT" << endl;
        }else if(rejectFlag == 1 && fullRejectFlag == 1){
            cout << "<< Rej" << (sendNext)%windowSize << endl;
        }else if(rejectFlag == 1){
            cout << "<< RR" << (sendNext)%windowSize << endl;
        }else{
            cout << "<< RR" << (sendNext + 1)%windowSize << endl;
            sendNext = (sendNext+1 )%windowSize;
        }


        /*
        if(rejectFlag == 1 && fullRejectFlag == 1){

            if(receiver.size() != 0){ // size 0 means the receiver didn't get any frames, so it will time out and the sender will send the same data next time
                if(receiverIndex != generatedBitRange-1){
                    cout << "<< Rej" << (sendNext)%windowSize << endl;
                }
            }else{
                cout << "Receiver TIMEOUT" << endl;
            }
        }else if(rejectFlag == 1){
            cout << "<< RR" << (sendNext)%windowSize << endl;
        }else{
            cout << "<< RR" << (sendNext + 1)%windowSize << endl;
            sendNext = (sendNext+1 )%windowSize;
        }
        */
        /*
        if(receiver.size() == windowSize){ // receiver got the full frame, so he will ask for the next frame
            cout << "<< RR" << (nextItem + 1)%windowSize << endl;
            rej = 0;
        }else{
            if(receiver.size() != 0){ // size 0 means the receiver didn't get any frames, so it will time out and the sender will send the same data next time
                if(receiverIndex != generatedBitRange-1){
                    cout << "<< Rej" << (nextItem + 1)%windowSize << endl;
                    rej = (nextItem+1)%windowSize;
                }
            }else{
                cout << "Receiver TIMEOUT" << endl;
            }
        }
        */
        //cout << receiverIndex << endl;
        cout << endl;
        receiver.clear();
    }


    return 0;
}
