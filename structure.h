//
// Created by Antoine on 02/10/2018.
//

#ifndef TP3_STRUCTURE_H
#define TP3_STRUCTURE_H

typedef struct maillon {
    char nom;
    maillon *suivant;
} maillon;

typedef struct fileAttente {
    maillon *tete;
    maillon *queue;
} fileAttente;

void menu();

void init(fileAttente *fda);

void ajoutPersonneQueue(fileAttente *fda, char lettre);

void persTeteListe(fileAttente *fda);

void suppEnTete(fileAttente *fda);

void calculLongFda(fileAttente *fda);

#endif //TP3_STRUCTURE_H
