#include "polynomiallist.h"

int	main(void)
{
	PolyList	*pList;
	PolyList	*pList1;
	PolyList	*pList2;
	PolyListNode	node;
	PolyListNode	*get;
	int				loop;
	int				loop2;
	int				opt;
	int				ret;
	int				position;

	pList = NULL;
	pList1 = NULL;
	pList2 = NULL;
	loop = 1;
	while (loop)
	{
		printf("[1] Create [2] Add [3] Remove [4] Make poly [5] Calculate [6] Get Element [7] Length [8] Display [9] Clear [10] Delete [11] Exit ");
		scanf("%d", &opt);
		switch (opt)
		{
			case 1:
				printf("A = 1, B = 2: ");
				scanf("%d", &opt);
				if (opt == 1)
				{
					pList1 = createPolyList("A");
					if (!pList1)
					{
						printf("Create poly: fail\n\n");
						break;
					}
				}
				else if (opt == 2)
				{
					pList2 = createPolyList("B");
					if (!pList2)
					{
						printf("Create poly: fail\n\n");
						break;
					}
				}
				printf("Create poly: Success\n\n");
				break;
			case 2:
				printf("A = 1 , B = 2: ");
				scanf("%d", &opt);
				if (opt == 1)
                {
					loop2 = 1;
					while (loop2)
					{
						printf("coef: ");
						scanf("%d", &node.coef);
						printf("degree: ");
						scanf("%d", &node.degree);
						if (!addPLElement(pList1, node))
						{
							printf("Add: Fail\n\n");
							break;
						}
						printf("Add: Success\n\n");
						displayPolyList(pList1);
						printf("continue:1, stop: 0: ");
						scanf("%d", &loop2);
					}
				}
				else if (opt == 2)
                {
					loop2 = 1;
					while (loop2)
					{
						printf("coef: ");
						scanf("%d", &node.coef);
						printf("degree: ");
						scanf("%d", &node.degree);
						if (!addPLElement(pList1, node))
						{
							printf("Add: Fail\n\n");
							break;
						}
						printf("Add: Success\n\n");
						displayPolyList(pList1);
						printf("continue:1, stop: 0: ");
						scanf("%d", &loop2);
					}
				}
                break;
			case 3:
				printf("A = 1 , B = 2: ");
				scanf("%d", &opt);
				printf("Degree: ");
				scanf("%d", &position);
				if (opt == 1)
                {
					if (removePLElement(pList1, position))
						printf("Remove: Success\n\n");
					else
						printf("Remove: Fail\n\n");
					displayPolyList(pList1);
				}
				else if (opt == 2)
                {
					if (removePLElement(pList2, position))
						printf("Remove: Success\n\n");
					else
						printf("Remove: Fail\n\n");
					displayPolyList(pList2);
				}
                break;
            case 4:
                pList = createPolyList("Poly");
				if (!pList)
				{
					printf("Create poly: fail\n\n");
					break;
				}
				if (addPoly(pList, pList1, pList2))
					printf("Add Poly Success\n\n");
				else
					printf("Add Poly Fail\n\n");
				displayPolyList(pList);
                break;
			case 5:
				printf("x: ");
				scanf("%d", &ret);
				printf("A = 1, B = 2, Poly = 3: ");
				scanf("%d", &opt);
				if (opt == 1)
				{
					if (!pList1)
					{
						printf("No polynomial. Create first.\n\n");
						break;
					}
					ret = calculator(pList1, ret);
					printf("ret: %d\n\n", ret);
				}
				else if (opt == 2)
				{
					if (!pList2)
					{
						printf("No polynomial. Create first.\n\n");
						break;
					}
					ret = calculator(pList2, ret);
					printf("ret: %d\n\n", ret);
				}
				else
				{
					if (!pList)
					{
						printf("No polynomial. Create first.\n\n");
						break;
					}
					ret = calculator(pList, ret);
					printf("ret: %d\n\n", ret);
				}
                break;
            case 6:
				printf("A = 1, B = 2, Poly = 3: ");
				scanf("%d", &opt);
				printf("Position: ");
				scanf("%d", &position);
                if (opt == 1)
				{
					get = getPLElement(pList1, position);
					printf("%s: [%d] - %dx%d\n\n", pList1->name, position, get->coef, get->degree);
				}
				else if (opt == 2)
				{
					get = getPLElement(pList2, position);
					printf("%s: [%d] - %dx%d\n\n", pList2->name, position, get->coef, get->degree);
				}
				else
				{
					get = getPLElement(pList, position);
					printf("%s: [%d] - %dx%d\n\n", pList->name, position, get->coef, get->degree);
				}
                break;
            case 7:
				printf("A = 1, B = 2, Poly = 3: ");
				scanf("%d", &opt);
                if (opt == 1)
					printf("%s: %d\n\n", pList1->name, getPolyListLength(pList1));
				else if (opt == 2)
					printf("%s: %d\n\n", pList1->name, getPolyListLength(pList2));
				else
					printf("%s: %d\n\n", pList1->name, getPolyListLength(pList));
                break;
            case 8:
				printf("A = 1, B = 2, Poly = 3: ");
				scanf("%d", &opt);
				if (opt == 1)
					displayPolyList(pList1);
				else if (opt == 2)
                	displayPolyList(pList2);
				else
                	displayPolyList(pList);
                break;
            case 9:
				printf("A = 1, B = 2, Poly = 3: ");
				scanf("%d", &opt);
                if (opt == 1)
                	clearPolyList(pList1);
				else if (opt == 2)
                	clearPolyList(pList2);
				else
                	clearPolyList(pList);
				printf("Clear: Success\n\n");
                break;
            case 10:
				printf("A = 1, B = 2, Poly = 3: ");
				scanf("%d", &opt);
                if (opt == 1)
				{
					if (!pList1)
					{
						printf("No polynomial\n\n");
						break;
					}
                	deletePolyList(pList1);
				}
				else if (opt == 2)
				{
					if (!pList2)
					{
						printf("No polynomial\n\n");
						break;
					}
                	deletePolyList(pList2);
				}
				else
				{
					if (!pList)
					{
						printf("No polynomial\n\n");
						break;
					}
                	deletePolyList(pList);
				}
				printf("Clear: Success\n\n");
                break;
            case 11:
                loop = 0;
                break;
            default:
                printf("Please Enter a Valid Option\n\n");
        }
    }
}
