#include "circularlist.h"

CircularList *createCircularList(void)
{
	CircularList *new;

	new = calloc(1, sizeof(CircularList));
	if (!new)
		return (NULL);
	return (new);
}

int addCLElement(CircularList *pList, int position, ListNode element)
{
	ListNode	*new;
	ListNode	*prev;
	ListNode	*last;

	if(!pList || position < 0 || position > pList->currentElementCount)
		return (FALSE);
	new = malloc(sizeof(ListNode));
	if (!new)
		return (FALSE);
	*new = element;
	prev = pList->headPtr;
	if (position == 0)
	{
		if (pList->currentElementCount == 0)
		{
			new->pLink = new;
			pList->headPtr = new;
		}
		else
		{
			last = prev;
			while (last->pLink != pList->headPtr)
				last = last->pLink;
			new->pLink = prev;
			last->pLink = new;
			pList->headPtr = new;
		}
	}
	else
	{
		while (--position > 0)
			prev = prev->pLink;
		new->pLink = prev->pLink;
		prev->pLink = new;
	}
	pList->currentElementCount++;
	return (TRUE);
}

int removeCLElement(CircularList* pList, int position)
{
	ListNode *remove;
	ListNode *prev;
	ListNode *last;

	if (!pList || position >= pList->currentElementCount || position < 0)
		return (FALSE);
	prev = pList->headPtr;
	if (position == 0)
	{
		remove = prev;
		if (pList->currentElementCount == 1)
			pList->headPtr = NULL;
		else
		{
			last = prev;
			while (last->pLink != pList->headPtr)
				last = last->pLink;
			pList->headPtr = remove->pLink;
			last->pLink = remove->pLink;
		}
	}
	else
	{
		while (--position > 0)
			prev = prev->pLink;
		remove = prev->pLink;
		prev->pLink = remove->pLink;
	}
	free(remove);
	pList->currentElementCount--;
	return (TRUE);
}

ListNode *getCLElement(CircularList *pList, int position)
{
	ListNode *ret;

	if (!pList || position < 0 || position >= pList->currentElementCount)
		return (FALSE);
	ret = pList->headPtr;
	while (position-- > 0)
		ret = ret->pLink;
	return (ret);
}

int getCircularListLength(CircularList *pList)
{
	return (pList->currentElementCount);
}

void displayCircularList(CircularList *pList)
{
	ListNode	*cur;
	int			i;

	if (!pList)
	{
		printf("No List\n");
		return ;
	}
	printf("(1) Current Element count: %d\n", pList->currentElementCount);
	if (pList->currentElementCount == 0)
		printf("(2) Element: No Element\n\n");
	else
	{
		printf("(2) Element\n");
		cur = pList->headPtr;
		for (i = 0; i < pList->currentElementCount; i++)
		{
			printf("[%d]: %d", i, cur->data);
			if (i != pList->currentElementCount - 1)
				printf(", ");
			cur = cur->pLink;
		}
		printf("\n\n");
	}
}

void clearCircularList(CircularList* pList)
{
	ListNode* node;
	ListNode* tmp;

	if (pList->currentElementCount == 0)
		return ;
	node = pList->headPtr;
	while (pList->currentElementCount-- > 0)
	{
		tmp = node->pLink;
		free(node);
		node = tmp;
	}
	pList->headPtr = NULL;
	pList->currentElementCount = 0;
}

void deleteCircularList(CircularList *pList)
{
	clearCircularList(pList);
	free(pList);
}

