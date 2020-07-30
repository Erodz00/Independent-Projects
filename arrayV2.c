#include <stdio.h>
#include <stdlib.h>

typedef struct arrayV2
{
	int *array;
	int length;
	int even;
	int odd;
} arrayV2;

arrayV2 *destroyArray(arrayV2 *arr)
{
	if(arr == NULL)
		return NULL;
	
	free(arr->array);
	free(arr);
	
	return NULL;
}

arrayV2 *createArray(int n)
{
	arrayV2 *temp = malloc(sizeof(arrayV2));
	temp->array = malloc(sizeof(int) * n);
	temp->length = n;
	
	return temp;
}

void setArray(arrayV2 *arr)
{
	for(int i = 0; i < arr->length; i++)
	{
		arr->array[i] = i;
		if(i % 2 == 0)
			arr->even++;
		else
			arr->odd++;
	}
}

void printArray(arrayV2 *arr)
{
	for(int i = 0; i < arr->length; i++)
	{
		printf("%d ", arr->array[i]);
	}
	printf("Even: %d, Odd: %d, Length: %d\n", arr->even, arr->odd, arr->length);
}

int main(void)
{
	int n;
	scanf("%d", &n);
	
	arrayV2 *arr = createArray(n);
	
	setArray(arr);
	
	printArray(arr);
	
	arr = destroyArray(arr);
	
	return 0;
}
