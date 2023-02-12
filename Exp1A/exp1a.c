#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(){
    int n,f1,f2,x=0;
    long double f4,f7,f11;
    double f3,f5,f6,f8,f9,f10;
    while(x<=11){
        printf("Enter the function no.:\n");
        scanf("%d",&x);
        if(x==1){
            printf("n\n");
            for(int i=0; i<=100; i++){
                f1=i;
                printf("%d\n",f1);
            }
        }
        if(x==2){
            printf("n^3\n");
            for(int i=0; i<=100; i++){
                f2=i*i*i;
                printf("%d\n",f2);
            }
        }
        if(x==3){
            printf("log(n)\n");
            for(int i=0; i<=100; i++){
                f3=log(i);
                printf("%.2lf\n",f3);
            }
        }
        if(x==4){
            printf("n.2^n\n");
            for(int i=0; i<=100; i++){
                f4=i*(pow(2,i));
                printf("%.Lf\n",f4);
            }
        }
        if(x==5){
            printf("(3/2)n\n");
            for(int i=0; i<=100; i++){
                f5=1.5*i;
                printf("%.2lf\n",f5);
            }
        }
        if(x==6){
            printf("e^n\n");
            for(int i=0; i<=100; i++){
                f6=exp(i);
                printf("%.2lf\n",f6);
            }
        }
        if(x==7){
            printf("2^n\n");
            for(int i=0; i<=100; i++){
                f7=(pow(2,i));
                printf("%.Lf\n",f7);
            }
        }
        if(x==8){
            printf("log(log(n))\n");
            for(int i=0; i<=100; i++){
                f8=log(log(i));
                printf("%.2lf\n",f8);
            }
        }
        if(x==9){
            printf("(logn)^1/2\n");
            for(int i=0; i<=100; i++){
                f9=pow(log(i),0.5);
                printf("%.2lf\n",f9);
            }
        }
        if(x==10){
            printf("n*log(n)\n");
            for(int i=0; i<=100; i++){
                f10=i*log(i);
                printf("%.2lf\n",f10);
            }
        }
        
        else{
            exit(0);
        }
    }
    return 0;
}
