#include "doublylist.h"

DoublyList *createDoublyList(void)
{
    DoublyList *new;

    new = malloc(sizeof(DoublyList));
    if (!new)
        return (NULL);
    new->currentElementCount = 0;
    new->headerNode.pLLink = &new->headerNode;
    new->headerNode.pRLink = &new->headerNode;
    return (new);
}

int addDLElement(DoublyList *pList, int position, DoublyListNode element)
{
    DoublyListNode *new;
    DoublyListNode *prev;

    if(!pList || position < 0 || position > pList->currentElementCount)
        return (FALSE);
    new = malloc(sizeof(DoublyListNode));
    if (!new)
        return (FALSE);
    *new = element;
    prev = &pList->headerNode;
    for (int i = 0; i < position; i++)
        prev = prev->pRLink;
    new->pRLink = prev->pRLink;
    new->pLLink = prev;
    prev->pRLink->pLLink = new;
    prev->pRLink = new;
    pList->currentElementCount++;
    return (TRUE);
}

int removeDLElement(DoublyList* pList, int position)
{
    DoublyListNode *remove;

    if (!pList || position < 0 || position >= pList->currentElementCount)
        return (FALSE);
    remove = getDLElement(pList, position);
	remove->pRLink->pLLink = remove->pLLink;
	remove->pLLink->pRLink = remove->pRLink;
	free(remove);
    pList->currentElementCount--;
    return (TRUE);
}

DoublyListNode *getDLElement(DoublyList *pList, int position)
{
    DoublyListNode *res;

    if (!pList || position < 0 || position >= pList->currentElementCount)
        return (FALSE);
    res = &pList->headerNode;
    if (pList->currentElementCount / 2 > position)
    {
        for (int i = 0; i <= position; i++)
            res = res->pRLink;
    }
    else
    {
        for (int i = 0; i < pList->currentElementCount - position; i++)
            res = res->pLLink;
    }
    return (res);
}

int getDoublyListLength(DoublyList *pList)
{
    return (pList->currentElementCount);
}

void displayDoublyList(DoublyList *pList)
{
    DoublyListNode	*cur;
    int				i;

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
		cur = pList->headerNode.pRLink;
		for (i = 0; i < pList->currentElementCount; i++)
		{
			printf("[%d]: %d", i, cur->data);
			if (i != pList->currentElementCount - 1)
				printf(", ");
			cur = cur->pRLink;
		}
		printf("\n\n");
	}
}

void clearDoublyList(DoublyList* pList)
{
    DoublyListNode* node;
    DoublyListNode* tmp;

    if (pList->currentElementCount == 0)
        return ;
    node = pList->headerNode.pRLink;
    while (node != &pList->headerNode)
    {
        tmp = node->pRLink;
        free(node);
        node = tmp;
    }
    node->pRLink = &pList->headerNode;
    node->pLLink = &pList->headerNode;
    pList->currentElementCount = 0;
}

void deleteDoublyList(DoublyList *pList)
{
    clearDoublyList(pList);
    free(pList);
}