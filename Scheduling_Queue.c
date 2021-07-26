#include<stdio.h>

int main()
{
    int at[20], bt[20],p[20],ct[20],wt[20],tat[20],pr[20],i,j,n,total=0,pos,temp;
    float avg_wt,avg_tat;
    printf("Enter Total Number of Process:");
    scanf("%d",&n);

    printf("\nEnter Arrival,Burst Time and Priority\n");
    for(i=0;i<n;i++)
    {
        printf("\nP[%d]\n",i+1);
        printf("Enter Arrival Time:");
        scanf("%d",&at[i]);
        printf("Enter Burst Time:");
        scanf("%d",&bt[i]);
        printf("Enter Priority:");
        scanf("%d",&pr[i]);
        p[i]=i+1;
    }




  for(i=0;i<n;i++)
    {
        pos=i;
  if(at[pos]==0)
        {
            pos=i;
        }
  else
    {
     for(j=i;j<n;j++)
        {
             if(pr[pos]<pr[j])
          {
             pos=j;

          }}
    }


        temp=pr[i];
        pr[i]=pr[pos];
        pr[pos]=temp;

        temp=bt[i];
        bt[i]=bt[pos];
        bt[pos]=temp;

        temp=at[i];
        at[i]=at[pos];
        at[pos]=temp;

        temp=p[i];
        p[i]=p[pos];
        p[pos]=temp;
    }
    ct[0]=bt[0];
    for(i=1;i<n;i++)
    {
        ct[i]=ct[i-1]+bt[i];
    }

    for(i=0;i<n;i++)
    {
        tat[i]=ct[i]-at[i];
        total=total+tat[i];
    }
    avg_tat=total/n;

    total=0;

    wt[0]=0;
    for(i=1;i<n;i++)
    {
       wt[i]=tat[i]-bt[i];
       total=total+wt[i];
    }

    avg_wt=total/n;


    printf("\nProcess\t    Arrival time   Burst Time    Complete time    Waiting Time\t     Turnaround Time");
    for(i=0;i<n;i++)
    {

        printf("\nP[%d]\t\t  %d   \t\t\%d\t\t %d   \t\t%d\t\t\t%d",p[i],at[i],bt[i],ct[i],wt[i],tat[i]);
    }


    printf("\n\nAverage Waiting Time=%.2f",avg_wt);
    printf("\nAverage Turnaround Time=%.2f\n",avg_tat);

	return 0;
}