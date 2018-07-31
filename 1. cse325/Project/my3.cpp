#include<bits/stdc++.h>
#define SIZE 100
using namespace std;

#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c ) cout << a << " : " << b << " : " << c << endl;




int CLOCK;
int finalClock;

class Process{
private:
    int processID;
    string processName;
    string processStatus;
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
    Process(string processName, int burst, int arrivalTime, int priority){
        this->processID = ++(this->processCounter);
        this->processName = processName;
        this->processStatus = "new";
        this->burst = burst;
        this->arrivalTime = arrivalTime;
        this->priority = priority;
    }
    void setProcess(string processName, int burst, int arrivalTime, int priority){
        this->processID = ++(this->processCounter);
        this->processName = processName;
        this->processStatus = "new";
        this->burst = burst;
        this->arrivalTime = arrivalTime;
        this->priority = priority;
    }
    void setProcessID(int processID){this->processID = processID;}
    void setProcessName(string processName){this->processName = processName;}
    void setProcessStatus(string processStatus){this->processStatus = processStatus;}
    void setBurst(int burst){this->burst = burst;}
    void setArrivalTime(int arrivalTime){this->arrivalTime = arrivalTime;}
    void setPriority(int priority){this->priority = priority;}
    int getProcessID(){ return this->processID;}
    string getProcessName(){ return this->processName;}
    string getProcessStatus(){return this->processStatus;}
    int getBurst(){ return this->burst;}
    int getArrivalTime(){ return this->arrivalTime;}
    int getPriority(){ return this->priority;}
};

/* for incrementing process id automatically */
int Process::processCounter = 0;

/* you may use other advanced data structures such as Linked List or Vector */
Process JOB_QUEUE[SIZE];
Process READY_QUEUE[SIZE];
Process DEVICE_QUEUE[SIZE];
vector<Process> readyQueue, jobQueue, deviceQueue;

/* for producing gantt chart */
int GANTT_CHART[1000];

/* keeping track of processes in the queue */
int job_queue_front, job_queue_rear = 0;
int ready_queue_front, ready_queue_rear = 0;
int device_queue_front, device_queue_rear = 0;
double getResponseTime();
double getWaitingTime();
double getTurnAroundTime();
void showProcessQueue(vector<Process>);


void initGanttChart(){
    for(int i=0; i<1000; i++)
        GANTT_CHART[i] = -1;
}

/* initiating a process */
void createProcess(){
    int pBurst, pArrivalTime, pPriority;
    string pName;
    cout << "Enter Process Name: ";
    cin >> pName;
    cout << "Enter Burst: ";
    cin >> pBurst;
    cout << "Enter Arrival Time: ";
    cin >> pArrivalTime;
    cout << "Enter Priority: ";
    cin >> pPriority;
    /* put the process into the job queue */
    jobQueue.push_back( Process(pName, pBurst, pArrivalTime, pPriority) );
    //JOB_QUEUE[job_queue_rear++].setProcess(pName, pBurst, pArrivalTime, pPriority);
}

void showProcessQueue(vector<Process> myVec){
    //cc(myVec.size())
    cout << setw(10) << "ID" << setw(10) << "Name" << setw(10) << "Burst" << setw(10) << "Arrival" << setw(10) << "Priority" << endl;
    for(int i = 0; i < myVec.size(); i++){
        cout << setw(10) << myVec[i].getProcessID() << setw(10) << myVec[i].getProcessName()
        << setw(10) << myVec[i].getBurst() << setw(10) << myVec[i].getArrivalTime()
        << setw(10) << myVec[i].getPriority() << endl;
    }
}

