/* gcc -Wall ./memory.c -o memory */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* 
 * System used: e.g. GNU/Linux Arch 64bit x86_64
 */

int calculate_page (int address) {
  /* bit level shift to reach relevant bits */
	return address >> 12;
}

int calculate_offset (int address , int page) {
  /* bit wise AND to return relevant bits */ 
  return address & 0xFFF;
}

int main(int argc, char *argv[])
{
	long long_input;
  /* int is 4 bytes on 64 bit arch */
	int address;
	int offset , page;
  printf("sizeof int %ld on current system\n\n", sizeof(address));

	if (argc != 2) {
		printf("You must provide a parameter as input!\n");
		return -1;
	} else {
		long_input = atol(argv[1]);
		long supremum = pow(2 , 8*sizeof(int));
		if (long_input < 0 || long_input >= supremum) {
			printf("You must enter a valid 32bit address as parameter!\n");
			return -1;
		} else {
			address = (int) long_input;
		}
	}

  page = calculate_page(address);
  offset = calculate_offset(address, page);
  printf("The provided address (%d) is located at ", address);
	printf("page %d ", page);
	printf("and offset %d\n", offset);

	return 0;
}
