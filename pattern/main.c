#include <stdio.h>
#include <stdlib.h>
void
main ()
{
  int n = 0,j, k = 1, rem, rev = 0;
  for (int i = 11; k; i++)
    {j=i;
      if (n == 100)
	{
	  k = 0;
	}
      while (i != 0)
	{
	  rem = i % 10;
	  rev = rev * 10 + rem;
	  i /= 10;
	}i=j;
      if (i == rev)
	{
	  printf ("%d. %d\n", (n++)+1, i);
	}

      rev = 0;
    }
}

/*
int n= 65,k,l;
printf("Enter number of rows ");
scanf("%d",&k);
if(k%2==0){l=k/2;}
else{l=(k/2)+1;}
    for(int i=1;i<=l;i++){
        for(int j=0;j<i;j++){
            printf("%c*",n);
        }printf("\b \n");n++;
        } n--;
        if(k%2==1){l--;}
    for(int i=l;i>=1;i--){
        for(int j=0;j<i;j++){
            printf("%c*",n);
        }printf("\b \n");n--;
    }





if(k%2==0){
    l=k/2;
    for(int i=1;i<=l;i++){
        for(int j=0;j<i;j++){
            printf("%c*",n);
        }printf("\b \n");n++;
    } n--;
    for(int i=l;i>=1;i--){
        for(int j=0;j<i;j++){
            printf("%c*",n);
        }printf("\b \n");n--;
    }
}
else{
    l=(k/2)+1;
    for(int i=1;i<=l;i++){
        for(int j=0;j<i;j++){
            printf("%c*",n);
        }printf("\b \n");n++;
    } n--;l--;
    for(int i=l;i>=1;i--){
        for(int j=0;j<i;j++){
            printf("%c*",n);
        }printf("\b \n");n--;
    }
*/

