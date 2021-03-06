#include<iostream>
using namespace std;

struct process{
    int bt;
    int pid;
    int tat;
    int wt;
}p[10];

int main(){
    int n;
    cout<<"Enter number of processes to be executed: ";
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<"Enter burst time of process "<<i+1<<": ";
        cin>>p[i].bt;
        p[i].pid = i;
    }
    for(int i=0; i<(n-1); i++)
    {
        for(int j=0; j<(n-i-1); j++)
        {
            if(p[j].bt>p[j+1].bt)
            {
                struct process temp;
                temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
            }
            if(p[j].bt==p[j+1].bt){
                if(p[j].pid>p[j+1].pid){
                    struct process temp;
                    temp = p[j];
                    p[j] = p[j+1];
                    p[j+1] = temp;
                }
            }
        }
    }
    float avgtat = 0;
    float avgwt = 0;
    int time =0;
    for(int i=0;i<n;i++){
        time+= p[i].bt;
        cout<<"Executing process with pid: "<<p[i].pid<<endl;
        cout<<"Time elasped: "<<time<<endl;
        p[i].tat = time;
        p[i].wt = p[i].tat - p[i].bt;
        avgtat += p[i].tat;
        avgwt += p[i].wt;
    }
    avgtat = avgtat/n;
    avgwt = avgwt/n;
    cout<<"Average turnaround time: "<<avgtat<<endl;
    cout<<"Average waiting time: "<<avgwt<<endl;
}