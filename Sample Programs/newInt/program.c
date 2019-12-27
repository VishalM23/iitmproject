#include<stdio.h>
#include"gfl.h"
void main(){


        mpint x;



        x=newInt();

        if(zeroint(x))
                printf("\nIt's zero element.\n");
        else
                printf("\nIt's not a zero element.\n");
}


//Function definition
//Present in gfl.h
/*
NODE insertbegin(NODE start,long int item){
  NODE temp= (NODE) malloc (sizeof(struct node));
  temp->data=item;
  temp->addr=NULL;
  if (start==NULL)
       return temp;
  temp->addr=start;
  return temp;
}

mpint newInt(){ // Initializes a mpint to zero element
	// This function must be called to initialize the variable before any use
	mpint x;


	x.sign=' ';
	x.size=1;
	x.start=insertbegin(x.start,0);

	return x;
}
*/
