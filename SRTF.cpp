#include<iostream>
#include<vector>
using namespace std; 
struct process
{
    int bt;
    int pid;
    int at;
    int flag;
}p[10];

int main(){
    int bt[10], at[10];
    int is_completed[10];
    int n;
    cout<<"Enter number of processes: ";
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<"Enter burst time of process "<<i+1<<": ";
        cin>>p[i].bt;
        cout<<"Enter arrival time of process "<<i+1<<": ";
        cin>>p[i].at;
        p[i].pid = i;
        p[i].flag = 0;
    }
    int ctr = 0;
    int time = 0;
    int minimum;
    while(ctr!=n){
        vector<int> ready;
        for(int i=0;i<n;i++){
            if(p[i].at<=time && p[i].bt!=0){
                ready.push_back(i);
                minimum = i;
            }
        }
        for(auto& i: ready){
            if(p[minimum].bt>p[i].bt){
                minimum = i;
            }
        }
        p[minimum].bt = p[minimum].bt-1;
        time++;
        cout<<"Executing process with pid: "<<p[minimum].pid<<endl;
        cout<<"Time elasped: "<<time<<endl;
        if(p[minimum].bt ==0){
            ctr++;
        }
    }
}