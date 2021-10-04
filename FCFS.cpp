#include<iostream>
using namespace std;
struct process{
    int bt;
    int pid;
    int at;
    int ta;
    int wt;
}p[10];
int main(){
    int time=0;
    int n;
    float awt=0;
    float ata=0;
    do{   
        cout<<"Enter number of processes to be run(less than 10): ";
        cin>>n;
    } while (n<10);
    for(int i=0; i<n; i++){
        cout<<"Enter burst time of process "<<i+1<<"(seconds): ";
        cin>>p[i].bt;
        cout<<"Enter arrival time of process "<<i+1<<"(seconds): ";
        cin>>p[i].at;
        p[i].pid = i;
    }
    for(int i=0; i<(n-1); i++)
    {
        for(int j=0; j<(n-i-1); j++)
        {
            if(p[j].at>p[j+1].at)
            {
                struct process temp;
                temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
            }
            if(p[j].at==p[j+1].at){
                if(p[j].pid>p[j+1].pid){
                    struct process temp;
                    temp = p[j];
                    p[j] = p[j+1];
                    p[j+1] = temp;
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        if(time<p[i].at){
            time+= time-p[i].at;
        }
        time += p[i].bt;
        p[i].ta = time-p[i].at;
        p[i].wt = p[i].ta-p[i].bt;
        cout<<"Completed process with pid: "<<p[i].pid<<endl;
        cout<<"Time elapsed: "<<time<<" s"<<endl;
    }
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
