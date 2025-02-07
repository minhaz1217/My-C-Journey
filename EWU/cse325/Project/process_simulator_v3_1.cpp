#include<bits/stdc++.h>
#define SIZE 100
using namespace std;

int sysResourceA;
int sysResourceB;
int sysResourceC;
int sysMemorySize;

class Process{
private:
    int processID;
    string processName;
    string processStatus;
    int processSize;
    int hasIOoperation; // 1 means yes, 0 means no
    int burst;
    int arrivalTime;
    int priority;
    static int processCounter;
public:
    Process(){}
    /*
    Process(string processName, int burst, int arrivalTime, int priority){
        this->processID = ++(this->processCounter);
        this->processName = processName;
        this->processStatus = "new";
        this->burst = burst;
        this->arrivalTime = arrivalTime;
        this->priority = priority;
    }
    */
    void setProcess(string processName, int processSize, int hasIOoperation, int burst, int arrivalTime, int priority){
        this->processID = ++(this->processCounter);
        this->processName = processName;
        this->processStatus = "new";
        this->processSize = processSize;
        this->hasIOoperation = hasIOoperation;
        this->burst = burst;
        this->arrivalTime = arrivalTime;
        this->priority = priority;
    }
    void setProcessID(int processID){this->processID = processID;}
    void setProcessName(string processName){this->processName = processName;}
    void setProcessStatus(string processStatus){this->processStatus = processStatus;}
    void setProcessSize(int processSize){this->processSize = processSize;}
    void setHasIOoperation(int hasIOoperation){this->hasIOoperation = hasIOoperation;}
    void setBurst(int burst){this->burst = burst;}
    void setArrivalTime(int arrivalTime){this->arrivalTime = arrivalTime;}
    void setPriority(int priority){this->priority = priority;}
    int getProcessID(){ return this->processID;}
    string getProcessName(){ return this->processName;}
    string getProcessStatus(){return this->processStatus;}
    int getProcessSize(){ return this->processSize;}
    int getHasIOoperation(){ return this->hasIOoperation;}
    int getBurst(){ return this->burst;}
    int getArrivalTime(){ return this->arrivalTime;}
    int getPriority(){ return this->priority;}
};

int Process::processCounter = 0;

Process JOB_QUEUE[SIZE];
Process READY_QUEUE[SIZE];
Process DEVICE_QUEUE[SIZE];

int GANTT_CHART[1000];

int job_queue_front, job_queue_rear = 0;
int ready_queue_front, ready_queue_rear = 0;
int device_queue_front, device_queue_rear = 0;

void initGanttChart(){
    for(int i=0; i<1000; i++)
        GANTT_CHART[i] = -1;
}

void createProcess(){
    int pSize, pOp, pBurst, pArrivalTime, pPriority;
    string pName;
    cout << "Enter Process Name: ";
    cin >> pName;
    cout << "Enter Process Size: ";
    cin >> pSize;
    cout << "Has IO operation? (1 for yes, 0 for no): ";
    cin >> pOp;
    cout << "Enter Burst: ";
    cin >> pBurst;
    cout << "Enter Arrival Time: ";
    cin >> pArrivalTime;
    cout << "Enter Priority: ";
    cin >> pPriority;
    JOB_QUEUE[job_queue_rear++].setProcess(pName, pSize, pOp, pBurst, pArrivalTime, pPriority);
}

void showJobQueue(){
    cout.setf(ios::left, ios::adjustfield);
    cout << "Job Queue" << endl;
    cout << "---------" << endl;
    cout << setw(10) << "ID" << setw(10) << "Name" << setw(10) << "Burst" << setw(10) << "Arrival"
         << setw(10) << "Priority" << setw(10) << "Size" << setw(10) << "hasIO?" <<endl;
    for(int i = 0; i < job_queue_rear; i++){
        cout << setw(10) << JOB_QUEUE[i].getProcessID() << setw(10) << JOB_QUEUE[i].getProcessName()
        << setw(10) << JOB_QUEUE[i].getBurst() << setw(10) << JOB_QUEUE[i].getArrivalTime()
        << setw(10) << JOB_QUEUE[i].getPriority()
        << setw(10) << JOB_QUEUE[i].getProcessSize()
        << setw(10) << JOB_QUEUE[i].getHasIOoperation() << endl;
    }

}

