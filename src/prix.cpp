#include "../includes/my.hpp"

int prix(int action, Animal *animal, float *budget){
    int prix;
    if (action == 1){
        if (animal->type_animal=="poule"){
            prix = 10;
            ((animal->isFemale == false) ? prix *= 2: prix = prix);
        }
        if (animal->type_animal=="tigre"){
            if (animal->age <= 0.5){
                prix = 1500;
            } else if (animal->age <= 4 && animal->age > 0,5){
                prix = 60000;
            } else if (animal->age> 4){
                prix = 10000;
            }
        }
        if (animal->type_animal=="aigle"){
            if (animal->age <= 0.5){
                prix = 500;
            } else if (animal->age <= 4 && animal->age > 0,5){
                prix = 2000;
            } else if (animal->age> 4){
                prix = 400;
            }
        }
        budget += prix;
    }
    else{
        if (animal->type_animal=="poule"){
            prix = 20;
            ((animal->isFemale == false) ? prix *= 5: prix = prix);
        }
        if (animal->type_animal=="tigre"){
            if (animal->age <= 0.5){
                prix = 3000;
            } else if (animal->age <= 4 && animal->age > 0,5){
                prix = 120000;
            } else if (animal->age> 4){
                prix = 60000;
            }
        }
        if (animal->type_animal=="aigle"){
            if (animal->age <= 0.5){
                prix = 1000;
            } else if (animal->age <= 4 && animal->age > 0,5){
                prix = 4000;
            } else if (animal->age> 4){
                prix = 2000;
            }
        }
        if ((*budget - prix) >= 0) {
            *budget -= prix;
        } else {
            std::cout << "Vous ne pouvez pas acheter cet animal" << stdin;
            return 1;
        }
    }
    return 0;
}