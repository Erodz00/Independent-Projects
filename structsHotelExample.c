#include <stdio.h>
#include <string.h>

typedef struct hotel
{
	int hotelRoom[10]; // [hotelCapacity]
	char *familyNames[10]; // [hotelCapacity]
	int hotelCapacity; // 10
	int hotelSize; // 0
} hotel;

hotel insertGuest(hotel h)
{
	if(h.hotelSize == h.hotelCapacity)
	{
		printf("Hotel is at max capacity!\nCannot accept any more guests!\n");
		return h;
	}
	char buffer[2048];
	for(int i = 0; i < h.hotelCapacity; i++)
	{
		if(h.hotelRoom[i] == 0)
		{
			h.hotelRoom[i] = 1;
			printf("What family is staying at room %d? \n", i + 1);
			scanf("%s", buffer);
			h.familyNames[i] = strdup(buffer); // Ronald
			h.hotelSize++;
			break;
		}
	}
	return h;
}

hotel removeGuest(hotel h)
{
	if(h.hotelSize == 0)
	{
		printf("Hotel is Empty!\nCannot remove any guests!\n");
		return h;
	}
	for(int i = h.hotelCapacity - 1; i >= 0; i--)
	{
		if(h.hotelRoom[i] == 1)
		{
			h.hotelRoom[i] = 0;
			printf("The %s Family is being removed from room %d.\n", h.familyNames[i], i + 1);
			h.familyNames[i] = "empty";
			h.hotelSize--;
			break;
		}
	}
	return h;
}

hotel createHotel(void)
{
	hotel h;
	h.hotelCapacity = 10;
	h.hotelSize = 0;
	
	for(int i = 0; i < h.hotelCapacity; i++)
	{
		h.hotelRoom[i] = 0;
		h.familyNames[i] = "empty";
	}
	return h;
}

void printHotel(hotel h)
{
	printf("There are %d out of %d people staying at the hotel!\n", h.hotelSize, h.hotelCapacity);
	for(int i = 0; i < h.hotelCapacity; i++)
	{
		printf("In room %d, the %s family is staying here.\n", i + 1, h.familyNames[i]);
	}
}

int main(void)
{
	hotel Example = createHotel();
	int menuSelection;
	while(1)
	{
		printf("\nEnter a program selection:\n");
		printf("Entry 1: Add Guest\n");
		printf("Entry 2: Remove Guest\n");
		printf("Entry 3: Print Guests\n");
		printf("Entry 4: Exit\n");
		scanf("%d", &menuSelection);
		switch(menuSelection)
		{
			case 1:
				Example = insertGuest(Example);
				continue;
			case 2:
				Example = removeGuest(Example);
				continue;
			case 3:
				printHotel(Example);
				continue;
			case 4:
				return 0;
			default:
				printf("Invalid Selection Number\n");
				continue;
		}
	}
	return 0;
}