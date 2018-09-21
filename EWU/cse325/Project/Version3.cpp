#include<bits/stdc++.h>
#define SIZE 100
using namespace std;


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

}void showDeviceQueue(){
    cout.setf(ios::left, ios::adjustfield);
    cout << "DEVICE Queue" << endl;
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

void readyProcess(){
    cout << "Transferring Processes from Job Queue to Ready Queue." << endl;
    Process temp[job_queue_rear];
    int tempCounter = 0;
    for(int i = 0; i<job_queue_rear; i++){
        if(JOB_QUEUE[i].getHasIOoperation() == 1){
                cout << "Sent " << i << " TO DEVICE QUEUE" << endl;
           // cout << "Sent " << i << " TO device" << endl;
            DEVICE_QUEUE[device_queue_rear].setProcessID(JOB_QUEUE[i].getProcessID());
            DEVICE_QUEUE[device_queue_rear].setProcessName(JOB_QUEUE[i].getProcessName());
            DEVICE_QUEUE[device_queue_rear].setProcessStatus("waiting");
            DEVICE_QUEUE[device_queue_rear].setBurst(JOB_QUEUE[i].getBurst());
            DEVICE_QUEUE[device_queue_rear].setArrivalTime(JOB_QUEUE[i].getArrivalTime());
            DEVICE_QUEUE[device_queue_rear].setPriority(JOB_QUEUE[i].getPriority());
            DEVICE_QUEUE[device_queue_rear].setHasIOoperation(JOB_QUEUE[i].getHasIOoperation());
            DEVICE_QUEUE[device_queue_rear].setProcessSize(JOB_QUEUE[i].getProcessSize());
            device_queue_rear++;
        }else{
            if(sysRemainingMemorySize >= JOB_QUEUE[i].getProcessSize()){
            cout << "Sent " << i << " TO READY QUEUE" << endl;
                READY_QUEUE[ready_queue_rear].setProcessID(JOB_QUEUE[i].getProcessID());
                READY_QUEUE[ready_queue_rear].setProcessName(JOB_QUEUE[i].getProcessName());
                READY_QUEUE[ready_queue_rear].setProcessStatus("ready");
                READY_QUEUE[ready_queue_rear].setBurst(JOB_QUEUE[i].getBurst());
                READY_QUEUE[ready_queue_rear].setArrivalTime(JOB_QUEUE[i].getArrivalTime());
                READY_QUEUE[ready_queue_rear].setPriority(JOB_QUEUE[i].getPriority());
                READY_QUEUE[ready_queue_rear].setHasIOoperation(JOB_QUEUE[i].getHasIOoperation());
                READY_QUEUE[ready_queue_rear].setProcessSize(JOB_QUEUE[i].getProcessSize());
                ready_queue_rear++;
                sysRemainingMemorySize -= JOB_QUEUE[i].getProcessSize();
                //JOB_QUEUE[i] = NULL;
            }else{
                cout << "Didn't Send " << i << endl;
                temp[tempCounter].setProcessID(JOB_QUEUE[i].getProcessID());
                temp[tempCounter].setProcessName(JOB_QUEUE[i].getProcessName());
                temp[tempCounter].setProcessStatus("new");
                temp[tempCounter].setBurst(JOB_QUEUE[i].getBurst());
                temp[tempCounter].setArrivalTime(JOB_QUEUE[i].getArrivalTime());
                temp[tempCounter].setPriority(JOB_QUEUE[i].getPriority());
                temp[tempCounter].setHasIOoperation(JOB_QUEUE[i].getHasIOoperation());
                temp[tempCounter].setProcessSize(JOB_QUEUE[i].getProcessSize());
                tempCounter++;
            }
        }
        /*
        check whether hasIo == 1 or nnot
        if yes,
            place the process into device queue;
        else
            check whether memory is available
            if yes
                then place the process into ready queue
            else
                continue;
*/

    }
    //ready_queue_rear = job_queue_rear-device_queue_rear;
    job_queue_rear = 0;
    for(int i=0;i<tempCounter;i++){
        JOB_QUEUE[job_queue_rear].setProcessID(temp[i].getProcessID());
        JOB_QUEUE[job_queue_rear].setProcessName(temp[i].getProcessName());
        JOB_QUEUE[job_queue_rear].setProcessStatus("new");
        JOB_QUEUE[job_queue_rear].setBurst(temp[i].getBurst());
        JOB_QUEUE[job_queue_rear].setArrivalTime(temp[i].getArrivalTime());
        JOB_QUEUE[job_queue_rear].setPriority(temp[i].getPriority());
        JOB_QUEUE[job_queue_rear].setHasIOoperation(temp[i].getHasIOoperation());
        JOB_QUEUE[job_queue_rear].setProcessSize(temp[i].getProcessSize());
        job_queue_rear++;
    }
    cout << "Transfer Completed." << endl;
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
    sysRemainingMemorySize = sysMemorySize;
}
void showAvailAbleMemory(){
    cout << "Available memory: " << sysRemainingMemorySize << endl;
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
        else if(command=="show-available-memory"){
            showAvailAbleMemory();
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
