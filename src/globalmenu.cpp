
#include "../includes/my.hpp"

using namespace std;

int countAnimal(char *type, Zoo *zoo) {
    int cnt = 0;
    for (int i = 0; i < zoo->habitats.size(); i++) {
        if ( zoo->habitats.at(i)->type_animal == type) {
            cnt += zoo->habitats.at(i)->animaux.size();
        }
    }
    return cnt;
}

float set_subvention(Zoo *zoo) {
    int nb_tigre = countAnimal((char*)"aigle", zoo);
    int nb_aigle = countAnimal((char*)"aigle" , zoo);
    float subvention = 0.0;
    subvention += nb_aigle * 2190.00;
    subvention += nb_tigre * 43800.00;
    return subvention;
}

void tourUp(int *mois, int *année, Zoo *zoo) {
    Habitat *tmp;
    *mois++;
    float subvention = set_subvention(zoo);
    if (*mois >= 12) {
        *mois = 0;
        *année++;
        zoo->budget += subvention;
    }
    for (int i = 0; i < zoo->habitats.size(); i++) {
        zoo->habitats.at(i)->eventsAnimal(zoo->habitats.at(i)->animaux, zoo->habitats, zoo->nourriture);
    }
}
bool isnum(char *val) {
    for (int i = 0; val[i] != '\0'; i++) {
        if (val[i] < '0' || val[i] > '9') {
            return false;
        }
    }
    return true;
}

int many() {
    char *val;
    cout<<"||==========================================================||\n";
    cout<<"||============ Combien voulez vous en acheter ? ============||\n";
    cout<<"||==========================================================||\n";
    cin >> val;
    if (isnum(val))
        return atoi(val);
        return 0;
}

Zoo *defineZoo() {
    Zoo *zoo = new Zoo;
    zoo->annee = 0;
    zoo->budget = 8000;
    zoo->mois = 0;
    return zoo;
}

int menu(void) {
    Zoo *zoo = defineZoo();
    char selection;
    bool ok = true;
        cout<<"||==========================================================||\n";
        cout<<"||===================  BIENVENUE AU ZOO  ===================||\n";
        cout<<"||=== Bonjour, Bienvenu dans ce simulateur de zoo!! ========||\n";
        cout<<"||================= Vous avez "<< zoo->budget <<"de budget ===================||" << endl;
        cout<<"||======== C'est le " << zoo->mois<< "ieme mois de la "<< zoo->annee <<"eme année ==============||"<< endl;
        cout<<"||================ Que voulez vous faire? ==================||\n";
        cout<<"||===== 1/ Acheter un habitat       ========================||\n";
        cout<<"||===== 2/ Acheter un animal        ========================||\n";
        cout<<"||===== 3/ Vendre un habitat        ========================||\n";
        cout<<"||===== 4/ Vendre un animal         ========================||\n";
        cout<<"||===== 5/ Acheter de la nouriture  ========================||\n";
        cout<<"||===== 6/ Passer au tour suivant!! ========================||\n";
        cout<<"||===== 7/ Quitter                  ========================||\n";
        cout<<"||==========================================================||\n\n";
        cout<<"||===== Entrez votre choix:";
        cin>>selection;
        switch(selection)
        {
            case '1' :  cout << "menu..."<< endl;
                achathabitat(zoo);
                break;
            case '2' : cout << "Achat d'un animal..."<< endl;
                achatanimal(zoo);
                break;
            case '3' : cout << "Vente d'un habitat..." << ventehabitat(zoo) << endl;
                break;
            case '4' : cout << "Vente d'un animal..." << vendreanimal(zoo) << endl;
                break;
            case '5' : cout << "Achat de nourriture..." << achatnourriture(zoo) << endl;
                break;
            case '6' : cout << "Mois suivant\n"; tourUp(&zoo->mois, &zoo->annee, zoo);
                break;
            case '7' : cout << "Revenez vite!!" << endl;
                return 0;
                break;
//------------default-------------//
            default : cout<<"\n Invalid selection";
                break;
        }
        cout<<"\n";
        menu();
        return 0;
}