#include "Elevador.h"
#include "delay.c"


void main()
{
	SM_States enCurrentState = enLobby;
	SM_States enNextState = enLobby;

	uint8 u8People_In = 0;
	uint8 u8People_Entering = 0;	
	uint8 u8Current_Floor = 0;
	uint8 u8Scan_Floor1 = NO_REQUEST_1;
	uint8 u8Scan_Floor2 = NO_REQUEST_2;
	uint8 u8Scan_Floor3 = NO_REQUEST_3;
	uint8 u8Scan_Floor4 = NO_REQUEST_4;
	uint8 u8Acomodo=0;
	uint8 u8PisoAux=0;
	uint8 u8NextRequest=1;
	uint8 u8RequestState=1;

	while(1)
	{
		printf("\nu8Scan_Floor1=%d,\nu8Scan_Floor2=%d,\nu8Scan_Floor3=%d,\nu8Scan_Floor4=%d\n",u8Scan_Floor1,u8Scan_Floor2,u8Scan_Floor4,u8Scan_Floor3);

		switch	(	enCurrentState	)
		{
			case enLobby:
			{
				u8NextRequest=1;
				printf("\n\nRequest Numero %d\n\n",u8NextRequest);
				printf("\nBuenas tardes, El elevador se encuentra en el piso %d ¿Cuantas personas quieren entrar?\n",enCurrentState);
				scanf("%d",&u8People_In);
				printf("¿A que piso desea ir? \n0)Lobby \n1)Piso 1 \n2)Piso 2 \n3)Piso 3 \n4)Piso 4 \n5)Piso 5 \n6)Piso 6 \n7)Piso 7 \n8)Piso 8 \n9)Piso 9 \n10)Piso 10\n");
				scanf("%d",&u8Scan_Floor1);	
				u8People_In+=u8People_Entering;	
				

				if( u8People_In+u8People_Entering < MAX_PEOPLE)
				{
					u8People_In+=u8People_Entering;

					while (u8NextRequest!=END_REQUEST)
					{	

						printf("\n\nEl elevador va hacia el piso %d, \n¿Desea ir a otro piso? \n1)Si \n2)No \n\n",u8Scan_Floor1);
						scanf("%d",&u8RequestState);

						if(u8RequestState==1)
						{
							if(u8NextRequest==1)
							{
								printf("¿A que piso desea ir? \n0)Lobby \n1)Piso 1 \n2)Piso 2 \n3)Piso 3 \n4)Piso 4 \n5)Piso 5 \n6)Piso 6 \n7)Piso 7 \n8)Piso 8 \n9)Piso 9 \n10)Piso 10\n");
								scanf("%d",&u8Scan_Floor2);

								if(u8Scan_Floor2!=u8Scan_Floor1 && u8Scan_Floor2!=u8Scan_Floor3 && u8Scan_Floor2!=u8Scan_Floor4)
								{
									printf("Eligio el piso %d",u8Scan_Floor2);
									u8NextRequest+=1;

									if(u8Current_Floor - u8Scan_Floor2 < u8Current_Floor - u8Scan_Floor1)
									{
										u8PisoAux=u8Scan_Floor1;
										u8Scan_Floor1=u8Scan_Floor2;
										u8Scan_Floor2=u8PisoAux;
									}
									enCurrentState=u8Scan_Floor2;
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

								if(u8Scan_Floor3!=u8Scan_Floor1 && u8Scan_Floor3!=u8Scan_Floor2 && u8Scan_Floor3!=u8Scan_Floor4)
								{
									printf("Eligio el piso %d",u8Scan_Floor3);
									u8NextRequest+=1;

									if(u8Current_Floor - u8Scan_Floor3 < u8Current_Floor - u8Scan_Floor1)
									{
										u8PisoAux=u8Scan_Floor1;
										u8Scan_Floor1=u8Scan_Floor3;
										u8Scan_Floor3=u8PisoAux;
									}
									if(u8Current_Floor - u8Scan_Floor3 < u8Current_Floor - u8Scan_Floor2)
									{
										u8PisoAux=u8Scan_Floor2;
										u8Scan_Floor2=u8Scan_Floor3;
										u8Scan_Floor3=u8PisoAux;
									}
									enCurrentState=u8Scan_Floor3;

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

								if(u8Scan_Floor4!=u8Scan_Floor1 && u8Scan_Floor4!=u8Scan_Floor3 && u8Scan_Floor4!=u8Scan_Floor2 )
								{
									printf("Eligio el piso %d",u8Scan_Floor4);
									u8NextRequest+=1;

									if(u8Current_Floor - u8Scan_Floor4 < u8Current_Floor - u8Scan_Floor1)
									{
										u8PisoAux=u8Scan_Floor1;
										u8Scan_Floor1=u8Scan_Floor4;
										u8Scan_Floor4=u8PisoAux;
									}
									if(u8Current_Floor - u8Scan_Floor4 < u8Current_Floor - u8Scan_Floor2)
									{
										u8PisoAux=u8Scan_Floor2;
										u8Scan_Floor2=u8Scan_Floor4;
										u8Scan_Floor4=u8PisoAux;
									}
									if(u8Current_Floor - u8Scan_Floor4 < u8Current_Floor - u8Scan_Floor3)
									{
										u8PisoAux=u8Scan_Floor3;
										u8Scan_Floor3=u8Scan_Floor4;
										u8Scan_Floor4=u8PisoAux;
									}
									else
										{
											//**Nothing to do**//
										}
										u8Current_Floor=u8Scan_Floor4;
								}
								else
								{
									printf("Eligio un piso ya seleccionado");
									u8Scan_Floor4=END_REQUEST;
								}
							}
							else
							{
								printf("\n\nNo puede haber más de 4 pisos elegidos a la vez, evite jugar con el ascensor\n\n");
							}

						}
						else 
						{
							u8NextRequest=END_REQUEST;
							printf("\n\nTodo listo\n\n");
							printf("\nu8Scan_Floor1=%d,\nu8Scan_Floor2=%d,\nu8Scan_Floor3=%d,\nu8Scan_Floor4=%d",u8Scan_Floor1,u8Scan_Floor2,u8Scan_Floor4,u8Scan_Floor3);
							u8People_In-=u8People_Entering;

						}
					}


					if( u8Scan_Floor1!=NO_REQUEST_1	)
					{
						u8Current_Floor = u8Scan_Floor1;
						enCurrentState = u8Scan_Floor1;

						if(u8Current_Floor==0)
						{
							enCurrentState=enLobby;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==1)
						{
							enCurrentState=enPiso1;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==2)
						{
							enCurrentState=enPiso2;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==3)
						{
							enCurrentState=enPiso3;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==4)
						{
							enCurrentState=enPiso4;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==5)
						{
							enCurrentState=enPiso5;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==6)
						{
							enCurrentState=enPiso6;
							printf("main2Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==7)
						{
							enCurrentState=enPiso7;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==8)
						{
							enCurrentState=enPiso8;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==9)
						{
							enCurrentState=enPiso9;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==10)
						{
							enCurrentState=enPiso10;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else
						{
							//**Nothing to do**//
						}
					}

					if( u8Scan_Floor2!=NO_REQUEST_2	)
					{
						u8Current_Floor = u8Scan_Floor2;
						enCurrentState = u8Scan_Floor2;

						if(u8Current_Floor==0)
						{
							enCurrentState=enLobby;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==1)
						{
							enCurrentState=enPiso1;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==2)
						{
							enCurrentState=enPiso2;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==3)
						{
							enCurrentState=enPiso3;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==4)
						{
							enCurrentState=enPiso4;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==5)
						{
							enCurrentState=enPiso5;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==6)
						{
							enCurrentState=enPiso6;
							printf("main2Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==7)
						{
							enCurrentState=enPiso7;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==8)
						{
							enCurrentState=enPiso8;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==9)
						{
							enCurrentState=enPiso9;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==10)
						{
							enCurrentState=enPiso10;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else
						{
							//**Nothing to do**//
						}
					}

					if( u8Scan_Floor3!=NO_REQUEST_3	)
					{
						u8Current_Floor = u8Scan_Floor3;
						enCurrentState = u8Scan_Floor3;

						if(u8Current_Floor==0)
						{
							enCurrentState=enLobby;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==1)
						{
							enCurrentState=enPiso1;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==2)
						{
							enCurrentState=enPiso2;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==3)
						{
							enCurrentState=enPiso3;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==4)
						{
							enCurrentState=enPiso4;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==5)
						{
							enCurrentState=enPiso5;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==6)
						{
							enCurrentState=enPiso6;
							printf("main2Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==7)
						{
							enCurrentState=enPiso7;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==8)
						{
							enCurrentState=enPiso8;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==9)
						{
							enCurrentState=enPiso9;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==10)
						{
							enCurrentState=enPiso10;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else
						{
							//**Nothing to do**//
						}
					}

					if( u8Scan_Floor4!=NO_REQUEST_4	)
					{
						u8Current_Floor = u8Scan_Floor4;
						enCurrentState = u8Scan_Floor4;
						if(u8Current_Floor==0)
						{
							enCurrentState=enLobby;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==1)
						{
							enCurrentState=enPiso1;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==2)
						{
							enCurrentState=enPiso2;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==3)
						{
							enCurrentState=enPiso3;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==4)
						{
							enCurrentState=enPiso4;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==5)
						{
							enCurrentState=enPiso5;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==6)
						{
							enCurrentState=enPiso6;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==7)
						{
							enCurrentState=enPiso7;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==8)
						{
							enCurrentState=enPiso8;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==9)
						{
							enCurrentState=enPiso9;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==10)
						{
							enCurrentState=enPiso10;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else
						{
							//**Nothing to do**//
						}
					}

					else
					{
						printf("Terminaron los request");
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
				u8NextRequest=1;
				printf("\n\nRequest Numero %d\n\n",u8NextRequest);
				printf("\nBuenas tardes, El elevador se encuentra en el piso %d ¿Cuantas personas quieren entrar?\n",enCurrentState);
				scanf("%d",&u8People_In);
				printf("¿A que piso desea ir? \n0)Lobby \n1)Piso 1 \n2)Piso 2 \n3)Piso 3 \n4)Piso 4 \n5)Piso 5 \n6)Piso 6 \n7)Piso 7 \n8)Piso 8 \n9)Piso 9 \n10)Piso 10\n");
				scanf("%d",&u8Scan_Floor1);	
				u8People_In+=u8People_Entering;	
				printf("\n%d\n", u8People_In);

				if( u8People_In+u8People_Entering < MAX_PEOPLE)
				{
					u8People_In+=u8People_Entering;

					while (u8NextRequest!=END_REQUEST)
					{	

						printf("\n\nEl elevador va hacia el piso %d, \n¿Desea ir a otro piso? \n1)Si \n2)No \n\n",u8Scan_Floor1);
						scanf("%d",&u8RequestState);

						if(u8RequestState==1)
						{
							if(u8NextRequest==1)
							{
								printf("¿A que piso desea ir? \n0)Lobby \n1)Piso 1 \n2)Piso 2 \n3)Piso 3 \n4)Piso 4 \n5)Piso 5 \n6)Piso 6 \n7)Piso 7 \n8)Piso 8 \n9)Piso 9 \n10)Piso 10\n");
								scanf("%d",&u8Scan_Floor2);

								if(u8Scan_Floor2!=u8Scan_Floor1 && u8Scan_Floor2!=u8Scan_Floor3 && u8Scan_Floor2!=u8Scan_Floor4)
								{
									printf("Eligio el piso %d",u8Scan_Floor2);
									u8NextRequest+=1;

									if(u8Current_Floor - u8Scan_Floor2 < u8Current_Floor - u8Scan_Floor1)
									{
										u8PisoAux=u8Scan_Floor1;
										u8Scan_Floor1=u8Scan_Floor2;
										u8Scan_Floor2=u8PisoAux;
									}
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

								if(u8Scan_Floor3!=u8Scan_Floor1 && u8Scan_Floor3!=u8Scan_Floor2 && u8Scan_Floor3!=u8Scan_Floor4)
								{
									printf("Eligio el piso %d",u8Scan_Floor3);
									u8NextRequest+=1;

									if(u8Current_Floor - u8Scan_Floor3 < u8Current_Floor - u8Scan_Floor1)
									{
										u8PisoAux=u8Scan_Floor1;
										u8Scan_Floor1=u8Scan_Floor3;
										u8Scan_Floor3=u8PisoAux;
									}
									else if(u8Current_Floor - u8Scan_Floor3 < u8Current_Floor - u8Scan_Floor2)
									{
										u8PisoAux=u8Scan_Floor2;
										u8Scan_Floor2=u8Scan_Floor3;
										u8Scan_Floor3=u8PisoAux;
									}

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

								if(u8Scan_Floor4!=u8Scan_Floor1 && u8Scan_Floor4!=u8Scan_Floor3 && u8Scan_Floor4!=u8Scan_Floor2)
								{
									printf("Eligio el piso %d",u8Scan_Floor4);
									u8NextRequest+=1;

									if(u8Current_Floor - u8Scan_Floor4 < u8Current_Floor - u8Scan_Floor1)
									{
										u8PisoAux=u8Scan_Floor1;
										u8Scan_Floor1=u8Scan_Floor4;
										u8Scan_Floor4=u8PisoAux;
									}
									else if(u8Current_Floor - u8Scan_Floor4 < u8Current_Floor - u8Scan_Floor2)
									{
										u8PisoAux=u8Scan_Floor2;
										u8Scan_Floor2=u8Scan_Floor4;
										u8Scan_Floor4=u8PisoAux;
									}
									else if(u8Current_Floor - u8Scan_Floor4 < u8Current_Floor - u8Scan_Floor3)
									{
										u8PisoAux=u8Scan_Floor3;
										u8Scan_Floor3=u8Scan_Floor4;
										u8Scan_Floor4=u8PisoAux;
									}
									else
										{
											//**Nothing to do**//
										}
								}
								else
								{
									printf("Eligio un piso ya seleccionado");
									u8Scan_Floor4=END_REQUEST;
								}
							}
							else
							{
								printf("\n\nNo puede haber más de 4 pisos elegidos a la vez, evite jugar con el ascensor\n\n");
							}

						}
						else 
						{
							u8NextRequest=END_REQUEST;
							printf("\n\nTodo listo\n\n");

							u8People_In-=u8People_Entering;

						}
					}


					if( u8Scan_Floor1!=NO_REQUEST_1	)
					{
						u8Current_Floor = u8Scan_Floor1;
						enCurrentState = u8Scan_Floor1;

						if(u8Current_Floor==0)
						{
							enCurrentState=enLobby;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==1)
						{
							enCurrentState=enPiso1;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==2)
						{
							enCurrentState=enPiso2;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==3)
						{
							enCurrentState=enPiso3;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==4)
						{
							enCurrentState=enPiso4;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==5)
						{
							enCurrentState=enPiso5;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==6)
						{
							enCurrentState=enPiso6;
							printf("main2Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==7)
						{
							enCurrentState=enPiso7;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==8)
						{
							enCurrentState=enPiso8;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==9)
						{
							enCurrentState=enPiso9;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==10)
						{
							enCurrentState=enPiso10;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else
						{
							//**Nothing to do**//
						}
					}

					if( u8Scan_Floor2!=NO_REQUEST_2	)
					{
						u8Current_Floor = u8Scan_Floor2;
						enCurrentState = u8Scan_Floor2;

						if(u8Current_Floor==0)
						{
							enCurrentState=enLobby;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==1)
						{
							enCurrentState=enPiso1;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==2)
						{
							enCurrentState=enPiso2;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==3)
						{
							enCurrentState=enPiso3;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==4)
						{
							enCurrentState=enPiso4;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==5)
						{
							enCurrentState=enPiso5;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==6)
						{
							enCurrentState=enPiso6;
							printf("main2Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==7)
						{
							enCurrentState=enPiso7;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==8)
						{
							enCurrentState=enPiso8;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==9)
						{
							enCurrentState=enPiso9;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==10)
						{
							enCurrentState=enPiso10;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else
						{
							//**Nothing to do**//
						}
					}

					if( u8Scan_Floor3!=NO_REQUEST_3	)
					{
						u8Current_Floor = u8Scan_Floor3;
						enCurrentState = u8Scan_Floor3;

						if(u8Current_Floor==0)
						{
							enCurrentState=enLobby;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==1)
						{
							enCurrentState=enPiso1;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==2)
						{
							enCurrentState=enPiso2;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==3)
						{
							enCurrentState=enPiso3;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==4)
						{
							enCurrentState=enPiso4;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==5)
						{
							enCurrentState=enPiso5;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==6)
						{
							enCurrentState=enPiso6;
							printf("main2Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==7)
						{
							enCurrentState=enPiso7;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==8)
						{
							enCurrentState=enPiso8;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==9)
						{
							enCurrentState=enPiso9;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==10)
						{
							enCurrentState=enPiso10;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else
						{
							//**Nothing to do**//
						}
					}

					if( u8Scan_Floor4!=NO_REQUEST_4	)
					{
						u8Current_Floor = u8Scan_Floor4;
						enCurrentState = u8Scan_Floor4;
						if(u8Current_Floor==0)
						{
							enCurrentState=enLobby;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==1)
						{
							enCurrentState=enPiso1;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==2)
						{
							enCurrentState=enPiso2;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==3)
						{
							enCurrentState=enPiso3;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==4)
						{
							enCurrentState=enPiso4;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==5)
						{
							enCurrentState=enPiso5;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==6)
						{
							enCurrentState=enPiso6;
							printf("main2Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==7)
						{
							enCurrentState=enPiso7;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==8)
						{
							enCurrentState=enPiso8;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==9)
						{
							enCurrentState=enPiso9;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==10)
						{
							enCurrentState=enPiso10;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else
						{
							//**Nothing to do**//
						}
					}

					else
					{
						printf("Terminaron los request");
					}
				}
				else
				{
					printf("Maximo numero de personas son %d, espere a que se desocupe\n",MAX_PEOPLE);
				}
				break;
			}

			case enPiso2:
			{
				u8NextRequest=1;
				printf("\n\nRequest Numero %d\n\n",u8NextRequest);
				printf("\nBuenas tardes, El elevador se encuentra en el piso %d ¿Cuantas personas quieren entrar?\n",enCurrentState);
				scanf("%d",&u8People_In);
				printf("¿A que piso desea ir? \n0)Lobby \n1)Piso 1 \n2)Piso 2 \n3)Piso 3 \n4)Piso 4 \n5)Piso 5 \n6)Piso 6 \n7)Piso 7 \n8)Piso 8 \n9)Piso 9 \n10)Piso 10\n");
				scanf("%d",&u8Scan_Floor1);	
				u8People_In+=u8People_Entering;	
				printf("\n%d\n", u8People_In);

				if( u8People_In+u8People_Entering < MAX_PEOPLE)
				{
					u8People_In+=u8People_Entering;

					while (u8NextRequest!=END_REQUEST)
					{	

						printf("\n\nEl elevador va hacia el piso %d, \n¿Desea ir a otro piso? \n1)Si \n2)No \n\n",u8Scan_Floor1);
						scanf("%d",&u8RequestState);

						if(u8RequestState==1)
						{
							if(u8NextRequest==1)
							{
								printf("¿A que piso desea ir? \n0)Lobby \n1)Piso 1 \n2)Piso 2 \n3)Piso 3 \n4)Piso 4 \n5)Piso 5 \n6)Piso 6 \n7)Piso 7 \n8)Piso 8 \n9)Piso 9 \n10)Piso 10\n");
								scanf("%d",&u8Scan_Floor2);

								if(u8Scan_Floor2!=u8Scan_Floor1 && u8Scan_Floor2!=u8Scan_Floor3 && u8Scan_Floor2!=u8Scan_Floor4)
								{
									printf("Eligio el piso %d",u8Scan_Floor2);
									u8NextRequest+=1;

									if(u8Current_Floor - u8Scan_Floor2 < u8Current_Floor - u8Scan_Floor1)
									{
										u8PisoAux=u8Scan_Floor1;
										u8Scan_Floor1=u8Scan_Floor2;
										u8Scan_Floor2=u8PisoAux;
									}
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

								if(u8Scan_Floor3!=u8Scan_Floor1 && u8Scan_Floor3!=u8Scan_Floor2 && u8Scan_Floor3!=u8Scan_Floor4)
								{
									printf("Eligio el piso %d",u8Scan_Floor3);
									u8NextRequest+=1;

									if(u8Current_Floor - u8Scan_Floor3 < u8Current_Floor - u8Scan_Floor1)
									{
										u8PisoAux=u8Scan_Floor1;
										u8Scan_Floor1=u8Scan_Floor3;
										u8Scan_Floor3=u8PisoAux;
									}
									else if(u8Current_Floor - u8Scan_Floor3 < u8Current_Floor - u8Scan_Floor2)
									{
										u8PisoAux=u8Scan_Floor2;
										u8Scan_Floor2=u8Scan_Floor3;
										u8Scan_Floor3=u8PisoAux;
									}

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

								if(u8Scan_Floor4!=u8Scan_Floor1 && u8Scan_Floor4!=u8Scan_Floor3 && u8Scan_Floor4!=u8Scan_Floor2)
								{
									printf("Eligio el piso %d",u8Scan_Floor4);
									u8NextRequest+=1;

									if(u8Current_Floor - u8Scan_Floor4 < u8Current_Floor - u8Scan_Floor1)
									{
										u8PisoAux=u8Scan_Floor1;
										u8Scan_Floor1=u8Scan_Floor4;
										u8Scan_Floor4=u8PisoAux;
									}
									else if(u8Current_Floor - u8Scan_Floor4 < u8Current_Floor - u8Scan_Floor2)
									{
										u8PisoAux=u8Scan_Floor2;
										u8Scan_Floor2=u8Scan_Floor4;
										u8Scan_Floor4=u8PisoAux;
									}
									else if(u8Current_Floor - u8Scan_Floor4 < u8Current_Floor - u8Scan_Floor3)
									{
										u8PisoAux=u8Scan_Floor3;
										u8Scan_Floor3=u8Scan_Floor4;
										u8Scan_Floor4=u8PisoAux;
									}
									else
										{
											//**Nothing to do**//
										}
								}
								else
								{
									printf("Eligio un piso ya seleccionado");
									u8Scan_Floor4=END_REQUEST;
								}
							}
							else
							{
								printf("\n\nNo puede haber más de 4 pisos elegidos a la vez, evite jugar con el ascensor\n\n");
							}

						}
						else 
						{
							u8NextRequest=END_REQUEST;
							printf("\n\nTodo listo\n\n");

							u8People_In-=u8People_Entering;

						}
					}


					if( u8Scan_Floor1!=NO_REQUEST_1	)
					{
						u8Current_Floor = u8Scan_Floor1;
						enCurrentState = u8Scan_Floor1;

						if(u8Current_Floor==0)
						{
							enCurrentState=enLobby;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==1)
						{
							enCurrentState=enPiso1;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==2)
						{
							enCurrentState=enPiso2;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==3)
						{
							enCurrentState=enPiso3;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==4)
						{
							enCurrentState=enPiso4;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==5)
						{
							enCurrentState=enPiso5;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==6)
						{
							enCurrentState=enPiso6;
							printf("main2Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==7)
						{
							enCurrentState=enPiso7;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==8)
						{
							enCurrentState=enPiso8;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==9)
						{
							enCurrentState=enPiso9;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==10)
						{
							enCurrentState=enPiso10;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else
						{
							//**Nothing to do**//
						}
					}

					if( u8Scan_Floor2!=NO_REQUEST_2	)
					{
						u8Current_Floor = u8Scan_Floor2;
						enCurrentState = u8Scan_Floor2;

						if(u8Current_Floor==0)
						{
							enCurrentState=enLobby;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==1)
						{
							enCurrentState=enPiso1;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==2)
						{
							enCurrentState=enPiso2;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==3)
						{
							enCurrentState=enPiso3;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==4)
						{
							enCurrentState=enPiso4;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==5)
						{
							enCurrentState=enPiso5;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==6)
						{
							enCurrentState=enPiso6;
							printf("main2Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==7)
						{
							enCurrentState=enPiso7;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==8)
						{
							enCurrentState=enPiso8;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==9)
						{
							enCurrentState=enPiso9;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==10)
						{
							enCurrentState=enPiso10;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else
						{
							//**Nothing to do**//
						}
					}

					if( u8Scan_Floor3!=NO_REQUEST_3	)
					{
						u8Current_Floor = u8Scan_Floor3;
						enCurrentState = u8Scan_Floor3;

						if(u8Current_Floor==0)
						{
							enCurrentState=enLobby;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==1)
						{
							enCurrentState=enPiso1;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==2)
						{
							enCurrentState=enPiso2;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==3)
						{
							enCurrentState=enPiso3;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==4)
						{
							enCurrentState=enPiso4;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==5)
						{
							enCurrentState=enPiso5;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==6)
						{
							enCurrentState=enPiso6;
							printf("main2Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==7)
						{
							enCurrentState=enPiso7;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==8)
						{
							enCurrentState=enPiso8;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==9)
						{
							enCurrentState=enPiso9;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==10)
						{
							enCurrentState=enPiso10;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else
						{
							//**Nothing to do**//
						}
					}

					if( u8Scan_Floor4!=NO_REQUEST_4	)
					{
						u8Current_Floor = u8Scan_Floor4;
						enCurrentState = u8Scan_Floor4;
						if(u8Current_Floor==0)
						{
							enCurrentState=enLobby;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==1)
						{
							enCurrentState=enPiso1;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==2)
						{
							enCurrentState=enPiso2;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==3)
						{
							enCurrentState=enPiso3;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==4)
						{
							enCurrentState=enPiso4;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==5)
						{
							enCurrentState=enPiso5;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==6)
						{
							enCurrentState=enPiso6;
							printf("main2Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==7)
						{
							enCurrentState=enPiso7;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==8)
						{
							enCurrentState=enPiso8;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==9)
						{
							enCurrentState=enPiso9;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==10)
						{
							enCurrentState=enPiso10;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else
						{
							//**Nothing to do**//
						}
					}

					else
					{
						printf("Terminaron los request");
					}
				}
				else
				{
					printf("Maximo numero de personas son %d, espere a que se desocupe\n",MAX_PEOPLE);
				}
				break;
			}

			case enPiso3:
			{
				u8NextRequest=1;
				printf("\n\nRequest Numero %d\n\n",u8NextRequest);
				printf("\nBuenas tardes, El elevador se encuentra en el piso %d ¿Cuantas personas quieren entrar?\n",enCurrentState);
				scanf("%d",&u8People_In);
				printf("¿A que piso desea ir? \n0)Lobby \n1)Piso 1 \n2)Piso 2 \n3)Piso 3 \n4)Piso 4 \n5)Piso 5 \n6)Piso 6 \n7)Piso 7 \n8)Piso 8 \n9)Piso 9 \n10)Piso 10\n");
				scanf("%d",&u8Scan_Floor1);	
				u8People_In+=u8People_Entering;	
				printf("\n%d\n", u8People_In);

				if( u8People_In+u8People_Entering < MAX_PEOPLE)
				{
					u8People_In+=u8People_Entering;

					while (u8NextRequest!=END_REQUEST)
					{	

						printf("\n\nEl elevador va hacia el piso %d, \n¿Desea ir a otro piso? \n1)Si \n2)No \n\n",u8Scan_Floor1);
						scanf("%d",&u8RequestState);

						if(u8RequestState==1)
						{
							if(u8NextRequest==1)
							{
								printf("¿A que piso desea ir? \n0)Lobby \n1)Piso 1 \n2)Piso 2 \n3)Piso 3 \n4)Piso 4 \n5)Piso 5 \n6)Piso 6 \n7)Piso 7 \n8)Piso 8 \n9)Piso 9 \n10)Piso 10\n");
								scanf("%d",&u8Scan_Floor2);

								if(u8Scan_Floor2!=u8Scan_Floor1 && u8Scan_Floor2!=u8Scan_Floor3 && u8Scan_Floor2!=u8Scan_Floor4)
								{
									printf("Eligio el piso %d",u8Scan_Floor2);
									u8NextRequest+=1;

									if(u8Current_Floor - u8Scan_Floor2 < u8Current_Floor - u8Scan_Floor1)
									{
										u8PisoAux=u8Scan_Floor1;
										u8Scan_Floor1=u8Scan_Floor2;
										u8Scan_Floor2=u8PisoAux;
									}
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

								if(u8Scan_Floor3!=u8Scan_Floor1 && u8Scan_Floor3!=u8Scan_Floor2 && u8Scan_Floor3!=u8Scan_Floor4)
								{
									printf("Eligio el piso %d",u8Scan_Floor3);
									u8NextRequest+=1;

									if(u8Current_Floor - u8Scan_Floor3 < u8Current_Floor - u8Scan_Floor1)
									{
										u8PisoAux=u8Scan_Floor1;
										u8Scan_Floor1=u8Scan_Floor3;
										u8Scan_Floor3=u8PisoAux;
									}
									else if(u8Current_Floor - u8Scan_Floor3 < u8Current_Floor - u8Scan_Floor2)
									{
										u8PisoAux=u8Scan_Floor2;
										u8Scan_Floor2=u8Scan_Floor3;
										u8Scan_Floor3=u8PisoAux;
									}

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

								if(u8Scan_Floor4!=u8Scan_Floor1 && u8Scan_Floor4!=u8Scan_Floor3 && u8Scan_Floor4!=u8Scan_Floor2)
								{
									printf("Eligio el piso %d",u8Scan_Floor4);
									u8NextRequest+=1;

									if(u8Current_Floor - u8Scan_Floor4 < u8Current_Floor - u8Scan_Floor1)
									{
										u8PisoAux=u8Scan_Floor1;
										u8Scan_Floor1=u8Scan_Floor4;
										u8Scan_Floor4=u8PisoAux;
									}
									else if(u8Current_Floor - u8Scan_Floor4 < u8Current_Floor - u8Scan_Floor2)
									{
										u8PisoAux=u8Scan_Floor2;
										u8Scan_Floor2=u8Scan_Floor4;
										u8Scan_Floor4=u8PisoAux;
									}
									else if(u8Current_Floor - u8Scan_Floor4 < u8Current_Floor - u8Scan_Floor3)
									{
										u8PisoAux=u8Scan_Floor3;
										u8Scan_Floor3=u8Scan_Floor4;
										u8Scan_Floor4=u8PisoAux;
									}
									else
										{
											//**Nothing to do**//
										}
								}
								else
								{
									printf("Eligio un piso ya seleccionado");
									u8Scan_Floor4=END_REQUEST;
								}
							}
							else
							{
								printf("\n\nNo puede haber más de 4 pisos elegidos a la vez, evite jugar con el ascensor\n\n");
							}

						}
						else 
						{
							u8NextRequest=END_REQUEST;
							printf("\n\nTodo listo\n\n");

							u8People_In-=u8People_Entering;

						}
					}


					if( u8Scan_Floor1!=NO_REQUEST_1	)
					{
						u8Current_Floor = u8Scan_Floor1;
						enCurrentState = u8Scan_Floor1;

						if(u8Current_Floor==0)
						{
							enCurrentState=enLobby;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==1)
						{
							enCurrentState=enPiso1;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==2)
						{
							enCurrentState=enPiso2;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==3)
						{
							enCurrentState=enPiso3;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==4)
						{
							enCurrentState=enPiso4;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==5)
						{
							enCurrentState=enPiso5;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==6)
						{
							enCurrentState=enPiso6;
							printf("main2Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==7)
						{
							enCurrentState=enPiso7;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==8)
						{
							enCurrentState=enPiso8;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==9)
						{
							enCurrentState=enPiso9;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==10)
						{
							enCurrentState=enPiso10;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else
						{
							//**Nothing to do**//
						}
					}

					if( u8Scan_Floor2!=NO_REQUEST_2	)
					{
						u8Current_Floor = u8Scan_Floor2;
						enCurrentState = u8Scan_Floor2;

						if(u8Current_Floor==0)
						{
							enCurrentState=enLobby;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==1)
						{
							enCurrentState=enPiso1;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==2)
						{
							enCurrentState=enPiso2;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==3)
						{
							enCurrentState=enPiso3;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==4)
						{
							enCurrentState=enPiso4;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==5)
						{
							enCurrentState=enPiso5;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==6)
						{
							enCurrentState=enPiso6;
							printf("main2Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==7)
						{
							enCurrentState=enPiso7;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==8)
						{
							enCurrentState=enPiso8;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==9)
						{
							enCurrentState=enPiso9;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==10)
						{
							enCurrentState=enPiso10;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else
						{
							//**Nothing to do**//
						}
					}

					if( u8Scan_Floor3!=NO_REQUEST_3	)
					{
						u8Current_Floor = u8Scan_Floor3;
						enCurrentState = u8Scan_Floor3;

						if(u8Current_Floor==0)
						{
							enCurrentState=enLobby;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==1)
						{
							enCurrentState=enPiso1;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==2)
						{
							enCurrentState=enPiso2;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==3)
						{
							enCurrentState=enPiso3;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==4)
						{
							enCurrentState=enPiso4;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==5)
						{
							enCurrentState=enPiso5;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==6)
						{
							enCurrentState=enPiso6;
							printf("main2Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==7)
						{
							enCurrentState=enPiso7;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==8)
						{
							enCurrentState=enPiso8;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==9)
						{
							enCurrentState=enPiso9;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==10)
						{
							enCurrentState=enPiso10;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else
						{
							//**Nothing to do**//
						}
					}

					if( u8Scan_Floor4!=NO_REQUEST_4	)
					{
						u8Current_Floor = u8Scan_Floor4;
						enCurrentState = u8Scan_Floor4;
						if(u8Current_Floor==0)
						{
							enCurrentState=enLobby;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==1)
						{
							enCurrentState=enPiso1;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==2)
						{
							enCurrentState=enPiso2;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==3)
						{
							enCurrentState=enPiso3;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==4)
						{
							enCurrentState=enPiso4;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==5)
						{
							enCurrentState=enPiso5;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==6)
						{
							enCurrentState=enPiso6;
							printf("main2Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==7)
						{
							enCurrentState=enPiso7;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==8)
						{
							enCurrentState=enPiso8;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==9)
						{
							enCurrentState=enPiso9;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==10)
						{
							enCurrentState=enPiso10;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else
						{
							//**Nothing to do**//
						}
					}

					else
					{
						printf("Terminaron los request");
					}
				}
				else
				{
					printf("Maximo numero de personas son %d, espere a que se desocupe\n",MAX_PEOPLE);
				}
				break;
			}

			case enPiso4:
			{
				u8NextRequest=1;
				printf("\n\nRequest Numero %d\n\n",u8NextRequest);
				printf("\nBuenas tardes, El elevador se encuentra en el piso %d ¿Cuantas personas quieren entrar?\n",enCurrentState);
				scanf("%d",&u8People_In);
				printf("¿A que piso desea ir? \n0)Lobby \n1)Piso 1 \n2)Piso 2 \n3)Piso 3 \n4)Piso 4 \n5)Piso 5 \n6)Piso 6 \n7)Piso 7 \n8)Piso 8 \n9)Piso 9 \n10)Piso 10\n");
				scanf("%d",&u8Scan_Floor1);	
				u8People_In+=u8People_Entering;	
				printf("\n%d\n", u8People_In);

				if( u8People_In+u8People_Entering < MAX_PEOPLE)
				{
					u8People_In+=u8People_Entering;

					while (u8NextRequest!=END_REQUEST)
					{	

						printf("\n\nEl elevador va hacia el piso %d, \n¿Desea ir a otro piso? \n1)Si \n2)No \n\n",u8Scan_Floor1);
						scanf("%d",&u8RequestState);

						if(u8RequestState==1)
						{
							if(u8NextRequest==1)
							{
								printf("¿A que piso desea ir? \n0)Lobby \n1)Piso 1 \n2)Piso 2 \n3)Piso 3 \n4)Piso 4 \n5)Piso 5 \n6)Piso 6 \n7)Piso 7 \n8)Piso 8 \n9)Piso 9 \n10)Piso 10\n");
								scanf("%d",&u8Scan_Floor2);

								if(u8Scan_Floor2!=u8Scan_Floor1 && u8Scan_Floor2!=u8Scan_Floor3 && u8Scan_Floor2!=u8Scan_Floor4)
								{
									printf("Eligio el piso %d",u8Scan_Floor2);
									u8NextRequest+=1;

									if(u8Current_Floor - u8Scan_Floor2 < u8Current_Floor - u8Scan_Floor1)
									{
										u8PisoAux=u8Scan_Floor1;
										u8Scan_Floor1=u8Scan_Floor2;
										u8Scan_Floor2=u8PisoAux;
									}
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

								if(u8Scan_Floor3!=u8Scan_Floor1 && u8Scan_Floor3!=u8Scan_Floor2 && u8Scan_Floor3!=u8Scan_Floor4)
								{
									printf("Eligio el piso %d",u8Scan_Floor3);
									u8NextRequest+=1;

									if(u8Current_Floor - u8Scan_Floor3 < u8Current_Floor - u8Scan_Floor1)
									{
										u8PisoAux=u8Scan_Floor1;
										u8Scan_Floor1=u8Scan_Floor3;
										u8Scan_Floor3=u8PisoAux;
									}
									else if(u8Current_Floor - u8Scan_Floor3 < u8Current_Floor - u8Scan_Floor2)
									{
										u8PisoAux=u8Scan_Floor2;
										u8Scan_Floor2=u8Scan_Floor3;
										u8Scan_Floor3=u8PisoAux;
									}

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

								if(u8Scan_Floor4!=u8Scan_Floor1 && u8Scan_Floor4!=u8Scan_Floor3 && u8Scan_Floor4!=u8Scan_Floor2)
								{
									printf("Eligio el piso %d",u8Scan_Floor4);
									u8NextRequest+=1;

									if(u8Current_Floor - u8Scan_Floor4 < u8Current_Floor - u8Scan_Floor1)
									{
										u8PisoAux=u8Scan_Floor1;
										u8Scan_Floor1=u8Scan_Floor4;
										u8Scan_Floor4=u8PisoAux;
									}
									else if(u8Current_Floor - u8Scan_Floor4 < u8Current_Floor - u8Scan_Floor2)
									{
										u8PisoAux=u8Scan_Floor2;
										u8Scan_Floor2=u8Scan_Floor4;
										u8Scan_Floor4=u8PisoAux;
									}
									else if(u8Current_Floor - u8Scan_Floor4 < u8Current_Floor - u8Scan_Floor3)
									{
										u8PisoAux=u8Scan_Floor3;
										u8Scan_Floor3=u8Scan_Floor4;
										u8Scan_Floor4=u8PisoAux;
									}
									else
										{
											//**Nothing to do**//
										}
								}
								else
								{
									printf("Eligio un piso ya seleccionado");
									u8Scan_Floor4=END_REQUEST;
								}
							}
							else
							{
								printf("\n\nNo puede haber más de 4 pisos elegidos a la vez, evite jugar con el ascensor\n\n");
							}

						}
						else 
						{
							u8NextRequest=END_REQUEST;
							printf("\n\nTodo listo\n\n");

							u8People_In-=u8People_Entering;

						}
					}


					if( u8Scan_Floor1!=NO_REQUEST_1	)
					{
						u8Current_Floor = u8Scan_Floor1;
						enCurrentState = u8Scan_Floor1;

						if(u8Current_Floor==0)
						{
							enCurrentState=enLobby;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==1)
						{
							enCurrentState=enPiso1;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==2)
						{
							enCurrentState=enPiso2;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==3)
						{
							enCurrentState=enPiso3;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==4)
						{
							enCurrentState=enPiso4;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==5)
						{
							enCurrentState=enPiso5;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==6)
						{
							enCurrentState=enPiso6;
							printf("main2Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==7)
						{
							enCurrentState=enPiso7;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==8)
						{
							enCurrentState=enPiso8;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==9)
						{
							enCurrentState=enPiso9;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==10)
						{
							enCurrentState=enPiso10;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else
						{
							//**Nothing to do**//
						}
					}

					if( u8Scan_Floor2!=NO_REQUEST_2	)
					{
						u8Current_Floor = u8Scan_Floor2;
						enCurrentState = u8Scan_Floor2;

						if(u8Current_Floor==0)
						{
							enCurrentState=enLobby;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==1)
						{
							enCurrentState=enPiso1;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==2)
						{
							enCurrentState=enPiso2;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==3)
						{
							enCurrentState=enPiso3;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==4)
						{
							enCurrentState=enPiso4;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==5)
						{
							enCurrentState=enPiso5;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==6)
						{
							enCurrentState=enPiso6;
							printf("main2Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==7)
						{
							enCurrentState=enPiso7;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==8)
						{
							enCurrentState=enPiso8;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==9)
						{
							enCurrentState=enPiso9;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==10)
						{
							enCurrentState=enPiso10;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else
						{
							//**Nothing to do**//
						}
					}

					if( u8Scan_Floor3!=NO_REQUEST_3	)
					{
						u8Current_Floor = u8Scan_Floor3;
						enCurrentState = u8Scan_Floor3;

						if(u8Current_Floor==0)
						{
							enCurrentState=enLobby;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==1)
						{
							enCurrentState=enPiso1;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==2)
						{
							enCurrentState=enPiso2;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==3)
						{
							enCurrentState=enPiso3;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==4)
						{
							enCurrentState=enPiso4;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==5)
						{
							enCurrentState=enPiso5;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==6)
						{
							enCurrentState=enPiso6;
							printf("main2Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==7)
						{
							enCurrentState=enPiso7;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==8)
						{
							enCurrentState=enPiso8;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==9)
						{
							enCurrentState=enPiso9;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==10)
						{
							enCurrentState=enPiso10;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else
						{
							//**Nothing to do**//
						}
					}

					if( u8Scan_Floor4!=NO_REQUEST_4	)
					{
						u8Current_Floor = u8Scan_Floor4;
						enCurrentState = u8Scan_Floor4;
						if(u8Current_Floor==0)
						{
							enCurrentState=enLobby;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==1)
						{
							enCurrentState=enPiso1;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==2)
						{
							enCurrentState=enPiso2;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==3)
						{
							enCurrentState=enPiso3;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==4)
						{
							enCurrentState=enPiso4;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==5)
						{
							enCurrentState=enPiso5;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==6)
						{
							enCurrentState=enPiso6;
							printf("main2Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==7)
						{
							enCurrentState=enPiso7;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==8)
						{
							enCurrentState=enPiso8;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==9)
						{
							enCurrentState=enPiso9;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==10)
						{
							enCurrentState=enPiso10;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else
						{
							//**Nothing to do**//
						}
					}

					else
					{
						printf("Terminaron los request");
					}
				}
				else
				{
					printf("Maximo numero de personas son %d, espere a que se desocupe\n",MAX_PEOPLE);
				}
				break;
			}

			case enPiso5:
			{
				u8NextRequest=1;
				printf("\n\nRequest Numero %d\n\n",u8NextRequest);
				printf("\nBuenas tardes, El elevador se encuentra en el piso %d ¿Cuantas personas quieren entrar?\n",enCurrentState);
				scanf("%d",&u8People_In);
				printf("¿A que piso desea ir? \n0)Lobby \n1)Piso 1 \n2)Piso 2 \n3)Piso 3 \n4)Piso 4 \n5)Piso 5 \n6)Piso 6 \n7)Piso 7 \n8)Piso 8 \n9)Piso 9 \n10)Piso 10\n");
				scanf("%d",&u8Scan_Floor1);	
				u8People_In+=u8People_Entering;	
				printf("\n%d\n", u8People_In);

				if( u8People_In+u8People_Entering < MAX_PEOPLE)
				{
					u8People_In+=u8People_Entering;

					while (u8NextRequest!=END_REQUEST)
					{	

						printf("\n\nEl elevador va hacia el piso %d, \n¿Desea ir a otro piso? \n1)Si \n2)No \n\n",u8Scan_Floor1);
						scanf("%d",&u8RequestState);

						if(u8RequestState==1)
						{
							if(u8NextRequest==1)
							{
								printf("¿A que piso desea ir? \n0)Lobby \n1)Piso 1 \n2)Piso 2 \n3)Piso 3 \n4)Piso 4 \n5)Piso 5 \n6)Piso 6 \n7)Piso 7 \n8)Piso 8 \n9)Piso 9 \n10)Piso 10\n");
								scanf("%d",&u8Scan_Floor2);

								if(u8Scan_Floor2!=u8Scan_Floor1 && u8Scan_Floor2!=u8Scan_Floor3 && u8Scan_Floor2!=u8Scan_Floor4)
								{
									printf("Eligio el piso %d",u8Scan_Floor2);
									u8NextRequest+=1;

									if(u8Current_Floor - u8Scan_Floor2 < u8Current_Floor - u8Scan_Floor1)
									{
										u8PisoAux=u8Scan_Floor1;
										u8Scan_Floor1=u8Scan_Floor2;
										u8Scan_Floor2=u8PisoAux;
									}
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

								if(u8Scan_Floor3!=u8Scan_Floor1 && u8Scan_Floor3!=u8Scan_Floor2 && u8Scan_Floor3!=u8Scan_Floor4)
								{
									printf("Eligio el piso %d",u8Scan_Floor3);
									u8NextRequest+=1;

									if(u8Current_Floor - u8Scan_Floor3 < u8Current_Floor - u8Scan_Floor1)
									{
										u8PisoAux=u8Scan_Floor1;
										u8Scan_Floor1=u8Scan_Floor3;
										u8Scan_Floor3=u8PisoAux;
									}
									else if(u8Current_Floor - u8Scan_Floor3 < u8Current_Floor - u8Scan_Floor2)
									{
										u8PisoAux=u8Scan_Floor2;
										u8Scan_Floor2=u8Scan_Floor3;
										u8Scan_Floor3=u8PisoAux;
									}

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

								if(u8Scan_Floor4!=u8Scan_Floor1 && u8Scan_Floor4!=u8Scan_Floor3 && u8Scan_Floor4!=u8Scan_Floor2)
								{
									printf("Eligio el piso %d",u8Scan_Floor4);
									u8NextRequest+=1;

									if(u8Current_Floor - u8Scan_Floor4 < u8Current_Floor - u8Scan_Floor1)
									{
										u8PisoAux=u8Scan_Floor1;
										u8Scan_Floor1=u8Scan_Floor4;
										u8Scan_Floor4=u8PisoAux;
									}
									else if(u8Current_Floor - u8Scan_Floor4 < u8Current_Floor - u8Scan_Floor2)
									{
										u8PisoAux=u8Scan_Floor2;
										u8Scan_Floor2=u8Scan_Floor4;
										u8Scan_Floor4=u8PisoAux;
									}
									else if(u8Current_Floor - u8Scan_Floor4 < u8Current_Floor - u8Scan_Floor3)
									{
										u8PisoAux=u8Scan_Floor3;
										u8Scan_Floor3=u8Scan_Floor4;
										u8Scan_Floor4=u8PisoAux;
									}
									else
										{
											//**Nothing to do**//
										}
								}
								else
								{
									printf("Eligio un piso ya seleccionado");
									u8Scan_Floor4=END_REQUEST;
								}
							}
							else
							{
								printf("\n\nNo puede haber más de 4 pisos elegidos a la vez, evite jugar con el ascensor\n\n");
							}

						}
						else 
						{
							u8NextRequest=END_REQUEST;
							printf("\n\nTodo listo\n\n");

							u8People_In-=u8People_Entering;

						}
					}


					if( u8Scan_Floor1!=NO_REQUEST_1	)
					{
						u8Current_Floor = u8Scan_Floor1;
						enCurrentState = u8Scan_Floor1;

						if(u8Current_Floor==0)
						{
							enCurrentState=enLobby;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==1)
						{
							enCurrentState=enPiso1;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==2)
						{
							enCurrentState=enPiso2;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==3)
						{
							enCurrentState=enPiso3;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==4)
						{
							enCurrentState=enPiso4;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==5)
						{
							enCurrentState=enPiso5;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==6)
						{
							enCurrentState=enPiso6;
							printf("main2Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==7)
						{
							enCurrentState=enPiso7;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==8)
						{
							enCurrentState=enPiso8;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==9)
						{
							enCurrentState=enPiso9;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==10)
						{
							enCurrentState=enPiso10;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else
						{
							//**Nothing to do**//
						}
					}

					if( u8Scan_Floor2!=NO_REQUEST_2	)
					{
						u8Current_Floor = u8Scan_Floor2;
						enCurrentState = u8Scan_Floor2;

						if(u8Current_Floor==0)
						{
							enCurrentState=enLobby;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==1)
						{
							enCurrentState=enPiso1;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==2)
						{
							enCurrentState=enPiso2;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==3)
						{
							enCurrentState=enPiso3;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==4)
						{
							enCurrentState=enPiso4;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==5)
						{
							enCurrentState=enPiso5;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==6)
						{
							enCurrentState=enPiso6;
							printf("main2Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==7)
						{
							enCurrentState=enPiso7;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==8)
						{
							enCurrentState=enPiso8;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==9)
						{
							enCurrentState=enPiso9;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==10)
						{
							enCurrentState=enPiso10;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else
						{
							//**Nothing to do**//
						}
					}

					if( u8Scan_Floor3!=NO_REQUEST_3	)
					{
						u8Current_Floor = u8Scan_Floor3;
						enCurrentState = u8Scan_Floor3;

						if(u8Current_Floor==0)
						{
							enCurrentState=enLobby;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==1)
						{
							enCurrentState=enPiso1;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==2)
						{
							enCurrentState=enPiso2;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==3)
						{
							enCurrentState=enPiso3;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==4)
						{
							enCurrentState=enPiso4;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==5)
						{
							enCurrentState=enPiso5;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==6)
						{
							enCurrentState=enPiso6;
							printf("main2Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==7)
						{
							enCurrentState=enPiso7;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==8)
						{
							enCurrentState=enPiso8;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==9)
						{
							enCurrentState=enPiso9;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==10)
						{
							enCurrentState=enPiso10;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else
						{
							//**Nothing to do**//
						}
					}

					if( u8Scan_Floor4!=NO_REQUEST_4	)
					{
						u8Current_Floor = u8Scan_Floor4;
						enCurrentState = u8Scan_Floor4;
						if(u8Current_Floor==0)
						{
							enCurrentState=enLobby;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==1)
						{
							enCurrentState=enPiso1;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==2)
						{
							enCurrentState=enPiso2;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==3)
						{
							enCurrentState=enPiso3;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==4)
						{
							enCurrentState=enPiso4;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==5)
						{
							enCurrentState=enPiso5;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==6)
						{
							enCurrentState=enPiso6;
							printf("main2Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==7)
						{
							enCurrentState=enPiso7;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==8)
						{
							enCurrentState=enPiso8;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==9)
						{
							enCurrentState=enPiso9;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==10)
						{
							enCurrentState=enPiso10;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else
						{
							//**Nothing to do**//
						}
					}

					else
					{
						printf("Terminaron los request");
					}
				}
				else
				{
					printf("Maximo numero de personas son %d, espere a que se desocupe\n",MAX_PEOPLE);
				}
				break;
			}

			case enPiso6:
			{
				u8NextRequest=1;
				printf("\n\nRequest Numero %d\n\n",u8NextRequest);
				printf("\nBuenas tardes, El elevador se encuentra en el piso %d ¿Cuantas personas quieren entrar?\n",enCurrentState);
				scanf("%d",&u8People_In);
				printf("¿A que piso desea ir? \n0)Lobby \n1)Piso 1 \n2)Piso 2 \n3)Piso 3 \n4)Piso 4 \n5)Piso 5 \n6)Piso 6 \n7)Piso 7 \n8)Piso 8 \n9)Piso 9 \n10)Piso 10\n");
				scanf("%d",&u8Scan_Floor1);	
				u8People_In+=u8People_Entering;	
				printf("\n%d\n", u8People_In);

				if( u8People_In+u8People_Entering < MAX_PEOPLE)
				{
					u8People_In+=u8People_Entering;

					while (u8NextRequest!=END_REQUEST)
					{	

						printf("\n\nEl elevador va hacia el piso %d, \n¿Desea ir a otro piso? \n1)Si \n2)No \n\n",u8Scan_Floor1);
						scanf("%d",&u8RequestState);

						if(u8RequestState==1)
						{
							if(u8NextRequest==1)
							{
								printf("¿A que piso desea ir? \n0)Lobby \n1)Piso 1 \n2)Piso 2 \n3)Piso 3 \n4)Piso 4 \n5)Piso 5 \n6)Piso 6 \n7)Piso 7 \n8)Piso 8 \n9)Piso 9 \n10)Piso 10\n");
								scanf("%d",&u8Scan_Floor2);

								if(u8Scan_Floor2!=u8Scan_Floor1 && u8Scan_Floor2!=u8Scan_Floor3 && u8Scan_Floor2!=u8Scan_Floor4)
								{
									printf("Eligio el piso %d",u8Scan_Floor2);
									u8NextRequest+=1;

									if(u8Current_Floor - u8Scan_Floor2 < u8Current_Floor - u8Scan_Floor1)
									{
										u8PisoAux=u8Scan_Floor1;
										u8Scan_Floor1=u8Scan_Floor2;
										u8Scan_Floor2=u8PisoAux;
									}
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

								if(u8Scan_Floor3!=u8Scan_Floor1 && u8Scan_Floor3!=u8Scan_Floor2 && u8Scan_Floor3!=u8Scan_Floor4)
								{
									printf("Eligio el piso %d",u8Scan_Floor3);
									u8NextRequest+=1;

									if(u8Current_Floor - u8Scan_Floor3 < u8Current_Floor - u8Scan_Floor1)
									{
										u8PisoAux=u8Scan_Floor1;
										u8Scan_Floor1=u8Scan_Floor3;
										u8Scan_Floor3=u8PisoAux;
									}
									else if(u8Current_Floor - u8Scan_Floor3 < u8Current_Floor - u8Scan_Floor2)
									{
										u8PisoAux=u8Scan_Floor2;
										u8Scan_Floor2=u8Scan_Floor3;
										u8Scan_Floor3=u8PisoAux;
									}

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

								if(u8Scan_Floor4!=u8Scan_Floor1 && u8Scan_Floor4!=u8Scan_Floor3 && u8Scan_Floor4!=u8Scan_Floor2)
								{
									printf("Eligio el piso %d",u8Scan_Floor4);
									u8NextRequest+=1;

									if(u8Current_Floor - u8Scan_Floor4 < u8Current_Floor - u8Scan_Floor1)
									{
										u8PisoAux=u8Scan_Floor1;
										u8Scan_Floor1=u8Scan_Floor4;
										u8Scan_Floor4=u8PisoAux;
									}
									else if(u8Current_Floor - u8Scan_Floor4 < u8Current_Floor - u8Scan_Floor2)
									{
										u8PisoAux=u8Scan_Floor2;
										u8Scan_Floor2=u8Scan_Floor4;
										u8Scan_Floor4=u8PisoAux;
									}
									else if(u8Current_Floor - u8Scan_Floor4 < u8Current_Floor - u8Scan_Floor3)
									{
										u8PisoAux=u8Scan_Floor3;
										u8Scan_Floor3=u8Scan_Floor4;
										u8Scan_Floor4=u8PisoAux;
									}
									else
										{
											//**Nothing to do**//
										}
								}
								else
								{
									printf("Eligio un piso ya seleccionado");
									u8Scan_Floor4=END_REQUEST;
								}
							}
							else
							{
								printf("\n\nNo puede haber más de 4 pisos elegidos a la vez, evite jugar con el ascensor\n\n");
							}

						}
						else 
						{
							u8NextRequest=END_REQUEST;
							printf("\n\nTodo listo\n\n");

							u8People_In-=u8People_Entering;

						}
					}


					if( u8Scan_Floor1!=NO_REQUEST_1	)
					{
						u8Current_Floor = u8Scan_Floor1;
						enCurrentState = u8Scan_Floor1;

						if(u8Current_Floor==0)
						{
							enCurrentState=enLobby;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==1)
						{
							enCurrentState=enPiso1;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==2)
						{
							enCurrentState=enPiso2;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==3)
						{
							enCurrentState=enPiso3;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==4)
						{
							enCurrentState=enPiso4;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==5)
						{
							enCurrentState=enPiso5;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==6)
						{
							enCurrentState=enPiso6;
							printf("main2Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==7)
						{
							enCurrentState=enPiso7;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==8)
						{
							enCurrentState=enPiso8;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==9)
						{
							enCurrentState=enPiso9;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==10)
						{
							enCurrentState=enPiso10;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else
						{
							//**Nothing to do**//
						}
					}

					if( u8Scan_Floor2!=NO_REQUEST_2	)
					{
						u8Current_Floor = u8Scan_Floor2;
						enCurrentState = u8Scan_Floor2;

						if(u8Current_Floor==0)
						{
							enCurrentState=enLobby;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==1)
						{
							enCurrentState=enPiso1;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==2)
						{
							enCurrentState=enPiso2;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==3)
						{
							enCurrentState=enPiso3;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==4)
						{
							enCurrentState=enPiso4;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==5)
						{
							enCurrentState=enPiso5;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==6)
						{
							enCurrentState=enPiso6;
							printf("main2Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==7)
						{
							enCurrentState=enPiso7;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==8)
						{
							enCurrentState=enPiso8;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==9)
						{
							enCurrentState=enPiso9;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==10)
						{
							enCurrentState=enPiso10;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else
						{
							//**Nothing to do**//
						}
					}

					if( u8Scan_Floor3!=NO_REQUEST_3	)
					{
						u8Current_Floor = u8Scan_Floor3;
						enCurrentState = u8Scan_Floor3;

						if(u8Current_Floor==0)
						{
							enCurrentState=enLobby;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==1)
						{
							enCurrentState=enPiso1;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==2)
						{
							enCurrentState=enPiso2;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==3)
						{
							enCurrentState=enPiso3;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==4)
						{
							enCurrentState=enPiso4;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==5)
						{
							enCurrentState=enPiso5;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==6)
						{
							enCurrentState=enPiso6;
							printf("main2Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==7)
						{
							enCurrentState=enPiso7;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==8)
						{
							enCurrentState=enPiso8;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==9)
						{
							enCurrentState=enPiso9;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==10)
						{
							enCurrentState=enPiso10;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else
						{
							//**Nothing to do**//
						}
					}

					if( u8Scan_Floor4!=NO_REQUEST_4	)
					{
						u8Current_Floor = u8Scan_Floor4;
						enCurrentState = u8Scan_Floor4;
						if(u8Current_Floor==0)
						{
							enCurrentState=enLobby;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==1)
						{
							enCurrentState=enPiso1;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==2)
						{
							enCurrentState=enPiso2;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==3)
						{
							enCurrentState=enPiso3;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==4)
						{
							enCurrentState=enPiso4;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==5)
						{
							enCurrentState=enPiso5;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==6)
						{
							enCurrentState=enPiso6;
							printf("main2Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==7)
						{
							enCurrentState=enPiso7;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==8)
						{
							enCurrentState=enPiso8;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==9)
						{
							enCurrentState=enPiso9;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==10)
						{
							enCurrentState=enPiso10;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else
						{
							//**Nothing to do**//
						}
					}

					else
					{
						printf("Terminaron los request");
					}
				}
				else
				{
					printf("Maximo numero de personas son %d, espere a que se desocupe\n",MAX_PEOPLE);
				}
				break;
			}

			case enPiso7:
			{
				u8NextRequest=1;
				printf("\n\nRequest Numero %d\n\n",u8NextRequest);
				printf("\nBuenas tardes, El elevador se encuentra en el piso %d ¿Cuantas personas quieren entrar?\n",enCurrentState);
				scanf("%d",&u8People_In);
				printf("¿A que piso desea ir? \n0)Lobby \n1)Piso 1 \n2)Piso 2 \n3)Piso 3 \n4)Piso 4 \n5)Piso 5 \n6)Piso 6 \n7)Piso 7 \n8)Piso 8 \n9)Piso 9 \n10)Piso 10\n");
				scanf("%d",&u8Scan_Floor1);	
				u8People_In+=u8People_Entering;	
				printf("\n%d\n", u8People_In);

				if( u8People_In+u8People_Entering < MAX_PEOPLE)
				{
					u8People_In+=u8People_Entering;

					while (u8NextRequest!=END_REQUEST)
					{	

						printf("\n\nEl elevador va hacia el piso %d, \n¿Desea ir a otro piso? \n1)Si \n2)No \n\n",u8Scan_Floor1);
						scanf("%d",&u8RequestState);

						if(u8RequestState==1)
						{
							if(u8NextRequest==1)
							{
								printf("¿A que piso desea ir? \n0)Lobby \n1)Piso 1 \n2)Piso 2 \n3)Piso 3 \n4)Piso 4 \n5)Piso 5 \n6)Piso 6 \n7)Piso 7 \n8)Piso 8 \n9)Piso 9 \n10)Piso 10\n");
								scanf("%d",&u8Scan_Floor2);

								if(u8Scan_Floor2!=u8Scan_Floor1 && u8Scan_Floor2!=u8Scan_Floor3 && u8Scan_Floor2!=u8Scan_Floor4)
								{
									printf("Eligio el piso %d",u8Scan_Floor2);
									u8NextRequest+=1;

									if(u8Current_Floor - u8Scan_Floor2 < u8Current_Floor - u8Scan_Floor1)
									{
										u8PisoAux=u8Scan_Floor1;
										u8Scan_Floor1=u8Scan_Floor2;
										u8Scan_Floor2=u8PisoAux;
									}
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

								if(u8Scan_Floor3!=u8Scan_Floor1 && u8Scan_Floor3!=u8Scan_Floor2 && u8Scan_Floor3!=u8Scan_Floor4)
								{
									printf("Eligio el piso %d",u8Scan_Floor3);
									u8NextRequest+=1;

									if(u8Current_Floor - u8Scan_Floor3 < u8Current_Floor - u8Scan_Floor1)
									{
										u8PisoAux=u8Scan_Floor1;
										u8Scan_Floor1=u8Scan_Floor3;
										u8Scan_Floor3=u8PisoAux;
									}
									else if(u8Current_Floor - u8Scan_Floor3 < u8Current_Floor - u8Scan_Floor2)
									{
										u8PisoAux=u8Scan_Floor2;
										u8Scan_Floor2=u8Scan_Floor3;
										u8Scan_Floor3=u8PisoAux;
									}

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

								if(u8Scan_Floor4!=u8Scan_Floor1 && u8Scan_Floor4!=u8Scan_Floor3 && u8Scan_Floor4!=u8Scan_Floor2)
								{
									printf("Eligio el piso %d",u8Scan_Floor4);
									u8NextRequest+=1;

									if(u8Current_Floor - u8Scan_Floor4 < u8Current_Floor - u8Scan_Floor1)
									{
										u8PisoAux=u8Scan_Floor1;
										u8Scan_Floor1=u8Scan_Floor4;
										u8Scan_Floor4=u8PisoAux;
									}
									else if(u8Current_Floor - u8Scan_Floor4 < u8Current_Floor - u8Scan_Floor2)
									{
										u8PisoAux=u8Scan_Floor2;
										u8Scan_Floor2=u8Scan_Floor4;
										u8Scan_Floor4=u8PisoAux;
									}
									else if(u8Current_Floor - u8Scan_Floor4 < u8Current_Floor - u8Scan_Floor3)
									{
										u8PisoAux=u8Scan_Floor3;
										u8Scan_Floor3=u8Scan_Floor4;
										u8Scan_Floor4=u8PisoAux;
									}
									else
										{
											//**Nothing to do**//
										}
								}
								else
								{
									printf("Eligio un piso ya seleccionado");
									u8Scan_Floor4=END_REQUEST;
								}
							}
							else
							{
								printf("\n\nNo puede haber más de 4 pisos elegidos a la vez, evite jugar con el ascensor\n\n");
							}

						}
						else 
						{
							u8NextRequest=END_REQUEST;
							printf("\n\nTodo listo\n\n");

							u8People_In-=u8People_Entering;

						}
					}


					if( u8Scan_Floor1!=NO_REQUEST_1	)
					{
						u8Current_Floor = u8Scan_Floor1;
						enCurrentState = u8Scan_Floor1;

						if(u8Current_Floor==0)
						{
							enCurrentState=enLobby;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==1)
						{
							enCurrentState=enPiso1;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==2)
						{
							enCurrentState=enPiso2;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==3)
						{
							enCurrentState=enPiso3;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==4)
						{
							enCurrentState=enPiso4;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==5)
						{
							enCurrentState=enPiso5;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==6)
						{
							enCurrentState=enPiso6;
							printf("main2Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==7)
						{
							enCurrentState=enPiso7;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==8)
						{
							enCurrentState=enPiso8;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==9)
						{
							enCurrentState=enPiso9;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==10)
						{
							enCurrentState=enPiso10;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else
						{
							//**Nothing to do**//
						}
					}

					if( u8Scan_Floor2!=NO_REQUEST_2	)
					{
						u8Current_Floor = u8Scan_Floor2;
						enCurrentState = u8Scan_Floor2;

						if(u8Current_Floor==0)
						{
							enCurrentState=enLobby;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==1)
						{
							enCurrentState=enPiso1;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==2)
						{
							enCurrentState=enPiso2;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==3)
						{
							enCurrentState=enPiso3;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==4)
						{
							enCurrentState=enPiso4;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==5)
						{
							enCurrentState=enPiso5;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==6)
						{
							enCurrentState=enPiso6;
							printf("main2Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==7)
						{
							enCurrentState=enPiso7;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==8)
						{
							enCurrentState=enPiso8;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==9)
						{
							enCurrentState=enPiso9;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==10)
						{
							enCurrentState=enPiso10;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else
						{
							//**Nothing to do**//
						}
					}

					if( u8Scan_Floor3!=NO_REQUEST_3	)
					{
						u8Current_Floor = u8Scan_Floor3;
						enCurrentState = u8Scan_Floor3;

						if(u8Current_Floor==0)
						{
							enCurrentState=enLobby;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==1)
						{
							enCurrentState=enPiso1;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==2)
						{
							enCurrentState=enPiso2;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==3)
						{
							enCurrentState=enPiso3;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==4)
						{
							enCurrentState=enPiso4;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==5)
						{
							enCurrentState=enPiso5;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==6)
						{
							enCurrentState=enPiso6;
							printf("main2Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==7)
						{
							enCurrentState=enPiso7;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==8)
						{
							enCurrentState=enPiso8;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==9)
						{
							enCurrentState=enPiso9;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==10)
						{
							enCurrentState=enPiso10;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else
						{
							//**Nothing to do**//
						}
					}

					if( u8Scan_Floor4!=NO_REQUEST_4	)
					{
						u8Current_Floor = u8Scan_Floor4;
						enCurrentState = u8Scan_Floor4;
						if(u8Current_Floor==0)
						{
							enCurrentState=enLobby;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==1)
						{
							enCurrentState=enPiso1;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==2)
						{
							enCurrentState=enPiso2;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==3)
						{
							enCurrentState=enPiso3;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==4)
						{
							enCurrentState=enPiso4;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==5)
						{
							enCurrentState=enPiso5;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==6)
						{
							enCurrentState=enPiso6;
							printf("main2Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==7)
						{
							enCurrentState=enPiso7;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==8)
						{
							enCurrentState=enPiso8;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==9)
						{
							enCurrentState=enPiso9;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==10)
						{
							enCurrentState=enPiso10;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else
						{
							//**Nothing to do**//
						}
					}

					else
					{
						printf("Terminaron los request");
					}
				}
				else
				{
					printf("Maximo numero de personas son %d, espere a que se desocupe\n",MAX_PEOPLE);
				}
				break;
			}

			case enPiso8:
			{
				u8NextRequest=1;
				printf("\n\nRequest Numero %d\n\n",u8NextRequest);
				printf("\nBuenas tardes, El elevador se encuentra en el piso %d ¿Cuantas personas quieren entrar?\n",enCurrentState);
				scanf("%d",&u8People_In);
				printf("¿A que piso desea ir? \n0)Lobby \n1)Piso 1 \n2)Piso 2 \n3)Piso 3 \n4)Piso 4 \n5)Piso 5 \n6)Piso 6 \n7)Piso 7 \n8)Piso 8 \n9)Piso 9 \n10)Piso 10\n");
				scanf("%d",&u8Scan_Floor1);	
				u8People_In+=u8People_Entering;	
				printf("\n%d\n", u8People_In);

				if( u8People_In+u8People_Entering < MAX_PEOPLE)
				{
					u8People_In+=u8People_Entering;

					while (u8NextRequest!=END_REQUEST)
					{	

						printf("\n\nEl elevador va hacia el piso %d, \n¿Desea ir a otro piso? \n1)Si \n2)No \n\n",u8Scan_Floor1);
						scanf("%d",&u8RequestState);

						if(u8RequestState==1)
						{
							if(u8NextRequest==1)
							{
								printf("¿A que piso desea ir? \n0)Lobby \n1)Piso 1 \n2)Piso 2 \n3)Piso 3 \n4)Piso 4 \n5)Piso 5 \n6)Piso 6 \n7)Piso 7 \n8)Piso 8 \n9)Piso 9 \n10)Piso 10\n");
								scanf("%d",&u8Scan_Floor2);

								if(u8Scan_Floor2!=u8Scan_Floor1 && u8Scan_Floor2!=u8Scan_Floor3 && u8Scan_Floor2!=u8Scan_Floor4)
								{
									printf("Eligio el piso %d",u8Scan_Floor2);
									u8NextRequest+=1;

									if(u8Current_Floor - u8Scan_Floor2 < u8Current_Floor - u8Scan_Floor1)
									{
										u8PisoAux=u8Scan_Floor1;
										u8Scan_Floor1=u8Scan_Floor2;
										u8Scan_Floor2=u8PisoAux;
									}
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

								if(u8Scan_Floor3!=u8Scan_Floor1 && u8Scan_Floor3!=u8Scan_Floor2 && u8Scan_Floor3!=u8Scan_Floor4)
								{
									printf("Eligio el piso %d",u8Scan_Floor3);
									u8NextRequest+=1;

									if(u8Current_Floor - u8Scan_Floor3 < u8Current_Floor - u8Scan_Floor1)
									{
										u8PisoAux=u8Scan_Floor1;
										u8Scan_Floor1=u8Scan_Floor3;
										u8Scan_Floor3=u8PisoAux;
									}
									else if(u8Current_Floor - u8Scan_Floor3 < u8Current_Floor - u8Scan_Floor2)
									{
										u8PisoAux=u8Scan_Floor2;
										u8Scan_Floor2=u8Scan_Floor3;
										u8Scan_Floor3=u8PisoAux;
									}

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

								if(u8Scan_Floor4!=u8Scan_Floor1 && u8Scan_Floor4!=u8Scan_Floor3 && u8Scan_Floor4!=u8Scan_Floor2)
								{
									printf("Eligio el piso %d",u8Scan_Floor4);
									u8NextRequest+=1;

									if(u8Current_Floor - u8Scan_Floor4 < u8Current_Floor - u8Scan_Floor1)
									{
										u8PisoAux=u8Scan_Floor1;
										u8Scan_Floor1=u8Scan_Floor4;
										u8Scan_Floor4=u8PisoAux;
									}
									else if(u8Current_Floor - u8Scan_Floor4 < u8Current_Floor - u8Scan_Floor2)
									{
										u8PisoAux=u8Scan_Floor2;
										u8Scan_Floor2=u8Scan_Floor4;
										u8Scan_Floor4=u8PisoAux;
									}
									else if(u8Current_Floor - u8Scan_Floor4 < u8Current_Floor - u8Scan_Floor3)
									{
										u8PisoAux=u8Scan_Floor3;
										u8Scan_Floor3=u8Scan_Floor4;
										u8Scan_Floor4=u8PisoAux;
									}
									else
										{
											//**Nothing to do**//
										}
								}
								else
								{
									printf("Eligio un piso ya seleccionado");
									u8Scan_Floor4=END_REQUEST;
								}
							}
							else
							{
								printf("\n\nNo puede haber más de 4 pisos elegidos a la vez, evite jugar con el ascensor\n\n");
							}

						}
						else 
						{
							u8NextRequest=END_REQUEST;
							printf("\n\nTodo listo\n\n");

							u8People_In-=u8People_Entering;

						}
					}


					if( u8Scan_Floor1!=NO_REQUEST_1	)
					{
						u8Current_Floor = u8Scan_Floor1;
						enCurrentState = u8Scan_Floor1;

						if(u8Current_Floor==0)
						{
							enCurrentState=enLobby;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==1)
						{
							enCurrentState=enPiso1;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==2)
						{
							enCurrentState=enPiso2;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==3)
						{
							enCurrentState=enPiso3;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==4)
						{
							enCurrentState=enPiso4;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==5)
						{
							enCurrentState=enPiso5;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==6)
						{
							enCurrentState=enPiso6;
							printf("main2Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==7)
						{
							enCurrentState=enPiso7;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==8)
						{
							enCurrentState=enPiso8;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==9)
						{
							enCurrentState=enPiso9;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==10)
						{
							enCurrentState=enPiso10;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else
						{
							//**Nothing to do**//
						}
					}

					if( u8Scan_Floor2!=NO_REQUEST_2	)
					{
						u8Current_Floor = u8Scan_Floor2;
						enCurrentState = u8Scan_Floor2;

						if(u8Current_Floor==0)
						{
							enCurrentState=enLobby;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==1)
						{
							enCurrentState=enPiso1;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==2)
						{
							enCurrentState=enPiso2;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==3)
						{
							enCurrentState=enPiso3;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==4)
						{
							enCurrentState=enPiso4;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==5)
						{
							enCurrentState=enPiso5;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==6)
						{
							enCurrentState=enPiso6;
							printf("main2Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==7)
						{
							enCurrentState=enPiso7;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==8)
						{
							enCurrentState=enPiso8;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==9)
						{
							enCurrentState=enPiso9;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==10)
						{
							enCurrentState=enPiso10;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else
						{
							//**Nothing to do**//
						}
					}

					if( u8Scan_Floor3!=NO_REQUEST_3	)
					{
						u8Current_Floor = u8Scan_Floor3;
						enCurrentState = u8Scan_Floor3;

						if(u8Current_Floor==0)
						{
							enCurrentState=enLobby;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==1)
						{
							enCurrentState=enPiso1;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==2)
						{
							enCurrentState=enPiso2;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==3)
						{
							enCurrentState=enPiso3;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==4)
						{
							enCurrentState=enPiso4;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==5)
						{
							enCurrentState=enPiso5;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==6)
						{
							enCurrentState=enPiso6;
							printf("main2Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==7)
						{
							enCurrentState=enPiso7;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==8)
						{
							enCurrentState=enPiso8;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==9)
						{
							enCurrentState=enPiso9;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==10)
						{
							enCurrentState=enPiso10;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else
						{
							//**Nothing to do**//
						}
					}

					if( u8Scan_Floor4!=NO_REQUEST_4	)
					{
						u8Current_Floor = u8Scan_Floor4;
						enCurrentState = u8Scan_Floor4;
						if(u8Current_Floor==0)
						{
							enCurrentState=enLobby;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==1)
						{
							enCurrentState=enPiso1;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==2)
						{
							enCurrentState=enPiso2;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==3)
						{
							enCurrentState=enPiso3;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==4)
						{
							enCurrentState=enPiso4;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==5)
						{
							enCurrentState=enPiso5;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==6)
						{
							enCurrentState=enPiso6;
							printf("main2Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==7)
						{
							enCurrentState=enPiso7;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==8)
						{
							enCurrentState=enPiso8;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==9)
						{
							enCurrentState=enPiso9;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==10)
						{
							enCurrentState=enPiso10;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else
						{
							//**Nothing to do**//
						}
					}

					else
					{
						printf("Terminaron los request");
					}
				}
				else
				{
					printf("Maximo numero de personas son %d, espere a que se desocupe\n",MAX_PEOPLE);
				}
				break;
			}

			case enPiso9:
			{
				u8NextRequest=1;
				printf("\n\nRequest Numero %d\n\n",u8NextRequest);
				printf("\nBuenas tardes, El elevador se encuentra en el piso %d ¿Cuantas personas quieren entrar?\n",enCurrentState);
				scanf("%d",&u8People_In);
				printf("¿A que piso desea ir? \n0)Lobby \n1)Piso 1 \n2)Piso 2 \n3)Piso 3 \n4)Piso 4 \n5)Piso 5 \n6)Piso 6 \n7)Piso 7 \n8)Piso 8 \n9)Piso 9 \n10)Piso 10\n");
				scanf("%d",&u8Scan_Floor1);	
				u8People_In+=u8People_Entering;	
				printf("\n%d\n", u8People_In);

				if( u8People_In+u8People_Entering < MAX_PEOPLE)
				{
					u8People_In+=u8People_Entering;

					while (u8NextRequest!=END_REQUEST)
					{	

						printf("\n\nEl elevador va hacia el piso %d, \n¿Desea ir a otro piso? \n1)Si \n2)No \n\n",u8Scan_Floor1);
						scanf("%d",&u8RequestState);

						if(u8RequestState==1)
						{
							if(u8NextRequest==1)
							{
								printf("¿A que piso desea ir? \n0)Lobby \n1)Piso 1 \n2)Piso 2 \n3)Piso 3 \n4)Piso 4 \n5)Piso 5 \n6)Piso 6 \n7)Piso 7 \n8)Piso 8 \n9)Piso 9 \n10)Piso 10\n");
								scanf("%d",&u8Scan_Floor2);

								if(u8Scan_Floor2!=u8Scan_Floor1 && u8Scan_Floor2!=u8Scan_Floor3 && u8Scan_Floor2!=u8Scan_Floor4)
								{
									printf("Eligio el piso %d",u8Scan_Floor2);
									u8NextRequest+=1;

									if(u8Current_Floor - u8Scan_Floor2 < u8Current_Floor - u8Scan_Floor1)
									{
										u8PisoAux=u8Scan_Floor1;
										u8Scan_Floor1=u8Scan_Floor2;
										u8Scan_Floor2=u8PisoAux;
									}
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

								if(u8Scan_Floor3!=u8Scan_Floor1 && u8Scan_Floor3!=u8Scan_Floor2 && u8Scan_Floor3!=u8Scan_Floor4)
								{
									printf("Eligio el piso %d",u8Scan_Floor3);
									u8NextRequest+=1;

									if(u8Current_Floor - u8Scan_Floor3 < u8Current_Floor - u8Scan_Floor1)
									{
										u8PisoAux=u8Scan_Floor1;
										u8Scan_Floor1=u8Scan_Floor3;
										u8Scan_Floor3=u8PisoAux;
									}
									else if(u8Current_Floor - u8Scan_Floor3 < u8Current_Floor - u8Scan_Floor2)
									{
										u8PisoAux=u8Scan_Floor2;
										u8Scan_Floor2=u8Scan_Floor3;
										u8Scan_Floor3=u8PisoAux;
									}

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

								if(u8Scan_Floor4!=u8Scan_Floor1 && u8Scan_Floor4!=u8Scan_Floor3 && u8Scan_Floor4!=u8Scan_Floor2)
								{
									printf("Eligio el piso %d",u8Scan_Floor4);
									u8NextRequest+=1;

									if(u8Current_Floor - u8Scan_Floor4 < u8Current_Floor - u8Scan_Floor1)
									{
										u8PisoAux=u8Scan_Floor1;
										u8Scan_Floor1=u8Scan_Floor4;
										u8Scan_Floor4=u8PisoAux;
									}
									else if(u8Current_Floor - u8Scan_Floor4 < u8Current_Floor - u8Scan_Floor2)
									{
										u8PisoAux=u8Scan_Floor2;
										u8Scan_Floor2=u8Scan_Floor4;
										u8Scan_Floor4=u8PisoAux;
									}
									else if(u8Current_Floor - u8Scan_Floor4 < u8Current_Floor - u8Scan_Floor3)
									{
										u8PisoAux=u8Scan_Floor3;
										u8Scan_Floor3=u8Scan_Floor4;
										u8Scan_Floor4=u8PisoAux;
									}
									else
										{
											//**Nothing to do**//
										}
								}
								else
								{
									printf("Eligio un piso ya seleccionado");
									u8Scan_Floor4=END_REQUEST;
								}
							}
							else
							{
								printf("\n\nNo puede haber más de 4 pisos elegidos a la vez, evite jugar con el ascensor\n\n");
							}

						}
						else 
						{
							u8NextRequest=END_REQUEST;
							printf("\n\nTodo listo\n\n");

							u8People_In-=u8People_Entering;

						}
					}


					if( u8Scan_Floor1!=NO_REQUEST_1	)
					{
						u8Current_Floor = u8Scan_Floor1;
						enCurrentState = u8Scan_Floor1;

						if(u8Current_Floor==0)
						{
							enCurrentState=enLobby;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==1)
						{
							enCurrentState=enPiso1;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==2)
						{
							enCurrentState=enPiso2;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==3)
						{
							enCurrentState=enPiso3;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==4)
						{
							enCurrentState=enPiso4;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==5)
						{
							enCurrentState=enPiso5;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==6)
						{
							enCurrentState=enPiso6;
							printf("main2Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==7)
						{
							enCurrentState=enPiso7;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==8)
						{
							enCurrentState=enPiso8;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==9)
						{
							enCurrentState=enPiso9;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==10)
						{
							enCurrentState=enPiso10;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else
						{
							//**Nothing to do**//
						}
					}

					if( u8Scan_Floor2!=NO_REQUEST_2	)
					{
						u8Current_Floor = u8Scan_Floor2;
						enCurrentState = u8Scan_Floor2;

						if(u8Current_Floor==0)
						{
							enCurrentState=enLobby;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==1)
						{
							enCurrentState=enPiso1;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==2)
						{
							enCurrentState=enPiso2;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==3)
						{
							enCurrentState=enPiso3;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==4)
						{
							enCurrentState=enPiso4;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==5)
						{
							enCurrentState=enPiso5;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==6)
						{
							enCurrentState=enPiso6;
							printf("main2Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==7)
						{
							enCurrentState=enPiso7;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==8)
						{
							enCurrentState=enPiso8;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==9)
						{
							enCurrentState=enPiso9;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==10)
						{
							enCurrentState=enPiso10;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else
						{
							//**Nothing to do**//
						}
					}

					if( u8Scan_Floor3!=NO_REQUEST_3	)
					{
						u8Current_Floor = u8Scan_Floor3;
						enCurrentState = u8Scan_Floor3;

						if(u8Current_Floor==0)
						{
							enCurrentState=enLobby;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==1)
						{
							enCurrentState=enPiso1;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==2)
						{
							enCurrentState=enPiso2;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==3)
						{
							enCurrentState=enPiso3;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==4)
						{
							enCurrentState=enPiso4;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==5)
						{
							enCurrentState=enPiso5;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==6)
						{
							enCurrentState=enPiso6;
							printf("main2Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==7)
						{
							enCurrentState=enPiso7;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==8)
						{
							enCurrentState=enPiso8;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==9)
						{
							enCurrentState=enPiso9;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==10)
						{
							enCurrentState=enPiso10;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else
						{
							//**Nothing to do**//
						}
					}

					if( u8Scan_Floor4!=NO_REQUEST_4	)
					{
						u8Current_Floor = u8Scan_Floor4;
						enCurrentState = u8Scan_Floor4;
						if(u8Current_Floor==0)
						{
							enCurrentState=enLobby;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==1)
						{
							enCurrentState=enPiso1;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==2)
						{
							enCurrentState=enPiso2;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==3)
						{
							enCurrentState=enPiso3;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==4)
						{
							enCurrentState=enPiso4;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==5)
						{
							enCurrentState=enPiso5;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==6)
						{
							enCurrentState=enPiso6;
							printf("main2Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==7)
						{
							enCurrentState=enPiso7;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==8)
						{
							enCurrentState=enPiso8;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==9)
						{
							enCurrentState=enPiso9;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==10)
						{
							enCurrentState=enPiso10;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else
						{
							//**Nothing to do**//
						}
					}

					else
					{
						printf("Terminaron los request");
					}
				}
				else
				{
					printf("Maximo numero de personas son %d, espere a que se desocupe\n",MAX_PEOPLE);
				}
				break;
			}

			case enPiso10:
			{
				u8NextRequest=1;
				printf("\n\nRequest Numero %d\n\n",u8NextRequest);
				printf("\nBuenas tardes, El elevador se encuentra en el piso %d ¿Cuantas personas quieren entrar?\n",enCurrentState);
				scanf("%d",&u8People_In);
				printf("¿A que piso desea ir? \n0)Lobby \n1)Piso 1 \n2)Piso 2 \n3)Piso 3 \n4)Piso 4 \n5)Piso 5 \n6)Piso 6 \n7)Piso 7 \n8)Piso 8 \n9)Piso 9 \n10)Piso 10\n");
				scanf("%d",&u8Scan_Floor1);	
				u8People_In+=u8People_Entering;	
				printf("\n%d\n", u8People_In);

				if( u8People_In+u8People_Entering < MAX_PEOPLE)
				{
					u8People_In+=u8People_Entering;

					while (u8NextRequest!=END_REQUEST)
					{	

						printf("\n\nEl elevador va hacia el piso %d, \n¿Desea ir a otro piso? \n1)Si \n2)No \n\n",u8Scan_Floor1);
						scanf("%d",&u8RequestState);

						if(u8RequestState==1)
						{
							if(u8NextRequest==1)
							{
								printf("¿A que piso desea ir? \n0)Lobby \n1)Piso 1 \n2)Piso 2 \n3)Piso 3 \n4)Piso 4 \n5)Piso 5 \n6)Piso 6 \n7)Piso 7 \n8)Piso 8 \n9)Piso 9 \n10)Piso 10\n");
								scanf("%d",&u8Scan_Floor2);

								if(u8Scan_Floor2!=u8Scan_Floor1 && u8Scan_Floor2!=u8Scan_Floor3 && u8Scan_Floor2!=u8Scan_Floor4)
								{
									printf("Eligio el piso %d",u8Scan_Floor2);
									u8NextRequest+=1;

									if(u8Current_Floor - u8Scan_Floor2 < u8Current_Floor - u8Scan_Floor1)
									{
										u8PisoAux=u8Scan_Floor1;
										u8Scan_Floor1=u8Scan_Floor2;
										u8Scan_Floor2=u8PisoAux;
									}
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

								if(u8Scan_Floor3!=u8Scan_Floor1 && u8Scan_Floor3!=u8Scan_Floor2 && u8Scan_Floor3!=u8Scan_Floor4)
								{
									printf("Eligio el piso %d",u8Scan_Floor3);
									u8NextRequest+=1;

									if(u8Current_Floor - u8Scan_Floor3 < u8Current_Floor - u8Scan_Floor1)
									{
										u8PisoAux=u8Scan_Floor1;
										u8Scan_Floor1=u8Scan_Floor3;
										u8Scan_Floor3=u8PisoAux;
									}
									else if(u8Current_Floor - u8Scan_Floor3 < u8Current_Floor - u8Scan_Floor2)
									{
										u8PisoAux=u8Scan_Floor2;
										u8Scan_Floor2=u8Scan_Floor3;
										u8Scan_Floor3=u8PisoAux;
									}

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

								if(u8Scan_Floor4!=u8Scan_Floor1 && u8Scan_Floor4!=u8Scan_Floor3 && u8Scan_Floor4!=u8Scan_Floor2)
								{
									printf("Eligio el piso %d",u8Scan_Floor4);
									u8NextRequest+=1;

									if(u8Current_Floor - u8Scan_Floor4 < u8Current_Floor - u8Scan_Floor1)
									{
										u8PisoAux=u8Scan_Floor1;
										u8Scan_Floor1=u8Scan_Floor4;
										u8Scan_Floor4=u8PisoAux;
									}
									else if(u8Current_Floor - u8Scan_Floor4 < u8Current_Floor - u8Scan_Floor2)
									{
										u8PisoAux=u8Scan_Floor2;
										u8Scan_Floor2=u8Scan_Floor4;
										u8Scan_Floor4=u8PisoAux;
									}
									else if(u8Current_Floor - u8Scan_Floor4 < u8Current_Floor - u8Scan_Floor3)
									{
										u8PisoAux=u8Scan_Floor3;
										u8Scan_Floor3=u8Scan_Floor4;
										u8Scan_Floor4=u8PisoAux;
									}
									else
										{
											//**Nothing to do**//
										}
								}
								else
								{
									printf("Eligio un piso ya seleccionado");
									u8Scan_Floor4=END_REQUEST;
								}
							}
							else
							{
								printf("\n\nNo puede haber más de 4 pisos elegidos a la vez, evite jugar con el ascensor\n\n");
							}

						}
						else 
						{
							u8NextRequest=END_REQUEST;
							printf("\n\nTodo listo\n\n");

							u8People_In-=u8People_Entering;

						}
					}


					if( u8Scan_Floor1!=NO_REQUEST_1	)
					{
						u8Current_Floor = u8Scan_Floor1;
						enCurrentState = u8Scan_Floor1;

						if(u8Current_Floor==0)
						{
							enCurrentState=enLobby;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==1)
						{
							enCurrentState=enPiso1;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==2)
						{
							enCurrentState=enPiso2;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==3)
						{
							enCurrentState=enPiso3;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==4)
						{
							enCurrentState=enPiso4;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==5)
						{
							enCurrentState=enPiso5;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==6)
						{
							enCurrentState=enPiso6;
							printf("main2Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==7)
						{
							enCurrentState=enPiso7;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==8)
						{
							enCurrentState=enPiso8;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==9)
						{
							enCurrentState=enPiso9;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==10)
						{
							enCurrentState=enPiso10;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else
						{
							//**Nothing to do**//
						}
					}

					if( u8Scan_Floor2!=NO_REQUEST_2	)
					{
						u8Current_Floor = u8Scan_Floor2;
						enCurrentState = u8Scan_Floor2;

						if(u8Current_Floor==0)
						{
							enCurrentState=enLobby;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==1)
						{
							enCurrentState=enPiso1;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==2)
						{
							enCurrentState=enPiso2;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==3)
						{
							enCurrentState=enPiso3;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==4)
						{
							enCurrentState=enPiso4;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==5)
						{
							enCurrentState=enPiso5;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==6)
						{
							enCurrentState=enPiso6;
							printf("main2Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==7)
						{
							enCurrentState=enPiso7;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==8)
						{
							enCurrentState=enPiso8;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==9)
						{
							enCurrentState=enPiso9;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==10)
						{
							enCurrentState=enPiso10;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else
						{
							//**Nothing to do**//
						}
					}

					if( u8Scan_Floor3!=NO_REQUEST_3	)
					{
						u8Current_Floor = u8Scan_Floor3;
						enCurrentState = u8Scan_Floor3;

						if(u8Current_Floor==0)
						{
							enCurrentState=enLobby;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==1)
						{
							enCurrentState=enPiso1;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==2)
						{
							enCurrentState=enPiso2;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==3)
						{
							enCurrentState=enPiso3;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==4)
						{
							enCurrentState=enPiso4;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==5)
						{
							enCurrentState=enPiso5;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==6)
						{
							enCurrentState=enPiso6;
							printf("main2Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==7)
						{
							enCurrentState=enPiso7;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==8)
						{
							enCurrentState=enPiso8;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==9)
						{
							enCurrentState=enPiso9;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==10)
						{
							enCurrentState=enPiso10;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else
						{
							//**Nothing to do**//
						}
					}

					if( u8Scan_Floor4!=NO_REQUEST_4	)
					{
						u8Current_Floor = u8Scan_Floor4;
						enCurrentState = u8Scan_Floor4;
						if(u8Current_Floor==0)
						{
							enCurrentState=enLobby;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==1)
						{
							enCurrentState=enPiso1;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==2)
						{
							enCurrentState=enPiso2;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==3)
						{
							enCurrentState=enPiso3;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==4)
						{
							enCurrentState=enPiso4;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==5)
						{
							enCurrentState=enPiso5;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==6)
						{
							enCurrentState=enPiso6;
							printf("main2Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==7)
						{
							enCurrentState=enPiso7;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==8)
						{
							enCurrentState=enPiso8;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==9)
						{
							enCurrentState=enPiso9;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else if(u8Current_Floor==10)
						{
							enCurrentState=enPiso10;
							printf("Siguiente parada, piso %d\n\n", enCurrentState);
							Moving();
						}
						else
						{
							//**Nothing to do**//
						}
					}

					else
					{
						printf("Terminaron los request");
					}
				}
				else
				{
					printf("Maximo numero de personas son %d, espere a que se desocupe\n",MAX_PEOPLE);
				}
				break;
			}
		}
	}
}
