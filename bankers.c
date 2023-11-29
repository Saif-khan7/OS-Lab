#include<stdio.h>
int i,j;
int np,nr,max[10][10],allocation[10][10],need[10][10],avail[10];
void readmatrix(int matrix[10][10]);
void calculateNeed();
void display();
void banker();
int main() {
    printf("enter the number of process:");
    scanf("%d",&np);
    printf("\n enter the number of resources:" );
    scanf("%d",&nr);
    printf("enter the max matrix:");
    readmatrix(max);
    printf("enter the allocation matrix:");
    readmatrix(allocation);
    printf("\n Enter Available Resource:");
    for(i=0;i<nr;i++)
    {
        scanf("%d",&avail[i]);
    }
    calculateNeed();
    printf("\n Max Matrix\n");
    display(max);
    printf("\n Allocation Matrix");
    display(allocation);
    printf("\n Need Matrix");
    display(need);
    printf("\n Available Resources");
    for(i=0;i<nr;i++)
    printf("%d  \t",avail[i]);
    banker();
}
void readmatrix(int matrix[10][10])
{
    int i,j;
    for(i=0;i<np;i++)
    for(j=0;j<nr;j++)
    scanf("%d",&matrix[i][j]);
}
void calculateNeed()
{
    int i,j;
    for(i=0;i<np;i++)
    {
        for(j=0;j<nr;j++)
        {
            need[i][j]=max[i][j]-allocation[i][j];
        }
    }
}
void display(int matrix[10][10])
{
    int i,j;
    for(i=0;i<np;i++)
    {
        for(j=0;j<nr;j++)
        {
            printf("%d  \t",matrix[i][j]);
        }
        printf("\n");
    }
}
void banker()
{
    int finish[10],i,j,k=0,safe_seq[10],flag=0;
    for(i=0;i<np;i++)
    finish[i]=0;
    for(i=0;i<np;i++)
    {
        flag=0;
        if(finish[i]==0)
        for(j=0;j<nr;j++)
        {
            if(need[i][j]>avail[i])
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            finish[i]=1;
            safe_seq[k]=i;
            k++;
            for(j=0;j<nr;j++)
            avail[j]=avail[j]+allocation[i][j];
            i=-1;
        }
    }
    flag=0;
    for(i=0;i<np;i++)
    {
        if(finish[i]==0)
        {
            printf("Deadlock");
            flag=1;
            break;
        }
    }
    if(flag==0)
    {
        for(i=0;i<np;i++)
        printf("%d",safe_seq[i]);
    }
}
