/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: phabert
 *
 * Created on 21 septembre 2018, 10:25
 */

#include <stdio.h>
#include <stdlib.h>

int main ( int argc, char *argv[] )
{
	int pid1,pid2 ;
	int cpt=0;
	pid1 = fork();
	if ( pid1 == 0 )
	{
		cpt++;
		pid2 = fork();
		if ( pid2 == 0 )
		{ 
			cpt++ ;
			printf("dans petit fils cpt=%d a l'adresse %4X\n",cpt,&cpt) ;
		}
		else
		{
			cpt++ ;
			printf("dans fils cpt=%d a l'adresse %4X\n",cpt,&cpt) ;
		}
	}
	else
	{
		cpt++;
		printf("dans pere cpt=%d a l'adresse %4X\n",cpt,&cpt) ;
	}
	return EXIT_SUCCESS;
}
