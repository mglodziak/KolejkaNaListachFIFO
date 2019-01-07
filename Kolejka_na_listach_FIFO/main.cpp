
#include "stdafx.h"
#include "kolejki.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>


void PrintList( Kolejka* head ); // drukuje kolejke na ekran

int main( )
{
	Kolejka * head = Create(); // tworze kolejke
	EnQueue( head, 1 ); // wstawiam liczby ktore chce
	EnQueue( head, 2 );
	EnQueue( head, 3 );
	EnQueue( head, 4 );
	PrintList( head ); //drukuje kolejke
	DeQueue ( head ); //usuwam z kolejki
	PrintList( head );
	Clear( head ); //czyszcze kolejke, ale nie usuwam
	PrintList( head );

	srand( ( unsigned )time( NULL ) ); //uzupelniam randomowo
	for ( int i = 0; i < 10; i++ )
		EnQueue ( head, rand ( ) % 100 + 1 );

	PrintList( head);  //drukuje liste
	DeQueue( head ); //ususwam elementy
	DeQueue( head );
	DeQueue( head );
	PrintList( head );
	Del( &head );

	return 0;
}

void PrintList( Kolejka* head )
{
	QItem* p = head->pHead;
	while ( p )
	{
		printf( "%d ", p->nKey );
		p = p->pNext;
	}
	printf ( "\n" );
}

