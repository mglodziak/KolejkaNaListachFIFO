#include "kolejki.h"
#include <stdlib.h>
#include <stdio.h>

Kolejka* Create()
{
	Kolejka* nowy =	(Kolejka*)calloc( 1, sizeof( Kolejka ) );
	if ( !nowy )
	{
		printf ( "Error: nie udalo sie utowrzyc kolejki\n" );
		return NULL ;
	}
	return nowy;
}
//----------
int isEmpty( Kolejka* q )
{
	return ( !q->pHead );
}
void EnQueue( Kolejka* q, int x )
{
	QItem* nowy_elem = ( QItem* )calloc( 1, sizeof( QItem ) );
	if ( !nowy_elem )
	{
		printf ( "Error: nie udalo sie zaalokowac pamieci do nowego elementu\n" );
		return;
	}

	nowy_elem->nKey = x;

	if ( isEmpty( q ) )
		q->pHead = nowy_elem;
	else
		q->pTail->pNext = nowy_elem;

	q->pTail = nowy_elem;
}
//----------
int DeQueue( Kolejka* q )
{
	if ( isEmpty( q ) )
	{
		printf ( "Error: kolejka jest juz pusta" );
		return 0;
	}
	QItem* top = q->pHead;
	int wynik = top->nKey; // wynik juz mamy 
	q->pHead = top->pNext;
	free ( top );

	if ( isEmpty( q ) )
		q->pTail = NULL;
	
	return wynik;
}
//----------
void Clear( Kolejka* q )
{
	while ( !isEmpty ( q ) )
		DeQueue ( q );

	q->pHead = NULL;
	q->pTail = NULL;
}
//----------
void Del( Kolejka** q )
{
	if ( !q )
	{
		printf ( "Error: brak kolejki" );
		return;
	}

	Clear ( *q );
	free ( *q );
	*q = NULL;
}

