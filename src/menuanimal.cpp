#include "../includes/my.hpp"
using namespace std;

//---------------------------Menu principal animal achat et vente ------------------------------//

int achatanimal(Zoo *zoo){
    char selection;
    cout<<"||==========================================================||\n";
    cout<<"||===============  Quel Animal Voulez vous  ===============||\n";
    cout<<"||================= Vous avez  de budget =================||\n";
    cout<<"||======== C'est le %dieme mois de la %deme année ==============||\n"<< zoo->mois, zoo->annee;
    cout<<"||================ Que voulez vous faire? ==================||\n";
    cout<<"||===== 1/ Acheter un tigre mâle      ======================||\n";
    cout<<"||===== 2/ Acheter un aigle mâle      ======================||\n";
    cout<<"||===== 3/ Acheter un coq             ======================||\n";
    cout<<"||===== 1/ Acheter un tigre femelle   ======================||\n";
    cout<<"||===== 2/ Acheter un aigle femelle   ======================||\n";
    cout<<"||===== 3/ Acheter une poule femelle  ======================||\n";
    cout<<"||==========================================================||\n\n";
    cout<<"||===== Entrez votre choix:";
    cin >> selection;
    switch(selection)
    {
    case '1' :  cout << "menu..." << achattigre(zoo, 0) << endl;
    break; 
    case '2' : cout << "menu..." << achataigle(zoo, 0) << endl;
    break;
    case '3' : cout << "menu..." << achatpoule(zoo, 0) << endl;
    break;
    case '4' :  cout << "menu..." << achattigre(zoo, 1) << endl;
    break;
    case '5' : cout << "menu..." << achataigle(zoo, 1) << endl;
    break;
    case '6' : cout << "menu..." << achatpoule(zoo, 1) << endl;
    break;
//------------default-------------//
    default : cout<<"\n Invalid selection";
    break;
    }
    cout<<"\n";
    return 0;
}

int vendreanimal(Zoo *zoo){
    char selection;
    cout<<"||==========================================================||\n";
    cout<<"||============  Quel Animal Voulez vous vendre  ============||\n";
    cout<<"||================= Vous avez  de budget =================||\n";
    cout<<"||======== C'est le %dieme mois de la %deme année ==============||\n"<< zoo->mois, zoo->annee;
    cout<<"||================ Que voulez vous faire? ==================||\n";
    cout<<"||===== 1/ Vendre un tigre mâle      =======================||\n";
    cout<<"||===== 2/ Vendre un aigle mâle      =======================||\n";
    cout<<"||===== 3/ Vendre une poule mâle     =======================||\n";
    cout<<"||===== 1/ Vendre un tigre femelle   =======================||\n";
    cout<<"||===== 2/ Vendre un aigle femelle   =======================||\n";
    cout<<"||===== 3/ Vendre une poule femelle  =======================||\n";
    cout<<"||==========================================================||\n\n";
    cout<<"||===== Entrez votre choix:";
    cin >> selection;
    switch(selection)
    {
    case 1 :  cout << "menu..." << vendretigre(zoo) << endl;
    break;
    case 2 : cout << "menu..." << vendreaigle(zoo) << endl;
    break;
    case 3 : cout << "menu..." << vendrepoule(zoo) << endl;
    break;
    case 4 :  cout << "menu..." << vendretigre(zoo) << endl;
    break;
    case 5 : cout << "menu..." << vendreaigle(zoo) << endl;
    break;
    case 6 : cout << "menu..." << vendrepoule(zoo) << endl;
    break;
//------------default-------------//
    default : cout<<"\n Invalid selection";
    break;
    }
    cout<<"\n";
    return 0;
}



//---------------------------Menu achat animal------------------------------//


int achattigre(Zoo *zoo, int isFemale){
    Animal *animal;
    zoo->habitats.at(0)->animaux.at(0)->defineAnimal(animal, (char*)"tigre");
    char selection;
    cout<<"||==========================================================||\n";
    cout<<"||===============  Choisissez un tigre  ====================||\n";
    cout<<"||================= Vous avez  de budget =================||\n";
    cout<<"||======== C'est le %dieme mois de la %deme année ==============||\n"<< zoo->mois, zoo->annee;
    cout<<"||================ Que voulez vous faire? ==================||\n";
    cout<<"||===== 1/ Acheter un tigre 6 mois      ====================||\n";
    cout<<"||===== 2/ Acheter un tigre 4 ans       ====================||\n";
    cout<<"||===== 3/ Acheter un tigre 14 ans      ====================||\n";
    cout<<"||===== Entrez votre choix:";
    cin >> selection;
    ((selection == '1') ? animal->age = 0.5: 0);
    ((selection == '1') ? animal->age = 4: 0);
    ((selection == '1') ? animal->age = 14: 0);
    for (int i = 0; i < zoo->habitats.size(); i++) {
        if (strcmp(zoo->habitats.at(i)->type_animal, "tigre") == 0) {
            zoo->habitats.at(i)->addAnimal(animal, 1, zoo->habitats.at(i)->animaux, &zoo->budget);
        }
    }
    return 0;
}


