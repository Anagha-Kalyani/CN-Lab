#include<stdio.h>
#include<stdlib.h>
#include<strings.h>
char str[50];
int generate(int mode,int checksum){
    int n,temp,sum=0;
    if(strlen(str)%2==0){
        n=strlen(str)/2;
    }
    else{
        n=(strlen(str)+1)/2;
    }
    for(int i=0;i<n;i++){
        temp=(str[i*2]*256)+(str[(i*2)+1]);
        printf("%x\t",temp);
        sum+=temp;
    }
    printf("\n");
    if(mode==1){
        sum+=checksum;
    }
    if(sum%65536!=0){
        n=sum%65536;
        sum=(sum/65536) + n;
    }
    printf("sum is %x\n",sum);
    sum=65535-sum;
    printf("checksum is %x\n",sum);
    return sum;
}
void main(){
    printf("Enter string:\n");
    gets(str);
    int s1=generate(0,0);
    int ch;
    printf("Enter received string:\n");
    gets(str);
    int s2=generate(1,s1);
    if(s2==0){
        printf("NO ERROR\n");
    }
    else{
        printf("ERROR\n");
    }
}
