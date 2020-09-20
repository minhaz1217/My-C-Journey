/*
Minhazul Hayat Khan
Website: www.minhazul.com
EWU, Bangladesh
Problem Name:
Problem Link:
Date : 04 / 07 / 2020
Comment:
*/
#include<bits/stdc++.h>
//#include<iostream>
using namespace std;

class Compression{
public:
    string id;
    string data;
    Compression(string id):id(id){}
    void SetData(string data){
        this->data =data;
        cout << "Setting data to " << data << endl;
    }
    void DoCompression(){
        cout << "Doing '"<< this->id << "' compression on " << data << endl;
    }
    string getId(){
        return this->id;
    }
};

class Application{
private:
    // using singleton pattern as this is an application, it won't need more than one instance of itself in the whole lifecycle
    static Application *instance;
    vector<Compression> compressions;
    string currentCompressionId;
    string path;
    Application(){
    }
public:
    static Application *getInstance() {
      if (!instance){
        instance = new Application();
      }
      return instance;
    }
    void AddCompressionAlgorithm(Compression c){
        compressions.push_back(c);
    }
    void SelectCurrentAlgorithm(string id){
        for(int i=0;i<compressions.size();i++){
            if(this->compressions[i].getId() == id){
                currentCompressionId = id;
                cout << currentCompressionId << " selected as current algorithm" << endl;
                return;
            }
        }
        cout << id << " not in application algorithm list." << endl;
    }
    void OpenFile(string path){
        this->path = path;
        cout << "Path set to: " << path << endl;
    }
    void Compress(){
        for(int i=0;i<compressions.size();i++){
            if(this->compressions[i].getId() == this->currentCompressionId){
                this->compressions[i].SetData(this->path);
                this->compressions[i].DoCompression();
                break;
            }
        }
    }
    ~Application(){
        this->compressions.clear();
        this->currentCompressionId = "";
        this->path = "";
    }
};
Application *Application::instance = 0;

int main(){
    cout << "Simulation of an compression application using singleton pattern" << endl;
    Compression c1("7z");
    Compression c2("bzip2");
    Compression c3("gzip");
    Compression c4("tar");
    Application *application = application->getInstance();
    application->AddCompressionAlgorithm(c1);
    application->AddCompressionAlgorithm(c2);
    application->AddCompressionAlgorithm(c3);
    application->SelectCurrentAlgorithm("tarm");
    application->SelectCurrentAlgorithm("gzip");
    application->OpenFile("D:/output.txt");
    application->Compress();
    cout << endl;
    Compression c5("wim");
    Compression c6("xz");
    Compression c7("zip");
    application->AddCompressionAlgorithm(c4);
    application->AddCompressionAlgorithm(c5);
    application->AddCompressionAlgorithm(c6);
    application->AddCompressionAlgorithm(c7);
    application->SelectCurrentAlgorithm("zip");
    application->OpenFile("D:/output.txt");
    application->Compress();


    cout <<endl <<  "-----After changing object-----" << endl;
    Application *application2 = application2->getInstance();
    application2->SelectCurrentAlgorithm("tar");
    application2->OpenFile("D:/output.txt");
    application2->Compress();

    application2->~Application();
    return 0;
}
