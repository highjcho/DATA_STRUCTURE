#ifndef _CIRCULARLIST_
#define _CIRCULARLIST_

#include <stdio.h>
#include <stdlib.h>

typedef struct ListNodeType
{
	int data;
	struct ListNodeType* pLink;
} ListNode;

typedef struct CircularListType
{
	int currentElementCount;	
	ListNode *headPtr;		
} CircularList;

CircularList* createCircularList();
int addCLElement(CircularList* pList, int position, ListNode element);
int removeCLElement(CircularList* pList, int position);
ListNode* getCLElement(CircularList* pList, int position);
int getCircularListLength(CircularList* pList);
void displayCircularList(CircularList *pList);
void clearCircularList(CircularList* pList);
void deleteCircularList(CircularList* pList);
#endif

#ifndef _COMMON_LIST_DEF_
#define _COMMON_LIST_DEF_

#define TRUE		1
#define FALSE		0

#endif
