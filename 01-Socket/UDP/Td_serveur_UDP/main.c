/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: phabert
 *
 * Created on 14 septembre 2018, 10:12
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
int main(int argc, char** argv) {
    int socketServeur;
    int valeurRecue;
    int valeurRetour;
    int tailleStructure;
    int retourR;
    int retourS;
    int retour;
    struct sockaddr_in adresse;
    struct sockaddr_in infoClient;

    //Création de la socket UDP
    socketServeur = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP);

    if (socketServeur == -1) {
        printf("pb socket : %s \n", strerror(errno));
        exit(errno);
    }

    //Init des informations
    adresse.sin_family = AF_INET;
    adresse.sin_port = htons(2222);
    adresse.sin_addr.s_addr = htonl(INADDR_ANY);

    retour = bind(socketServeur, (struct sockaddr*) &adresse, sizeof (adresse)); //attachement ip-port
    
    if(retour == -1)
    {
        printf("pb bind : %s\n", strerror(errno));
        exit(0);
    }
    
    tailleStructure = sizeof(infoClient);
    
    //Reception de la valeur envoyé par le client
    retourR = recvfrom(socketServeur, &valeurRecue, sizeof(valeurRecue), 0, (struct sockaddr *) &infoClient, &tailleStructure);

    if (retourR == -1) 
    {
        printf("pb recvfrom: %s \n", strerror(errno));
    }
    
    //affiche la valeur reçu
    printf("message du client %s Réponse : %d\n", inet_ntoa(infoClient.sin_addr), valeurRecue);
    
    valeurRetour= - valeurRecue;

    //Envoi de la valeurRetour au client
    retourS = sendto(socketServeur, &valeurRetour, sizeof(valeurRetour), 0, (struct sockaddr *) &infoClient, tailleStructure);

    if (retourS == -1) {
        printf("pb sento : %s \n", strerror(errno));
        exit(errno);
    }

    return (EXIT_SUCCESS);
}