/* printing job queue */
void showJobQueue(){
    /*
    cout.setf(ios::left, ios::adjustfield);
    cout << "Job Queue" << endl;
    cout << "---------" << endl;
    cout << setw(10) << "ID" << setw(10) << "Name" << setw(10) << "Burst" << setw(10) << "Arrival" << setw(10) << "Priority" << endl;
    for(int i = 0; i < job_queue_rear; i++){
        cout << setw(10) << JOB_QUEUE[i].getProcessID() << setw(10) << JOB_QUEUE[i].getProcessName()
        << setw(10) << JOB_QUEUE[i].getBurst() << setw(10) << JOB_QUEUE[i].getArrivalTime()
        << setw(10) << JOB_QUEUE[i].getPriority() << endl;
    }
    */
    cout.setf(ios::left, ios::adjustfield);
    cout << "Job Queue" << endl;
    cout << "---------" << endl;
    showProcessQueue(readyQueue);
}
/* printing ready queue */
void showReadyQueue(){
    /*
    cout.setf(ios::left, ios::adjustfield);
    cout << "Ready Queue" << endl;
    cout << "---------" << endl;
    cout << setw(10) << "ID" << setw(10) << "Name" << setw(10) << "Burst" << setw(10) << "Arrival" << setw(10) << "Priority" << endl;
    for(int i = 0; i < ready_queue_rear; i++){
        cout << setw(10) << READY_QUEUE[i].getProcessID() << setw(10) << READY_QUEUE[i].getProcessName()
        << setw(10) << READY_QUEUE[i].getBurst() << setw(10) << READY_QUEUE[i].getArrivalTime()
        << setw(10) << READY_QUEUE[i].getPriority() << endl;
    }
    */
    cout.setf(ios::left, ios::adjustfield);
    cout << "Ready Queue" << endl;
    cout << "---------" << endl;
    showProcessQueue(readyQueue);
}
/* once user is ready, shifting process from new -> ready state */
void readyProcess(){
    cout << "Transferring Processes from Job Queue to Ready Queue." << endl;
    /*
    for(int i = 0; i<job_queue_rear; i++){
        READY_QUEUE[i].setProcessID(JOB_QUEUE[i].getProcessID());
        READY_QUEUE[i].setProcessName(JOB_QUEUE[i].getProcessName());
        READY_QUEUE[i].setProcessStatus("ready");
        READY_QUEUE[i].setBurst(JOB_QUEUE[i].getBurst());
        READY_QUEUE[i].setArrivalTime(JOB_QUEUE[i].getArrivalTime());
        READY_QUEUE[i].setPriority(JOB_QUEUE[i].getPriority());
    }
    */
    for(int i=0;i<jobQueue.size();i++){
        readyQueue.push_back(jobQueue[i]);
    }
    jobQueue.clear();
    //ready_queue_rear = job_queue_rear;
    //job_queue_rear = 0;
    cout << "Transfer Completed." << endl;
}
/* displaying gantt chart */
void displayGanttChart(int clock){
    cout.setf(ios::left, ios::adjustfield);
    for(int i=0; i<clock; i++){
        if(i%10==0 && i/10>=1)
            cout << endl;
        cout << setw(3) << GANTT_CHART[i];
    }
    cout << endl;
}
/* calculating average of a given array */
double average(int *list){
    int sum = 0;
    for(int i = 0; i<ready_queue_rear; i++){
        sum += list[i];
    }
    return sum*1.0/ready_queue_rear;
}
double avrg(int arr[], double n){
    double sum = 0;
    for(int i = 0; i<n ;i++){
        sum += arr[i];
    }
    return sum*1.0/n;
}
double getResponseTime(){
    vector<int>vec;
    int current = -1;
    double counter = 0, sum = 0;
    map<int, int>mp;
    for(int i=0;i<finalClock;i++){
        if(GANTT_CHART[i]!=current){
            if(!mp[GANTT_CHART[i]]){
                mp[GANTT_CHART[i]] = 1;
                sum += i;
                counter++;
                //vec.push_back(i);
            }
            current = GANTT_CHART[i];
        }
    }
    return (sum / counter);
}

