#include "arraystack.h"

ArrayStack* createArrayStack(int maxElementCount)
{
	ArrayStack *new;

	new = malloc(sizeof(ArrayStack) * 1);
	if (!new) 
		return (NULL);
	new->maxElementCount = maxElementCount;
	new->currentElementCount = 0;
	new->pElement = malloc(sizeof(ArrayStackNode) * maxElementCount);
	if (!(new->pElement))
	{
		free(new);
		return (NULL);
	}
	return (new);
}

// 배열 크기가 모자랄 경우 새 배열 할당
int pushAS(ArrayStack* pStack, ArrayStackNode element)
{
	ArrayStackNode *newElement;

	if(!pStack)
		return (FALSE);
	if (pStack->currentElementCount == pStack->maxElementCount)
	{
		printf("Array is Full. New Array Allocated. Size of Array : %d\n", pStack->maxElementCount * 2);
		newElement = malloc(sizeof(ArrayStackNode) * (pStack->maxElementCount * 2));
		if (!newElement)
			return (FALSE);
		pStack->maxElementCount *= 2;
		for (int i = 0; i < pStack->currentElementCount; i++)
			newElement[i] = pStack->pElement[i];
		free(pStack->pElement);
		pStack->pElement = newElement;
	}
	pStack->pElement[pStack->currentElementCount] = element;
	pStack->currentElementCount++;
	return (TRUE);
}

ArrayStackNode* popAS(ArrayStack* pStack)
{
	if ((!pStack) || pStack->currentElementCount == 0)
		return (NULL);
	pStack->currentElementCount--;
	return (&pStack->pElement[pStack->currentElementCount]);
}

ArrayStackNode* peekAS(ArrayStack* pStack)
{
	if ((!pStack) || pStack->currentElementCount == 0)
		return (NULL);
	return (&pStack->pElement[pStack->currentElementCount - 1]);
}

void displayStack(ArrayStack *pStack)
{
	if (!pStack)
	{
		printf("No Array\n\n");
		return ;
	}
	printf("(1) Size of Array: %d\n", pStack->maxElementCount);
	printf("(2) Current Element count: %d\n", pStack->currentElementCount);
	if (pStack->currentElementCount == 0)
		printf("(3) Element: No Element");
	else
		printf("(3) Element:\n");
	for (int i = 0; i < pStack->currentElementCount; i++)
	{
		printf("[%d] = %c", i, pStack->pElement[i].data);
		if (i != pStack->currentElementCount - 1)
			printf(", ");
	}
	printf("\n\n");
}

int isArrayStackFull(ArrayStack* pStack)
{
	return (pStack->currentElementCount == pStack->maxElementCount);
}

int isArrayStackEmpty(ArrayStack* pStack)
{
	return (pStack->currentElementCount == 0);
}

void deleteArrayStack(ArrayStack* pStack)
{
	if (!pStack)
		return ;
	free(pStack->pElement);
	pStack->pElement = NULL;
	free(pStack);
}
