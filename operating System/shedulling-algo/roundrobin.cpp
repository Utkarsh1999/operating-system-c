#include <iostream>
using namespace std;

class process {
  public:
    int id;
    int burstTime;
    int waitingTime;
    int turnTime;
};

int main()
{
    int numProcess = 0;
    cout<<"enter number of processes \n";
    cin>>numProcess;

    //set time quantum
    int timeQuantum=0;
    cout<<"enter time quantum : ";
    cin>>timeQuantum;
    //array of object of processes
    process pList[numProcess];


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
    int totalBurst=0;

    for(int i=0;i<numProcess;i++)
    {
        cin>>pList[i].burstTime;
        totalBurst += pList[i].burstTime;
        pList[i].id = i;
    }

        //executing processes
        int p=0;
        while(totalBurst>0)
        {
            if(p==numProcess-1)
            {
                p=0;
            }
            if(pList[p].burstTime < 0)
            {
                p++;
                totalBurst--;
            }
            else{
            cout<<"\nprocess : "<<pList[p].id<<"\n";
            }
            for(int time=0;time<timeQuantum;time++)
            {
                 totalBurst--;
                if(pList[p].burstTime < 0)
                {
                    break;
                }
                pList[p].waitingTime =pList.burstTime[p-1] + pList.waitingTime[p-1];
                cout<<pList[p].burstTime<<" ";
                pList[p].burstTime-- ;



            }
            cout<<"\n\n";

            p++;
        }
}
