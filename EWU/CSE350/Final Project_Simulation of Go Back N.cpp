#include<bits/stdc++.h>
#include<windows.h>
#include<conio.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout <<                                                               a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;
#define msg3(a,b,c,d) cout << a << " : " << b << " : " << c << " : " << d << endl;

#define SYSTEM_BITS 100

char fileName[] = "CSE350.txt";
int generatedBitRange = SYSTEM_BITS;
vector<int>loadedDataList;
int fileLoaded, generatedText ;
int color_error = 252;
int color_success = 250;
int color_normal = 240;
int color_info = 249;
int color_warning = 245;
int delayTime = 30;

void changeConsoleColor(int color){
    HANDLE consoleHandler = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(consoleHandler, color);
    //SetConsoleTextAttribute(consoleHandler, 0 | 1 | BACKGROUND_RED);
}
void generateRandomBitsInFile(){
    int n;
    ofstream myFile;
    myFile.open(fileName);
    cout << "How many data you want to generate: ";
    cin >> generatedBitRange;

    for(int i=1;i<=generatedBitRange;i++){
        n = rand()%100; /// 0 - 99
        if(n<50){
            n = 0;
        }else{
            n = 1;
        }
        myFile << n;

        if(i == 1){
            cout << "First bit: " << n << "";
        }else if(i==generatedBitRange){
            cout << " Last bit: " << n << endl;
        }
    }
    myFile.close();
    cout << generatedBitRange << " datas Generated successfully in " << fileName << "." << endl;
    cout << "Press any key to continue..." << endl;
    getch();
}

void loadFromFile(){
    ifstream inFile;
    char c;
    int arrIndex = 0,data;
    inFile.open(fileName);
    if(!inFile){
        cout << "File Doesn't Exists" << endl;
    }else{

        loadedDataList.clear();
        while(inFile >> c){
            if(c == '1'){
                data = 1;
            }else if(c == '0'){
                data = 0;
            }
            loadedDataList.push_back(data);
            //arr[arrIndex++] = data;

        }
        inFile.close();
        cout << loadedDataList.size() << " datas loaded successfully from " << fileName << "." << endl;

        fileLoaded = 1;
        cout << "First bit: " << loadedDataList[0] << " Last bit: " << loadedDataList[loadedDataList.size()-1] << endl;
        cout << "Press any key to continue..." << endl;
        getch();
    }

}

