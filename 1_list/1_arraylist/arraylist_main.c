#include "arraylist.h"

int main(void)
{
	ArrayList       *pList;
	ArrayListNode   *element;
	ArrayListNode   node;
	int             loop;
	int             opt;
	int             position;

	pList = NULL;
	loop = 1;
	while (loop)
	{
		printf("[1] Create [2] Add [3] Remove [4] Get element [5] Length [6] Full check [7] Display [8] Clear [9] Delete [10] Exit ");
		scanf("%d", &opt);
		switch (opt)
		{
			case 1:
				printf("Size of Array: ");
				scanf("%d", &opt);
				pList = createArrayList(opt);
				if (pList)
					printf("Create Array: Success\n\n");
				else
					printf("Create Array: Fail\n");
				break;
			case 2:
				printf("Position: ");
				scanf("%d", &position);
				printf("Data: ");
				scanf("%d", &node.data);
				if (addALElement(pList, position, node))
				{
					printf("ADD: Success\n\n");
					displayArrayList(pList);
				}
				else 
					printf("ADD: Fail\n\n");
				break;
			case 3:
				printf("Position: ");
				scanf("%d", &position);
				if (removeALElement(pList, position))
				{
					printf("Remove: Success\n\n");
					displayArrayList(pList);
				}
				else
					printf("Remove: Fail\n\n");
				break;
			case 4:
				printf("Position: ");
				scanf("%d", &position);
				element = getALElement(pList, position);
				if (element)
					printf("[%d]: %d\n\n", position, element->data);
				else
					printf("Fail\n\n");
				break;
			case 5:
				printf("Length: %d\n\n", getArrayListLength(pList));
				break;
			case 6:
				if (isArrayListFull(pList))
					printf("Yes\n\n");
				else
					printf("No\n\n");
				break;
			case 7:
				displayArrayList(pList);
				break;
			case 8:
				if (!pList)
					printf("Error: No arraylist\n\n");
				clearArrayList(pList);
				printf("Clear: Success\n\n");
				break;
			case 9:
				if (!pList)
					printf("Error: No arraylist\n\n");
				else
				{
					deleteArrayList(pList);
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