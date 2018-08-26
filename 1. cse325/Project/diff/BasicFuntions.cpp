

void initGanttChart(){
    for(int i=0; i<1000; i++)
        GANTT_CHART[i] = -1;
}

/* initiating a process */
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

    jobQueue.push_back( Process(pName, pSize, pOp,pBurst, pArrivalTime, pPriority) );
    //JOB_QUEUE[job_queue_rear++].setProcess(pName, pBurst, pArrivalTime, pPriority);
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
void showGanttChart(int clockTime){
    int i;
    for(i = 0;i<clockTime;i++){
        cout << GANTT_CHART[i] << " ";
    }
    cout << endl;
}

double avrg(int arr[], double n){
    double sum = 0;
    for(int i = 0; i<n ;i++){
        sum += arr[i];
    }
    return sum*1.0/n;
}


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
int compareBurstTime1(pair<Process,int> p1, pair<Process,int> p2){
    return (p1.first.getBurst() < p2.first.getBurst());
}
int comparePriority1(pair<Process,int> p1, pair<Process,int> p2){
    return (p1.first.getPriority() < p2.first.getPriority());
}

int comparePriority(Process p1, Process p2){
    //return 1;
    return (p1.getPriority() < p2.getPriority());
    //return p1->getArrivalTime() < p2->getArrivalTime();
}


// displaying the queues
void showProcessQueue(deque<Process> receivedQueue){
    //cc(myVec.size())
    cout << setw(10) << "ID" << setw(10) << "Name" << setw(10) << "Burst" << setw(10) << "Arrival"
         << setw(10) << "Priority" << setw(10) << "Size" << setw(10) << "hasIO?" <<endl;
    for(int i = 0; i < receivedQueue.size(); i++){
        cout << setw(10) << receivedQueue[i].getProcessID() << setw(10) << receivedQueue[i].getProcessName()
        << setw(10) << receivedQueue[i].getBurst() << setw(10) << receivedQueue[i].getArrivalTime()
        << setw(10) << receivedQueue[i].getPriority()
        << setw(10) << receivedQueue[i].getProcessSize()
        << setw(10) << receivedQueue[i].getHasIOoperation() << endl;
    }
}

/* printing job queue */
void showJobQueue(){
    cout.setf(ios::left, ios::adjustfield);
    cout << "Job Queue" << endl;
    cout << "---------" << endl;
    showProcessQueue(jobQueue);
}
/* printing ready queue */
void showReadyQueue(){
    cout.setf(ios::left, ios::adjustfield);
    cout << "Ready Queue" << endl;
    cout << "---------" << endl;
    showProcessQueue(readyQueue);
}
// printing device queues
void showDeviceQueue(){
    cout.setf(ios::left, ios::adjustfield);
    cout << "Device Queue" << endl;
    cout << "---------" << endl;
    showProcessQueue(deviceQueue);
}
void showAllQueue(){
    showJobQueue();
    showReadyQueue();
    showDeviceQueue();
}
void showSystemInfo(){
    cout << "-----SYSTEM INFO-----" <<  endl;
    cout << "Sytem Memory Size: " << sysMemorySize << endl;
    cout << "Sytem Frame Size: " << sysFrameSize<< endl;
    cout << "System Resources" << endl;
    for(int i=0;i<sysResource.size();i++){
        cout << "Resource " << i+1 << ": " << sysResource[i] << endl;
    }
    cout << "Internal Fragmentation: " << sysInternalFragmentation << endl;
}
void sysConfig(){
    int a;
    cout << "Enter number of instances of A: ";
    cin >> a;
    sysResource.push_back(a);
    cout << "Enter number of instances of B: ";
    cin >> a;
    sysResource.push_back(a);
    cout << "Enter number of instances of C: ";
    cin >> a;
    sysResource.push_back(a);

    cout << "Enter memory size: ";
    cin >> sysMemorySize;

    cout << "Enter block size: " ;
    cin >> sysFrameSize;

    while( sysMemorySize%sysFrameSize != 0 ){
        cout << "!!!Block size must be a divisible of total memory.!!!\nEnter block size: " ;
        cin >> sysFrameSize;
    }
    blocks.assign(sysFrameSize, 0);
    sysRemainingMemorySize = sysMemorySize;
    sysRemainingFrame = sysMemorySize/ sysFrameSize;
}

/* once user is ready, shifting process from new -> ready state */
void readyProcess(){
    cout << "Transferring Processes from Job Queue to Ready Queue." << endl;
    deque<Process>temp;
    for(int i=0;i<jobQueue.size();i++){
        if(jobQueue[i].getHasIOoperation()){
            deviceQueue.push_back(jobQueue[i]);
        }else{

            if(ceil(jobQueue[i].getProcessSize()/sysFrameSize) <= sysRemainingFrame){
                readyQueue.push_back(jobQueue[i]);
                sysRemainingFrame -= ceil(jobQueue[i].getProcessSize()/sysFrameSize);
                sysInternalFragmentation += ceil(jobQueue[i].getProcessSize()/sysFrameSize)- jobQueue[i].getProcessSize();

                sysRemainingMemorySize -= jobQueue[i].getProcessSize();
            }else{
                cout << "Couldn't assign " << jobQueue[i].getProcessName() << " because of insufficent memory" << endl;
                temp.push_back(jobQueue[i]);
            }
        }
    }
    jobQueue.clear();
    jobQueue = temp;
    cout << "Transfer Completed." << endl;
}


