#include<stdio.h>
#include<math.h>
int gcd(int a,int b){
    if(a%b==0) return b;
    else if(b%a==0) return a;
    else if(a>b) return gcd(a%b,b);
    else if(b>a) return gcd(a,b%a);
}
void main(){
    int p,q,n,phi,d,e;
    printf("Enter prime p:\n");
    scanf("%d",&p);
    printf("Enter prime q:\n");
    scanf("%d",&q);
    n=p*q;
    phi=(p-1)*(q-1);
    e=2;
    while(e<phi){
        if(gcd(e,phi)==1){
            break;
        }
        e++;
    }
    printf("n: %d\n",n);
    printf("phi: %d\n",phi);
    printf("e: %d\n",e);
    d=1;
    while((d*e)%phi!=1){
        d++;
    }
    printf("d: %d\n",d);
    int plain,cipher;
    printf("Enter the message: \n");
    scanf("%d",&plain);
    cipher=(int)pow(plain,e) % n;
    int plain1=(int)pow(cipher,d) % n;
    printf("cipher: %d\n",cipher);
    printf("plain: %d\n",plain1);
}
