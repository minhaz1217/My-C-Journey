#include<bits/stdc++.h>
#define SIZE 100
using namespace std;

#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c ) cout << a << " : " << b << " : " << c << endl;

#include "Process.cpp"
#include "FunctionDefination.cpp"
#include "BasicFuntions.cpp"



void bankers_algorithm(){
    showDeviceQueue();
    int temp, changed, safe;
    vector<int>allocationResource,maxResource, needResource;
    cout << "Enter into bankers algorithm" << endl;
    msg("RESOU", resource.size())
    for(int i=0;i<deviceQueue.size();i++){
        cout << "Enter allocation data for " << deviceQueue[i].getProcessName() << endl;
        for(int j=0;j<resource.size();j++){
            cout << "Enter for resource " << j+1 << ": ";
            cin >> temp;
            allocationResource.push_back(temp);
        }
        cout << "Enter max data for " << deviceQueue[i].getProcessName() << endl;
        for(int j=0;j<resource.size();j++){
            cout << "Enter for resource " << j+1 << ": ";
            cin >> temp;
            maxResource.push_back(temp);
        }
        for(int j=0;j<resource.size();j++){
            int resIndex = j + i*resource.size();
            needResource.push_back(maxResource[resIndex] - allocationResource[resIndex]);
        }
    }
    vector<int>available(resource);
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
                for(int j=0;j<resource.size();j++){
                    int resIndex = j + i*resource.size();
                    //msg2("CHECKING",j, allocationResource[resIndex])
                    if( !(needResource[resIndex] <= available[j])){
                        canAssign = 0;
                        break;
                    }
                }
                if(canAssign == 1){
                    for(int j=0;j<resource.size();j++){
                        int resIndex = j + i*resource.size();
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
            mp2[GANTT_CHART[i]] = i-getArrivalTimeByID(i);
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
            mp2[GANTT_CHART[i]] = i-getArrivalTimeByID(i);
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
    return (sum / counter);

}
void fcfs(){
    int CLOCK = 0;
    deque<Process>temp;
    deque<pair<Process,int> >onHand;
    temp = readyQueue;
    sort(temp.begin(),temp.end(), compareArrivalTime);

    for(int i=0;i<temp.size();i++){
        cout << temp[i].getProcessName() << endl;
    }
    showProcessQueue(temp);

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

    for(int i=0;i<temp.size();i++){
        cout << temp[i].getProcessName() << endl;
    }
    showProcessQueue(temp);

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
}
void priorityScheduling(){
}
void preemptivePriorityScheduling(){
}
void roundRobin(){
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

int main(){
    string command;
    do{
        cout << "> ";
        cin >> command;
        if(command=="create-process"){
            createProcess();
        }
        else if(command=="system-config"){
            sysConfig();
        }
        else if(command=="ready-process"){
            readyProcess();
        }
        else if(command=="show-job-queue"){
            showJobQueue();
        }
        else if(command=="show-ready-queue"){
            showReadyQueue();
        }
        else if(command=="show-device-queue"){
            showDeviceQueue();
        }
        else if(command=="show-all-queue"){
            showAllQueue();
        }
        else if(command=="execute-process"){
            executeProcess();
        }
        else if(command=="reexecute-process"){
            reexecuteProcess();
        }
        else if(command=="apply-bankers"){
            bankers_algorithm();
        }
        else if(command=="exit"){
            cout << "Thank You." << endl;
            exit(0);
        }
        else{
            cout << "Unrecognized Command. Try again." << endl;
        }
    } while(true);
}
