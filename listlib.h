#include <stdio.h>

#define MAX 10000

typedef int ElementType;

typedef int Position;

typedef struct
{
	ElementType Elements[MAX];
	Position Last;
} List;

void MakeNull_List(List *L)
{
	L->Last = 0;	
}

int Empty_List(List L)
{
	return L.Last == 0; 
}

int Full_List(List L)
{
	return L.Last == MAX;
}

Position First(List L)
{
	return 1;
}

Position End_List(List L)
{
	return L.Last + 1;
}

void Insert_List(ElementType x, Position p, List *L)
{
	if(Full_List(*L))
		printf("List is full!");
	else if(x < First(*L) || x > End_List(*L))
		printf("The position %d is not valid!", x);
	else
	{
		for(Position i = End_List(*L) - 1 + 1; i > p - 1; i--)
			L->Elements[i] = L->Elements[i-1];
		L->Elements[p-1] = x;
		L->Last++;
	}
}

void Delete_List(Position p, List *L)
{
	if (p < First(*L) || p > End_List(*L))
		printf("The position %d is not valid!", p);
	else if (Empty_List(*L))
		printf("List is empty!");
	else 
	{
		for (Position i = p - 1; i < End_List(*L); i++)
			L->Elements[p-1] = L->Elements[p];
		L->Last--;
	}
}

ElementType Retrieve(Position p,List L)
{
	if (p < 1 || p>L.Last)
	{
		printf("The position %d is out of list", p);
		return -1;
	}
	return L.Elements[p-1];
}

Position Locate(ElementType x, List L)
{
	for(Position i = 0; i < End_List(L); i++)
		if(Retrieve(i, L) == x)
			return i;
}

Position Next(Position P, List L)
{
	if (P < 1 || P > L.Last)
	{
		printf("The position %d is out of list", P);
		return -1;
	}
	return P+1;
}

