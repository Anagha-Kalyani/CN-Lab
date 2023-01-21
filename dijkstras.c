#include<stdio.h>
#define INF 999
int n, g[10][10], cost[10][10],distance[10],visited[10],min,next,count=0;
void dijkstra(int g[10][10],int n,int source){
    for (int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(g[i][j]==0){
                cost[i][j]=INF;
            }
            else{
                cost[i][j]=g[i][j];
            }
        }
    }
    for (int i=0;i<n;i++){
        visited[i]=0;
        distance[i]=cost[source][i];
    }
    distance[source]=0;
    visited[source]=1;
    count=1;
    while(count<=n-1){
        min=INF;
        for (int i=0;i<n;i++){
            if(distance[i]<min&&!visited[i]){
                min=distance[i];
                next=i;
            }
        }
        visited[next]=1;
        for (int i=0;i<n;i++){
            if(distance[next]+cost[next][i]<distance[i]){
                distance[i]=distance[next]+cost[next][i];
            }
        }
        count++;
    }
    printf("To\tCost\n");
    for(int i=0;i<n;i++){
        if(i!=source){
            printf("%d\t%d\n",i,distance[i]);
        }
    }
}
void main(){
    printf("Enter the number of nodes:\n");
    scanf("%d",&n);
    printf("Enter the cost matrix:\n");
    for (int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&g[i][j]);
        }
    }
    printf("Enter the source node:\n");
    int source;
    scanf("%d",&source);
    printf("From source %d:\n",source);
    dijkstra(g,n,source);
}
