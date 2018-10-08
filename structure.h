//
// Created by Antoine on 02/10/2018.
//

#ifndef TP3_STRUCTURE_H
#define TP3_STRUCTURE_H

typedef struct maillon {
    char nom[30];
    maillon *suivant;
} maillon;

typedef struct fileAttente {
    maillon *tete;
    maillon *queue;
} fileAttente;

void menu(int &choix);

void init(fileAttente *fda);

void ajoutPersonneQueue(fileAttente *fda, char *nom);

void persTeteListe(fileAttente *fda);

void suppEnTete(fileAttente *fda);

void calculLongFda(fileAttente *fda);

void tabAssign(char *nomEntre, char *nomMaillon);

#endif //TP3_STRUCTURE_H
