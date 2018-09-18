/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: phabert
 *
 * Created on 18 septembre 2018, 08:19
 */
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
/*
 * 
 */
int main(int argc, char** argv) {

   /* int socketClient;
    struct sockaddr_in infosServeur;
    int entierAEnvoyer = 125;
    int entierRecu;
    int retourConnect;
    int retourWrite;
    int retourRead;

    // Création de la socket client 
    socketClient = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (socketClient == -1) {
        printf("Problème création socket client : %s \n", strerror(errno));
    }

    // Init des infos serveur 
    //infosServeur.sin_addr.s_addr = inet_addr("172.18.58.82");
    infosServeur.sin_addr.s_addr = inet_addr("172.0.0.1");
    infosServeur.sin_family = AF_INET;
    infosServeur.sin_port = htons(5555);
    int addrlen = sizeof (infosServeur);

    // Connect 
    retourConnect = connect(socketClient, (struct sockaddr *) &infosServeur, addrlen);

    // Envoie de l'entier 
    retourWrite = write(socketClient, &entierAEnvoyer, sizeof (entierAEnvoyer));

    // Reception de l'entier 
    retourRead = read(socketClient, &entierRecu, sizeof (entierRecu));

    // Fin de connection par close
    int close(int socketClient);

    // Afficher du reel du serveur 
    printf("Entier recu : %i", entierRecu); */
    
    int socketClient;
    struct sockaddr_in infosServeur;
    float reelAEnvoyer = 125;
    float reelRecu;
    int retourConnect;
    int retourWrite;
    int retourRead;

    // Création de la socket client 
    socketClient = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (socketClient == -1) {
        printf("Problème création socket client : %s \n", strerror(errno));
    }

    // Init des infos serveur 
    infosServeur.sin_addr.s_addr = inet_addr("172.18.58.82");
    infosServeur.sin_family = AF_INET;
    infosServeur.sin_port = htons(6666);
    int addrlen = sizeof (infosServeur);

    // Connect 
    retourConnect = connect(socketClient, (struct sockaddr *) &infosServeur, addrlen);

    // Envoie du reel 
    retourWrite = write(socketClient, &reelAEnvoyer, sizeof (reelAEnvoyer));

    // Reception du reel 
    retourRead = read(socketClient, &reelRecu, sizeof (reelRecu));

    // Fin de connection par close
    int close(socketClient);

    // Afficher du reel du serveur 
    printf("Reel recu : %.f", reelRecu);
    
    return (EXIT_SUCCESS);
}

