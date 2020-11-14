#include "queue.h"

int main()
{
	Queue qu; //Program variables
	int itt, value, arr[6] = {1,2,3,4,5,6};
	qu.size = 0;
	qu.head = NULL;
	qu.tail = NULL;
	for (itt = 0; itt < 6; itt++)
	{
		printf("Trying to Enqueue item %d: %d\n", itt+1, arr[itt]);
		enQueue(&qu, arr[itt]);
	}
	printf("--------------------\n");
	for (itt = 0; itt < 6; itt++)
	{
		deQueue(&qu, &value) ? printf("Dequeue item %d: %d\n", itt+1, value) : 0;
	}
	return 0;
}
