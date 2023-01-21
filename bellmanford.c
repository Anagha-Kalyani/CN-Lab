#include<stdio.h>
struct node{
    int dist[20];
    int next[20];
}rt[10];
void main(){
    int costmat[20][20];
    int nodes,i,j,source,count=0;
    printf("Enter the number of nodes: \n");
    scanf("%d",&nodes);
    printf("Enter the cost matrix: \n");
    for(i=0;i<nodes;i++){
        for(j=0;j<nodes;j++){
            scanf("%d",&costmat[i][j]);
            costmat[i][i]=0;
            rt[i].dist[j]=costmat[i][j];
            rt[i].next[j]=j;
        }
    }
    printf("Enter the source node:\n");
    scanf("%d",&source);
    do{
        count=0;
        for(i=0;i<nodes;i++)
            for(j=0;j<nodes;j++)
                if(rt[source].dist[i]>costmat[source][j]+rt[j].dist[i]){
                    rt[source].dist[i]=rt[source].dist[j]+rt[j].dist[i];
                    rt[source].next[i]=j;
                        count++;
                }   
    }while(count!=0);
        
    printf("\n\nFor router %d:\n",source);
    printf("To\tNext\tCost\n");
    for(i=0;i<nodes;i++){
        if (i!=source){
            printf("%d\t%d\t%d\n",i,rt[source].next[i],rt[source].dist[i]);
        }
    }
}
