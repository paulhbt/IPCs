/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   zone.h
 * Author: phabert
 *
 * Created on 2 octobre 2018, 08:54
 */


#ifndef ZONE_H_INCLUDED
#define ZONE_H_INCLUDED

#include <sys/types.h>
#include <sys/ipc.h>
#include <errno.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/msg.h>


// type de ce qui va etre partage
struct donnees{
	long type;
	char texte[9];
};

#endif // ZONE_H_INCLUDED

