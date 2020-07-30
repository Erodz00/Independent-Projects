#include <stdio.h>

int main(void)
{
	// 5 ^ 4
	// 5 * 5 = 25
	// 25 * 5 = 125
	// 125 * 5 = 625
	int a = 5, b = 4;
	int answer = a;
	for(int i = 0; i < b - 1;i++)
	{
		answer = answer * a;
	}
	
	printf("%d\n",answer);
 	return 0;
}
