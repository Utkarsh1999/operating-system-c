//assuming all process arrived at same time

#include <iostream>
using namespace std;

int main()
{
    int numProcess = 0;
    cout<<"enter number of processes \n";
    cin>>numProcess;

    //burstTime array
    double pBurst[numProcess];

    //waiting time array
    double wTime[numProcess];

    //turn around time array
    double taTime[numProcess];

    //total waiting time variable
    double totalWTime = 0;

    //total turnaround time variable
    double totalTATime = 0;
    cout<<"Enter burst of processes : \n";

    for(int i=0;i<numProcess;i++)
    {
        cin>>pBurst[i];
        if(i == 0)
        {
            //waiting time of 0th process
            wTime[i] = 0.0;
        }
        else
        {
            //waiting time of process > 0
            wTime[i] = pBurst[i-1] + wTime[i-1];
        }
        //turnaround time of process
        taTime[i] = wTime[i] + pBurst[i];
        //calculate total waiting time
        totalWTime += wTime[i];
        //calculate total turn around time
        totalTATime += taTime[i];
    }

    //printing process table
    cout<<"|process number||"<<"burst time||"<<"waiting time||"<<"turn around time|"<<endl;
    for(int i=0;i<numProcess;i++)
    {
        cout<<i<<"\t\t\t"<<pBurst[i]<<"\t\t"<<wTime[i]<<"\t\t"<<taTime[i]<<endl;
    }



    double averageWTime = totalWTime / numProcess;
    double averageTATime = totalTATime / numProcess;
    cout<<"averageWTime = "<<averageWTime<<endl;
    cout<<"averageTATime = "<<averageTATime<<endl;



}
