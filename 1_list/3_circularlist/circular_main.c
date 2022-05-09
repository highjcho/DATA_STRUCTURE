#include "circularlist.h"

int main(void)
{
	CircularList	*pList;
	ListNode		*node;
	ListNode		ListNode;
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
				pList = createCircularList();
				if (pList)
					printf("Create Circular List: Success\n\n");
				else
					printf("Create Circular List: Fail\n\n");
				break;
			case 2:
				printf("Position: ");
				scanf("%d", &position);
				printf("Data: ");
				scanf("%d", &ListNode.data);
				if (addCLElement(pList, position, ListNode))
				{
					printf("Add: Success\n\n");
					displayCircularList(pList);
				}
				else
					printf("Add: Fail\n\n");
				break;
			case 3:
				printf("Position: ");
				scanf("%d", &position);
				if (removeCLElement(pList, position))
				{
					printf("Remove: Success\n\n");
					displayCircularList(pList);
				}
				else
					printf("Remove: Fail\n\n");
				break;
			case 4:
				printf("Position: ");
				scanf("%d", &position);
				node = getCLElement(pList, position);
				if (node)
					printf("[%d]: %d\n\n", position, node->data);
				else
					printf("Fail\n\n");
				break;
			case 5:
				printf("Length: %d\n\n", getCircularListLength(pList));
				break;
			case 6:
				displayCircularList(pList);
				break;
			case 7:
				if (!pList)
					printf("Clear: Fail\n\n");
				else
				{
					clearCircularList(pList);
					printf("Clear: Success\n\n");
				}
				break;
			case 8:
				if (!pList)
					printf("Delete: Fail\n\n");
				else
				{
					deleteCircularList(pList);
					pList = NULL;
					printf("Delete: Success\n\n");
				}
				break;
			case 9:
				loop = 0;
				break;
			default:
				printf("Please Enter a Valid Option\n\n");
		}
	}
}
