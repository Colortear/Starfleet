#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

#include "header.h"

int main(void)
{
	struct s_queue	*queue;

	queue = queueInit();
	enqueue(queue, "msg1");
	enqueue(queue, "msg2");
	printf("result of peek: %s\n", peek(queue));
	printf("result should be 0\nresult: %i\n", isEmpty(queue));
	printf("result of dequeue: %s\n", dequeue(queue));
	printf("result of dequeue: %s\n", dequeue(queue));
	printf("result of dequeue: %s\n", dequeue(queue));
	printf("result should be 1\nresult: %i\n", isEmpty(queue));
	return (0);
}



// Function used for the test
// Don't go further :)

