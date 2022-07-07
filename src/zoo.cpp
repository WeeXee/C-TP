#include "../includes/my.hpp"
using namespace std;

int Zoo::countAnimals(vector<Habitat*> habitats) {
    int nb_animals = 0;
    for (int i = 0; i <= habitats.size(); i++) {
        nb_animals += habitats.at(i)->nb_animal;
    }
    return nb_animals;
}

void Zoo::addHabitat(int type, vector<Habitat*> habitats, float *budget) {
    Habitat *to_add;
    if (type >= tigre && *budget >= 2000) {
        to_add->type_animal = (char*)"tigre";
        to_add->nb_animal = 0;
        to_add->isSurpopulated = false;
        to_add->max = 2;
    } if (type >= aigle && *budget >= 2000) {
        to_add->type_animal = (char*)"aigle";
        to_add->nb_animal = 0;
        to_add->isSurpopulated = false;
        to_add->max = 4;
    } if (type >= poule && *budget >= 300) {
        to_add->type_animal = (char*)"poule";
        to_add->nb_animal = 0;
        to_add->isSurpopulated = false;
        to_add->max = 10;
    } if (to_add != NULL) {
        habitats.push_back(to_add);
    }
}


void Zoo::sellHabitat(Zoo *zoo, char *who) {
    for (int i = 0; i < zoo->habitats.size(); i++) {
        if (strcmp(zoo->habitats.at(i)->type_animal, who) == 0) {
            for (int j = 0; j< zoo->habitats.at(i)->animaux.size(); i++) {
                sellAnimal(zoo, who, 30);
            }
            ((strcmp(who, "tigre") == 0 || (strcmp(who, "aigle") == 0)) ? zoo->budget += 500: zoo->budget += 50);
            zoo->habitats.erase(habitats.begin()+i);
        }
    }
}