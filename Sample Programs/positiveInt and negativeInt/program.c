#include<stdio.h>
#include"gfl.h"
void main(){


        GFelement x;

        long int num;
        int s;

        x=newInt();

        printf("\nEnter the long integer number:");
        scanf("%ld",&num);

        longToInt(&x,num);

        if(positiveint(x))
                printf("\n\nThe number %ld is positive\n",num);


        else if (negativeint(x))
                printf("\n\nThe number %ld is negative\n",num);

        else
                printf("\n\nThe given number is zero.\n");

}

//Function definition
//Present in gfl.h

/*
int positiveint(mpint n)
{
    if(n.sign=='+')
        return 1;
    else
        return 0;
}

int negativeint(mpint n)
{
    if(n.sign=='-')
        return 1;
    else
        return 0;
}
*/
