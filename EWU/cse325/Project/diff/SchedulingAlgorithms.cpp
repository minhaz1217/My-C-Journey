
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
            //msg( onHand.size(), temp.size());
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

    int currentTime = 0;
    int currentIndex = 0;
    while(temp.size()!=0 || onHand.size() !=0){

        while(temp.size()>0 && temp[0].getArrivalTime() == CLOCK){
            onHand.push_back(make_pair(temp[0], temp[0].getBurst()));
            temp.pop_front();
            //msg( onHand.size(), temp.size());
        }
        //showProcessQueue(temp);
        //cc(CLOCK)
        if(onHand.size() != 0){
            GANTT_CHART[CLOCK] = onHand[0].first.getProcessID();
            onHand[0].second--;
            currentTime++;
            if(onHand[0].second == 0){
                onHand.pop_front();
                currentTime = 0;
            }
            if(currentTime == timeQuantum){
                onHand.push_back(onHand[0]);
                onHand.pop_front();
                currentTime = 0;
            }
            //msg(clock,currentTime)
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
