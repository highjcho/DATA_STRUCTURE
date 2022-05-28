#include "linkedstack.h"

int main(void)
{
	LinkedStack	*pStack;
	StackNode	*node;
	StackNode	stackNode;
	int			loop;
	int			opt;

	pStack = NULL;
	loop = 1;
	while (loop)
	{
		printf("[1] Create [2] Push [3] Pop [4] Peek [5] Reverse [6] Check Full [7] Check Empty [8] Display [9] Delete [10] Exit ");
		scanf("%d", &opt);
		switch (opt)
		{
			case 1:
				if (pStack)
				{
					printf("Stack already exists.\n\n");
					break;
				}
				pStack = createLinkedStack();
				if (pStack)
					printf("Create linked stack: Success\n\n");
				else
					printf("Create linked stack: Fail\n\n");
				break;
			case 2:
				if (!pStack)
				{
					printf("There is no stack. Please create first.\n\n");
					break;
				}
				printf("Data: ");
				scanf(" %c", &stackNode.data);
				if (pushLS(pStack, stackNode))
				{
					printf("Push: Success\n\n");
					displayStack(pStack);
				}
				else
					printf("Push: Fail\n\n");
				break;
			case 3:
				node = popLS(pStack);
				if (node)
				{
					printf("Pop: %c\n\n", node->data);
					free(node);
					node = NULL;
					displayStack(pStack);
				}
				else
					printf("Pop: fail\n\n");
				break;
			case 4:
				node = peekLS(pStack);
				if (node)
					printf("Peek: %c\n\n", node->data);
				else
					printf("Peek: Fail\n\n");
				break;
			case 5:
				pStack = reverseLS(pStack);
				if (pStack)
				{
					printf("Reverse: Success\n\n");
					displayStack(pStack);
				}
				else
					printf("Reverse: Fail\n\n");
				break;
			case 6:
				if (isLinkedStackFull(pStack))
					printf("Yes\n\n");
				else
					printf("No\n\n");
				break;
			case 7:
				if (isLinkedStackEmpty(pStack) == -1)
					printf("No Stack\n\n");
				else if (isLinkedStackEmpty(pStack))
					printf("Yes\n\n");
				else
					printf("No\n\n");
				break;
			case 8:
				if (!pStack)
				{
					printf("There is no stack. Please create first.\n\n");
					break;
				}
				displayStack(pStack);
				break;
			case 9:
				if (!pStack)
					printf("Delete: There is no stack.\n\n");
				else
				{
					deleteLinkedStack(pStack);
					pStack = NULL;
					printf("Delete: Success\n\n");
				}
				break;
			case 10:
				loop = 0;
				break;
			default:
				printf("Please enter a valid option\n\n");
				break;
		}
	}
}