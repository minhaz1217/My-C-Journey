#include<bits/stdc++.h>
#define SIZE 100
using namespace std;

#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c ) cout << a << " : " << b << " : " << c << endl;

#include "Process.cpp"
#include "MemberDefination.cpp"
#include "BasicFuntions.cpp"
#include "BankersAlgorithm.cpp"
#include "SchedulingAlgorithms.cpp"

/*
void displayBankersMatrix(){
    cout << "Available Resources" << endl;
    for(int i=0;i<resource.size();i++){
        cout << "Resource " << i+1 << ": " << resource[i] << endl;
    }
    for(int i=0;i<deviceQueue.size();i++){
        cout << deviceQueue[i].getProcessName() << endl;
    }

}
*/

void terminate_all(){
    jobQueue.clear();
    readyQueue.clear();
    deviceQueue.clear();
    sysResource.clear();
    sysFrameSize = 0;
    sysRemainingFrame = 0;
    sysMemorySize = 0;
    initGanttChart();
    cout << "System is like new now." << endl;

}

void executeProcess(){
    int choice;
    cout << "CPU Scheduling Algorithm Selection" << endl;
    cout << "-------------------" << endl;
    cout << "(1) First-Come-First-Served (FCFS)" << endl;
    cout << "(2) Shortest-Job-First (SJF)" << endl;
    cout << "(3) Preemptive SJF (shortest-remaining-time-first" << endl;
    cout << "(4) Priority-based Scheduling" << endl;
    cout << "(5) Preemptive Priority-based Scheduling" << endl;
    cout << "(6) Round-Robin Scheduling" << endl;
    cout << "Enter Choice: ";
    cin >> choice;
    switch(choice){
    case 1:
        fcfs();
        break;
    case 2:
        //sjf();
        sjf();
        break;
    case 3:
        srtf();
        break;
    case 4:
        priorityScheduling();
        break;
    case 5:
        preemptivePriorityScheduling();
        break;
    case 6:
        roundRobin();
        break;
    default:
        cout << "Unrecognized Option. " << endl;
    }
}

void reexecuteProcess(){
    for(int i=0;i<readyQueue.size();i++){
        readyQueue[i].setProcessStatus("ready");
    }
    executeProcess();
}

map<string, int> commands;
vector<string>concatCommands[15], helpDescription;

void init(){

    commands["help"] = 0;
    commands["?"] = 0;
    commands["/?"] = 0;
    commands["0"] = 0;

    commands["system-config"] = 1;
    commands["sysconfig"] = 1;
    commands["1"] = 1;

    commands["create-process"] = 2;
    commands["new-process"] = 2;
    commands["process"] = 2;
    commands["cp"] = 2;
    commands["2"] = 2;

    commands["ready-process"] = 3;
    commands["rp"] = 3;
    commands["p_ready"] = 3;
    commands["3"] = 3;

    commands["execute-process"] = 4;
    commands["ep"] = 4;
    commands["execute"] = 4;
    commands["4"] = 4;

    commands["reexecute-process"] = 5;
    commands["reexecute"] = 5;
    commands["rep"] = 5;
    commands["5"] = 5;

    commands["show-job-queue"] = 6;
    commands["job"] = 6;
    commands["6"] = 6;

    commands["show-ready-queue"] = 7;
    commands["ready"] = 7;
    commands["7"] = 7;

    commands["show-device-queue"] = 8;
    commands["device"] = 8;
    commands["8"] = 8;

    commands["show-all-queue"] = 9;
    commands["all"] = 9;
    commands["9"] = 9;

    commands["apply-bankers"] = 10;
    commands["bankers"] = 10;
    commands["10"] = 10;

    commands["exit"] = 11;
    commands["-1"] = 11;
    commands["11"] = 11;

    commands["12"] = 12;
    commands["sysinfo"] = 12;
    commands["system-info"] = 12;

    commands["terminate-all"] = 13;
    commands["clear-all"] = 13;
    commands["empty"] = 13;
    commands["13"] = 13;


    map<string, int>::iterator it;
    for(it = commands.begin();it!= commands.end();it++){
        concatCommands[it->second].push_back(it->first);
        //msg(it->first, it->second)
    }
    helpDescription.push_back("Shows list of commands");
    helpDescription.push_back("Configures the system initial information");
    helpDescription.push_back("Creates new process");
    helpDescription.push_back("Takes process from new job queue to ready queue given that it is possible to do so.");
    helpDescription.push_back("Takes process from ready queue to device queue if it has io flag on");
    helpDescription.push_back("Same as execute process");
    helpDescription.push_back("Shows the JOB queue");
    helpDescription.push_back("Shows the READY queue");
    helpDescription.push_back("Shows the DEVICE queue");
    helpDescription.push_back("Shows ALL queues together");
    helpDescription.push_back("Apply bankers algorithm on the processes in device queue");
    helpDescription.push_back("Exits the Program");
    helpDescription.push_back("Shows System's Current Information");
    helpDescription.push_back("Clears All queue and resets the system resources.");

}

void help(){
    cout <<"-----LIST OF COMMANDS-----" << endl;
    for(int i=0;i<helpDescription.size();i++){

        for(int j=0;j<concatCommands[i].size();j++){
            if(j>0){
                cout << " , ";
            }
            cout << concatCommands[i][j];
        }
        cout << " - " << helpDescription[i] << endl;
    }
}

int main(){
    init();

    string command;
    do{
        cout << "> ";
        cin >> command;
        //msg(command, commands[command])
        if(commands.find(command) == commands.end()){
            cout << "Unrecognized Command. Try again." << endl;
        }else{
            int tempInt = commands[command];

            if(tempInt == 0){
                help();
            }else if(tempInt == 11){
                cout << "Thank You." << endl;
                exit(0);
            }else if(tempInt == 1){
                    sysConfig();
            }else{
                if(sysResource.size() == 0){
                    cout << "Please start with the 'system-config' command." << endl;
                    continue;
                }if(tempInt == 2){
                    createProcess();
                }else if(tempInt == 3){
                    readyProcess();
                }else if(tempInt == 4){
                    executeProcess();
                }else if(tempInt == 5){
                    reexecuteProcess();
                }else if(tempInt == 6){
                    showJobQueue();
                }else if(tempInt == 7){
                    showReadyQueue();
                }else if(tempInt == 8){
                    showDeviceQueue();
                }else if(tempInt == 9){
                    showAllQueue();
                }else if(tempInt == 10){
                    bankers_algorithm();
                }else if(tempInt == 12){
                    showSystemInfo();
                }else if(tempInt == 13){
                    terminate_all();
                }
            }
        }
    } while(true);
}
