#include <stdio.h>
#include <stdlib.h>

// Find if number is a perfect square
// If number is not a perfect square, find the next closest square

void perfect_square(int n, int *perfect_ptr, int *root_ptr)
{
	int flag = 0, i;
	for(i = 1; i * i <= n; i++)
	{
		if(n / i == i && n % i == 0)
		{
			*perfect_ptr = i;
			flag = 1;
			break;
		}
		else
		{
			*perfect_ptr = 0;
		}
	}
	if(flag)
		*root_ptr = *perfect_ptr;
	else
		*root_ptr = i;
}

int main(void)
{
	int n, *perfect_ptr = malloc(sizeof(int)), *root_ptr = malloc(sizeof(int));
	scanf("%d", &n);
	perfect_square(n, perfect_ptr, root_ptr);
	printf("n = %d, *perfect_ptr = %d, *root_ptr = %d\n", n , *perfect_ptr, *root_ptr);
	free(perfect_ptr);
	free(root_ptr);
	return 0;
}
