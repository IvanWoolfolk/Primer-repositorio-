#include <stdio.h>
#include <stdlib.h>
#include "MaquinaEstados.h"

void main(void)
{
	uint8 TRAGO=0;
	uint8 ENCENDIDO=1;
	uint8 CurrentState=0;
	uint8 enSecondState;
	uint8 enThirdState;
	SM_NineStates enCurrentState = idle;
	while(ENCENDIDO!=APAGADO)
	{
		CurrentState+=1;
		if (CurrentState<=3)
		{
			switch ( enCurrentState )
			{
				case idle:
				{	//**Menú**//
					printf("\n\n\n\nBuen Dia, ¿Que le gustaria que le sirva?\n1)Margarita\n2)Mojito\n3)Gintonic\n4)BlackRussian\n5)Manhattan\n6)Piña colada\n7)Daiquiri\n8)Cosmopolitan\n9)Martini\n");
					scanf("%d",&TRAGO);

					if(TRAGO==TRAGO1)
					{//***Margarita**//
						printf("\nSelecciono Margarita");
						enCurrentState = enTequila;
						enSecondState = enTripleseco;
						enThirdState = enLimon;
					}
					else if(TRAGO==TRAGO2)
					{//***Mojito**//
						printf("\nSelecciono Mojito");
						enCurrentState = enRon;
						enSecondState=enLimon;
						enThirdState=enAguagas;
					}	
					else if (TRAGO==TRAGO3)
					{//***Gintonic**//
						printf("\nSeleccionoo Gintonic");
						enCurrentState = enGinebra;
						enSecondState=enTonica;
						enThirdState=enHielo;
					}
					else if (TRAGO==TRAGO4)
					{//***BlackRussian**//
						printf("\nSelecciono BlackRussian");
						enCurrentState = enVodka;
						enSecondState=enCafe;
						enThirdState=enHielo;
					}
					else if (TRAGO==TRAGO5)
					{//***Manhattan**//
						printf("\nSelecciono Manhattan");
						enCurrentState = enWhisky;
						enSecondState=enVermut;
						enThirdState=enHielo;
					}
					else if (TRAGO==TRAGO6)
					{//***Piña colada**//
						printf("\nSelecciono Piña Colada");
						enCurrentState = enRon;
						enSecondState=enPina;
						enThirdState=enCoco;
					}
					else if (TRAGO==TRAGO7)
					{//***Daiquiri**//
						printf("\nSelecciono Daiquiri");
						SM_NineStates enCurrentState = enRonb;
						enSecondState=enLimon;
						enThirdState=enHielo;
					}
					else if (TRAGO==TRAGO8)
					{//***Cosmopolitan**//
						printf("\nSelecciono Cosmopolitan");
						enCurrentState = enVodka;
						enSecondState=enTripleseco;
						enThirdState=enLimon;
					}
					else if (TRAGO==TRAGO9)
					{//***Martini**//
						printf("\nSelecciono Martini");
						enCurrentState = enGinebra;
						enSecondState=enVermut;
						enThirdState=enHielo;
					}
					else
					{
						printf("\nOpcion no válida");
						enCurrentState = idle;
					}
					break;
				}

				case enTequila: 
				{
					printf("\nSe sirve Tequila");
					if (CurrentState==1)
					{
						enCurrentState==enSecondState;
					}
					else if (CurrentState==2)
					{
						enCurrentState==enThirdState;
					}
					else 
					{
						//**Nothing to do**//
					}
					break;
				}
				case enTripleseco: 
				{
					printf("\nSe sirve Triple seco");
					if (CurrentState==1)
					{
						enCurrentState==enSecondState;
					}
					else if (CurrentState==2)
					{
						enCurrentState==enThirdState;
					}
					else 
					{
						//**Nothing to do**//
					}
					break;
				}	
				case enRon: 
				{
					printf("\nSe sirve Ron");
					if (CurrentState==1)
					{
						enCurrentState==enSecondState;
					}
					else if (CurrentState==2)
					{
						enCurrentState==enThirdState;
					}
					else 
					{
						//**Nothing to do**//
					}
					break;
				}
				case enLimon:
				{
					printf("\nSe sirve zumo de limón");
					if (CurrentState==1)
					{
						enCurrentState==enSecondState;
					}
					else if (CurrentState==2)
					{
						enCurrentState==enThirdState;
					}
					else 
					{
						//**Nothing to do**//
					}
					break;
				}
				case enAguagas:
				{
					printf("\nSe sirve Agua Mineral");
					if (CurrentState==1)
					{
						enCurrentState==enSecondState;
					}
					else if (CurrentState==2)
					{
						enCurrentState==enThirdState;
					}
					else 
					{
						//**Nothing to do**//
					}
					break;
				}
				case enTonica:
				{
					printf("\nSe sirve Tonica");
					if (CurrentState==1)
					{
						enCurrentState==enSecondState;
					}
					else if (CurrentState==2)
					{
						enCurrentState==enThirdState;
					}
					else 
					{
						//**Nothing to do**//
					}
					break;
				}
				case enHielo:
				{
					printf("\nSe sirve Hielo");
					if (CurrentState==1)
					{
						enCurrentState==enSecondState;
					}
					else if (CurrentState==2)
					{
						enCurrentState==enThirdState;
					}
					else 
					{
						//**Nothing to do**//
					}
					break;
				}
				case enVodka:
				{
					printf("\nSe sirve Vodka");
					if (CurrentState==1)
					{
						enCurrentState==enSecondState;
					}
					else if (CurrentState==2)
					{
						enCurrentState==enThirdState;
					}
					else 
					{
						//**Nothing to do**//
					}
					break;
				}
				case enCafe:
				{
					printf("\nSe sirve licor de café");
					if (CurrentState==1)
					{
						enCurrentState==enSecondState;
					}
					else if (CurrentState==2)
					{
						enCurrentState==enThirdState;
					}
					else 
					{
						//**Nothing to do**//
					}
					break;
				}
				case enVermut:
				{
					printf("\nSe sirve Vermut");
					if (CurrentState==1)
					{
						enCurrentState==enSecondState;
					}
					else if (CurrentState==2)
					{
						enCurrentState==enThirdState;
					}
					else 
					{
						//**Nothing to do**//
					}
					break;
				}
				case enWhisky:
				{
					printf("\nSe sirve Whisky");
					if (CurrentState==1)
					{
						enCurrentState==enSecondState;
					}
					else if (CurrentState==2)
					{
						enCurrentState==enThirdState;
					}
					else 
					{
						//**Nothing to do**//
					}
					break;
				}
				case enPina:
				{
					printf("\nSe sirve Piña");
					if (CurrentState==1)
					{
						enCurrentState==enSecondState;
					}
					else if (CurrentState==2)
					{
						enCurrentState==enThirdState;
					}
					else 
					{
						//**Nothing to do**//
					}
					break;
				}
				case enCoco:
				{
					printf("\nSe sirve Crema de Coco");
					if (CurrentState==1)
					{
						enCurrentState==enSecondState;
					}
					else if (CurrentState==2)
					{
						enCurrentState==enThirdState;
					}
					else 
					{
						//**Nothing to do**//
					}
					break;
				}
				case enRonb:
				{
					printf("\nSe sirve Ron Blanco");
					if (CurrentState==1)
					{
						enCurrentState==enSecondState;
					}
					else if (CurrentState==2)
					{
						enCurrentState==enThirdState;
					}
					else 
					{
						//**Nothing to do**//
					}
					break;
				}
				case enGinebra:
				{
					printf("\nSe sirve Ginebra");
					if (CurrentState==1)
					{
						enCurrentState==enSecondState;
					}
					else if (CurrentState==2)
					{
						enCurrentState==enThirdState;
					}
					else 
					{
						//**Nothing to do**//
					}
					break;
				}

				
				break;
			}
		}

		else
		{
			enCurrentState = idle;
		}

	}
}