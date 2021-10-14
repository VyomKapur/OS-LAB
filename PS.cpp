#include<iostream>
#include<vector>

using namespace std;

struct process{
    int bt;
    int pid;
    int ta;
    int wt;
    int priority;
    int at;
    bool flag;
}p[10];

int main(){
    vector<int> v1;
    int n;
    cout<<"Enter number of processes to be executed: ";
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<"Enter burst time of process "<<i+1<<": ";
        cin>>p[i].bt;
        cout<<"Enter priority of process "<<i+1<<": ";
        cin>>p[i].priority;
        cout<<"Enter arrival time of process "<<i+1<<": ";
        cin>>p[i].at;
        p[i].pid = i;
        p[i].flag = false;
    }
    int time = 0;
    int ctr = 0;
    for(int i=0; i<(n-1); i++)
    {
        for(int j=0; j<(n-i-1); j++)
        {
            if(p[j].priority>p[j+1].priority)
            {
                struct process temp;
                temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
            }
            if(p[j].priority==p[j+1].priority){
                if(p[j].pid>p[j+1].pid){
                    struct process temp;
                    temp = p[j];
                    p[j] = p[j+1];
                    p[j+1] = temp;
                }
            }
        }
    }
    while(ctr!=n){
        for(int i=0;i<n;i++){
            if(time>=p[i].at && p[i].flag!=true){
                time += p[i].bt;
                p[i].ta = time-p[i].at;
                p[i].wt = p[i].ta-p[i].bt;
                cout<<"Completed process with pid: "<<p[i].pid<<endl;
                cout<<"Time elapsed: "<<time<<" s"<<endl;
                p[i].flag = true;
                ctr++;
            }
        }
    }
    int ata = 0, awt=0;
    for (int i = 0; i < n; i++)
    {
        ata += p[i].ta;
        awt += p[i].wt;
    }
    ata = ata/n;
    awt = awt/n;
    cout<<"Average waiting time: "<<ata<<endl;
    cout<<"Average turnaround time: "<<awt<<endl;
}