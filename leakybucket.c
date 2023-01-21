#include<stdio.h>
void main(){
    int bucketsize=0,outrate=0,n=0;
    int inbucket=0, inflowrate=0, outflowrate=0,dropped=0;
    printf("Enter the maximum bucket size: \n");
    scanf("%d",&bucketsize);
    printf("Enter the outrate: \n");
    scanf("%d",&outrate);
    printf("Enter the number of sets of packet: \n");
    scanf("%d",&n);
    int pack[n];
    for(int i=0;i<n;i++){
        printf("Enter the number of packets in set %d: \n",i+1);
        scanf("%d",&pack[i]);
    }
    int k=0;
    printf("\nClk\tInflowrate\tOutflowrate\tInbucket\tDropped\n");
    do{
        if(k<n){
            inflowrate=pack[k];
        }
    	else{
    	    inflowrate=0;
    	}
        int x=inbucket+inflowrate;
    
        if(x<=outrate){
            outflowrate=x;
        }
        else{
            outflowrate=outrate;
        }
    
        if(x-outflowrate<=bucketsize){
            inbucket=x-outflowrate;
            dropped=0;
        }
        else{
            inbucket=bucketsize;
            dropped=x-outflowrate-inbucket;
        }
    
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n",k,inflowrate,outflowrate,inbucket,dropped);
        k++;
       
    } while(inbucket!=0 || k<n);
}
