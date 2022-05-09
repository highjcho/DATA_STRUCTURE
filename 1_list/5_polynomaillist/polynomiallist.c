#include "polynomiallist.h"

PolyList *createPolyList(char *name)
{
	PolyList *res;

	res = calloc(1, sizeof(PolyList));
	if (!res)
		return (NULL);
	res->name = name;
	return (res);
}

int addPLElement(PolyList *pList, PolyListNode element)
{
	PolyListNode *newPoly;
	PolyListNode *prev;

	if(!pList || (element.coef == 0 && element.degree != 0))
		return (FALSE);
	prev = &(pList->headerNode); //prev 세팅
	while (prev->pLink != NULL && (prev->pLink->degree >= element.degree)) // 마지막 노드 전까지 && 추가하려는 노드의 차수가 작거나 같을 때까지
		prev = prev->pLink;
	if (prev->degree == element.degree) // 리스트에 있는 노드의 차수와 같으면 계수 더하기
		prev->coef += element.coef;
	else //prev의 차수가 더 클 경우 리스트에 존재하지 않는 차수이기 때문에 새로운 노드 추가
	{
		newPoly = calloc(1, sizeof(PolyListNode)); // 새 노드 생성
		if (!newPoly)
			return (FALSE);
		*newPoly = element; // 역참조로 값복사
		newPoly->pLink = prev->pLink; // pLink 연결
		prev->pLink = newPoly; // pLink연결
		pList->currentElementCount++; // 현재 원소 개수 갱신
	}
	return (TRUE);
}

int addPoly(PolyList *pList, PolyList *pList1, PolyList *pList2)
{
	PolyListNode *poly1;
	PolyListNode *poly2;

	if(!pList && !pList1 && !pList2)
		return (FALSE);
	poly1 = pList1->headerNode.pLink; // 각 다항식의 첫 노드
	poly2 = pList2->headerNode.pLink; // 각 다항식의 첫 노드
	while (poly1 != NULL && poly2 != NULL) // 둘 중에 하나라도 끝나기 전까지
	{
		if (poly1->degree == poly2->degree) // 각 다항식에 같은 차수의 노드가 존재할 경우
		{
			poly1->coef += poly2->coef; // poly1에 poly2의 계수를 합산
			if (!addPLElement(pList, *poly1)) // 최종 다항식에 합산한 폴리노드 추가
				return (FALSE);
			poly1 = poly1->pLink; // poly1 다음 노드로 이동
			poly2 = poly2->pLink; // poly2 다음 노드로 이동
		}
		else if (poly1->degree > poly2->degree) // poly1의 차수가 poly2 차수보다 높을 경우
		{
			if (!addPLElement(pList, *poly1)) // 최종 다항식에 poly1 노드 추가
				return (FALSE);
			poly1 = poly1->pLink; // poly1 다음 노드로 이동
		}
		else // poly2의 차수가 poly1의 차수보다 높을 경우
		{
			if (!addPLElement(pList, *poly2)) // 최종 다항식에 poly2 노드 추가
				return (FALSE);
			poly2 = poly2->pLink; // poly2 다음 노드로 이동
		}
	}
	while (poly1 != NULL) // poly1이 남아 있다면 poly1 끝날 때까지
	{
		if (!addPLElement(pList, *poly1)) // 최종 폴리리스트에 poly1 노드 추가
			return (FALSE);
		poly1 = poly1->pLink; // poly1 다음 노드로 이동
	}
	while (poly2 != NULL)
	{
		if (!addPLElement(pList, *poly2)) // 최종 폴리리스트에 poly2 노드 추가
			return (FALSE);
		poly2 = poly2->pLink; // poly2 다음 노드로 이동
	}
	return (TRUE);
}

int removePLElement(PolyList* pList, int degree)
{
    PolyListNode *remove;
    PolyListNode *prev;

	if(!pList)
		return (FALSE);
	prev = &(pList->headerNode); //prev 세팅
	while (prev->pLink != NULL && (prev->pLink->degree > degree)) // 마지막 노드 전까지 && 추가하려는 노드의 차수가 작을 때까지
		prev = prev->pLink;
    remove = prev->pLink; // remove 저장
	if (remove->degree != degree) // 제거하려는 차수가 리스트에 존재하지 않을 경우
		return (FALSE);
    prev->pLink = remove->pLink; // prev의 pLink 연결
    pList->currentElementCount--; // 현재 원소 개수 갱신
    free(remove); // remove free
    return (TRUE);
}

PolyListNode *getPLElement(PolyList *pList, int position)
{
    PolyListNode *res;

    if (!pList || position < 0 || position > pList->currentElementCount) // 에러처리
        return (FALSE);
    res = &(pList->headerNode);
    for (int i = 0; i <= position; i++)
        res = res->pLink;
    return (res);
}

int	recursive_power(int	x, int	power)
{
	if (power == 0) // 종료 조건
		return (1);
	return (x * recursive_power(x, power - 1)); // 차수만큼 반복
}

int calculator(PolyList *pList, int x)
{
	PolyListNode *node;
	int ret;

	node = pList->headerNode.pLink;
	ret = 0;
	while (node)
	{
		ret += node->coef * recursive_power(x, node->degree); // 계수 * 차수
		node = node->pLink; // 다음 노드로 이동
	}
	return (ret);
}

void displayPolyList(PolyList *pList)
{
    PolyListNode *cur;
	if ((pList->headerNode.pLink == NULL) || pList->currentElementCount == 0)
	{
		printf("No Array or No Node\n");
		return ;
	}
	cur = pList->headerNode.pLink;
    printf("Current Element Count : %d\n", pList->currentElementCount);
    printf("%s: ", pList->name);
	while (cur)
	{
        if (cur->coef != 0 && cur->degree != 0) // 계수와 차수가 모두 0이 아닌 경우
		    printf("%dx%d", cur->coef, cur->degree);
        else if (cur->coef != 0 && cur->degree == 0) // 차수가 0인 경우
            printf("%d", cur->coef);
        else if (cur->coef == 0 && cur->degree == 0) // 둘 다 0인 경우
            printf("0");
        if (cur->pLink != NULL && (cur->coef != 0 && cur->degree != 0)) // 다음 노드가 존재하고 현재 노드의 계수와 차수가 모두 0이 아닌 경우
            printf(" + ");
		cur = cur->pLink; // 다음 노드 탐색
	}
    printf("\n\n");
}

void clearPolyList(PolyList* pList)
{
    PolyListNode* node;
    PolyListNode* tmp;

    pList->currentElementCount = 0;
    node = pList->headerNode.pLink;
    while (node)
    {
        tmp = node->pLink; // 다음 노드 정보 저장
        free(node);
        node = tmp;
    }
}

int getPolyListLength(PolyList *pList)
{
    return (pList->currentElementCount);
}

void deletePolyList(PolyList *pList)
{
    clearPolyList(pList);
    free(pList);
}
