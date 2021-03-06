/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: phabert
 *
 * Created on 28 septembre 2018, 08:33
 */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <sys/syscall.h>


typedef struct {
    int v1;
    int v2;
    int v3;
}laStruct;

laStruct global;

void *tache1(void *p_data)
{
    int val = *((int *) p_data);
    int tid;

    global.v1 = val;
    tid = syscall(SYS_gettid);
    printf("je suis T1 TID = %d v1 = %d,\n", tid, global.v1);
    printf("dans T1 l'argument vaut : %d\n", val);
    sleep(3);

    pthread_exit((void *)"Job terminé pour T1 \n");
}

void *tache2(void *p_data)
{

    int val = *((int *) p_data);
    int tid;

    global.v2 = val;
    tid = syscall(SYS_gettid);
    printf("je suis T2 TID = %d v2 = %d,\n", tid, global.v2);
    printf("dans T2 l'argument vaut : %d\n", val);
    sleep(3);
    pthread_exit((void *)"job terminé pour T2 \n");
}

void *tache3(void *p_data)
{

    int val = *((int *) p_data);
    int tid;


    global.v3 = val;
    tid = syscall(SYS_gettid);
    printf("je suis T3 TID = %d v3 = %d,\n", tid, global.v3);
    printf("dans T3 l'argument vaut : %d\n", val);
    sleep(2);

    pthread_exit((void *)"Job terminé pour T3 \n");
}

int main()
{
    int i,res;
    pthread_t T[3];
    void *thread_result;

    int a = 10;
    int b = 20;
    int c = 30;



    /** Création des trois threads  **/


    res = pthread_create(&T[0], NULL, tache1, (void *)&a);
    if (res != 0) {
        perror("Thread creation failed");
        exit(EXIT_FAILURE);
    }

    res = pthread_create(&T[1], NULL, tache2, (void *)&b);
    if (res != 0) {
        perror("Thread creation failed");
        exit(EXIT_FAILURE);
    }

    res = pthread_create(&T[2], NULL, tache3, (void *)&c);
    if (res != 0) {
        perror("Thread creation failed");
        exit(EXIT_FAILURE);
    }
    /** attente de la fin des trois threads **/

    printf("Attente de la fin des thread...\n");

    for ( i = 0; i < 3; i++){
        res = pthread_join(T[i], &thread_result);
        if (res != 0) {
            perror("Thread join a échoué");
            exit(EXIT_FAILURE);
        }
        printf("OK, valeur de retour du thread join : %s\n", (char *)thread_result);
    }

    printf(" V1 = %d\n V2 = %d\n V3 = %d\n", global.v1, global.v2, global.v3);

    exit(EXIT_SUCCESS);
}