void showReadyQueue(){
    cout.setf(ios::left, ios::adjustfield);
    cout << "Ready Queue" << endl;
    cout << "---------" << endl;
    cout << setw(10) << "ID" << setw(10) << "Name" << setw(10) << "Burst" << setw(10) << "Arrival" << setw(10) << "Priority"
         << setw(10) << "Size" << setw(10) << "hasIO?" << endl;
    for(int i = 0; i < ready_queue_rear; i++){
        cout << setw(10) << READY_QUEUE[i].getProcessID() << setw(10) << READY_QUEUE[i].getProcessName()
        << setw(10) << READY_QUEUE[i].getBurst() << setw(10) << READY_QUEUE[i].getArrivalTime()
        << setw(10) << READY_QUEUE[i].getPriority()
        << setw(10) << READY_QUEUE[i].getProcessSize()
        << setw(10) << READY_QUEUE[i].getHasIOoperation() << endl;    }

}

void showDeviceQueue(){
    cout.setf(ios::left, ios::adjustfield);
    cout << "Device Queue" << endl;
    cout << "---------" << endl;
    cout << setw(10) << "ID" << setw(10) << "Name" << setw(10) << "Burst" << setw(10) << "Arrival" << setw(10) << "Priority"
         << setw(10) << "Size" << setw(10) << "hasIO?" << endl;
    for(int i = 0; i < device_queue_rear; i++){
        cout << setw(10) << DEVICE_QUEUE[i].getProcessID() << setw(10) << DEVICE_QUEUE[i].getProcessName()
        << setw(10) << DEVICE_QUEUE[i].getBurst() << setw(10) << DEVICE_QUEUE[i].getArrivalTime()
        << setw(10) << DEVICE_QUEUE[i].getPriority()
        << setw(10) << DEVICE_QUEUE[i].getProcessSize()
        << setw(10) << DEVICE_QUEUE[i].getHasIOoperation() << endl;    }

}
void bankers_algorithm(){
    showDeviceQueue();
    cout << "Enter into bankers algorithm" << endl;
    cout << "Read Allocation and Max matrix for each process in device queue" << endl;
    cout << "then determine system state" << endl;
}
void readyProcess(){
    cout << "Transferring Processes from Job Queue to Ready/Device Queue." << endl;
    int j = 0, k = 0;
    for(int i = 0; i<job_queue_rear; i++){
        Process P = JOB_QUEUE[i];
        if(P.getHasIOoperation() == 1){
            DEVICE_QUEUE[j].setProcessID(P.getProcessID());
            DEVICE_QUEUE[j].setProcessName(P.getProcessName());
            DEVICE_QUEUE[j].setProcessSize(P.getProcessSize());
            DEVICE_QUEUE[j].setHasIOoperation(P.getHasIOoperation());
            DEVICE_QUEUE[j].setProcessStatus("waiting");
            DEVICE_QUEUE[j].setBurst(P.getBurst());
            DEVICE_QUEUE[j].setArrivalTime(P.getArrivalTime());
            DEVICE_QUEUE[j].setPriority(P.getPriority());
            j++;
        }
        else{
            READY_QUEUE[k].setProcessID(P.getProcessID());
            READY_QUEUE[k].setProcessName(P.getProcessName());
            READY_QUEUE[k].setProcessSize(P.getProcessSize());
            READY_QUEUE[k].setHasIOoperation(P.getHasIOoperation());
            READY_QUEUE[k].setProcessStatus("ready");
            READY_QUEUE[k].setBurst(P.getBurst());
            READY_QUEUE[k].setArrivalTime(P.getArrivalTime());
            READY_QUEUE[k].setPriority(P.getPriority());
            k++;
        }
    }
    ready_queue_rear = k;
    device_queue_rear = j;
    job_queue_rear = 0;
    cout << "Transfer Completed." << endl;
    if(device_queue_rear > 0)
        bankers_algorithm();
}

