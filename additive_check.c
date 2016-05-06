#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/******************************************************
* [in]	 : int n upper bound of primes
* [out]	 :  void **primes pointer to primes
* 
*[return]	 : int size - size of **primes or error value
*
******************************************************/
int get_prime_nums (int n, void **primes) 
{
	int *tmp_primes = NULL;

	int count = 0;
	
	for (int i=2; i<n; i++)
	{ 
		for (int j=2; j*j<=i; j++)
      	{
     		if (i%j==0)
	 	   	{ 
            	break;
	 	   	}
        	if(j+1 > sqrt(i)) 
	 	   	{
				count++;
				tmp_primes = (int*)realloc((void*)tmp_primes ,(sizeof(int)*count));
				if (tmp_primes != NULL)
					tmp_primes[count-1] = i;
	
         	}
		}   
   }   
   
   *primes = tmp_primes;
   return count;
}

/******************************************************
* [in]	 : int vector
* 
*[return]	 : int 
*
******************************************************/
int secret(int vector)
{
	const int degree = 45;
	
	return (int)cos(degree * vector); // rotate vector by 45 degrees
	 
}

/******************************************************
* [in]	 : int *array - pointer to array
* [in]	 : int size - size of array
* [in]	 : int input - input from user
*
******************************************************/
void is_additive(int *array, int size, int input)
{	
	
	for (int i=0; i<size; i++)
	{
		for (int j=i+1; j<size; j++)
		{
			if( secret(array[i] + array[j]) != (secret(array[i]) + secret(array[j])))
			{
				printf("\nsectet() is not additive for all combinations of prime #'s less than %d.\n", input);
				return;
			}
		}
	}
	printf("\nsectet() is additive for all combinations of prime #'s less than %d.\n", input); 
}
	
int main(int argc, const char * argv[])
{
	int *pprimes = NULL;
	int input = 0;
  	int size = 0;
	
    if ((argc != 2) || ( strtol(argv[1], NULL, 10) <= 0)) 
	{
   		printf("\nUsage: %s n, where n is a positive interger\n",argv[0]);
        return 1;
    }
	else
		input = strtol(argv[1], NULL, 10);
	
  	size = get_prime_nums(input, (void*)&pprimes); 
  
	if (!size)
		printf("\n\nNo prime # found less than %d, try a larger #\n", input);
	else
	{
		printf("\n\nThere are %d prime # less than %d\n", size, input);
	  	/*
		for (int i=0; i<size; i++)
		{
			printf("%d\n", pprimes[i]);
		} 
		*/
	  	is_additive(pprimes, size, input);
	
		if (pprimes != NULL)
		  free(pprimes);
	}
  	
	  
	return 0;
}

