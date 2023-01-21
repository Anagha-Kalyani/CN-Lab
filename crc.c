#include<stdio.h>
#include<strings.h>
#include<ctype.h>
char data[50],original[50],temp[50],divisor[50],x[50],q[50],rem[50],key[50];
int datalen,divlen;
void divide(char data[50],char divisor[50]){
    strcpy(original,data);
    strcpy(temp,data);
    for(int i=0;i<datalen;i++){
        q[i]=temp[0];
        if(q[i]=='0'){
            for(int j=0;j<divlen;j++){
                key[i]='0';
            }
        }
        else{
            for(int j=0;j<divlen;j++){
                key[j]=divisor[j];
            }
        }
        for(int j=divlen-1;j>0;j--){
            if(temp[j]==key[j]){
                rem[j-1]='0';
            }
            else{
                rem[j-1]='1';
            }
        }
        rem[divlen-1]=original[i+divlen];
        strcpy(temp,rem);
    }
    strcpy(rem,temp);
}
void main(){
    printf("Enter data:\n");
    gets(data);
    do{
        printf("Enter 17 bit divisor:\n");
        gets(divisor);
    }while(strlen(divisor)!=17);
    datalen=strlen(data);
    divlen=strlen(divisor);
    for(int i=0;i<16;i++){
        data[datalen+i]='0';
    }
    divide(data,divisor);
    printf("Remainder is:\n");
    for(int i=0;i<divlen-1;i++){
        printf("%c",rem[i]);
    }
    printf("\n");
    
    printf("Enter received data:\n");
    gets(data);
    for(int i=0;i<16;i++){
        data[datalen+i]=rem[i];
    }
    divide(data,divisor);
    printf("Remainder is:\n");
    for(int i=0;i<divlen-1;i++){
        printf("%c",rem[i]);
    }
    printf("\n");
    if(strcmp(rem,"0000000000000000")==0){
        printf("NO ERROR\n");
    }
    else{
        printf("ERROR\n");
    }
}
