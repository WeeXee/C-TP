#include "../includes/my.hpp"
using namespace std;

//---------------------------Menu principal habitat achat et vente ------------------------------//


int achathabitat(Zoo *zoo){
    char selection;
    cout<<"||==========================================================||\n";
    cout<<"||===============  Quel Habitat Voulez vous  ===============||\n";
    cout<<"||================= Vous avez  de budget =================||\n";
    cout<<"||======== C'est le %dieme mois de la %deme année ==============||\n"<< zoo->mois, zoo->annee;
    cout<<"||================ Que voulez vous faire? ==================||\n";
    cout<<"||===== 1/ Acheter un habitat pour tigre  ==================||\n";
    cout<<"||===== 2/ Acheter un habitat pour aigle  ==================||\n";
    cout<<"||===== 3/ Acheter un habitat pour poule  ==================||\n";
    cout<<"||==========================================================||\n\n";
    cout<<"||===== Entrez votre choix:";
    cin >> selection;
    zoo->addHabitat(selection, zoo->habitats, &zoo->budget);
    return selection;
}


int ventehabitat(Zoo *zoo){
    char selection;
    cout<<"||==========================================================||\n";
    cout<<"||===============  Quel Habitat Voulez vous  ===============||\n";
    cout<<"||================= Vous avez  de budget =================||\n";
    cout<<"||======== C'est le %dieme mois de la %deme année ==============||\n"<< zoo->mois, zoo->annee;
    cout<<"||================ Que voulez vous faire? ==================||\n";
    cout<<"||===== 1/ Vendre un habitat pour tigre  ===================||\n";
    cout<<"||===== 2/ Vendre un habitat pour aigle  ===================||\n";
    cout<<"||===== 3/ Vendre un habitat pour poule  ===================||\n";
    cout<<"||==========================================================||\n\n";
    cout<<"||===== Entrez votre choix:";
    cin >> selection;
    ((selection == '1') ? zoo->sellHabitat(zoo, (char*)"tigre"): (void)NULL);
    ((selection == '2') ? zoo->sellHabitat(zoo, (char*)"aigle"): (void)NULL);
    ((selection == '3') ? zoo->sellHabitat(zoo, (char*)"poule"): (void)NULL);
    return 0;
}