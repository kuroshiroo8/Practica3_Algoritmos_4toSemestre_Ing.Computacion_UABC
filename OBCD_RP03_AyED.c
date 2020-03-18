// Carlos Daniel Orozco Bravo 351285 441 L3
//**************************************************LIBRERIAS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//**************************************************ESTRUCTURAS
typedef struct _tdato{
								int dato ;
								struct _tdato *sig ;
							} stdato ;

typedef stdato *Tdato ;

//**************************************************PROTOTIPO DE FUNCIONES
int MENU() ;
int MENUpila() ;
int MENUcola() ;
void PUSHpila( Tdato *pila , Tdato *nuevo );
Tdato POPpila( Tdato *pila );
void PUSHcola( Tdato *cabeza , Tdato *cola , Tdato *nuevo );
Tdato POPcola( Tdato *cola , Tdato *cabeza );
int leenum( int InfLim , int SupLim , char *msg , char *msgError ) ;
void servicio( Tdato temp ) ;
Tdato Gendatos( void ) ;

//**************************************************MAIN
int main()
{
	MENU();
	return 0;
}

//**************************************************MENU
int MENU()
{
	int opcion=0 ;
	do{
			system( "cls" ) ;
			printf( "M   E   N   U\n\n" ) ;
			printf( "a).\n" ) ;
			printf( "\t1- PILA.\n" ) ;
			printf( "\nb).\n" ) ;
			printf( "\t2- COLA.\n" ) ;
			printf( "\n\n3- Salir.\n" ) ;
			printf("\n\nESCOGE UNA OPCION.\n\n");
			opcion=leenum( 1 , 3 , "Dame un numero.\t" , "Error.." );
			switch( opcion )
				{
					case 1 :	system( "cls" );	MENUpila();	break;
					case 2:	system( "cls" );	MENUcola();	break;
				}
    	}while( opcion !=3 );
}

//**************************************************MENU PILA
int MENUpila()
{
	int opcion=0 ;
	Tdato pila=NULL , nuevo=NULL , temp=NULL ;
	do{
			system( "cls" ) ;
			printf( "M   E   N   U   -   P   I   L   A\n\n" ) ;
			printf( "a).\n" ) ;
			printf( "\t1- PUSHpila.\n" ) ;
			printf( "\t2- POPpila.\n" ) ;
			printf( "\n\n3- Salir.\n" ) ;
			printf("\n\nESCOGE UNA OPCION.\t");
			opcion=leenum( 1 , 3 , "Dame un numero.\t" , "Error.." );
			switch( opcion )
				{
					case 1 :
									system( "cls" ) ;
									nuevo=Gendatos() ;
              					PUSHpila( &pila , &nuevo ) ;
              					system( "pause" ) ;
									break;
					case 2:
									system( "cls" ) ;
               				temp=POPpila( &pila ) ;
              					if(temp)
              						{
            							servicio( temp ) ;
            							free( temp ) ;
              						}
              					else
              						{
                  					printf( "pila vacia...\n" ) ;
                  					system( "pause" ) ;
              						}
									break;
				}
    	}while( opcion !=3 );
}

//**************************************************MENU COLA
int MENUcola()
{
	int opcion=0 ;
  	Tdato nuevo=NULL , temp=NULL , cola=NULL , cabeza=NULL ;
	do{
			system( "cls" ) ;
			printf( "M   E   N   U   -   C   O   L   A\n\n" ) ;
			printf( "b).\n" ) ;
			printf( "\t1- PUSHcola.\n" ) ;
			printf( "\t2- POPcola.\n" ) ;
			printf( "\n\n3- Salir.\n" ) ;
			printf("\n\nESCOGE UNA OPCION.\n\n");
			opcion=leenum( 1 , 3 , "Dame un numero.\t" , "Error.." );
			switch( opcion )
				{
					case 1 :
									system( "cls" ) ;
									nuevo=Gendatos() ;
               				PUSHcola( &cola , &cabeza , &nuevo ) ;
               				system( "pause" ) ;
									break ;
					case 2:
									system( "cls" ) ;
									temp=POPcola( &cola , &cabeza ) ;
             					if( temp )
             						{
                						servicio( temp ) ;
                						free( temp ) ;
             						}
             						else
             							{
                 							printf( "cola vacia...\n" ) ;
                 							system("pause");
             							}
									break;
				}
    	}while( opcion !=3 );
}

//**************************************************PUSHpila
void PUSHpila( Tdato *pila , Tdato *nuevo )
{
	( *nuevo )->sig=*pila ;
	*pila=*nuevo;
	*nuevo=NULL;
}

//**************************************************POPpila
Tdato POPpila( Tdato *pila )
{
	Tdato temp=NULL ;
	if( *pila )
		{
			temp=*pila ;
			*pila=( *pila )->sig ;
			temp->sig=NULL ;
		}
	return temp ;
}

//**************************************************PUSHcola
void PUSHcola( Tdato *cola , Tdato *cabeza , Tdato *nuevo )
{
	( *nuevo )->sig=*cola ;
	*cola=*nuevo ;
	*cabeza=*cola ;
	*nuevo=NULL ;
}

//**************************************************POPcola
Tdato POPcola( Tdato *cola , Tdato *cabeza )
{
	Tdato temp=NULL ;
	if( *cabeza )
		{
			temp=*cabeza ;
			*cabeza=temp->sig ;
			temp->sig=NULL ;
			if( !*cabeza )
				{
					*cola=*cabeza ;
				}
		}
		return temp ;
}

//**************************************************VALIDAR NUMERO
int leenum( int InfLim , int SupLim , char *msg , char *msgError )
{
	char strnum[30] ;
	int num ;
	do
		{
			puts( msg ) ;
			fflush( stdin ) ;
			gets( strnum ) ;
			num=atoi( strnum ) ;
			if( num<InfLim || num>SupLim )
				{
					puts( msgError ) ;
					system( "pause" ) ;
				}
		}while( num<InfLim || num>SupLim ) ;
	return num ;
}

//**************************************************SERVICIO
void servicio( Tdato temp )
{
	system( "cls" );
	printf( "%d\n", temp->dato );
	system( "pause" );
}

//**************************************************GENDATO
Tdato Gendatos( void )
{
    Tdato temp ;
	temp = ( Tdato )malloc( sizeof( stdato ) ) ;
	temp->dato = rand()%100 ;
	return temp;
}
