#include <iostream>
#include "structure.h"

using namespace std;

int main() {

    int choix, nbPers;
    char nom;

    fileAttente *fda;
    fda = (fileAttente *) malloc(sizeof(fileAttente));

    cout << "FILE D'ATTENTE";
    menu(choix);

    init(fda);

    while (choix != 4) {

        switch (choix) {
            case 0 :
                cout << "Combien de personne voulez vous ajouter ?" << endl;
                cin >> nbPers;
                while (nbPers != 0) {
                    demandeNom(nom);
                    ajoutPersonneQueue(fda, nom);
                    nbPers--;
                }
                break;
            case 1 :
                suppEnTete(fda);
                break;
            case 2 :
                persTeteListe(fda);
                break;
            case 3:
                calculLongFda(fda);
                break;
            default:
                return 0;
                break;
        }

        menu(choix);
    }

}