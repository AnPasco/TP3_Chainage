#include <iostream>
#include "structure.h"

using namespace std;

int main() {

    int choix, nbPers;
    char *nom = (char *) malloc(sizeof(char) * 30);

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
                    cout << "Veuillez saisir le nom de la personne dans la file d'attente (30 caracteres max): "
                         << endl;
                    cin >> nom;
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
                cout << "A plus !";
                return 0;
                break;
        }

        menu(choix);
    }
    free(nom);
    free(fda);
}