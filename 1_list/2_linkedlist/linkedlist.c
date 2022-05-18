#include "linkedlist.h"

LinkedList *createLinkedList(void)
{
	LinkedList *new;

	new = calloc(1, sizeof(LinkedList));
	if (!new)
		return (NULL);
	return (new);
}

int addLLElement(LinkedList *pList, int position, ListNode element)
{
	ListNode *new;
	ListNode *prev;

	if(!pList || position < 0 || position > pList->currentElementCount)
		return (FALSE);
	new = malloc(sizeof(ListNode) * 1);
	if (!new)
		return (FALSE);
	*new = element;
	prev = &(pList->headerNode);
	for (int i = 0; i < position; i++)
		prev = prev->pLink;
	new->pLink = prev->pLink;
	prev->pLink = new;
	pList->currentElementCount++;
	return (TRUE);
}

int removeLLElement(LinkedList* pList, int position)
{
	ListNode *remove;
	ListNode *prev;

	if (!pList || position < 0 || position >= pList->currentElementCount)
		return (FALSE);
	prev = &(pList->headerNode);
	for (int i = 0; i < position; i++)
		prev = prev->pLink;
	remove = prev->pLink;
	prev->pLink = remove->pLink;
	pList->currentElementCount--;
	free(remove);
	return (TRUE);
}

ListNode *getLLElement(LinkedList *pList, int position)
{
	ListNode *ret;

	if (!pList || position < 0 || position >= pList->currentElementCount)
		return (FALSE);
	ret = &(pList->headerNode);
	for (int i = 0; i <= position; i++)
		ret = ret->pLink;
	return (ret);
}

void reverseList(LinkedList *pList)
{
	ListNode *first;
	ListNode *cur;
	ListNode *last;

	if (!pList)
		return ;
	first = pList->headerNode.pLink;
	cur = NULL;
	while (first)
	{
		last = cur;
		cur = first;
		first = cur->pLink;
		cur->pLink = last;
	}
	pList->headerNode.pLink = cur;
}

int getLinkedListLength(LinkedList *pList)
{
	return (pList->currentElementCount);
}


void displayLinkedList(LinkedList *pList)
{
	ListNode   *cur;
	int         i;

	if (!pList)
	{
		printf("No List\n");
		return ;
	}
	printf("(1) Current Element count: %d\n", pList->currentElementCount);
	if (pList->currentElementCount == 0)
		printf("(2) Element: No Element");
	else
		printf("(2) Element: \n");
	cur = pList->headerNode.pLink;
	i = 0;
	while (cur)
	{
		printf("[%d]: %d", i++, cur->data);
		if (i != pList->currentElementCount)
			printf(", ");
		cur = cur->pLink;
	}
	printf("\n\n");
}

void clearLinkedList(LinkedList* pList)
{
	ListNode* headerNode;
	ListNode* node;
	ListNode* temp;

	if (pList->currentElementCount == 0)
		return ;
	headerNode = &(pList->headerNode);
	node = headerNode->pLink;
	while (node)
	{
		temp = node->pLink;
		free(node);
		node = temp;
	}
	headerNode->pLink = NULL;
	pList->currentElementCount = 0;
}

void deleteLinkedList(LinkedList *pList)
{
	clearLinkedList(pList);
	free(pList);
}
