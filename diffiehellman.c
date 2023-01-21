#include<stdio.h>
#include<math.h>
long long int keyeex(int a, int b, int c){
    return (int)pow(a,b) % c;
}
void main(){
    int p,g,x,y;
    printf("Enter p:\n");
    scanf("%d",&p);
    printf("Enter g:\n");
    scanf("%d",&g);
    printf("What is Alice's secret key?\n");
    scanf("%d",&x);
    printf("What is Bob's secret key?\n");
    scanf("%d",&y);
    long long int r1=keyeex(g,x,p);
    long long int r2=keyeex(g,y,p);
    long long int k1=keyeex(r2,x,p);
    long long int k2=keyeex(r1,y,p);
    printf("Alice calculates Shared key: %lld\n",k1);
    printf("Bob calculates Shared key: %lld\n",k2);
    
}