void simulate(){
    int sendNext,qSize,frameSize, windowSize=3,datalistIndex,senderIndex, maxReceive,rejectFlag, fullRejectFlag,receiveCount, success, receiverIndex;
    cout << "Enter Window Size: ";
    cin >> windowSize;
    cout << "Enter Frame Size: ";
    cin >> frameSize;
    changeConsoleColor(color_info);
    cout << endl<< endl << "------Simulation Starting------" << endl;
    cout << "With frame size: " << frameSize << " Window Size: " << windowSize << endl << endl;
    datalistIndex = 1;
    vector<vector<int> >datalist;
    vector<int>tempdata,receivedData;
    for(int i=0;i<loadedDataList.size();i++){
        tempdata.push_back(loadedDataList[i]);
        if(tempdata.size() == frameSize){
            datalist.push_back(tempdata);
            tempdata.clear();
        }
    }
    if(tempdata.size() != 0){
        datalist.push_back(tempdata);
        tempdata.clear();
    }
    //msg(datalist.size(), datalist[datalist.size()-1].size())

    deque<pair<vector<int>,int> >myQ;
    vector<pair<int,int> > receiver;

    sendNext = 0;
    senderIndex = 0;
    receivedData.clear();
    while(1){

        if(senderIndex == datalist.size()){
            changeConsoleColor(color_success);
            cout << ">> EOT" << endl;
            changeConsoleColor(color_normal);
            break;
        }

        qSize = myQ.size();
        //sender interface
        changeConsoleColor(color_info);
        cout << "Sender Sending: \t";
        //msg("SEND NEXT", sendNext)
        /// each time sending windsize = windowSize amount of data in myQ
        for(int i=0;i<windowSize - qSize;i++){
            datalistIndex = senderIndex + i + qSize ;
            if(datalistIndex< datalist.size()){
                myQ.push_back( make_pair( datalist[datalistIndex] , (datalistIndex)%windowSize ) );
            }
        }
        cout << "Frames: ";
        for(int i=0;i<myQ.size();i++){
            cout << myQ[i].second << " ";
        }
        cout << endl << "Datas: ";

        for(int i=0;i<myQ.size();i++){
            if(i > 0){
                cout << " , ";
            }
            for(int j=0;j<myQ[i].first.size() ;j++){
                cout << myQ[i].first[j];
            }
        }
        cout << endl;

        //receiver interface
        receiver.clear();

        maxReceive = min( int(myQ.size()), windowSize);

        rejectFlag = 0;
        fullRejectFlag = 0;
        deque<pair<vector<int>,int> > tempDataStream = myQ;
        receiveCount = 0;

        Sleep(delayTime);
        cout << "Receiver Receiving: \t";
        for(int i=0;i<maxReceive;i++){
            success = ( ( (rand()%100) < 75 )? 1: 0); // 75% chance of success
            if(i>0){
                changeConsoleColor(color_normal);
                cout << ", ";
            }
            if(success){
                if(rejectFlag == 0){
                    changeConsoleColor(color_success);
                    cout << tempDataStream.front().second << " ";
                    changeConsoleColor(color_normal);
                    receiveCount++;
                    sendNext = myQ.front().second;
                    for(int j=0;j<myQ.front().first.size();j++){
                        receivedData.push_back(myQ.front().first[j]);
                    }
                    myQ.pop_front();
                    senderIndex++;
                    receiverIndex++;


                }else{
                    changeConsoleColor(color_warning);
                    cout << tempDataStream.front().second << " ";
                    changeConsoleColor(color_normal);
                    receiveCount++;
                    fullRejectFlag = 1;
                }
            }else{

                changeConsoleColor(color_error);
                cout << tempDataStream.front().second << "x ";

                changeConsoleColor(color_normal);
                if(rejectFlag == 0){
                    sendNext= myQ.front().second;
                }
                rejectFlag = 1;
            }
            tempDataStream.pop_front();
        }
        cout << endl;
        if(receiveCount   == 0){
            cout << "Timeout" << endl;
            cout << ">> Pbit()" << endl;
            cout << "<< RR" << (sendNext)%windowSize << endl;
            //cout << "Receiver TIMEOUT" << endl;
        }else if(rejectFlag == 1 && fullRejectFlag == 1){
            changeConsoleColor(color_error);
            cout << "<< Rej" << (sendNext)%windowSize << endl;
            changeConsoleColor(color_normal);
        }else if(rejectFlag == 1){
            changeConsoleColor(color_warning);
            cout << "<< RR" << (sendNext)%windowSize << endl;
            changeConsoleColor(color_normal);
        }else{
            changeConsoleColor(color_success);
            cout << "<< RR" << (sendNext + 1)%windowSize << endl;
            changeConsoleColor(color_normal);
            sendNext = (sendNext+1 )%windowSize;
        }

        cout << endl;
        receiver.clear();
    }
    cout << endl << endl <<"Simulation complete" << endl;
    cout << "Total Data Received: "<< receivedData.size() << " => " << endl;
    for(int i=0;i<receivedData.size();i++){
        cout << receivedData[i];
    }
    cout << endl;


    cout << "Press any key to continue..." << endl;
    getch();
}
int main(){

    fileLoaded = 0;
    srand( time(0) );
    int choice;
    while(1){
        system("cls");
        changeConsoleColor(159);
        SetConsoleTitle("Simulation of GO BACK N");
        cout << "            Simulation of GO BACK N            " << endl;
        cout << "-----------------------------------------------"<< endl;
        changeConsoleColor(color_normal);
        cout << "1. Generate New File" << endl;
        cout << "2. Load The File" << endl;
        cout << "3. Simulate" << endl;
        cout << "4. Exit" << endl;

        cout << "Enter Your Choice: ";
        cin >> choice;
        if(choice == 1){
            generateRandomBitsInFile();
        }else if(choice == 2){
            loadFromFile();
        }else if(choice == 4){
            changeConsoleColor(192);
            cout << "THANK YOU VERY MUCH" << endl;
            changeConsoleColor(color_normal);
            exit(0);
        }else{
            if(fileLoaded == 0){
                cout << "No data loaded. Please load the data using option (2)." << endl;
                cout << "Press any key to continue..." << endl;
                getch();
            }else{
                simulate();
            }
        }
    }

    return 0;
}
