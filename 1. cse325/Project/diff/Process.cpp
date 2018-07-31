vector<int>resource;
int sysMemorySize;

int sysRemainingMemorySize;
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

    Process(string processName, int pSize, int hasIo, int burst, int arrivalTime, int priority){
        this->processID = ++(this->processCounter);
        this->processName = processName;
        this->processSize = pSize;
        this->hasIOoperation = hasIo;
        this->processStatus = "new";
        this->burst = burst;
        this->arrivalTime = arrivalTime;
        this->priority = priority;
    }

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


/* for incrementing process id automatically */
int Process::processCounter = 0;

/* for producing gantt chart */
int GANTT_CHART[1000];

deque<Process> readyQueue, jobQueue, deviceQueue;