int achataigle(Zoo *zoo, int isfemale){
    char selection;
    Animal *animal;
    zoo->habitats.at(0)->animaux.at(0)->defineAnimal(animal, (char*)"tigre");
    cout<<"||==========================================================||\n";
    cout<<"||===============  Choisissez un aigle  ====================||\n";
    cout<<"||================= Vous avez  de budget =================||\n";
    cout<<"||======== C'est le %dieme mois de la %deme année ==============||\n"<< zoo->mois, zoo->annee;
    cout<<"||================ Que voulez vous faire? ==================||\n";
    cout<<"||===== 1/ Acheter un aigle 6 mois      ====================||\n";
    cout<<"||===== 2/ Acheter un aigle 4 ans     ======================||\n";
    cout<<"||===== 3/ Acheter un aigle 14 ans     =====================||\n";
    cout<<"||===== Entrez votre choix:";
    cin >> selection;
    ((selection == '1') ? animal->age = 0.5: 0);
    ((selection == '1') ? animal->age = 4: 0);
    ((selection == '1') ? animal->age = 14: 0);
    for (int i = 0; i < zoo->habitats.size(); i++) {
        if (strcmp(zoo->habitats.at(i)->type_animal, "tigre") == 0) {
            zoo->habitats.at(i)->addAnimal(animal, 1, zoo->habitats.at(i)->animaux, &zoo->budget);
        }
    }
    return 0;
}

int achatpoule(Zoo *zoo, int isfemale){
    char selection;
    Animal *animal;
    zoo->habitats.at(0)->animaux.at(0)->defineAnimal(animal, (char*)"tigre");
    cout<<"||==========================================================||\n";
    cout<<"||===============  Choisissez un animal  ====================||\n";
    cout<<"||================= Vous avez  de budget =================||\n";
    cout<<"||======== C'est le %dieme mois de la %deme année ==============||\n"<< zoo->mois, zoo->annee;
    cout<<"||================ Que voulez vous faire? ==================||\n";
    cout<<"||===== 1/ Acheter un coq               ====================||\n";
    cout<<"||===== 2/ Acheter une poule            ====================||\n";
    cout<<"||===== Entrez votre choix:";
    cin >> selection;
    ((selection == '1') ? animal->isFemale = false: animal->isFemale = true);
    for (int i = 0; i < zoo->habitats.size(); i++) {
        if (strcmp(zoo->habitats.at(i)->type_animal, "tigre") == 0) {
            zoo->habitats.at(i)->addAnimal(animal, 1, zoo->habitats.at(i)->animaux, &zoo->budget);
        }
    }
    return 0;
}

//---------------------------Menu vente animal------------------------------//



int vendretigre(Zoo *zoo){
    char selection;
    cout<<"||==========================================================||\n";
    cout<<"||===============  Choisissez un tigre  ====================||\n";
    cout<<"||================= Vous avez  de budget =================||\n";
    cout<<"||======== C'est le %dieme mois de la %deme année ==============||\n"<< zoo->mois, zoo->annee;
    cout<<"||================ Que voulez vous faire? ==================||\n";
    cout<<"||===== 1/ Vendre un tigre 6 mois      =====================||\n";
    cout<<"||===== 2/ Vendre un tigre 4 ans       =====================||\n";
    cout<<"||===== 3/ Vendre un tigre 14 ans      =====================||\n";
    cout<<"||===== Entrez votre choix:";
    cin >> selection;
    ((selection == '1') ? sellAnimal(zoo, (char*)"tigre", 0.5): (void)NULL);
    ((selection == '2') ? sellAnimal(zoo, (char*)"tigre", 4): (void)NULL);
    ((selection == '3') ? sellAnimal(zoo, (char*)"tigre", 14): (void)NULL);
    return 0;
}


int vendreaigle(Zoo *zoo){
    char selection;
    cout<<"||==========================================================||\n";
    cout<<"||===============  Choisissez un aigle  ====================||\n";
    cout<<"||================= Vous avez  de budget =================||\n";
    cout<<"||======== C'est le %dieme mois de la %deme année ==============||\n"<< zoo->mois, zoo->annee;
    cout<<"||================ Que voulez vous faire? ==================||\n";
    cout<<"||===== 1/ Vendre un aigle 6 mois      =====================||\n";
    cout<<"||===== 2/ Vendre un aigle 4 ans       =====================||\n";
    cout<<"||===== 3/ Vendre un aigle 14 ans      =====================||\n";
    cout<<"||===== Entrez votre choix:";
    cin >> selection;
    ((selection == '1') ? sellAnimal(zoo, (char*)"aigle", 0.5): (void)NULL);
    ((selection == '2') ? sellAnimal(zoo, (char*)"aigle", 4): (void)NULL);
    ((selection == '3') ? sellAnimal(zoo, (char*)"aigle", 14): (void)NULL);
    return 0;
}

int vendrepoule(Zoo *zoo){
    char selection;
    cout<<"||==========================================================||\n";
    cout<<"||===============  Choisissez un animal  ====================||\n";
    cout<<"||================= Vous avez  de budget =================||\n";
    cout<<"||======== C'est le %dieme mois de la %deme année ==============||\n"<< zoo->mois, zoo->annee;
    cout<<"||================ Que voulez vous faire? ==================||\n";
    cout<<"||===== 1/ Vendre un coq               =====================||\n";
    cout<<"||===== 2/ Vendre une poule            =====================||\n";
    cout<<"||===== Entrez votre choix:";
    cin >> selection;
    ((selection == '1') ? sellAnimal(zoo, (char*)"poule", 20): (void)NULL);
    ((selection == '2') ? sellAnimal(zoo, (char*)"poule", 40): (void)NULL);
    return 0;
}