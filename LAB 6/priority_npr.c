#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int pid;	//Process No
    int at;		//Arrival Time
    int bt;		//Burst Time
    int pt;		//Priority (0 by default)

    int ct;		//Closing Time
    int tat;	//Turn-Around Time
    int wt;		//Waiting Time
} PCB;

struct queue{
    int pid;    //Process No
    int ct;     //Closing Time
    int bt;     //Burst Time
    struct queue *next;
};

PCB B[10];
struct queue *gantt = NULL;
int n, opt;

void sort_arrival();
void print_table(PCB B[]);
void print_gantt_chart(struct queue *B);
void fcfs();
void sjf_pr();
void prior_no_pr();
void round_robin();

int main(){
    int i;
    printf("\nEnter the No of Process : ");
    scanf("%d", &n);
    printf("\n--------------Process Details--------------");
    for (i=0; i<n; i++){
        B[i].pid = i;
        printf("\nProcess Id   : %d", B[i].pid);
        printf("\nArrival Time : "); scanf("%d", &B[i].at);
        printf("Burst Time   : "); scanf("%d", &B[i].bt);
		printf("Priority     : "); scanf("%d", &B[i].pt);
    }

        prior_no_pr();
    return 0;
}
void prior_no_pr(){
    int i, j, x;
    PCB f, A[10];
    for(i=0; i<n; i++)
        A[i] = B[i];

    sort_arrival(); //Sorting based on Arrival Time

    int t=0;
    for(i=0; i<n; i++){
        x=i;
        for(j=i+1; j<n; j++)
            if (B[j].at <= t && B[x].pt > B[j].pt)
                x=j;
        f = B[x];
        B[x] = B[i];
        B[i] = f;
        t += B[i].bt;
    }

    x=0;
    struct queue *b;
    float av_tat=0.0, av_wt=0.0;
    x += B[0].at - 0;
    for(i=0; i<n; i++){
        x+=B[i].bt;
        B[i].ct = x;
        B[i].tat = B[i].ct - B[i].at;
        B[i].wt = B[i].tat - B[i].bt;
        av_tat += B[i].tat;
        av_wt += B[i].wt;
        A[B[i].pid].ct = B[i].ct;
        A[B[i].pid].tat = B[i].tat;
        A[B[i].pid].wt = B[i].wt;
        if(gantt == NULL)
            b = gantt = (struct queue *)malloc(sizeof(struct queue));
        else{
            b->next = (struct queue *)malloc(sizeof(struct queue));
            b = b->next;
        }
        b->pid = B[i].pid;
        b->ct = B[i].ct;
        b->bt = B[i].bt;
        b->next = NULL;
    }

    print_table(A);
    print_gantt_chart(gantt);

    av_tat /= n;
    av_wt /= n;

    printf("\n");
    printf("\nAverage Turn-Around Time : %f", av_tat);
    printf("\nAverage Waiting Time     : %f", av_wt);

    printf("\n");
}
void sort_arrival(){
    int x, i, j;
    PCB f;
    for(i=0; i<n; i++){
        x=i;
        for(j=i+1; j<n; j++)
            if (B[x].at > B[j].at)
                x=j;
        f = B[x];
        B[x] = B[i];
        B[i] = f;
    }
}
void print_table(PCB B[]) {
    int i;

    if (opt == 3){
        puts("+-----+--------------+-----------+----------+--------------+-----------------+--------------+");
        puts("| PID | Arrival Time |Burst Time | Priority | Closing Time | Turnaround Time | Waiting Time |");
        puts("+-----+--------------+-----------+----------+--------------+-----------------+--------------+");

        for(i=0; i<n; i++) {
            printf("| %2d  |      %2d      |     %2d    |    %2d    |      %2d      |       %2d        |       %2d     |\n"
                    , B[i].pid, B[i].at, B[i].bt, B[i].pt, B[i].ct, B[i].tat, B[i].wt );
            puts("+-----+--------------+-----------+----------+--------------+-----------------+--------------+");
        }
    }
    else{
        puts("+-----+--------------+-----------+--------------+-----------------+--------------+");
        puts("| PID | Arrival Time |Burst Time | Closing Time | Turnaround Time | Waiting Time |");
        puts("+-----+--------------+-----------+--------------+-----------------+--------------+");

        for(i=0; i<n; i++) {
            printf("| %2d  |      %2d      |     %2d    |      %2d      |       %2d        |       %2d     |\n"
                    , B[i].pid, B[i].at, B[i].bt, B[i].ct, B[i].tat, B[i].wt );
            puts("+-----+--------------+-----------+--------------+-----------------+--------------+");
        }
    }
}

void print_gantt_chart(struct queue *b) {
    struct queue *a; int j;

    // print top bar
    a=b;
    printf(" ");
    if (B[0].at > 0){
        for(j=0; j<B[0].at; j++) printf("--");
        printf(" ");
    }
    while(a!=NULL) {
        for(j=0; j<a->bt; j++) printf("--");
        printf(" ");
        a=a->next;
    }
    printf("\n");

    // printing process id in the middle
    a=b;
    printf("|");
    if (B[0].at > 0){
        for(j=0; j<B[0].at-2; j++) printf(" ");
        printf("IDLE");
        for(j=0; j<B[0].at-2; j++) printf(" ");
        printf("|");
    }
    while(a!=NULL) {
        for(j=0; j<a->bt - 1; j++) printf(" ");
        printf("P%d", a->pid);
        for(j=0; j<a->bt - 1; j++) printf(" ");
        printf("|");
        a=a->next;
    }
    printf("\n");

    // printing bottom bar
    a=b;
    printf(" ");
    if (B[0].at > 0){
        for(j=0; j<B[0].at; j++) printf("--");
        printf(" ");
    }
    while(a!=NULL) {
        for(j=0; j<a->bt; j++) printf("--");
        printf(" ");
        a=a->next;
    }
    printf("\n");

    // printing the time line
    a=b;
    if (B[0].at > 0){
        for(j=0; j<2*B[0].at-2; j++) printf(" ");
        printf("  %2d", B[0].at);
    }
    while(a!=NULL) {
        for(j=0; j<a->bt-1; j++) printf("  ");
        printf(" %2d", a->ct);
        a=a->next;
    }
    printf("\n");
}
