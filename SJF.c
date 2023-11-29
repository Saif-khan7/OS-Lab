#include<stdio.h>
#include<math.h>
struct proc{
    int id ;
    int at;
    int bt;
    int ct;
    int tat;
    int wt
};
void sort(struct proc p[], int n ){
    for(int i=0;i<n;i++){
        for(int j = 0; j<n-i-1 ; j++){
            if(p[j].bt > p[j+1].bt){
                struct proc tmp = p[j];
                p[j] = p[j+1];
                p[j+1] = tmp;
            }
        }
    }
}
void Calc(struct proc p[],int n){
    float Ttat=0;
    float Twt=0;
    p[0].ct = p[0].at + p[0].bt;
    p[0].tat = p[0].ct - p[0].at;
    p[0].wt = p[0].tat - p[0].bt;
    Ttat += p[0].tat;

    for (int i = 1 ; i<n ; i++){
        p[i].ct = p[i-1].ct + p[i].bt;
        p[i].tat = p[i].ct - p[i].at;
        p[i].wt = p[i].tat - p[i].bt;

        Ttat += p[i].tat;
        printf("%d\n",Ttat);
        Twt += p[i].wt;
    }
    float awgTAT;
    awgTAT = Ttat / n;
    float awgWT = Twt / n;

    printf("\nProcess\tat\tbt\tct\ttat\twt\n");
    for(int i=0 ; i < n ; i++){
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", p[i].id, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt);

    }
    printf("Average TAT: %f\n",awgTAT);
    printf("Average WT: %f\n",awgWT);

}
int main(){
    int n;
    printf("Enter number of processes: ");
    scanf("%d",&n);

    struct proc p[n];

    for(int i = 0 ; i<n; i++){
        p[i].id = i+1;
        printf("Enter AT: ",i+1);
        scanf("%d",&p[i].at);
        printf("Enter BT: ",i+1);
        scanf("%d",&p[i].bt);
        printf("\n");
    }
    sort(p , n);
    Calc(p , n);

    return 0;
}
