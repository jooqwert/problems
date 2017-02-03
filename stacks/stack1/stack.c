#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Elem
{
	int value;
	struct Elem * prev;
} Elem;

typedef struct Stack
{
	int size;
	struct Elem * top;
} Stack;



int main()
{
	int N;
	char buffer[1024];
	Stack stack;
	scanf("%d", &N);

	// initialize stack //
	stack.size=0;
	for(int i=0;i<N;i++){	

		int value;
		Elem * temp;
		scanf("%s", buffer);
		if(!strcmp(buffer, "push")){
			scanf("%d", &value);
			temp = (Elem*)malloc(sizeof(Elem));
			temp->value = value;
			temp->prev = stack.top;
			stack.top = temp;
			stack.size++;
		}
		else if(!strcmp(buffer, "pop")){
			if(stack.size > 0){
				temp = stack.top;
				stack.top = temp->prev;
				printf("%d\n", temp->value);
				stack.size--;
				free(temp);
			}
			else {
				printf("-1\n");
			}
		}
		else if(!strcmp(buffer, "size")){
			printf("%d\n", stack.size);
		}
		else if(!strcmp(buffer, "empty")){
			if(stack.size==0){
				printf("1\n");
			} else{
				printf("0\n");
			}

		}
		else if(!strcmp(buffer, "top")){
			if(stack.size > 0){
				printf("%d\n", stack.top->value);	
			}
			else {
				printf("-1\n");
			}
			
		}
	}

	return 0;
}