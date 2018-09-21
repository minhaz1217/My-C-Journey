
/* for incrementing process id automatically */
int Process::processCounter = 0;
/* for producing gantt chart */
int GANTT_CHART[1000];
deque<Process> readyQueue, jobQueue, deviceQueue;

// needed variables
vector<int>sysResource, blocks;
int sysMemorySize;

int sysFrameSize;
int sysRemainingMemorySize;
int sysRemainingFrame;

int sysInternalFragmentation = 0;

vector<int>allocationResource,maxResource, needResource;

//scheduling algorithm
void fcfs();
void sjf();
void srtf();
void priorityScheduling();
void preemptivePriorityScheduling();
void roundRobin();

// get the times
double getResponseTime(int);
double getWaitingTime(int);
double getTurnAroundTime(int);


void showProcessQueue(vector<Process>);
void initGanttChart();
void createProcess();
void displayGanttChart(int);
void showGanttChart(int);
double avrg(int[], double);
int compare(const void *a, const void *b);
int compareArrivalTime(Process p1, Process p2);
int compareBurstTime(Process p1, Process p2);
int compareBurstTime1(pair<Process,int> p1, pair<Process,int> p2);
int comparePriority1(pair<Process,int> p1, pair<Process,int> p2);
int comparePriority(Process p1, Process p2);

void showProcessQueue(deque<Process> receivedQueue);
void showJobQueue();
void showReadyQueue();
void showDeviceQueue();
void showAllQueue();
void sysConfig();
void readyProcess();
void showSystemInfo();
