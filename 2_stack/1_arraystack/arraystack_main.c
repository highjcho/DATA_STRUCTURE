#include "arraystack.h"

int main(void)
{
	ArrayStack	*pStack;
	ArrayStackNode	*element;
	ArrayStackNode	stackElement;
	int				loop;
	int				opt;

	pStack = NULL;
	loop = 1;
	while (loop)
	{
		printf("[1] Create [2] Push [3] Pop [4] Peek [5] Check Full [6] Check Empty [7] Display [8] Delete [9] Exit ");
		scanf("%d", &opt);
		switch (opt)
		{
			case 1:
				if (pStack)
				{
					printf("Stack already exists.\n\n");
					break;
				}
				printf("Size of Array: ");
				scanf("%d", &opt);
				pStack = createArrayStack(opt);
				if (pStack)
					printf("Create array stack: Success\n\n");
				else
					printf("Create array stack: Fail\n\n");
				break;
			case 2:
				if (!pStack)
				{
					printf("There is no stack. Please create first.\n\n");
					break;
				}
				printf("Data: ");
				scanf(" %c", &stackElement.data);
				if (pushAS(pStack, stackElement))
				{
					printf("Push: Success\n\n");
					displayStack(pStack);
				}
				else
					printf("Push: Fail\n\n");
				break;
			case 3:
				element = popAS(pStack);
				if (element)
				{
					printf("Pop: %c\n", element->data);
					displayStack(pStack);
				}
				else
					printf("Pop: Fail\n\n");
				break;
			case 4:
				element = peekAS(pStack);
				if (element)
					printf("Peek: %c\n\n", element->data);
				else
					printf("Peek: Fail\n\n");
				break;
			case 5:
				if (isArrayStackFull(pStack))
					printf("Yes\n\n");
				else
					printf("No\n\n");
				break;
			case 6:
				if (isArrayStackEmpty(pStack))
					printf("Yes\n\n");
				else
					printf("No\n\n");
				break;
			case 7:
				if (!pStack)
				{
					printf("There is no stack. Please create first.\n\n");
					break;
				}
				displayStack(pStack);
				break;
			case 8:
				if (!pStack)
					printf("Delete: There is no stack.\n\n");
				else
				{
					deleteArrayStack(pStack);
					pStack = NULL;
					printf("Delete: Success\n\n");
				}
				break;
			case 9:
				loop = 0;
				break;
			default:
				printf("Please Enter a Valid Option\n");
				break;
		}
	}
}