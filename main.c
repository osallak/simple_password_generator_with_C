#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

int main()
{
	srand((unsigned long) &main);
label:
	int t[15];

	for(int i = 0; i < 15; i++){
		t[i] = (rand() % 95) + 33;
	}

	bool __upper = false, __lower = false, __digit = false, __special = false, __out = false;
	for (int i = 0; i < 15; i++){
		if (t[i] <= 32 || t[i] > 127) __out = true;
		if (isupper(t[i])) __upper = true;
		else if (islower(t[i])) __lower = true;
		else if (isdigit(t[i])) __digit = true;
		else __special = true;
	}

	if ((__upper | __lower | __digit | __special | __out) == false)
		goto label;

	for(int i = 0; i < 15; i++)
		printf("%c", t[i]);
	printf("%s\n", t);
}
