/* gcc -Wall -pthread statistics.c */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>
#include <ctype.h>

// I have commented some printf statements that helped me debug the functions

int max;
int min;
float avg;
int num_of_values;

int checkArguments(int len, char *argv[]) {
	for(int i=1; i<len;i++)	{
		char *str = argv[i];
       
		for(int j = ( (str[0] == '-') ? 1 : 0 ); j<strlen(str); j++) {
			if (isdigit(str[j]) == 0) {
				return 0; 
			}
		}
	}
        
    return 1;
}

void *average(void *val) {
  /* cast to integer  */
  int *values = (int*)val;
  int sum = 0;
	for (int i=0; i < num_of_values; i++)	{
		sum = sum + values[i];
    printf("number with index %i is %i and sum is %i \n", i, values[i], sum);
	}
	avg = (float)sum / (num_of_values);
	return NULL;
}

void *minimum(void *val) {
  /* cast to integer  */
  int *values = (int*)val;

  min = values[0];
  // printf("first number set to min, number is %i\n", min);
  for (int i=1; i < num_of_values; i++) {
    if (values[i]<min) 
        min = values[i];
    // printf("number with index %i is %i and new min is %i\n", i, values[i], min);
  }
	return NULL;
}

void *maximum(void *val) {
  /* cast to integer  */
  int *values = (int*)val;
  max = values[0];
  // printf("first number set to max, number is %i\n", max);
  for (int i=1; i < num_of_values; i++) {
    if (values[i]>max) 
        max = values[i];
    // printf("number with index %i is %i and new max is %i\n", i, values[i], max);
  }
	return NULL;
}

int main(int argc, char *argv[])
{
	pthread_t thread0;
	pthread_t thread1;
	pthread_t thread2;


	if (argc < 3) {
		printf("You have to supply at least 2 integers as arguments!\n");
		return 0;
	}

	if (checkArguments(argc, argv) == 0) {
		printf("You should only enter integers!\n");
		return 0;
	}

  num_of_values = argc - 1;
  printf("Number of arguments %i\n", num_of_values);
	int parsedInts[num_of_values];
	/* parsedInts[0]=argc; */
	for(int i=0; i < num_of_values; i++) {
		parsedInts[i]=atoi(argv[i+1]);
    // printf("parsedInt at %i: %i\n", i, parsedInts[i]);
	}
	int *values=parsedInts;

	pthread_create(&thread0, NULL, minimum, values);
	pthread_create(&thread1, NULL, maximum, values);
	pthread_create(&thread2, NULL, average, values);

  /* wait for threads */
	pthread_join(thread0, NULL);
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);

	printf("Average: %f\n" , avg);
	printf("Maximum: %i\n" , max);
	printf("Minimum: %i\n" , min);

	return 0;
}
