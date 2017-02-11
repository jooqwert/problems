/* https://www.acmicpc.net/problem/10845 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Elem
{
	int value;
	struct Elem * nextv;
} Elem;

typedef struct Queue
{
	int size;
	struct Elem * front;
} Queue;



int main()
{
	int N;
	char buffer[1024];
	Queue queue;
	scanf("%d", &N);

	// initialize queue //
	queue.size=0;
	for(int i=0;i<N;i++){	

		int value;
		Elem * temp;
		scanf("%s", buffer);
		if(!strcmp(buffer, "push")){
			scanf("%d", &value);
			temp = (Elem*)malloc(sizeof(Elem));
			temp->value = value;
			temp->nextv = NULL;
			if (queue.size == 0)
			{
				queue.front = temp;
			}
			else
			{
				Elem * back = queue.front;
				while(back->nextv != NULL)
					back = back->nextv;
				back->nextv = temp;
			}
			queue.size++;
		}
		else if(!strcmp(buffer, "pop")){
			if(queue.size > 0){
				temp = queue.front;
				queue.front = temp->nextv;
				printf("%d\n", temp->value);
				queue.size--;
				free(temp);
			}
			else {
				printf("-1\n");
			}
		}
		else if(!strcmp(buffer, "size")){
			printf("%d\n", queue.size);
		}
		else if(!strcmp(buffer, "empty")){
			if(queue.size==0){
				printf("1\n");
			} else{
				printf("0\n");
			}

		}
		else if(!strcmp(buffer, "front")){
			if(queue.size > 0){
				printf("%d\n", queue.front->value);	
			}
			else {
				printf("-1\n");
			}
			
		}
		else if(!strcmp(buffer, "back")){
			if(queue.size > 0){
				temp = queue.front;
				while((temp->nextv!=NULL))
				{
					temp = temp->nextv;
				}
				printf("%d\n", temp->value);	
			}
			else {
				printf("-1\n");
			}
			
		}
	}

	return 0;
}