#include<bits/stdc++.h>
#define SIZE 100
using namespace std;
int CLOCK;
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

/* for producing gantt chart */
int GANTT_CHART[1000];

/* keeping track of processes in the queue */
int job_queue_front, job_queue_rear = 0;
int ready_queue_front, ready_queue_rear = 0;
int device_queue_front, device_queue_rear = 0;

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
    JOB_QUEUE[job_queue_rear++].setProcess(pName, pBurst, pArrivalTime, pPriority);
}
/* printing job queue */
void showJobQueue(){
    cout.setf(ios::left, ios::adjustfield);
    cout << "Job Queue" << endl;
    cout << "---------" << endl;
    cout << setw(10) << "ID" << setw(10) << "Name" << setw(10) << "Burst" << setw(10) << "Arrival" << setw(10) << "Priority" << endl;
    for(int i = 0; i < job_queue_rear; i++){
        cout << setw(10) << JOB_QUEUE[i].getProcessID() << setw(10) << JOB_QUEUE[i].getProcessName()
        << setw(10) << JOB_QUEUE[i].getBurst() << setw(10) << JOB_QUEUE[i].getArrivalTime()
        << setw(10) << JOB_QUEUE[i].getPriority() << endl;
    }

}
/* printing ready queue */
void showReadyQueue(){
    cout.setf(ios::left, ios::adjustfield);
    cout << "Ready Queue" << endl;
    cout << "---------" << endl;
    cout << setw(10) << "ID" << setw(10) << "Name" << setw(10) << "Burst" << setw(10) << "Arrival" << setw(10) << "Priority" << endl;
    for(int i = 0; i < ready_queue_rear; i++){
        cout << setw(10) << READY_QUEUE[i].getProcessID() << setw(10) << READY_QUEUE[i].getProcessName()
        << setw(10) << READY_QUEUE[i].getBurst() << setw(10) << READY_QUEUE[i].getArrivalTime()
        << setw(10) << READY_QUEUE[i].getPriority() << endl;
    }

}
/* once user is ready, shifting process from new -> ready state */
void readyProcess(){
    cout << "Transferring Processes from Job Queue to Ready Queue." << endl;
    for(int i = 0; i<job_queue_rear; i++){
        READY_QUEUE[i].setProcessID(JOB_QUEUE[i].getProcessID());
        READY_QUEUE[i].setProcessName(JOB_QUEUE[i].getProcessName());
        READY_QUEUE[i].setProcessStatus("ready");
        READY_QUEUE[i].setBurst(JOB_QUEUE[i].getBurst());
        READY_QUEUE[i].setArrivalTime(JOB_QUEUE[i].getArrivalTime());
        READY_QUEUE[i].setPriority(JOB_QUEUE[i].getPriority());
    }
    ready_queue_rear = job_queue_rear;
    job_queue_rear = 0;
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
/* compare function to sort the processes for FCFS according to arrival time*/
int compare(const void *a, const void *b){
    if (((Process *)a)->getArrivalTime() == ((Process *)b)->getArrivalTime()){
       return ((Process *)a)->getProcessID() - ((Process *)b)->getProcessID();
    }
    return ((Process *)a)->getArrivalTime() - ((Process *)b)->getArrivalTime();
}

void fcfs(){
    qsort(READY_QUEUE, ready_queue_rear, sizeof(READY_QUEUE[0]), compare);
    showReadyQueue();
    /* complete the rest */
    double sumWait =0, sumTurnAroundTime = 0, waitingTime,turnAroundTime;


    //for(int i=0;i<ready_queue_rear;i++){
    int current= 0;
    CLOCK = 0;
    while(1){
        if(current == ready_queue_rear){
            break;
        }
        Process p = READY_QUEUE[current];
        if( p.getArrivalTime() <= CLOCK && p.getProcessStatus() != "terminated"){
            CLOCK += p.getBurst();
            waitingTime = CLOCK - p.getArrivalTime() - p.getBurst();
            turnAroundTime = CLOCK - p.getArrivalTime();
            p.setProcessStatus("terminated");

            sumWait += waitingTime;
            sumTurnAroundTime += turnAroundTime;
            current++;
        }else{
            CLOCK++;
            //CLOCK = p.getArrivalTime();
        }
    }

    cout << "Average Waiting Time: " << sumWait/(double)current << endl;
    cout << "Average Turn Around Time: " << sumTurnAroundTime/(double)current << endl;
    cout << "Average Response Time: " << sumWait/(double)current << endl;



}

int compareBurstTime(const void *a, const void *b){
    if (((Process *)a)->getBurst() == ((Process *)b)->getBurst()){
       return ((Process *)a)->getProcessID() - ((Process *)b)->getProcessID();
    }
    return ((Process *)a)->getBurst() - ((Process *)b)->getBurst();
}
void sjf(){
    qsort(READY_QUEUE, ready_queue_rear, sizeof(READY_QUEUE[0]), compareBurstTime);
    showReadyQueue();
    /* complete the rest */
    double sumWait =0, sumTurnAroundTime = 0, waitingTime,turnAroundTime, sumResponseTime = 0,responseTime;


    //for(int i=0;i<ready_queue_rear;i++){
    int current= 0;
    CLOCK = 0;
    while(1){
        if(current == ready_queue_rear){
            break;
        }
        Process p = READY_QUEUE[current];
        if( p.getArrivalTime() <= CLOCK && p.getProcessStatus() != "terminated"){
            responseTime = CLOCK - p.getArrivalTime() ;
            CLOCK += p.getBurst();
            waitingTime = CLOCK - p.getArrivalTime() - p.getBurst();
            turnAroundTime = CLOCK - p.getArrivalTime();
            p.setProcessStatus("terminated");

            sumWait += waitingTime;
            sumTurnAroundTime += turnAroundTime;
            sumResponseTime += responseTime;
            current++;
        }else{
            CLOCK++;
            //CLOCK = p.getArrivalTime();
        }
    }

    cout << "Average Waiting Time: " << sumWait/(double)current << endl;
    cout << "Average Turn Around Time: " << sumTurnAroundTime/(double)current << endl;
    cout << "Average Response Time: " << sumResponseTime/(double)current << endl;
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
