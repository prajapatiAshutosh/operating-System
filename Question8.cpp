//program 8
// Write a program to implement SJF scheduling algorithm
#include <bits/stdc++.h>
using namespace std;

struct Pro
{
   int pid;
   int bt;
};

void bubbleSort(Pro arr[], int n)
{
   int i, j;
   for (i = 0; i < n-1; i++)
       for (j = 0; j < n-i-1; j++)
           if (arr[j].bt > arr[j+1].bt)
              swap(arr[j], arr[j+1]);
}

bool comparison(Pro a, Pro b)
{
     return (a.bt < b.bt);
}

void findWaitingTime(Pro p[], int n, int wt[])
{
    wt[0] = 0;

    for (int i = 1; i < n ; i++ )
        wt[i] = p[i-1].bt + wt[i-1] ;
}

void findTurnAroundTime(Pro p[], int n, int wt[], int tat[])
{
    for (int i = 0; i < n ; i++)
        tat[i] = p[i].bt + wt[i];
}

void findavgTime(Pro p[], int n)
{
    int wt[n], tat[n], twt = 0, ttat = 0;

    findWaitingTime(p, n, wt);

    findTurnAroundTime(p, n, wt, tat);

    cout << "\nProcesses "<< " Burst time " << " Waiting time " << " Turn around time\n";
    for (int i = 0; i < n; i++)
    {
        twt = twt + wt[i];
        ttat = ttat + tat[i];
        cout << " " << p[i].pid << "\t\t" << p[i].bt << "\t " << wt[i] << "\t\t " << tat[i] << endl;
    }

    cout << "Average waiting time = " << (float)twt / (float)n;
    cout << "\nAverage turn around time = " << (float)ttat / (float)n;
}

int main()
{
    int n;
    cout<<"\nSJF\nEnter the Number of Processes=";
    cin>>n;
    Pro *proc= new Pro[n];
	for(int i=0; i < n; i++)
	{
        cout<<"\nEnter the Burst Time for Process "<< i+1<<"=";
        cin>>proc[i].bt;
        proc[i].pid=i+1;
    }
    bubbleSort(proc,n);
    cout << "Order in which process gets executed\n";
    for (int i = 0 ; i < n; i++)
        cout << proc[i].pid <<" ";

    findavgTime(proc, n);
    return 0;
}