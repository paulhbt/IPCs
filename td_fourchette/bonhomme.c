/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   bonhomme.c
 * Author: phabert
 *
 * Created on 21 septembre 2018, 08:24
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

/*
 * 
 */
int main(int argc, char** argv) {
    
    int pid;
    //p1
    pid = fork();
    if (pid == 0)//p3
    {
        pid = fork();
        if (pid == 0)//p2
        {
            printf("p2");
        } else //p3
        {
            pid = fork();
            if (pid == 0) //p4
            {
                printf("p4");
            } else //p3
            {
                pid = fork();
                if (pid == 0)//p5
                {
                    pid = fork();
                    if (pid == 0)//p6
                    {
                        printf("p6");
                    } else //p5
                    {
                        pid = fork();
                        if (pid == 0)//p7
                        {
                            printf("p7");
                        } else //p5
                        {
                            printf("p5");
                        }
                    }
                } else //p3 
                {
                    printf("p3");
                }
            }
        }
    } else //p1
    {
        printf("p1");
    }
    
    return (EXIT_SUCCESS);
}

