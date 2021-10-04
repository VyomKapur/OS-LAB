#include<iostream>
using namespace std;
struct process{
    int bt;
    int at;
    int tat;
    int wt;
    int pid;
}p[10];
int main(){
    int n;
    int time = 0;
    do{
        cout<<"Enter number of processes to be run: ";
        cin>>n;
    }while (n<10);
    for (int i = 0; i < n; i++)
    {
        cout<<"Enter burst time of process "<<i+1<<": ";
        cin>>p[i].bt;
        cout<<"Enter arrival time of process "<<i+1<<": ";
        cin>>p[i].at;
        p[i].pid = i+1;
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
}