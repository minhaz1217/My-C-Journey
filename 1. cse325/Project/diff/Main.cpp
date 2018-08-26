#include<bits/stdc++.h>
#define SIZE 100
using namespace std;

#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c ) cout << a << " : " << b << " : " << c << endl;

#include "Process.cpp"
#include "FunctionDefination.cpp"
#include "BasicFuntions.cpp"



vector<int>allocationResource,maxResource, needResource;
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
void bankers_algorithm(){
    showDeviceQueue();
    int temp, changed, safe;
    cout << "Enter into bankers algorithm" << endl;
    //msg("RESOU", resource.size())
    vector<int> available (sysResource), testSum;
    testSum.assign(3,0);
    for(int i=0;i<deviceQueue.size();i++){
        cout << "Enter allocation data for " << deviceQueue[i].getProcessName() << endl;
        for(int j=0;j<sysResource.size();j++){
            cout << "Enter for resource " << j+1 << ": ";
            cin >> temp;
            allocationResource.push_back(temp);
            available[j] -= temp;
            testSum[j] += temp;
        }
        cout << "Enter max data for " << deviceQueue[i].getProcessName() << endl;
        for(int j=0;j<sysResource.size();j++){
            cout << "Enter for resource " << j+1 << ": ";
            cin >> temp;
            maxResource.push_back(temp);
        }
        for(int j=0;j<sysResource.size();j++){
            int resIndex = j + i*sysResource.size();
            needResource.push_back(maxResource[resIndex] - allocationResource[resIndex]);
        }
    }
    for(int i=0;i<available.size();i++){
        msg2("SUM", i, testSum[i])
        msg2("Available" , i, available[i])
    }

    //vector<int> available (resource);
    changed = 1;
    //msg("AVAIL", available.size());
    /*
    for(int i=0;i<needResource.size();i++){
        msg(i, needResource[i])
    }
    */
    vector<bool>finish;
    vector<string>sequence;
    for(int i=0;i<deviceQueue.size();i++){
        finish.push_back(false);
    }
    while(changed){
        changed = 0;
        for(int i=0;i<deviceQueue.size();i++){
            int canAssign = 1;
            if(finish[i] == false){
                for(int j=0;j<sysResource.size();j++){
                    int resIndex = j + i*sysResource.size();
                    //msg2("CHECKING",j, allocationResource[resIndex])
                    if( !(needResource[resIndex] <= available[j])){
                        canAssign = 0;
                        break;
                    }
                }
                if(canAssign == 1){
                    for(int j=0;j<sysResource.size();j++){
                        int resIndex = j + i*sysResource.size();
                        available[j] += allocationResource[resIndex];
                        //msg("ALLOCATED" , i)
                    }
                    changed = 1;
                    finish[i] = true;
                    sequence.push_back(deviceQueue[i].getProcessName());
                }
            }
        }
    }
    safe = 1;
    /*
    for(int i=0;i<deviceQueue.size();i++){
        msg(i, taken[i])
    }
    */
    for(int i=0;i<deviceQueue.size();i++){
        if(finish[i] == false){
            safe = 0;
        }
    }
    if(safe == 0){
        cout << "THE STATE IS UNSAFE" << endl;
    }else{
        cout << "THE STATE IS SAFE, with sequence.." << endl;
        for(int i=0;i<sequence.size();i++){
            if(i>0){
                cout << " > ";
            }
            cout << sequence[i];
        }
        cout << endl;
    }



    //cout << "then determine system state" << endl;
}
void redo_bankers_algorithm(){
    showDeviceQueue();
    int temp, changed, safe;
    cout << "Redoing Bankers Algorithm." << endl;
    if(allocationResource.size() == 0){
        cout << "No data inserted, Insert data first" << endl;
        bankers_algorithm();
    }
    cout << "Enter new available resource data" << endl;
    vector<int>available(sysResource);
    for(int i=0;i<sysResource.size();i++){
        cout << "Enter data for " << i+1 << " : ";
        cin >> sysResource[i];
    }
    changed = 1;
    vector<bool>finish;
    vector<string>sequence;
    for(int i=0;i<deviceQueue.size();i++){
        finish.push_back(false);
    }
    while(changed){
        changed = 0;
        for(int i=0;i<deviceQueue.size();i++){
            int canAssign = 1;
            if(finish[i] == false){
                for(int j=0;j<sysResource.size();j++){
                    int resIndex = j + i*sysResource.size();
                    //msg2("CHECKING",j, allocationResource[resIndex])
                    if( !(needResource[resIndex] <= available[j])){
                        canAssign = 0;
                        break;
                    }
                }
                if(canAssign == 1){
                    for(int j=0;j<sysResource.size();j++){
                        int resIndex = j + i*sysResource.size();
                        available[j] += allocationResource[resIndex];
                        //msg("ALLOCATED" , i)
                    }
                    changed = 1;
                    finish[i] = true;
                    sequence.push_back(deviceQueue[i].getProcessName());
                }
            }
        }
    }
    safe = 1;
    /*
    for(int i=0;i<deviceQueue.size();i++){
        msg(i, taken[i])
    }
    */
    for(int i=0;i<deviceQueue.size();i++){
        if(finish[i] == false){
            safe = 0;
        }
    }
    if(safe == 0){
        cout << "THE STATE IS UNSAFE" << endl;
    }else{
        cout << "THE STATE IS SAFE, with sequence.." << endl;
        for(int i=0;i<sequence.size();i++){
            if(i>0){
                cout << " > ";
            }
            cout << sequence[i];
        }
        cout << endl;
    }
    //cout << "then determine system stae" << endl;
}

