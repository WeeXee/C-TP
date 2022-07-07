#include "../includes/my.hpp"

void Animal::addAge(vector<Animal*> animaux){
    for (int i = 0; i < animaux.size(); i++) {
        animaux.at(i)->timeage++;
        if (animaux.at(i)->timeage >= 12) {
            animaux.at(i)->timeage = 0;
            animaux.at(i)->age++;
        }
    }
}

void Animal::defineAnimal(Animal *that, char *type_animal) {
    char *name = (char*)"";
    std::cout << "quel nom voulez vous lui donner?" <<stdin;
    cin >>name;
    that->type_animal = type_animal;
    that->name_animal= name;
    if (strcmp(type_animal, "poule") == 0) {
        ((that->isFemale == false) ? that->needs = 0.18: that->needs = 0.15);
    }
    if (strcmp(type_animal, "tigre") == 0) {
        ((that->isFemale == false) ? that->needs = 12: that->needs = 10);
    }
    if (strcmp(type_animal, "aigle") == 0) {
        ((that->isFemale == false) ? that->needs = 0.25: that->needs = 0.30);
    }
    srand(time(NULL));
    int random = rand() % 2;
    if (random == 1) {
        that->isFemale = true;
    } else {
        that->isFemale = false;
    }
}

void birth(vector<Animal*> animaux, vector<Habitat*> habitats) {
    Animal *animal = NULL;
    float p = -10;
    for (int i = 0; i <= animaux.size(); i++) {
        if (animaux.at(i)->type_animal == "tigre") {
            if (animaux.at(i)->isGross == true && animaux.at(i)->timeGross >= 3) {
                animaux.at(i)->isGross = false;
                animaux.at(i)->timeGross = 0;
                for (int j = 0; j <= habitats.size(); j++) {
                    if ((habitats.at(j)->nb_animal - habitats.at(j)->max) <= 0 && strcmp(habitats.at(j)->type_animal, "tigre") == 0) {
                        for (int k = 0; k < 3; k++) {
                            animaux.at(i)->defineAnimal(animal, (char*)"tigre");
                            habitats.at(j)->addAnimal(animal, 1, animaux, &p);
                        }
                    }
                }
            }
            if (animaux.at(i)->type_animal == "aigle") {
                if (animaux.at(i)->isGross == true && animaux.at(i)->timeGross >= 2) {
                    animaux.at(i)->isGross = false;
                    animaux.at(i)->timeGross = 0;
                    for (int j = 0; j <= habitats.size(); j++) {
                        if ((habitats.at(j)->nb_animal - habitats.at(j)->max) <= 0 && strcmp(habitats.at(j)->type_animal, "aigle") == 0) {
                            for (int k = 0; k < 2; k++) {
                                animaux.at(i)->defineAnimal(animal, (char*)"aigle");
                                habitats.at(j)->addAnimal(animal, 1, animaux, &p);
                            }
                        }
                    }
                }
            }
            if (animaux.at(i)->type_animal == "poule") {
                if (animaux.at(i)->isGross == true && animaux.at(i)->timeGross >= 2) {
                    animaux.at(i)->isGross = false;
                    animaux.at(i)->timeGross = 0;
                    for (int j = 0; j <= habitats.size(); j++) {
                        if ((habitats.at(j)->nb_animal - habitats.at(j)->max) <= 0 && strcmp(habitats.at(j)->type_animal, "poule") == 0) {
                            for (int k = 0; k < 33; k++) {
                                animaux.at(i)->defineAnimal(animal, (char*)"poule");
                                habitats.at(j)->addAnimal(animal, 1, animaux, &p);
                            }
                        }
                    }
                }
            }
        }
    }
}


void isDead(vector<Animal*> animaux) {
    for (int i = 0; i < animaux.size(); i++) {
        if (animaux.at(i)->type_animal == "poule" && animaux.at(i)->age >= 15) {
            animaux.erase(animaux.begin()+i);
        } else if (animaux.at(i)->age >= 25) {
             animaux.erase(animaux.begin()+i);
        }
    }
}

void Habitat::eventsAnimal(vector<Animal*> animaux, vector<Habitat*> habitats, Nourriture *stock){
    for (int i = 0; i <= animaux.size(); i++) {
        if (animaux.at(i)->isFemale == true && animaux.at(i)->isGross == false && animaux.at(i)->age == 4) {
            for (int j = 0; j <= animaux.size(); j++) {
                if (animaux.at(j)->age == 6 && animaux.at(j)->isFemale == false && j != i) {
                    animaux.at(i)->isGross = true;
                }
            }
        }
    }
    birth(animaux, habitats);
    isDead(animaux);
    int random = rand() % 100 + 1;
    for (int i = 0; i <= habitats.size(); i++){
        if (habitats.at(i)->nb_animal > habitats.at(i)->max){
            habitats.at(i)->isSurpopulated = true;
        }
        if (random == 43){
            habitats.at(i)->isFire = true;
        }
    }
    random = rand() % 100 + 1;
    for (int i = 0; i <= habitats.size(); i++){
        if (habitats.at(i)->isSurpopulated){
            ((random == 30) ? habitats.at(i)->animaux.pop_back(): (void)NULL);
        }
    }
    feedAnimal(animaux, stock);
    animaux.at(0)->addAge(animaux);
}

void feedAnimal(vector<Animal*> animaux, Nourriture *stock){
    for (int i = 0; i < animaux.size(); i++) {
        if (animaux.at(i)->type_animal == "poule" && animaux.at(i)->needs <= stock->stock_graine) {
            animaux.at(i)->isFeed = true;
            animaux.at(i)->timeFeed = 0;
        } else if (animaux.at(i)->needs <= stock->stock_viande){
            animaux.at(i)->isFeed = true;
            animaux.at(i)->timeFeed = 0;
        } 
    }
}