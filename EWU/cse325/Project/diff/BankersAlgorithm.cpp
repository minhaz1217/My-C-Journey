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
