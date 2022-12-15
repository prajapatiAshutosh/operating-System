//program 6
//Write a program to implement FCFS scheduling algorithm
#include <iostream>
using namespace std;
class fcfs
{
    public:
    int arriti;
	int bt;
	int wt;
	int tat;

	fcfs()
	{
		arriti=bt=wt=tat=0;
	}
};

int main()
{
    float wta=0,taa=0;int n;
    fcfs tmp;
    cout<<"\nEnter the Number of Processes=";
    cin>>n;
    fcfs *p=new fcfs[n];
	for(int i=1;i<=n;i++)
	{
        cout<<"\nEnter the arrival Time for Process "<< i <<"=";
        cin>>p[i-1].arriti;
		cout<<"\nEnter the Burst Time for Process "<< i <<"=";
        cin>>p[i-1].bt;
    }

	for(int i=0; i < n; i++)
	{
        for(int j=i+1; j < n; j++)
		if(p[i].arriti<=p[j].arriti)
		{
			p[j].wt=p[i].arriti+p[i].wt+p[i].bt-p[j].arriti;
			if(p[j].wt < 0)
            	p[j].wt=0;
		}
		else
		{
            tmp=p[i];
            p[i]=p[j];
            p[j]=tmp;
        }
        p[i].tat=p[i].bt+p[i].wt;
    }

	for(int i=0; i < n; i++)
	{
        wta+=p[i].wt;
        taa+=p[i].tat;
        cout<<"\nThe Waiting Time for Process "<< i+1<<"="<< p[i].wt;
        cout<<"\nThe Turnaround Time for Process "<< i+1<<"="<< p[i].tat;
    }
	cout<<"\nAverage Waiting Time="<< wta/(float)n;
	cout<<"\nAverage Turnaround Time="<< taa/(float)n;
	return 0;
}