#include <iostream>
#include "structure.h"

using namespace std;

//Procedure qui affiche le menu
void menu(int &choix) {
    cout << endl << "0 - Ajouter une personne en queue" << endl;
    cout << "1 - Retirer la personne en tete" << endl;
    cout << "2 - Consulter la personne en tete de file" << endl;
    cout << "3 - Calculer la longueur de la file d'attente" << endl;
    cout << "4 - Quitter" << endl;

    cout << "Choisissez une option :" << endl;
    cin >> choix;
}

//Procedure qui permet d'initiaiser la file d'attente
//Para-Sortie : fda
//Post-Cond : Que la file d'attente soit vide
void init(fileAttente *fda) {
    fda->tete = nullptr;
    fda->queue = nullptr;
}

//Cette procédure permet de copier un tableau dans un autre
//ENTREE : Pointeur vers l'indice 0 du tableau a copié, Pointeur vers l'indice 0 du tableau a remplir
//SORTIE : RIEN
void tabAssign(char *nomEntre, char *nomMaillon) {
    int i = 0;
    while (*(nomEntre + i) != '\0') {
        *(nomMaillon + i) = *(nomEntre + i);
        i++;
    }
}

//Procedure permettant d'ajouter une personne en queue de file
//Para-entrée : fda, num
//Para-sortie : fda
// Post-Cond : la file d'attente avec une nouvelle personne en queue
void ajoutPersonneQueue(fileAttente *fda, char *nom) {

    maillon *np;
    np = (maillon *) malloc(sizeof(maillon));
    tabAssign(nom, np->nom);
    np->suivant = nullptr;

    if (fda->tete == nullptr) {
        fda->tete = fda->queue = np;
    } else {
        fda->queue->suivant = np;
        fda->queue = np;
    }

    cout << "Personne ajoute ! " << endl;

}

//Procedure permettant de consulter la personne en tete de file
//Para-Entrée : fda
void persTeteListe(fileAttente *fda) {
    if (fda->tete == nullptr) {
        cout << "La file est vide !" << endl;
    } else {
        cout << "La personne au debut de la file est " << fda->tete->nom << "." << endl;
    }
}

//Procedure permettant de supprimer la personne en tete
//Para-Entrée : fda
//Post-Cond : la file d'attente avec un élément en moins au début
void suppEnTete(fileAttente *fda) {

    if (fda->tete == nullptr) {
        cout << "File d'attente vide !" << endl;
    } else {
        maillon *temp = (maillon *) malloc(sizeof(maillon));
        temp = fda->tete;
        fda->tete = fda->tete->suivant;
        free(temp);
        cout << "Personne supprimer ! " << endl;
    }
}

//Procedure permettant de calculer la longueur de la file d'attente
//Para-Entrée : fda
//Post-Cond : la longueur de la file d'attente
void calculLongFda(fileAttente *fda) {

    if (fda->tete == nullptr) {
        cout << "La file d'attente est vide !" << endl;
    } else {

        int compt;
        maillon *cursor;

        cursor = fda->tete;
        compt = 1;

        while (cursor->suivant != nullptr) {
            cursor = cursor->suivant;
            compt++;
        }

        cout << "La file d'attente est de " << compt << " personne(s) !" << endl;
    }

}

