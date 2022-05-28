#include "linkedstack.h"
 
LinkedStack* createLinkedStack()
{
	LinkedStack	*new;
	
	new = calloc(1, sizeof(LinkedStack));
	if (!new)
		return (NULL);
	return (new);
}

int pushLS(LinkedStack* pStack, StackNode element)
{
	StackNode	*new;

	if (!pStack)
		return (FALSE);
	new = malloc(sizeof(StackNode));
	if (!new)
		return (FALSE);
	*new = element;
	new->pLink = pStack->pTopElement;
	pStack->pTopElement = new;
	pStack->currentElementCount++;
	return (TRUE);
}

StackNode* popLS(LinkedStack* pStack)
{
	StackNode	*ret;

	if (!pStack || pStack->currentElementCount == 0)
		return (NULL);
	ret = pStack->pTopElement;
	pStack->pTopElement = ret->pLink;
	ret->pLink = NULL;
	pStack->currentElementCount--;
	return (ret);
}

StackNode* peekLS(LinkedStack* pStack)
{
	if (!pStack)
		return (NULL);
	return (pStack->pTopElement);
}

LinkedStack* reverseLS(LinkedStack* pStack)
{
	LinkedStack*	reverse;
	StackNode*		node;
	StackNode*		tmp;
	StackNode*		pop;

	if (!pStack)
		return (NULL);
	reverse = createLinkedStack();
	if (!reverse)
		return (NULL);
	node = pStack->pTopElement;
	while(node)
	{
		tmp = node->pLink; 
		pop = popLS(pStack);
		pushLS(reverse, *pop);
		free(pop);
		node = tmp;
	}
	deleteLinkedStack(pStack);
	return (reverse);
}

void	displayStack(LinkedStack *pStack)
{
	StackNode	*cur;
	int			i;

	if (!pStack)
	{
		printf("No List\n\n");
		return ;
	}
	printf("(1) Current Element count: %d\n", pStack->currentElementCount);
	if (pStack->currentElementCount == 0)
		printf("(2) Element: No Element");
	else
		printf("(2) Element: \n");
	cur = pStack->pTopElement;
	i = 0;
	while (cur)
	{
		printf("[%d]: %c", i++, cur->data);
		if (i != pStack->currentElementCount)
			printf(", ");
		cur = cur->pLink;
	}
	printf("\n\n");
}

int isLinkedStackFull(LinkedStack* pStack)
{
	return (FALSE);
}

int isLinkedStackEmpty(LinkedStack* pStack)
{
	if (!pStack)
		return (-1);
	return (pStack->currentElementCount == 0);
}

void deleteLinkedStack(LinkedStack* pStack)
{
	StackNode	*node;
	StackNode	*tmp;

	if (!pStack)
		return ;
	pStack->currentElementCount = 0;
	node = pStack->pTopElement;
	while (node)
	{
		tmp = node->pLink;
		node->pLink = NULL;
		free(node);
		node = tmp;
	}
	free(pStack);
}