double getResponseTime(int clockTime){
    int current = -1;
    double counter = 0, sum = 0;
    map<int, int>mp;
    mp[-1] = 1;
    for(int i=0;i<clockTime;i++){
        if(GANTT_CHART[i]!=current){
            if(!mp[GANTT_CHART[i]]){
                mp[GANTT_CHART[i]] = 1;
                sum += i;
                counter++;
            }
            current = GANTT_CHART[i];
        }
    }
    //msg2(counter, clockTime, sum)
    //cout << counter << endl;
    return (sum / counter);
}
int getArrivalTimeByID(int a){
    for(int i=0;i<readyQueue.size();i++){
        if(readyQueue[i].getProcessID() == a){
            return readyQueue[i].getArrivalTime();
        }
    }
}
int getBurstTimeByID(int a){
    for(int i=0;i<readyQueue.size();i++){
        if(readyQueue[i].getProcessID() == a){
            return readyQueue[i].getBurst();
        }
    }
}
double getWaitingTime(int clockTime){
    int current = -1;
    double counter = 0, sum = 0;
    map<int, int>mp, mp2; // mp for duplicate check, mp2 for calculation
    mp[-1] = 1;

    for(int i=clockTime-1;i>=0;i--){
        if(!mp[GANTT_CHART[i]]){
            mp[GANTT_CHART[i]]=1;
            counter++;
            mp2[GANTT_CHART[i]] = i-getArrivalTimeByID(GANTT_CHART[i]);
            //msg2("ARRIVAL", i, getArrivalTimeByID(i))
            //cc("HI")
        }else{
            mp2[GANTT_CHART[i]]--;
        }
    }
    map<int,int>::iterator it;
    for(it= mp2.begin();it!=mp2.end();it++){
        if(it->first !=-1){
            sum+= it->second;
        }
        //msg(it->first, it->second)
    }
    //msg2(counter, clockTime, sum)
    return (sum / counter);
    //return 0;
}
double getTurnAroundTime(int clockTime){
    int current = -1;
    double counter = 0, sum = 0;
    map<int, int>mp, mp2; // mp for duplicate check, mp2 for calculation
    mp[-1] = 1;

    for(int i=clockTime-1;i>=0;i--){
        if(!mp[GANTT_CHART[i]]){
            mp[GANTT_CHART[i]]=1;
            counter++;
            mp2[GANTT_CHART[i]] = i-getArrivalTimeByID(GANTT_CHART[i]);
            //cc("HI")
        }else{
            mp2[GANTT_CHART[i]]--;
        }
    }
    map<int,int>::iterator it;
    for(it= mp2.begin();it!=mp2.end();it++){
        if(it->first !=-1){
            sum += it->second + getBurstTimeByID(it->first);
        }
        //msg(it->first, it->second)
    }
    //msg2("Turnaround", clockTime, sum)
    return (sum / counter);

}
void fcfs(){
    int CLOCK = 0;
    deque<Process>temp;
    deque<pair<Process,int> >onHand;
    temp = readyQueue;
    sort(temp.begin(),temp.end(), compareArrivalTime);
    /*
    for(int i=0;i<temp.size();i++){
        cout << temp[i].getProcessName() << endl;
    }
    */
    //showProcessQueue(temp);

    while(temp.size()!=0 || onHand.size() !=0){
        while(temp.size()>0 && temp[0].getArrivalTime() == CLOCK){
            onHand.push_back(make_pair(temp[0], temp[0].getBurst()));
            temp.pop_front();
            msg( onHand.size(), temp.size());
        }
        //showProcessQueue(temp);
        //cc(CLOCK)
        if(onHand.size() != 0){
            GANTT_CHART[CLOCK] = onHand[0].first.getProcessID();
            onHand[0].second--;
            if(onHand[0].second == 0){
                onHand.pop_front();
            }
        }else{
            GANTT_CHART[CLOCK] = -1;
        }

        CLOCK++;
    }
    //msg("CLOCK", CLOCK);
    showGanttChart(CLOCK);
    msg("Response Time: ", getResponseTime(CLOCK))
    msg("Waiting Time: ", getWaitingTime(CLOCK))
    msg("Turn around Time: ", getTurnAroundTime(CLOCK))
}
void sjf(){
    int CLOCK = 0, needSort = 0;
    deque<Process>temp;
    deque<pair<Process,int> >onHand;
    temp = readyQueue;
    sort(temp.begin(),temp.end(), compareArrivalTime);
/*
    for(int i=0;i<temp.size();i++){
        cout << temp[i].getProcessName() << endl;
    }
    showProcessQueue(temp);
*/
    while(temp.size()!=0 || onHand.size() !=0){
        if(onHand.size() == 0){
            needSort = 1; // if the onhand is empty then we need to sort it after inserting all the processes from ready queue.
        }
        while(temp.size()>0 && temp[0].getArrivalTime() == CLOCK){
            onHand.push_back(make_pair(temp[0], temp[0].getBurst()));
            temp.pop_front();
            msg( onHand.size(), temp.size());
        }
        if(needSort == 1){
            needSort = 0;
            sort(onHand.begin(), onHand.end(), compareBurstTime1);
        }
        //showProcessQueue(temp);
        //cc(CLOCK)
        if(onHand.size() != 0){
            GANTT_CHART[CLOCK] = onHand[0].first.getProcessID();
            onHand[0].second--;
            if(onHand[0].second == 0){
                onHand.pop_front();
                sort(onHand.begin(), onHand.end(), compareBurstTime1); // after a process is finished operating we need to select the next one to go to top.
            }
        }else{
            GANTT_CHART[CLOCK] = -1;
        }

        CLOCK++;
    }
    //msg("CLOCK", CLOCK);
    showGanttChart(CLOCK);
    msg("Response Time: ", getResponseTime(CLOCK))
    msg("Waiting Time: ", getWaitingTime(CLOCK))
    msg("Turn around Time: ", getTurnAroundTime(CLOCK))
}
void srtf(){
    //cc("APPLYING SRTF")
    int CLOCK = 0, needSort = 0;
    deque<Process>temp;
    deque<pair<Process,int> >onHand;
    temp = readyQueue;
    sort(temp.begin(),temp.end(), compareArrivalTime);

    /*
    for(int i=0;i<temp.size();i++){
        cout << temp[i].getProcessName() << endl;
    }
    */
    //showProcessQueue(temp);

    while(temp.size()!=0 || onHand.size() !=0){
        if(onHand.size() == 0){
            needSort = 1; // if the onhand is empty then we need to sort it after inserting all the processes from ready queue.
        }
        while(temp.size()>0 && temp[0].getArrivalTime() == CLOCK){
            onHand.push_back(make_pair(temp[0], temp[0].getBurst()));
            temp.pop_front();
            needSort = 1;
            //msg( onHand.size(), temp.size());
        }
        if(needSort == 1){
            needSort = 0;
            sort(onHand.begin(), onHand.end(), compareBurstTime1);
        }
        //showProcessQueue(temp);
        //cc(CLOCK)
        if(onHand.size() != 0){
            GANTT_CHART[CLOCK] = onHand[0].first.getProcessID();
            onHand[0].second--;
            if(onHand[0].second == 0){
                onHand.pop_front();
                sort(onHand.begin(), onHand.end(), compareBurstTime1); // after a process is finished operating we need to select the next one to go to top.
            }
        }else{
            GANTT_CHART[CLOCK] = -1;
        }

        CLOCK++;
    }
    //msg("CLOCK", CLOCK);
    showGanttChart(CLOCK);
    msg("Response Time: ", getResponseTime(CLOCK))
    msg("Waiting Time: ", getWaitingTime(CLOCK))
    msg("Turn around Time: ", getTurnAroundTime(CLOCK))
}
void priorityScheduling(){
    int CLOCK = 0, needSort = 0;
    deque<Process>temp;
    deque<pair<Process,int> >onHand;
    temp = readyQueue;
    sort(temp.begin(),temp.end(), compareArrivalTime);
/*
    for(int i=0;i<temp.size();i++){
        cout << temp[i].getProcessName() << endl;
    }
    showProcessQueue(temp);
*/
    while(temp.size()!=0 || onHand.size() !=0){
        if(onHand.size() == 0){
            needSort = 1; // if the onhand is empty then we need to sort it after inserting all the processes from ready queue.
        }
        while(temp.size()>0 && temp[0].getArrivalTime() == CLOCK){
            onHand.push_back(make_pair(temp[0], temp[0].getBurst()));
            temp.pop_front();
            msg( onHand.size(), temp.size());
        }
        if(needSort == 1){
            needSort = 0;
            sort(onHand.begin(), onHand.end(), comparePriority1);
        }
        //showProcessQueue(temp);
        //cc(CLOCK)
        if(onHand.size() != 0){
            GANTT_CHART[CLOCK] = onHand[0].first.getProcessID();
            onHand[0].second--;
            if(onHand[0].second == 0){
                onHand.pop_front();
                sort(onHand.begin(), onHand.end(), comparePriority1); // after a process is finished operating we need to select the next one to go to top.
            }
        }else{
            GANTT_CHART[CLOCK] = -1;
        }

        CLOCK++;
    }
    //msg("CLOCK", CLOCK);
    showGanttChart(CLOCK);
    msg("Response Time: ", getResponseTime(CLOCK))
    msg("Waiting Time: ", getWaitingTime(CLOCK))
    msg("Turn around Time: ", getTurnAroundTime(CLOCK))
}
void preemptivePriorityScheduling(){
    //cc("APPLYING SRTF")
    int CLOCK = 0, needSort = 0;
    deque<Process>temp;
    deque<pair<Process,int> >onHand;
    temp = readyQueue;
    sort(temp.begin(),temp.end(), compareArrivalTime);

    /*
    for(int i=0;i<temp.size();i++){
        cout << temp[i].getProcessName() << endl;
    }
    */
    //showProcessQueue(temp);

    while(temp.size()!=0 || onHand.size() !=0){
        if(onHand.size() == 0){
            needSort = 1; // if the onhand is empty then we need to sort it after inserting all the processes from ready queue.
        }
        while(temp.size()>0 && temp[0].getArrivalTime() == CLOCK){
            onHand.push_back(make_pair(temp[0], temp[0].getBurst()));
            temp.pop_front();
            needSort = 1;
            //msg( onHand.size(), temp.size());
        }
        if(needSort == 1){
            needSort = 0;
            sort(onHand.begin(), onHand.end(), comparePriority1);
        }
        //showProcessQueue(temp);
        //cc(CLOCK)
        if(onHand.size() != 0){
            GANTT_CHART[CLOCK] = onHand[0].first.getProcessID();
            onHand[0].second--;
            if(onHand[0].second == 0){
                onHand.pop_front();
                sort(onHand.begin(), onHand.end(), comparePriority1); // after a process is finished operating we need to select the next one to go to top.
            }
        }else{
            GANTT_CHART[CLOCK] = -1;
        }

        CLOCK++;
    }
    //msg("CLOCK", CLOCK);
    showGanttChart(CLOCK);
    msg("Response Time: ", getResponseTime(CLOCK))
    msg("Waiting Time: ", getWaitingTime(CLOCK))
    msg("Turn around Time: ", getTurnAroundTime(CLOCK))
}
void roundRobin(){
    int timeQuantum;
    cout << "Input Time Quantum: ";
    cin >> timeQuantum;
    //cc("APPLYING SRTF")
    int CLOCK = 0, needSort = 0;
    deque<Process>temp;
    deque<pair<Process,int> >onHand;
    temp = readyQueue;
    sort(temp.begin(),temp.end(), compareArrivalTime);

    /*
    for(int i=0;i<temp.size();i++){
        cout << temp[i].getProcessName() << endl;
    }
    */
    //showProcessQueue(temp);
    int currentTime = 0;
    int currentIndex = 0;
    while(temp.size()!=0 || onHand.size() !=0){

        while(temp.size()>0 && temp[0].getArrivalTime() == CLOCK){
            onHand.push_back(make_pair(temp[0], temp[0].getBurst()));
            temp.pop_front();
            needSort = 1;
            //msg( onHand.size(), temp.size());
        }
        //showProcessQueue(temp);
        //cc(CLOCK)
        if(onHand.size() != 0){
            GANTT_CHART[CLOCK] = onHand[0].first.getProcessID();
            onHand[0].second--;
            if(onHand[0].second == 0){
                onHand.pop_front();
            }else if(currentTime == timeQuantum){
                onHand.push_back(onHand[0]);
                onHand.pop_front();
                currentTime = -1;
            }
        }else{
            GANTT_CHART[CLOCK] = -1;
        }
        currentTime++;
        CLOCK++;
    }
    //msg("CLOCK", CLOCK);
    showGanttChart(CLOCK);
    msg("Response Time: ", getResponseTime(CLOCK))
    msg("Waiting Time: ", getWaitingTime(CLOCK))
    msg("Turn around Time: ", getTurnAroundTime(CLOCK))

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
    /*
    for(int i=0;i<helpDescription.size();i++){
        msg(i, helpDescription[i])
    }
    */
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
            }else if(tempInt == 1){
                sysConfig();
            }else if(tempInt == 2){
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
            }else if(tempInt == 11){
                cout << "Thank You." << endl;
                exit(0);
            }
        }
    } while(true);
}
