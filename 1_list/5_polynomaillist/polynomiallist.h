#ifndef _POLYNOMIALLIST_
#define _POLYNOMIALLIST_

#include <stdio.h>
#include <stdlib.h>

typedef struct PolyListNodeType
{
	int coef;
	int degree;
	struct PolyListNodeType* pLink;
} PolyListNode;

typedef struct PolyListType
{
	char *name;
	int currentElementCount;
	PolyListNode headerNode;
} PolyList;

PolyList* createPolyList(char *name);
int addPoly(PolyList *pList, PolyList *pList1, PolyList *pList2);
int addPLElement(PolyList* pList, PolyListNode element);
int removePLElement(PolyList* pList, int position);
int calculator(PolyList *pList, int x);
PolyListNode* getPLElement(PolyList* pList, int position);
void displayPolyList(PolyList *pList);
void clearPolyList(PolyList* pList);
int getPolyListLength(PolyList* pList);
void deletePolyList(PolyList* pList);
#endif

#ifndef _COMMON_LIST_DEF_
#define _COMMON_LIST_DEF_

#define TRUE		1
#define FALSE		0

#endif
