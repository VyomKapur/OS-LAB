#include<iostream>
using namespace std;

struct process{
    int bt;
    int pid;
    int at;
    bool flag;
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
        cout<<"Enter arrival time of process "<<i+1<<": ";
        cin>>p[i].at;
        p[i].pid = i+1;
        p[i].flag = false;
    }
    int time =0;
    int k = 0;
    int ctr = 0;
    while (ctr!=n){
        struct process r[10];
        for(int i=0;i<n;i++){
            if(time>=p[i].at && p[i].flag == false){
                r[k] = p[i];
                cout<<"pid: "<<p[i].pid<<endl;
                k++;
            }
        }
        cout<<"k is: "<<k<<endl;
        for(int i=0; i<(k-1); i++)
        {
            for(int j=0; j<(k-i-1); j++)
            {
                if(r[j].bt>r[j+1].bt)
                {
                    struct process temp;
                    temp = r[j];
                    r[j] = r[j+1];
                    r[j+1] = temp;
                }
                if(r[j].bt==r[j+1].bt){
                    if(r[j].at>r[j+1].at){
                        struct process temp;
                        temp = r[j];
                        r[j] = r[j+1];
                        r[j+1] = temp;
                    }
                }
            }
        }
        cout<<"Running process with pid: "<<r[0].pid<<endl;
        time += r[0].bt;
        cout<<"Time elasped: "<<time<<endl;
        p[r[0].pid-1].flag = true;
        for (int i = 0; i < k; i++)
        {
            r[i] = r[i+1];
        }
        k=0;
        ctr++;
    }
}