double getWaitingTime(){
    int current = -1,i;
    double counter = 0;
    for(i =0;i<finalClock;i++){
        if(GANTT_CHART[i] != current){
            counter++;
        }
    }
    vector<int>timeSum;
    timeSum.assign(counter, 0);


}
double getTurnAroundTime(){}


/* compare function to sort the processes for FCFS according to arrival time*/
int compare(const void *a, const void *b){
    if (((Process *)a)->getArrivalTime() == ((Process *)b)->getArrivalTime()){
       return ((Process *)a)->getProcessID() - ((Process *)b)->getProcessID();
    }
    return ((Process *)a)->getArrivalTime() - ((Process *)b)->getArrivalTime();
}


int compareArrivalTime(Process p1, Process p2){
    //return 1;
    return (p1.getArrivalTime() < p2.getArrivalTime());
    //return p1->getArrivalTime() < p2->getArrivalTime();
}
int compareBurstTime(Process p1, Process p2){
    //return 1;
    return (p1.getBurst() < p2.getBurst());
    //return p1->getArrivalTime() < p2->getArrivalTime();
}
int comparePriority(Process p1, Process p2){
    //return 1;
    return (p1.getPriority() < p2.getPriority());
    //return p1->getArrivalTime() < p2->getArrivalTime();
}
void showGanttChart(){
    int i;
    for(i = 0;i<finalClock;i++){
        cout << GANTT_CHART[i] << " ";
    }
    cout << endl;
}
void fcfs_mine(){
    sort(readyQueue.begin(), readyQueue.end(), compareArrivalTime);
    //qsort(READY_QUEUE, ready_queue_rear, sizeof(READY_QUEUE[0]), compare);
    showReadyQueue();
    /* complete the rest */
    //for(int i=0;i<ready_queue_rear;i++){
  double sumWait =0, sumTurnAroundTime = 0, waitingTime,turnAroundTime;
    //for(int i=0;i<ready_queue_rear;i++){
    int current= 0;
    CLOCK = 0;
    vector<Process>onHand;
    int myTime[readyQueue.size()];
    int i;

    for(CLOCK = 0;;CLOCK++){
        for(i=0;i<readyQueue.size();i++){
            if(readyQueue[i].getArrivalTime() == CLOCK){
                onHand.push_back(readyQueue[i]);
                int ps = onHand.size()-1;

                myTime[ps] = onHand[ps].getBurst();
                //msg(ps, myTime[ps])
            }
        }
        GANTT_CHART[CLOCK] = onHand[current].getProcessID();
        myTime[current]--;
        if(myTime[current] == 0){
            current++;
            if(current>= readyQueue.size()){
                //cc(myTime[current])
                CLOCK++;
                break;
            }
        }
    }

    finalClock = CLOCK;
    showGanttChart();
    msg("Response Time", getResponseTime());
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

void sjf_mine(){

/*
    int clock = 0;
    vector<Process> onHand;
    int i,myTime[200],current = 0;
    for(CLOCK = 0;;CLOCK++){
        for(i=0;i<readyQueue.size();i++){
            if(readyQueue[i].getArrivalTime() == CLOCK){
                onHand.push_back(readyQueue[i]);
                int ps = onHand.size()-1;

                myTime[ps] = onHand[ps].getBurst();
                //msg(ps, myTime[ps])
            }
        }
        if(onHand.size() != 0 ){
            sort(onHand.begin(), onHand.end(), compareBurstTime);
        }
        sort(onHand.begin(), onHand.end(), compareBurstTime);
        GANTT_CHART[CLOCK] = onHand[current].getProcessID();
        //myTime[current]--;
        if(myTime[current] == 0){
            current++;
            if(current>= readyQueue.size()){
                //cc(myTime[current])
                CLOCK++;
                break;
            }
        }
    }
    */
    initGanttChart();
    int clock = 0;
    int i =0;
    int sz = readyQueue.size();
    bool seen[sz];
    int remainingTime[sz];
    for(int i=0;i<sz;i++){
        seen[i] = false;
        remainingTime[i] = readyQueue[i].getBurst();
    }
    int complete = 0;
    int waitingTime[sz], responseTime[sz], turnAroundTime[sz];
    while(complete<sz){
        int minm = INT_MAX;
        int shortest = -1;
        bool found = false;
        for(int i=0;i<sz;i++){
                if(readyQueue[i].getBurst() < minm && readyQueue[i].getArrivalTime() <= clock && readyQueue[i].getProcessStatus() != "Terminated"){
                  minm = readyQueue[i].getBurst();
                  shortest = i;
                }
        }
        if(shortest == -1){

            clock++;
            continue;
        }
        for(int j=clock;j<clock+remainingTime[shortest];j++){
            GANTT_CHART[j] = readyQueue[shortest].getProcessID();
        }
        if(seen[shortest] == false){
            responseTime[shortest] = clock - readyQueue[shortest].getArrivalTime();
            seen[shortest] = true;
        }
        clock += readyQueue[shortest].getBurst();
        readyQueue[shortest].setProcessStatus("Terminated");
        waitingTime[shortest] = clock - readyQueue[shortest].getArrivalTime() - readyQueue[shortest].getBurst();
        turnAroundTime[shortest] = clock - readyQueue[shortest].getArrivalTime();
        complete++;
    }

    cout << "SJF Scheduling: " << endl;
    displayGanttChart(clock);
    //cout << waitingTime << " : " << responseTime << " : " << turnAroundTime << endl;
    cout << "Average Waiting Time: " << avrg(waitingTime,sz) << endl;
    cout << "Average Response Time: " << avrg(responseTime,sz) << endl;
    cout << "Average Trunaround Time: " << avrg(turnAroundTime,sz) << endl;
}
void srtf(){
    initGanttChart();
    int clock = 0;
    int i =0;
    int sz = readyQueue.size();
    bool seen[sz];
    int remainingTime[sz];
    int current = 0;
    sort(readyQueue.begin(), readyQueue.end(), compareArrivalTime);
    for(int i=0;i<sz;i++){
        seen[i] = false;
        remainingTime[i] = readyQueue[i].getBurst();
    }
    int complete = 0;
    int waitingTime[sz], responseTime[sz], turnAroundTime[sz];
    for(clock = 0;;clock++){
        if(readyQueue[current].getArrivalTime() < clock){
            GANTT_CHART[clock] = -1;
            continue;
        }else if(readyQueue[current].getArrivalTime() == clock){
            for(int i=0;i<sz;i++){

            }
        }
    }
}

void priorityScheduling(){

    initGanttChart();
    int clock = 0;
    int i =0;
    int sz = readyQueue.size();
    bool seen[sz];
    int remainingTime[sz];
    int current = 0;
    sort(readyQueue.begin(), readyQueue.end(), compareArrivalTime);
    deque<Process>onHand;
    int freezeTill = 0;
    for(clock=0;;clock++){
        for(i=0;i<sz;i++){
            if(readyQueue[i].getArrivalTime() == clock){
                onHand.push_back(readyQueue[i]);
            }
        }
        sort(onHand.begin(), onHand.end(), comparePriority);
        onHand[current];
    }

}


void priorityScheduling_mine(){
    initGanttChart();
    int clock = 0;
    int i =0;
    int sz = readyQueue.size();
    bool seen[sz];
    int remainingTime[sz];
    for(int i=0;i<sz;i++){
        seen[i] = false;
        remainingTime[i] = readyQueue[i].getBurst();
    }
    int complete = 0;
    int waitingTime[sz], responseTime[sz], turnAroundTime[sz];
    while(complete<sz){
        int minm = INT_MAX;
        int shortest = -1;
        bool found = false;
        for(int i=0;i<sz;i++){
            if(readyQueue[i].getPriority() < minm && readyQueue[i].getArrivalTime() <= clock && readyQueue[i].getProcessStatus() != "Terminated"){
              minm = readyQueue[i].getPriority();
              shortest = i;
              //msg(minm, i)
            }
        }
        if(shortest == -1){

            clock++;
            continue;
        }
        for(int j=clock;j<clock+remainingTime[shortest];j++){
            GANTT_CHART[j] = readyQueue[shortest].getProcessID();
        }
        if(seen[shortest] == false){
            responseTime[shortest] = clock - readyQueue[shortest].getArrivalTime();
            seen[shortest] = true;
        }
        clock += readyQueue[shortest].getBurst();
        readyQueue[shortest].setProcessStatus("Terminated");
        waitingTime[shortest] = clock - readyQueue[shortest].getArrivalTime() - readyQueue[shortest].getBurst();
        turnAroundTime[shortest] = clock - readyQueue[shortest].getArrivalTime();
        complete++;
        msg(clock, shortest)
    }

    cout << "SJF Scheduling: " << endl;
    displayGanttChart(clock);
    cout << waitingTime << " : " << responseTime << " : " << turnAroundTime << endl;
    cout << "Average Waiting Time: " << avrg(waitingTime,sz) << endl;
    cout << "Average Response Time: " << avrg(responseTime,sz) << endl;
    cout << "Average Trunaround Time: " << avrg(turnAroundTime,sz) << endl;
}
void preemptivePriorityScheduling(){}
void preemptivePriorityScheduling_mine(){
    initGanttChart();
    int clock = 0;
    int i =0;
    int sz = readyQueue.size();
    int seen[sz];
    int remainingTime[sz];
    for(int i=0;i<sz;i++){
        seen[i] = 0;
        remainingTime[i] = readyQueue[i].getBurst();
    }
    vector<int>inserted;
    inserted.assign(sz, 0);
    int complete = 0,current = 0, ganttCounter = 0;
    int waitingTime[sz], responseTime[sz], turnAroundTime[sz];
    vector<Process>onHand;
    //sort(readyQueue.begin(), readyQueue.end(), compareArrivalTime);
    while(complete<sz){
        int minm = INT_MAX;
        int shortest = -1;
        bool found = false;

        for(i=0;i<sz;i++){
            if(readyQueue[i].getArrivalTime() < clock && inserted[i] == 0){
                onHand.push_back(readyQueue[i]);
                inserted[i] = 1;
                //msg("Inserted", readyQueue[i].getProcessID())
            }
        }

        for(int i=0;i<onHand.size();i++){
            if(onHand[i].getPriority() < minm && seen[i] < 2){ // seen = 2 means terminated
              minm = onHand[i].getPriority();
              shortest = i;
            }
        }
        msg2("FOUND: " ,minm, clock)
        if(shortest == -1){
            GANTT_CHART[clock] = -1;
            clock++;
            continue;
        }

        GANTT_CHART[clock] = onHand[shortest].getProcessID();

        if(seen[shortest] == 0){
            responseTime[shortest] = clock - onHand[shortest].getArrivalTime();
            seen[shortest] = 1;
        }else{
            remainingTime[shortest]--;
            if(remainingTime[shortest] == 0){
                complete++;
                seen[shortest] = 2;
            }
        }
        clock++;
        //clock += readyQueue[shortest].getBurst();
        //readyQueue[shortest].setProcessStatus("Terminated");
        //waitingTime[shortest] = clock - readyQueue[shortest].getArrivalTime() - readyQueue[shortest].getBurst();
        //turnAroundTime[shortest] = clock - readyQueue[shortest].getArrivalTime();
    }
    displayGanttChart(clock);
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
        sjf_mine();
        break;
    case 3:
        srtf();
        break;
    case 4:
        priorityScheduling_mine();
        break;
    case 5:
        preemptivePriorityScheduling_mine();
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

int main(){
    string command;
    do{
        cout << "> ";
        cin >> command;
        if(command=="create-process"){
            createProcess();
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
