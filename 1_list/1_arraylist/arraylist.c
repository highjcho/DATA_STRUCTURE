#include "arraylist.h"

ArrayList* createArrayList(int maxElementCount)
{
    ArrayList *new;

    new = (ArrayList *)malloc(sizeof(ArrayList) * 1);
    if (!new)
        return NULL;
    new->maxElementCount = maxElementCount;
    new->currentElementCount = 0;
    new->pElement = (ArrayListNode *)malloc(sizeof(ArrayListNode) * maxElementCount);
    if (!(new->pElement))
    {
        free(new);
        return (NULL);
    }
    return (new);
}

void deleteArrayList(ArrayList *pList)
{
    clearArrayList(pList);
	free(pList->pElement);
    pList->pElement = NULL;
    free(pList);
	pList = NULL;
}

int isArrayListFull(ArrayList* pList)
{
    return (pList->maxElementCount == pList->currentElementCount);
}

int addALElement(ArrayList* pList, int position, ArrayListNode element)
{
    ArrayListNode   *newArray;
    int             idx;

    if (!pList)
    {
        printf("Error: No ArrayList\n");
        return (FALSE);
    }
    if (position < 0 || position > pList->currentElementCount)
    {
        printf("Error: Invalid position\n");
        return (FALSE);
    }
    if (pList->currentElementCount == pList->maxElementCount)
    {
        newArray = malloc(sizeof(ArrayListNode) * pList->maxElementCount * 2);
        if (!newArray)
            return (FALSE);
        for (idx = 0; idx < pList->currentElementCount; idx++)
            newArray[idx] = pList->pElement[idx];
        free(pList->pElement);
        pList->pElement = newArray;
        pList->maxElementCount *= 2;
        printf("Array is Full. New Array Allocated. Size of Array : %d\n", pList->maxElementCount);
    }
    for (idx = pList->currentElementCount++; idx > position; idx--)
        pList->pElement[idx] = pList->pElement[idx - 1];
	pList->pElement[idx] = element;
	return (TRUE);
}

int removeALElement(ArrayList* pList, int position)
{
 	int	idx;
    
    if (!pList || pList->currentElementCount == 0 || position < 0 || position >= pList->currentElementCount)
    	return (FALSE);
    pList->currentElementCount--;
    for (idx = position; idx < pList->currentElementCount; idx++)
    	pList->pElement[idx] = pList->pElement[idx + 1];
    return (TRUE);
}

ArrayListNode* getALElement(ArrayList* pList, int position)
{
    if (pList != 0 && (position >= 0 && position < pList->currentElementCount))
        return (&pList->pElement[position]);
    return (NULL);
}

void displayArrayList(ArrayList* pList)
{
    int count;
    int i;

	if (!pList)
    {
		printf("Error: No Array");
        return ;
    }
	count = pList->currentElementCount;
    printf("Max Element Count: %d\n", pList->maxElementCount);
    printf("Current Element Count: %d\n", count);
    if (count == 0)
        printf("Elements: No Element");
    else
    {
        printf("Elements: ");
        for (i = 0; i < count; i++)
        {
            printf("[%d] %d", i, pList->pElement[i].data);
            if (i != count - 1)
                printf(", ");
        }
	    printf("\n\n");
    }
}

void clearArrayList(ArrayList* pList)
{
    pList->currentElementCount = 0;
	//만약 나중에 다른 데이터를 포함하게 되면 별도로 초기화 하는 메소드를 써주는게 좋을 것 같다
}

int getArrayListLength(ArrayList* pList)
{
    return (pList->currentElementCount);
}
