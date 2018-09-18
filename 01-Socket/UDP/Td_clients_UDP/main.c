/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: phabert
 *
 * Created on 12 septembre 2018, 08:33
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <string.h>
/*
 * 
 */


   /* int socketClient;
    struct sockaddr_in infoServeur;
    int entierAEnvoyer;
    int entierRecu;
    int retour;
    int reception;
    // création de la socket udp 
    socketClient = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (socket==-1) {
        printf("pb socket : %s \n", strerror(errno));
        exit(errno);
    }
    // Initialisation des informations serveur
    infoServeur.sin_addr.s_addr = inet_addr("172.18.58.83");
    infoServeur.sin_family = AF_INET;
    infoServeur.sin_port = htons(2222);

    //Envoi de l'entier au serveur
    entierAEnvoyer=158;
    retour = sendto(socketClient,&entierAEnvoyer,sizeof(entierAEnvoyer),0,(struct sockaddr *)&infoServeur,sizeof(infoServeur));
    if (retour == -1) {
        printf("pb sendto : %s \n", strerror(errno));
        exit(errno);
    }
    //Réception de l'entier du serveur
    reception = recvfrom(socketClient,&entierAEnvoyer,sizeof(entierAEnvoyer),0,(struct sockaddr *)&infoServeur,sizeof(infoServeur));
    if (reception == -1) {
        printf("pb sendto : %s \n", strerror(errno));
        exit(errno);
    }

    //Affichage de l'entier du serveur 
    printf("Recu du serveur : %d\n", entierRecu);
    
    
    int socketClient;
    struct sockaddr_in infoServeur;
    float reelAEnvoyer;
    float reelRecu;
    int retour;
    int reception;
    // création de la socket udp 
    socketClient = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (socket==-1) {
        printf("pb socket : %s \n", strerror(errno));
        exit(errno);
    
    // Initialisation des informations serveur
    infoServeur.sin_addr.s_addr = inet_addr("172.18.58.83");
    infoServeur.sin_family = AF_INET;
    infoServeur.sin_port = htons(3333);

    //Envoi du reel au serveur
    reelAEnvoyer=41.4141414141;
    retour = sendto(socketClient,&reelAEnvoyer,sizeof(reelAEnvoyer),0,(struct sockaddr *)&infoServeur,sizeof(infoServeur));
    if (retour == -1) {
        printf("pb sendto : %s \n", strerror(errno));
        exit(errno);
    }
    //Réception du reel du serveur
    reception = recvfrom(socketClient,&reelAEnvoyer,sizeof(reelAEnvoyer),0,(struct sockaddr *)&infoServeur,sizeof(infoServeur));
    if (reception == -1) {
        printf("pb sendto : %s \n", strerror(errno));
        exit(errno);
    }

    //Affichage du reel du serveur 
    printf("Recu du serveur : %f\n", reelRecu);*/
   
       
typedef struct{
	unsigned char jour;
	unsigned char mois;
	unsigned short int annee;
	char jourDeLaSemaine[10];	// le jour en toute lettre
}datePerso;

/*
 * 
 */
int main(int argc, char** argv) {
    int socketClient;
    struct sockaddr_in infoServeur;
    float entierAEnvoyer=3.14;
    float entierRecu;
    int tailleStructure;
    int retour;
    int ret;
    datePerso chaineAEnvoyer;    
    chaineAEnvoyer.jour = 14;
    chaineAEnvoyer.mois = 9;
    chaineAEnvoyer.annee = 2018;
    strcpy(chaineAEnvoyer.jourDeLaSemaine,"lundi");
    
    //Creation de la socket UDP
    socketClient=socket(PF_INET , SOCK_DGRAM, IPPROTO_UDP);
    if(socketClient==-1)
    {
        printf("pb socket : %s \n", strerror(errno));
        exit(errno);
    }
    //init des informations serveurs
    //u_long inet_addr(const char *adresseAuFormatTexte="172.18.58.147");
    infoServeur.sin_family=AF_INET;
    infoServeur.sin_port=htons(4444);
    infoServeur.sin_addr.s_addr=inet_addr("172.18.58.83");
    //envoyer l'entier du serveur
    retour=sendto(socketClient, &chaineAEnvoyer, sizeof(chaineAEnvoyer), 0, (struct sockaddr *)&infoServeur, sizeof(infoServeur));
    
    if(retour==-1)
    {
        printf("pb sento : %s \n",strerror(errno));
        exit(errno);
    }
    return (EXIT_SUCCESS);
}

