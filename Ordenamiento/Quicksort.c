#include <stdio.h>

void swap(int *p, int *q){
	int temp;
	temp = *p;
	*p = *q;
	*q = temp;
}

void printArray(int *a, int *b){
	for (a; a < b; a++)
		printf("%d, ",*a);
	printf("%d \n",*a);
}

void quicksort(int *izq, int *der )
{
    int *x , *a, *b, aux;
    a = izq;
    b = der;
    x = a;
    x += (der - izq) /2;
        do{
            while(( *a < *x) && (b <= der) )
            {
                a++;
            }

            while( (*x < *b) && (b > izq) )
            {
                b--;
            }

            if( a <= b )
            {
                swap(a,b);
                a++;  b--;
            }

        }while( a <= b );

    if( *izq < *b )
        quicksort( izq, b );
    if( *a < *der )
        quicksort( a, der );
}

int main(){
    int a[] = {4, 6, 2, 12, 10, 3, 9, 11, 16,8};
    printArray(a, (a+9));
	quicksort(a, (a+9));
	printArray(a, (a+9));
}
