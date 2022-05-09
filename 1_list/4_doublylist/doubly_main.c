#include "doublylist.h"

int main(void)
{
	DoublyList		*pList;
	DoublyListNode	*node;
	DoublyListNode	DoublyListNode;
	int				loop;
	int				opt;
	int				position;

	pList = NULL;
	loop = 1;
	while (loop)
	{
		printf("[1] Create [2] Add [3] Remove [4] Get Element [5] Length [6] Display [7] Clear [8] Delete [9] Exit ");
		scanf("%d", &opt);
		switch (opt)
		{
		case 1:
			pList = createDoublyList();
			if (pList)
				printf("Create Doubly List: Success\n\n");
			else
				printf("Create Doubly List: Fail\n\n");
			break;
		case 2:
			printf("Position: ");
			scanf("%d", &position);
			printf("Data: ");
			scanf("%d", &DoublyListNode.data);
			if (addDLElement(pList, position, DoublyListNode))
			{
				printf("Add: Success\n\n");
				displayDoublyList(pList);
			}
			else
				printf("Add: Fail\n\n");
			break;
		case 3:
			printf("Position: ");
			scanf("%d", &position);
			if (removeDLElement(pList, position))
			{
				printf("Remove: Success\n\n");
				displayDoublyList(pList);
			}
			else 
				printf("Remove: Fail\n\n");
			break;
		case 4:
			printf("Position: ");
			scanf("%d", &position);
			node = getDLElement(pList, position);
			if (node)
				printf("[%d]: %d\n\n", position, node->data);
			else
				printf("Fail\n\n");
			break;
		case 5:
			printf("Length: %d\n\n", getDoublyListLength(pList));
			break;
		case 6:
			displayDoublyList(pList);
			break;
		case 7:
			if (!pList)
				printf("Clear: Fail\n\n");
			else
			{
				clearDoublyList(pList);
				printf("Clear: Success\n\n");
			}
			break;
		case 8:
			if (!pList)
				printf("Delete: Fail\n\n");
			else
			{
				deleteDoublyList(pList);
				pList = NULL;
				printf("Delete: Success\n\n");
			}
			break;
		case 9:
			loop = 0;
			break;
		default:
			printf("Please Enter a Valid Option\n");
		}
	}
}