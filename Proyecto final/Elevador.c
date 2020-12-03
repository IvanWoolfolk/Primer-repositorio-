#include "Elevador.h"
#include "delay.c"


void main()
{
	SM_States enCurrentState = enLobby;
	SM_States enNextState = enLobby;

	uint8 u8People_In = 0;
	uint8 u8People_Entering = 0;
	uint8 u8Scan_Floor1 = END_REQUEST;
	uint8 u8Scan_Floor2 = END_REQUEST;
	uint8 u8Scan_Floor3 = END_REQUEST;
	uint8 u8Scan_Floor4 = END_REQUEST;
	uint8 u8Scan_Floor5 = END_REQUEST;
	uint8 u8Scan_Floor6 = END_REQUEST;
	uint8 u8Scan_Floor7 = END_REQUEST;
	uint8 u8Scan_Floor8 = END_REQUEST;
	uint8 u8Scan_Floor9 = END_REQUEST;
	uint8 u8Scan_Floor10 = END_REQUEST;
	uint8 u8Scan_Floor11 = END_REQUEST;
	uint8 u8Current_Floor = 0;
	uint8 u8NextFloor = 0;
	uint8 u8People_to_go1=0;
	uint8 u8People_to_going=0;
	uint8 u8NextRequest=1;
	uint8 u8RequestState=1;
	while(1)
	{

		switch	(	enCurrentState	)
		{
			case enLobby:
			{
				printf("\n\nRequest Numero %d\n\n",u8NextRequest);
				printf("\nBuenas tardes, El elevador se encuentra en el piso %d ¿Cuantas personas quieren entrar?\n",enCurrentState);
				scanf("%d",&u8People_Entering);
				printf("¿A que piso desea ir? \n0)Lobby \n1)Piso 1 \n2)Piso 2 \n3)Piso 3 \n4)Piso 4 \n5)Piso 5 \n6)Piso 6 \n7)Piso 7 \n8)Piso 8 \n9)Piso 9 \n10)Piso 10\n");
				scanf("%d",&u8Scan_Floor1);		

				while (u8NextRequest!=11)
				{	
					printf("\n\nEl elevador va hacia el piso %d, \n¿Desea ir a otro piso? \n1)Si \n2)No \n\n",u8Scan_Floor1);
					scanf("%d",&u8RequestState);

					if(u8RequestState==1)
					{
						if(u8NextRequest==1)
						{
							printf("¿A que piso desea ir? \n0)Lobby \n1)Piso 1 \n2)Piso 2 \n3)Piso 3 \n4)Piso 4 \n5)Piso 5 \n6)Piso 6 \n7)Piso 7 \n8)Piso 8 \n9)Piso 9 \n10)Piso 10\n");
							scanf("%d",&u8Scan_Floor2);

							if(u8Scan_Floor2!=u8Scan_Floor1 && u8Scan_Floor2!=u8Scan_Floor3 && u8Scan_Floor2!=u8Scan_Floor4 && u8Scan_Floor2!=u8Scan_Floor5 && u8Scan_Floor2!=u8Scan_Floor6 && u8Scan_Floor2!=u8Scan_Floor7 && u8Scan_Floor2!=u8Scan_Floor8 && u8Scan_Floor2!=u8Scan_Floor9 && u8Scan_Floor2!=u8Scan_Floor10 && u8Scan_Floor2!=u8Scan_Floor11)
							{
								printf("Eligio el piso %d",u8Scan_Floor2);
								u8NextRequest+=1;
							}
							else
							{
								printf("Eligio un piso ya seleccionado");
								u8Scan_Floor2=END_REQUEST;
							}
						}
						else if(u8NextRequest==2)
						{
							printf("¿A que piso desea ir? \n0)Lobby \n1)Piso 1 \n2)Piso 2 \n3)Piso 3 \n4)Piso 4 \n5)Piso 5 \n6)Piso 6 \n7)Piso 7 \n8)Piso 8 \n9)Piso 9 \n10)Piso 10\n");
							scanf("%d",&u8Scan_Floor3);

							if(u8Scan_Floor3!=u8Scan_Floor1 && u8Scan_Floor3!=u8Scan_Floor2 && u8Scan_Floor3!=u8Scan_Floor4 && u8Scan_Floor3!=u8Scan_Floor5 && u8Scan_Floor3!=u8Scan_Floor6 && u8Scan_Floor3!=u8Scan_Floor7 && u8Scan_Floor3!=u8Scan_Floor8 && u8Scan_Floor3!=u8Scan_Floor9 && u8Scan_Floor3!=u8Scan_Floor10 && u8Scan_Floor3!=u8Scan_Floor11)
							{
								printf("Eligio el piso %d",u8Scan_Floor3);
								u8NextRequest+=1;
							}
							else
							{
								printf("Eligio un piso ya seleccionado");
								u8Scan_Floor3=END_REQUEST;
							}
						}
						else if(u8NextRequest==3)
						{
							printf("¿A que piso desea ir? \n0)Lobby \n1)Piso 1 \n2)Piso 2 \n3)Piso 3 \n4)Piso 4 \n5)Piso 5 \n6)Piso 6 \n7)Piso 7 \n8)Piso 8 \n9)Piso 9 \n10)Piso 10\n");
							scanf("%d",&u8Scan_Floor4);

							if(u8Scan_Floor4!=u8Scan_Floor1 && u8Scan_Floor4!=u8Scan_Floor3 && u8Scan_Floor4!=u8Scan_Floor2 && u8Scan_Floor4!=u8Scan_Floor5 && u8Scan_Floor4!=u8Scan_Floor6 && u8Scan_Floor4!=u8Scan_Floor7 && u8Scan_Floor4!=u8Scan_Floor8 && u8Scan_Floor4!=u8Scan_Floor9 && u8Scan_Floor4!=u8Scan_Floor10 && u8Scan_Floor4!=u8Scan_Floor11)
							{
								printf("Eligio el piso %d",u8Scan_Floor4);
								u8NextRequest+=1;
							}
							else
							{
								printf("Eligio un piso ya seleccionado");
								u8Scan_Floor4=END_REQUEST;
							}
						}
						else if(u8NextRequest==4)
						{
							printf("¿A que piso desea ir? \n0)Lobby \n1)Piso 1 \n2)Piso 2 \n3)Piso 3 \n4)Piso 4 \n5)Piso 5 \n6)Piso 6 \n7)Piso 7 \n8)Piso 8 \n9)Piso 9 \n10)Piso 10\n");
							scanf("%d",&u8Scan_Floor5);

							if(u8Scan_Floor5!=u8Scan_Floor1 && u8Scan_Floor5!=u8Scan_Floor3 && u8Scan_Floor5!=u8Scan_Floor2 && u8Scan_Floor5!=u8Scan_Floor4 && u8Scan_Floor5!=u8Scan_Floor6 && u8Scan_Floor5!=u8Scan_Floor7 && u8Scan_Floor5!=u8Scan_Floor8 && u8Scan_Floor5!=u8Scan_Floor9 && u8Scan_Floor5!=u8Scan_Floor10 && u8Scan_Floor5!=u8Scan_Floor11)
							{
								printf("Eligio el piso %d",u8Scan_Floor5);
								u8NextRequest+=1;
							}
							else
							{
								printf("Eligio un piso ya seleccionado");
								u8Scan_Floor5=END_REQUEST;
							}
						}
						else if(u8NextRequest==5)
						{
							printf("¿A que piso desea ir? \n0)Lobby \n1)Piso 1 \n2)Piso 2 \n3)Piso 3 \n4)Piso 4 \n5)Piso 5 \n6)Piso 6 \n7)Piso 7 \n8)Piso 8 \n9)Piso 9 \n10)Piso 10\n");
							scanf("%d",&u8Scan_Floor6);

							if(u8Scan_Floor6!=u8Scan_Floor1 && u8Scan_Floor6!=u8Scan_Floor3 && u8Scan_Floor6!=u8Scan_Floor4 && u8Scan_Floor6!=u8Scan_Floor5 && u8Scan_Floor6!=u8Scan_Floor2 && u8Scan_Floor6!=u8Scan_Floor7 && u8Scan_Floor6!=u8Scan_Floor8 && u8Scan_Floor6!=u8Scan_Floor9 && u8Scan_Floor6!=u8Scan_Floor10 && u8Scan_Floor6!=u8Scan_Floor11)
							{
								printf("Eligio el piso %d",u8Scan_Floor6);
								u8NextRequest+=1;
							}
							else
							{
								printf("Eligio un piso ya seleccionado");
								u8Scan_Floor6=END_REQUEST;
							}
						}
						else if(u8NextRequest==6)
						{
							printf("¿A que piso desea ir? \n0)Lobby \n1)Piso 1 \n2)Piso 2 \n3)Piso 3 \n4)Piso 4 \n5)Piso 5 \n6)Piso 6 \n7)Piso 7 \n8)Piso 8 \n9)Piso 9 \n10)Piso 10\n");
							scanf("%d",&u8Scan_Floor7);

							if(u8Scan_Floor7!=u8Scan_Floor1 && u8Scan_Floor7!=u8Scan_Floor3 && u8Scan_Floor7!=u8Scan_Floor4 && u8Scan_Floor7!=u8Scan_Floor5 && u8Scan_Floor7!=u8Scan_Floor6 && u8Scan_Floor7!=u8Scan_Floor2 && u8Scan_Floor7!=u8Scan_Floor8 && u8Scan_Floor7!=u8Scan_Floor9 && u8Scan_Floor7!=u8Scan_Floor10 && u8Scan_Floor7!=u8Scan_Floor11)
							{
								printf("Eligio el piso %d",u8Scan_Floor7);
								u8NextRequest+=1;
							}
							else
							{
								printf("Eligio un piso ya seleccionado");
								u8Scan_Floor7=END_REQUEST;
							}
						}
						else if(u8NextRequest==7)
						{
							printf("¿A que piso desea ir? \n0)Lobby \n1)Piso 1 \n2)Piso 2 \n3)Piso 3 \n4)Piso 4 \n5)Piso 5 \n6)Piso 6 \n7)Piso 7 \n8)Piso 8 \n9)Piso 9 \n10)Piso 10\n");
							scanf("%d",&u8Scan_Floor8);

							if(u8Scan_Floor8!=u8Scan_Floor1 && u8Scan_Floor8!=u8Scan_Floor3 && u8Scan_Floor8!=u8Scan_Floor4 && u8Scan_Floor8!=u8Scan_Floor5 && u8Scan_Floor8!=u8Scan_Floor6 && u8Scan_Floor8!=u8Scan_Floor7 && u8Scan_Floor8!=u8Scan_Floor2 && u8Scan_Floor8!=u8Scan_Floor9 && u8Scan_Floor8!=u8Scan_Floor10 && u8Scan_Floor8!=u8Scan_Floor11)
							{
								printf("Eligio el piso %d",u8Scan_Floor8);
								u8NextRequest+=1;
							}
							else
							{
								printf("Eligio un piso ya seleccionado");
								u8Scan_Floor2=END_REQUEST;
							}
						}
						else if(u8NextRequest==8)
						{
							printf("¿A que piso desea ir? \n0)Lobby \n1)Piso 1 \n2)Piso 2 \n3)Piso 3 \n4)Piso 4 \n5)Piso 5 \n6)Piso 6 \n7)Piso 7 \n8)Piso 8 \n9)Piso 9 \n10)Piso 10\n");
							scanf("%d",&u8Scan_Floor9);

							if(u8Scan_Floor9!=u8Scan_Floor1 && u8Scan_Floor9!=u8Scan_Floor3 && u8Scan_Floor9!=u8Scan_Floor4 && u8Scan_Floor9!=u8Scan_Floor5 && u8Scan_Floor9!=u8Scan_Floor6 && u8Scan_Floor9!=u8Scan_Floor7 && u8Scan_Floor9!=u8Scan_Floor8 && u8Scan_Floor9!=u8Scan_Floor2 && u8Scan_Floor9!=u8Scan_Floor10 && u8Scan_Floor9!=u8Scan_Floor11)
							{
								printf("Eligio el piso %d",u8Scan_Floor9);
								u8NextRequest+=1;
							}
							else
							{
								printf("Eligio un piso ya seleccionado");
								u8Scan_Floor9=END_REQUEST;
							}
						}
						else if(u8NextRequest==9)
						{
							printf("¿A que piso desea ir? \n0)Lobby \n1)Piso 1 \n2)Piso 2 \n3)Piso 3 \n4)Piso 4 \n5)Piso 5 \n6)Piso 6 \n7)Piso 7 \n8)Piso 8 \n9)Piso 9 \n10)Piso 10\n");
							scanf("%d",&u8Scan_Floor10);

							if(u8Scan_Floor10!=u8Scan_Floor1 && u8Scan_Floor10!=u8Scan_Floor3 && u8Scan_Floor10!=u8Scan_Floor4 && u8Scan_Floor10!=u8Scan_Floor5 && u8Scan_Floor10!=u8Scan_Floor6 && u8Scan_Floor10!=u8Scan_Floor7 && u8Scan_Floor10!=u8Scan_Floor8 && u8Scan_Floor10!=u8Scan_Floor9 && u8Scan_Floor10!=u8Scan_Floor2 && u8Scan_Floor10!=u8Scan_Floor11)
							{
								printf("Eligio el piso %d",u8Scan_Floor10);
								u8NextRequest+=1;
							}
							else
							{
								printf("Eligio un piso ya seleccionado");
								u8Scan_Floor10=END_REQUEST;
							}
						}
						else if(u8NextRequest==10)
						{
							printf("¿A que piso desea ir? \n0)Lobby \n1)Piso 1 \n2)Piso 2 \n3)Piso 3 \n4)Piso 4 \n5)Piso 5 \n6)Piso 6 \n7)Piso 7 \n8)Piso 8 \n9)Piso 9 \n10)Piso 10\n");
							scanf("%d",&u8Scan_Floor11);

							if(u8Scan_Floor11!=u8Scan_Floor1 && u8Scan_Floor11!=u8Scan_Floor3 && u8Scan_Floor11!=u8Scan_Floor4 && u8Scan_Floor11!=u8Scan_Floor5 && u8Scan_Floor11!=u8Scan_Floor6 && u8Scan_Floor11!=u8Scan_Floor7 && u8Scan_Floor11!=u8Scan_Floor8 && u8Scan_Floor11!=u8Scan_Floor9 && u8Scan_Floor11!=u8Scan_Floor10 && u8Scan_Floor11!=u8Scan_Floor2)
							{
								printf("Eligio el piso %d",u8Scan_Floor11);
								u8NextRequest+=1;
							}
							else
							{
								printf("\n\nEligio un piso ya seleccionado\n\n");
								u8Scan_Floor11=END_REQUEST;
							}
						}
						else
						{
							printf("\n\nYa se seleccionaron todos los pisos\n\n");
						}
					}
					else 
					{
						u8NextRequest=11;
						printf("\n\nTodo listo\n\n");
					}

				}
				if(u8People_Entering+u8People_In<=MAX_PEOPLE)
				{
					u8People_In+=u8People_Entering;

					if(	u8Current_Floor - u8Scan_Floor1 < u8Current_Floor - u8Scan_Floor2)
					{
						u8Current_Floor = u8Scan_Floor1;
						u8NextFloor = u8Scan_Floor2;
						if(u8Current_Floor==0)
						{
							enCurrentState=enLobby;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							main2();
						}
						else if(u8Current_Floor==1)
						{
							enCurrentState=enPiso1;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							main2();
						}
						else if(u8Current_Floor==2)
						{
							enCurrentState=enPiso2;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							main2();
						}
						else if(u8Current_Floor==3)
						{
							enCurrentState=enPiso3;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							main2();
						}
						else if(u8Current_Floor==4)
						{
							enCurrentState=enPiso4;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							main2();
						}
						else if(u8Current_Floor==5)
						{
							enCurrentState=enPiso5;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							main2();
						}
						else if(u8Current_Floor==6)
						{
							enCurrentState=enPiso6;
							printf("main2Siguiente parada, piso %d\n\n", enCurrentState);
							main2();
						}
						else if(u8Current_Floor==7)
						{
							enCurrentState=enPiso7;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							main2();
						}
						else if(u8Current_Floor==8)
						{
							enCurrentState=enPiso8;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							main2();
						}
						else if(u8Current_Floor==9)
						{
							enCurrentState=enPiso9;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							main2();
						}
						else if(u8Current_Floor==10)
						{
							enCurrentState=enPiso10;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							main2();
						}
						else
						{
							//**Nothing to do**//
						}
					}
					else if(u8Current_Floor==u8Scan_Floor1)
					{
						printf("El primer request eligio el piso en el que se encuentra");
					}	
					else if(u8Current_Floor - u8Scan_Floor2 < u8Current_Floor - u8Scan_Floor1)
					{
						u8Current_Floor=u8Scan_Floor2;
						if(u8Current_Floor==0)
						{
							enCurrentState=enLobby;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							main2();
						}
						else if(u8Current_Floor==1)
						{
							enCurrentState=enPiso1;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							main2();
						}
						else if(u8Current_Floor==2)
						{
							enCurrentState=enPiso2;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							main2();
						}
						else if(u8Current_Floor==3)
						{
							enCurrentState=enPiso3;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							main2();
						}
						else if(u8Current_Floor==4)
						{
							enCurrentState=enPiso4;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							main2();
						}
						else if(u8Current_Floor==5)
						{
							enCurrentState=enPiso5;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							main2();
						}
						else if(u8Current_Floor==6)
						{
							enCurrentState=enPiso6;
							printf("main2Siguiente parada, piso %d\n\n", enCurrentState);
							main2();
						}
						else if(u8Current_Floor==7)
						{
							enCurrentState=enPiso7;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							main2();
						}
						else if(u8Current_Floor==8)
						{
							enCurrentState=enPiso8;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							main2();
						}
						else if(u8Current_Floor==9)
						{
							enCurrentState=enPiso9;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							main2();
						}
						else if(u8Current_Floor==10)
						{
							enCurrentState=enPiso10;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							main2();
						}
						else
						{
							//**Nothing to do**//
						}
					}
					else if(u8Current_Floor==u8Scan_Floor2)
					{
						printf("El segundo request eligio el piso en el que se encuentra");
					}
					else if(	u8Current_Floor - u8Scan_Floor2 < u8Current_Floor - u8Scan_Floor1)
					{
						u8Current_Floor = u8Scan_Floor2;
						u8NextFloor = u8Scan_Floor1;
						if(u8Current_Floor==0)
						{
							enCurrentState=enLobby;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							main2();
						}
						else if(u8Current_Floor==1)
						{
							enCurrentState=enPiso1;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							main2();
						}
						else if(u8Current_Floor==2)
						{
							enCurrentState=enPiso2;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							main2();
						}
						else if(u8Current_Floor==3)
						{
							enCurrentState=enPiso3;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							main2();
						}
						else if(u8Current_Floor==4)
						{
							enCurrentState=enPiso4;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							main2();
						}
						else if(u8Current_Floor==5)
						{
							enCurrentState=enPiso5;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							main2();
						}
						else if(u8Current_Floor==6)
						{
							enCurrentState=enPiso6;
							printf("main2Siguiente parada, piso %d\n\n", enCurrentState);
							main2();
						}
						else if(u8Current_Floor==7)
						{
							enCurrentState=enPiso7;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							main2();
						}
						else if(u8Current_Floor==8)
						{
							enCurrentState=enPiso8;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							main2();
						}
						else if(u8Current_Floor==9)
						{
							enCurrentState=enPiso9;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							main2();
						}
						else if(u8Current_Floor==10)
						{
							enCurrentState=enPiso10;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							main2();
						}
						else
						{
							//**Nothing to do**//
						}
					}
					else
					{
						//**Nothing to do**//
					}
				}
				else
				{
					printf("Maximo numero de personas son %d, espere a que se desocupe\n",MAX_PEOPLE);
				}
				break;
			}

			case enPiso1:
			{

				break;
			}

			case enPiso2:
			{

				break;
			}

			case enPiso3:
			{

				break;
			}

			case enPiso4:
			{

				break;
			}

			case enPiso5:
			{

				break;
			}

			case enPiso6:
			{

				break;
			}

			case enPiso7:
			{

				break;
			}

			case enPiso8:
			{

				break;
			}

			case enPiso9:
			{

				break;
			}

			case enPiso10:
			{

				break;
			}
		}
	}
}