int compare(const void *a, const void *b){
    if (((Process *)a)->getArrivalTime() == ((Process *)b)->getArrivalTime()){
       return ((Process *)a)->getProcessID() - ((Process *)b)->getProcessID();
    }
    return ((Process *)a)->getArrivalTime() - ((Process *)b)->getArrivalTime();
}

void displayGanttChart(int clock){
    cout.setf(ios::left, ios::adjustfield);
    for(int i=0; i<clock; i++){
        if(i%10==0 && i/10>=1)
            cout << endl;
        cout << setw(3) << GANTT_CHART[i];
    }
    cout << endl;
}

double average(int *list){
    int sum = 0;
    for(int i = 0; i<ready_queue_rear; i++){
        sum += list[i];
    }
    return sum*1.0/ready_queue_rear;
}

void fcfs(){
    qsort(READY_QUEUE, ready_queue_rear, sizeof(READY_QUEUE[0]), compare);
    showReadyQueue();
    initGanttChart();
    int clock = 0;
    int i = 0;
    bool seen[ready_queue_rear];
    int remaining_time[ready_queue_rear];
    for(int i=0; i<ready_queue_rear; i++){
        seen[i] = false;
        remaining_time[i] = READY_QUEUE[i].getBurst();
    }
    int complete = 0;
    int waiting_time [ready_queue_rear], response_time[ready_queue_rear], turnaround_time [ready_queue_rear];

    while(complete<ready_queue_rear){
        if(READY_QUEUE[i].getArrivalTime()<=clock && READY_QUEUE[i].getProcessStatus()!="Terminated"){
            for(int j = clock; j < clock + remaining_time[i]; j++){
                GANTT_CHART[j] = READY_QUEUE[i].getProcessID();
            }

            if(seen[i]==false){
                response_time[i] = clock - READY_QUEUE[i].getArrivalTime();
                seen[i]=true;
            }
            clock = clock + READY_QUEUE[i].getBurst();
            READY_QUEUE[i].setProcessStatus("Terminated");
            waiting_time[i] = clock - READY_QUEUE[i].getArrivalTime() - READY_QUEUE[i].getBurst();
            turnaround_time[i] = clock - READY_QUEUE[i].getArrivalTime();
            i++;
            complete++;
        }
        else{
            clock++;
        }
    }
    cout << "FCFS Scheduling" << endl;
    displayGanttChart(clock);
    cout << setw(30) << "Average Waiting Time: " << average(waiting_time) << endl;
    cout << setw(30) << "Average Response Time: " << average(response_time) << endl;
    cout << setw(30) << "Average Turnaround TIme: " << average(turnaround_time) << endl;
}

