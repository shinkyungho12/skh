#include <stdio.h>

int main() {
    int i [10] = {2, 4, 6, 8, 10};
    int *p = i;

    printf("p = %p \n", p);
    printf("++(*p) = %d \n", ++(*p));

    int g [9] = { 1, 3, 5, 7 ,9};

    printf("(*p)+1 = %d \n", (*p)+1);
    printf("++*p = %d \n", ++*p);

    int q = 2;
    p = &q;

    printf("(*p)+=1 = %d \n", (*p)+=1);
    printf("*p+=1 = %d \n", *p+=1);

    int a= 1;
    p = &a;

    printf("*p=*p+1 = %d \n", *p=*p+1);
    printf("(*p)++ = %d \n", (*p)++);

}