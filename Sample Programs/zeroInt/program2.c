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

