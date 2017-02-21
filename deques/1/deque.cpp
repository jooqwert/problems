/* 덱 : https://www.acmicpc.net/problem/10866 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Elem
{
	int value;
	struct Elem * forev;
	struct Elem * postv;
} Elem;

typedef struct Deque
{
	int size;
	struct Elem * front;
	struct Elem * back;
} Deque;



int main()
{
	int N;
	char buffer[1024];
	Deque deque;
	scanf("%d", &N);

	// initialize deque //
	deque.size=0;

	for(int i=0;i<N;i++){	

		int value;
		Elem * temp;
		scanf("%s", buffer);
		if(!strcmp(buffer, "push_back")){
			scanf("%d", &value);
			temp = (Elem*)malloc(sizeof(Elem));
			temp->value = value;
			temp->postv = NULL;
			if (deque.size == 0)
			{
				deque.front = temp;
				deque.back = temp;
				temp->forev = NULL;
			}
			else
			{
				Elem * back = deque.back;
				back->postv = temp;
				temp->forev = back;
				deque.back = temp;
			}
			deque.size++;
		}
		else if(!strcmp(buffer, "push_front")){
			scanf("%d", &value);
			temp = (Elem*)malloc(sizeof(Elem));
			temp->value = value;
			temp->forev = NULL;
			if (deque.size == 0)
			{
				deque.front = temp;
				deque.back = temp;
				temp->postv = NULL;
			}
			else
			{
				Elem * front = deque.front;
				front->forev = temp;
				temp->postv = front;
				deque.front = temp;
			}
			deque.size++;
		}
		else if(!strcmp(buffer, "pop_front")){
			if(deque.size > 0){
				temp = deque.front;
				deque.front = temp->postv;
				printf("%d\n", temp->value);
				deque.size--;
				free(temp);
			}
			else {
				printf("-1\n");
			}
		}
		else if(!strcmp(buffer, "pop_back")){
			if(deque.size > 0){
				temp = deque.back;
				deque.back = temp->forev;
				printf("%d\n", temp->value);
				deque.size--;
				free(temp);
			}
			else {
				printf("-1\n");
			}
		}
		else if(!strcmp(buffer, "size")){
			printf("%d\n", deque.size);
		}
		else if(!strcmp(buffer, "empty")){
			if(deque.size==0){
				printf("1\n");
			} else{
				printf("0\n");
			}

		}
		else if(!strcmp(buffer, "front")){
			if(deque.size > 0){
				printf("%d\n", deque.front->value);	
			}
			else {
				printf("-1\n");
			}
			
		}
		else if(!strcmp(buffer, "back")){
			if(deque.size > 0){
				printf("%d\n", deque.back->value);	
			}
			else {
				printf("-1\n");
			}
			
		}
	}

	return 0;
}