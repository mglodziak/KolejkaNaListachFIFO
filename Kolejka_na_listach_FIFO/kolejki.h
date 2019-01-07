
#ifndef  _KOLEJKA_FIFO
#define _KOLEJKA_FIFO

typedef struct tagQItem
{
	int nKey;
	tagQItem* pNext;
} QItem;

typedef struct
{
	QItem* pHead;
	QItem* pTail;
} Kolejka;

Kolejka* Create( );
int isEmpty( Kolejka* q );     						// Sprawdza, czy kolejka jest pusta
void EnQueue( Kolejka* q, int x );			    	// Wk³ada do kolejki
int DeQueue( Kolejka* q );					      	// Wyrzuæ z kolejki
void Clear( Kolejka* q );                         	// Czyœci wszystko, zostawia kolejkê jako strukturê
void Del( Kolejka** q );                          	// Usuniêcie ca³ej kolejki

#endif


