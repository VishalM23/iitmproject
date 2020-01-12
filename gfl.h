#include<stdlib.h>
#include<math.h>
#ifndef __GFL_H_
#define __GFL_H
#define MAX_FIELDS 64
#define MINUS_INFINITY 0

struct node{
  long int data;
  struct node* addr;
};

typedef struct node* NODE;

typedef struct { /* Multi-precision integer */
char sign;       /* ’+’ for positive integers, ’–’ for negative integers, ’ ’ for zero */
int size;        /* Number of longs needed to represent the integer */
NODE start;      /* link to the array of longs holding the integer */
} mpint;
typedef mpint GFelement;   /* Element of a Galois field */


typedef struct {    /* Data structure for polynomial */
int degree;         /* The exact degree */
GFelement *coeff;   /* Pointer to the array of coefficients */
} poly;

typedef short GF_d;        /* Galois field descriptor */


typedef struct {      /* Data structure vector */
int size;             /* Vector size */
GFelement *element;   /* Pointer to the array of vector elements */
} vector;


typedef struct {        /* Data structure matrix */
int row;                /* Number of rows */
int col;                /* Number of columns */
GFelement **element;    /* Pointer to 2-dimensional array of elements */
} matrix;

typedef struct {         /* Data structure to store complete or partial factorization of an integer */
int nf;                  /* Number of factors */
int *multiplicity;       /* Pointer to the array holding the multiplicities of the factors */
mpint *factor;           /* Pointer to the array of factors */
 } intFactor;


struct {
GFelement p;                  /* characteristic */
GFelement q;                 /* cardinality */
int extlev;                  /* Extension level */
GF_d extof;                  /* Extension of */
long extdeg;                /* Extension degree (over immediate subfield) */
long totextdeg;             /* Total extension degree (over prime subfield) */
GFelement *defpoly;          /* Pointer to coefficients of defining polynomial */
long *primpower;            /* Table of powers of a primitive element */
long *disclog;               /* Table of discrete logs with respect to a primitive element */
long *zechlt;               /* Zech’s logarithm table */
} GF_info[MAX_FIELDS];


typedef struct {             /* Structure holding the partial or complete factorization of a polynomial */
long nf;                      /* Number of factors */
long *multiplicity;           /* Pointer to the array holding the multiplicities of the factors */
poly *factor;                 /* Pointer to the array of factors */
} polyFactor;


/* Factor base for prime fields */
typedef struct {
GFelement p; /* Characteristic of the field in which discrete log is taken */
GFelement gen; /* Base to which discrete log is taken */
int fbsize; /* Number of primes in the factor base */
long *base; /* Elements of factor base */
GFelement *baselog; /* Discrete logs of factor base elements */
} factorBase1;



/* Factor base for non-prime fields of extension level = 1 */
typedef struct {
GFelement p;                /* Characteristic of the field in which discrete log is taken */
GFelement gen;               /* Base to which discrete log is taken */
int maxdeg;                 /* Maximum degree of irreducible polynomials in the factor base */
int fbsize;              /* Number of elements in the factor base */
int nprime;              /* Number of primes between 2 and p-1 */
long *base;            /* Elements of factor base */
GFelement *baselog;     /* Discrete logs of factor base elements */
} factorBase2;




/* Factor base for non-prime fields of extension level > 1 */
typedef struct {
GFelement p;              /* Characteristic of the field in which discrete log is taken */
matrix ctop;             /* Matrix for composed-to-polynomial basis transformation */
GFelement gen;           /* Base to which discrete log is taken */
int maxdeg;              /* Maximum degree of irreducible polynomials in the factor base */
int fbsize;            /* Number of elements in the factor base */
int nprime;            /* Number of primes between 2 and p-1 */
long *base;             /* Elements of factor base */
GFelement *baselog;        /* Discrete logs of factor base elements */
} factorBase3;


//Functions start from here

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


void longToInt(mpint *n,long m){ //Convert the long m to the mpint format and store it in n.
	int i=0;

	if(m>0)
                n->sign='+';
        if(m<0)
                n->sign='-';



	while(m>0){
		n->start=insertbegin(n->start,m%33554432);
		m/=33554432;
		i++;
	}

	n->size+=i-1;


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



int zeroint(mpint n)
{
    if(n.size==1 && n.sign==' '&& n.start->data==0)
        return 1;
    else
        return 0;
}


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

int unityInt(mpint n)
{
    if(n.start->data==1)
    return 1;
    else return 0;
}


int negUnityInt(mpint n)
{
    if(n.start->data==-1)
    return 1;
    else return 0;
}

int intTwo(mpint n)
{
    if(n.start->data==2)
    return 1;
    else return 0;
}

void twoPowerToInt(mpint *n,long e){ //Convert the long m to the mpint format and store it in n.
	int i=0;
	long long m=1;

    while (e > 0) {
            m = m * 2;
            e--;
}

        if(m>0)
                n->sign='+';
        if(m<0)
                n->sign='-';



	while(m>0){
		n->start=insertbegin(n->start,m%33554432);
		m/=33554432;
		i++;
	}

	n->size+=i-1;


}

void destroyInt(mpint* n)
{
    NODE start=n->start,next;
    while (start != NULL)
   {
       next = start->addr;
       free(start);
       start = next;
   }
    start=NULL;
    free(n);
}

void intMinus(mpint*n,mpint m)
{
    n->size=m.size;
    n->sign=m.sign=='+'?'-':'+';
    NODE cur=m.start;
    while(cur!=NULL)
    {
        insertbegin(n->start,cur->data);
    }

}

long logTwo(mpint n)
{

  return(log2(intToLong(n)));
}
#endif
