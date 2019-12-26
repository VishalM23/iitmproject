#include<stdio.h>
#include"gfl.h"
void main(){


        GFelement x;

        long int num,res;
        int s;

        NODE cur;

        x=newInt();

        printf("\nEnter the long integer number:");
        scanf("%ld",&num);

        longToInt(&x,num);

        //printing in radix format
        cur=x.start;
        s=x.size-1;
        printf("The given number in radix format is as follows:\n");
        while(cur->addr!=NULL && s>=1){
                printf("%ld R^%d + ",cur->data,s);
                cur=cur->addr;
                s--;
        }


        printf("%ld R^0",cur->data);

        printf("\n\nWhere R=33554432\n");

        res=intToLong(x);

        printf("\n\nThe number is :%ld\n",res);

}
