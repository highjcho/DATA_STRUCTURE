#include "linkedlist.h"

int main(void)
{
    LinkedList	*pList;
    ListNode	*node;
    ListNode	element;
    int			loop;
    int			opt;
	int			position;

	pList = NULL;
	loop = 1;
    while (loop)
    {
        printf("[1] Create [2] Add [3] Remove [4] Get element [5] Length [6] Reverse [7] Display [8] Clear [9] Delete [10] Exit ");
        scanf("%d", &opt);
        switch (opt)
        {
            case 1:
                pList = createLinkedList();
                if (pList)
                    printf("Create Linked List: Success\n\n");
                else
                    printf("Create Linked List: Failed\n\n");
                break;
            case 2:
                printf("Position: ");
                scanf("%d", &position);
                printf("Data: ");
                scanf("%d", &element.data);
                if (addLLElement(pList, position, element))
                {
                    printf("ADD: Success\n\n");
                    displayLinkedList(pList);
                }
                else
                    printf("Add: Fail\n\n");
                break;
            case 3:
                printf("Position: ");
                scanf("%d", &position);
                if (removeLLElement(pList, position))
                {
                    printf("Remove: Success\n\n");
                    displayLinkedList(pList);
                }
                else
                    printf("Remove: Fail\n\n");
                break;
            case 4:
                printf("Position: ");
                scanf("%d", &position);
                node = getLLElement(pList, position);
                if (node)
                    printf("[%d]: %d\n\n", position, node->data);
                else
                    printf("Fail\n\n");
                break;
            case 5:
                printf("Length: %d\n\n", getLinkedListLength(pList));
                break;
            case 6:
                reverseList(pList);
                displayLinkedList(pList);
                break;
            case 7:
                displayLinkedList(pList);
                break;
            case 8:
                clearLinkedList(pList);
                printf("Clear: Success\n\n");
                break;
            case 9:
                if (!pList)
                    printf("Delete: Fail\n\n");
                else
                {
                    deleteLinkedList(pList);
                    pList = NULL;
                    printf("Delete: Success\n\n");
                }
                break;
            case 10:
                loop = 0;
                break;
            default:
                printf("Please Enter a Valid Option\n\n");
        }
    }
}