void sjf(){
    //initGanttChart();
    int clock = 0;
    int i = 0;
    bool seen[ready_queue_rear];
    int remaining_time[ready_queue_rear];
    for(int i=0; i<ready_queue_rear; i++){
        seen[i] = false;
        remaining_time[i] = READY_QUEUE[i].getBurst();
    }
    int complete = 0;
    int waiting_time [ready_queue_rear], response_time[ready_queue_rear], turnaround_time [ready_queue_rear];

    while(complete<ready_queue_rear){
        // find next process to execute
        int minm = INT_MAX;
        int shortest = -1;
        //bool found = false;
        for(int i=0; i<ready_queue_rear; i++){
            if(READY_QUEUE[i].getBurst() < minm &&
               READY_QUEUE[i].getArrivalTime() <= clock
               && READY_QUEUE[i].getProcessStatus()!="Terminated"){
                minm = READY_QUEUE[i].getBurst();
                shortest = i;
            }
        }
        // no suitable process found, incrementing clock time
        if(shortest==-1){
            clock++;
            continue;
        }
        /*
        for(int j = clock; j < clock + remaining_time[shortest]; j++){
            GANTT_CHART[j] = READY_QUEUE[shortest].getProcessID();
        }*/
        if(seen[shortest]==false){
            response_time[shortest] = clock - READY_QUEUE[shortest].getArrivalTime();
            seen[shortest]=true;
        }
        clock = clock + READY_QUEUE[shortest].getBurst();
        READY_QUEUE[shortest].setProcessStatus("Terminated");
        waiting_time[shortest] = clock -
           READY_QUEUE[shortest].getArrivalTime() -
           READY_QUEUE[shortest].getBurst();
        turnaround_time[shortest] = clock -
           READY_QUEUE[shortest].getArrivalTime();
        complete++;
    }
    cout << "SJF Scheduling" << endl;
    //displayGanttChart(clock);
    cout << setw(30) << "Average Waiting Time: " << average(waiting_time) << endl;
    cout << setw(30) << "Average Response Time: " << average(response_time) << endl;
    cout << setw(30) << "Average Turnaround TIme: " << average(turnaround_time) << endl;
}

void srtf(){

}

void priorityScheduling(){
    int clock = 0;
    int i = 0;
    bool seen[ready_queue_rear];
    int remaining_time[ready_queue_rear];
    for(int i=0; i<ready_queue_rear; i++){
        seen[i] = false;
        remaining_time[i] = READY_QUEUE[i].getBurst();
    }
    int complete = 0;
    int waiting_time [ready_queue_rear], response_time[ready_queue_rear], turnaround_time [ready_queue_rear];

    while(complete<ready_queue_rear){
        // find next process to execute
        int minm = INT_MAX;
        int highest = -1;
        //bool found = false;
        for(int i=0; i<ready_queue_rear; i++){
            if(READY_QUEUE[i].getPriority() < minm &&
               READY_QUEUE[i].getArrivalTime() <= clock
               && READY_QUEUE[i].getProcessStatus()!="Terminated"){
                minm = READY_QUEUE[i].getBurst();
                highest = i;
            }
        }
        // no suitable process found, incrementing clock time
        if(highest==-1){
            clock++;
            continue;
        }
        /*
        for(int j = clock; j < clock + remaining_time[shortest]; j++){
            GANTT_CHART[j] = READY_QUEUE[shortest].getProcessID();
        }*/
        if(seen[highest]==false){
            response_time[highest] = clock - READY_QUEUE[highest].getArrivalTime();
            seen[highest]=true;
        }
        clock = clock + READY_QUEUE[highest].getBurst();
        READY_QUEUE[highest].setProcessStatus("Terminated");
        waiting_time[highest] = clock -
           READY_QUEUE[highest].getArrivalTime() -
           READY_QUEUE[highest].getBurst();
        turnaround_time[highest] = clock -
           READY_QUEUE[highest].getArrivalTime();
        complete++;
    }
    cout << "SJF Scheduling" << endl;
    //displayGanttChart(clock);
    cout << setw(30) << "Average Waiting Time: " << average(waiting_time) << endl;
    cout << setw(30) << "Average Response Time: " << average(response_time) << endl;
    cout << setw(30) << "Average Turnaround TIme: " << average(turnaround_time) << endl;

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
    for(int i=0; i<ready_queue_rear; i++){
        READY_QUEUE[i].setProcessStatus("ready");
    }
    executeProcess();
}

void sysConfig(){
    cout << "Enter number of instances of A: ";
    cin >> sysResourceA;
    cout << "Enter number of instances of B: ";
    cin >> sysResourceB;
    cout << "Enter number of instances of C: ";
    cin >> sysResourceC;
    cout << "Enter memory size: ";
    cin >> sysMemorySize;
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
        else if(command=="execute-process"){
            executeProcess();
        }
        else if(command=="reexecute-process"){
            reexecuteProcess();
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
