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


//Function definition
//Present in gfl.h

/*
void longToInt(mpint *n,long m){ //Convert the long m to the mpint format and store it in n.
	int i=0;
	while(m>0){
		n->start=insertbegin(n->start,m%33554432);
		m/=33554432;
		i++;
	}

	n->size+=i-1;

	if(m>=0)
		n->sign='+';
	else
		n->sign='-';
}

long intToLong(mpint a){
	int s=a.size-1;
	long int res=0;
	NODE cur=a.start;

	while(s>=0){
		res+=pow(33554432,s)*cur->data;
		cur=cur->addr;
		s--;
	}

	return res;
}
*/
