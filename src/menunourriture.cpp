#include "../includes/my.hpp"
#include <bits/stdc++.h>
using namespace std;


void achatViande(Zoo *zoo) {
    char *selection;
    float quantity;
    cout<<"||==========================================================||\n";
    cout<<"||=============== Quelle Quantité voulez vous? ===============||\n";
    cout<<"||==========================================================||\n";
    cin>>selection;
    quantity = atof(selection);
    if (zoo->budget >= (quantity * 5)) {
        zoo->nourriture->stock_viande += quantity;
        cout<<"Vous venez d'acheter %d Kg de Viande"<< quantity <<endl;
    }else {
        cout<<"Vous ne pouvez pas acheter autant de Viande"<<endl;
        cout<<"vous pouvez acheter max %d Kg de Viande"<< zoo->budget / 5 << endl;
    }
}

void achatGraine(Zoo *zoo) {
    char *selection;
    float quantity;
    cout<<"||==========================================================||\n";
    cout<<"||=============== Quelle Quantité voulez vous? ===============||\n";
    cout<<"||==========================================================||\n";
    cin>>selection;
    quantity = atof(selection);
    if (zoo->budget >= (quantity * 5)) {
        zoo->nourriture->stock_graine += quantity;
        cout<<"Vous venez d'acheter %d Kg de Graine"<< quantity <<endl;
    }else {
        cout<<"Vous ne pouvez pas acheter autant de Graine"<<endl;
        cout<<"vous pouvez acheter max %d Kg de Graine "<< zoo->budget / 2.5 << endl;
    }
}

int achatnourriture(Zoo *zoo){
    char selection;
    cout<<"||==========================================================||\n";
    cout<<"||===============  Quelle Nourriture Voulez vous  ==========||\n";
    cout<<"||================= Vous avez  de budget ===================||\n";
    cout<<"||================ Que voulez vous faire? ==================||\n";
    cout<<"||===== 1/ Acheter de la viande (5e/Kg)   ==================||\n";
    cout<<"||===== 2/ Acheter des graines (2,5e/Kg)  ==================||\n";
    cout<<"||==========================================================||\n\n";
    cout<<"||===== Entrez votre choix:";
    cin >> selection;
    switch(selection)
    {
    case '1' :  achatViande(zoo);
    break;
    case '2' : achatGraine(zoo);
    break;
//------------default-------------//
    default : cout<<"\n Invalid selection";
    break;
    }
    cout<<"\n";
    return 0;
}