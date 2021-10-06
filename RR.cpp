#include<iostream>
using namespace std;

struct process{
    int bt;
    int pbt;
    int pid;
    int tat;
    int wt;
}p[10];

int main(){
    int time = 0;
    int n, q;
    cout<<"Enter the number of processes to be executed: ";
    cin>>n;
    cout<<"Enter time quantum: ";
    cin>>q;
    for (int i = 0; i < n; i++){
        cout<<"Enter burst time of process "<<i<<": ";
        cin>>p[i].bt;
        p[i].pid = i;
        p[i].pbt = p[i].bt;
    }
    int ctr = 0;
    while(ctr!=n){
        for(int i=0;i<n;i++){
            if(p[i].bt>0){
                if(p[i].bt<q){
                    cout<<"Executing process with pid: "<<p[i].pid<<endl;
                    time+= p[i].bt;
                    cout<<"Time elasped: "<<time<<endl;
                    p[i].bt = 0;
                }
                else{
                    cout<<"Executing process with pid: "<<p[i].pid<<endl;
                    time+= q;
                    cout<<"Time elasped: "<<time<<endl;
                    p[i].bt -= q;
                }
                if(p[i].bt==0){
                    ctr++;
                    p[i].tat = time;
                    p[i].wt = time - p[i].pbt;
                }
            }
        }
    }
    float avgtat = 0;
    float avgwt = 0;
    for (int i = 0; i < n; i++)
    {
        avgtat += p[i].tat;
        avgwt += p[i].wt;
    }
    avgtat = avgtat/n;
    avgwt = avgwt/n;
    cout<<"Average turnaround time: "<<avgtat<<endl;
    cout<<"Average waiting time: "<<avgwt<<endl;
}