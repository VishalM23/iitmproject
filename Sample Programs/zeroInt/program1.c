#include<stdio.h>
#include"gfl.h"
void main(){


        GFelement x;


        x.sign=' ';
        x.size=1;
        x.start=insertbegin(x.start,0);

        if(zeroint(x))
                printf("\nIt's zero element.\n");
        else
                printf("\nIt's not a zero element.\n");
}
