#include<stdio.h>
#include"gfl.h"
void main(){


        GFelement x;


        x.sign='+';
        x.size=5;
        x.start=insertbegin(x.start,17261491);

        if(zeroint(x))
                printf("\nIt's zero element.\n");
        else
                printf("\nIt's not a zero element.\n");
}

//Function definition
//Present in gfl.h
/*
int zeroint(mpint n)
{
    if(n.size==1 && n.sign==' '&& n.start->data==0)
        return 1;
    else
        return 0;
}
*/
