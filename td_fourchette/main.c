/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: phabert
 *
 * Created on 19 septembre 2018, 08:57
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main(int argc, char** argv) {
    
   /* fork();
    fork();
    fork();
    printf("* ");*/
    
	int pid1,pid2;
	pid1 = fork();
	if ( pid1 == 0 )
	{
		boite("boite1","pid1=0");
		pid2 = fork();
		if ( pid2 == 0 )
		{
			boite("boite2","pid2=0");
		}
		else
		{			
			boite("boite3","pid2<>0");
		}
	}
	else
	{
		boite("boite4","pid1<>0");
	}
    return (EXIT_SUCCESS);
}

