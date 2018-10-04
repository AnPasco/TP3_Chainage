#include <iostream>
#include "structure.h"

using namespace std;

int main() {

    int choix;
    fileAttente *fda;
    fda = (fileAttente *) malloc(sizeof(fileAttente));

    cout << "FILE D'ATTENTE" << endl;
    menu();
    cout << "Choisissez une option :" << endl;
    cin >> choix;

    init(fda);

    while (choix != 4) {

        switch (choix) {
            case 0 :
                ajoutPersonneQueue(fda, 1);
                ajoutPersonneQueue(fda, 2);
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

        cout << "Choisissez une option :" << endl;
        cin >> choix;
    }

}