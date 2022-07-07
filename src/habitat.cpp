#include "../includes/my.hpp"

void Habitat::addAnimal(Animal *animal, int nb_animal, vector<Animal*> animaux, float *budget) {
    for (int i = 0; i < nb_animal; i++) {
        if (*budget< 0) {
            animaux.push_back(animal);
        } if (prix(0, animal, budget) == 0) {
                    animaux.push_back(animal);
        }
    }
}

void Habitat::deathAnimal(int nb_animal, vector<Animal*> animaux) {
    for (int i = 0; i < nb_animal; i++) {
        animaux.pop_back();
    }
}

void Habitat::events(int nb_animal, int max, bool *isSurpopulated, bool *isFire, vector<Animal*> animaux) {
    srand(time(NULL));
    int random = rand() % 100 + 1;
    if (nb_animal > max){
        *isSurpopulated = true;
    }
    if (random == 43){
        *isFire = true;
    }
    random = rand() % 100 + 1;
    if (random == 12) {
        animaux.pop_back();
    }
}

void sellAnimal(Zoo *zoo, char *type_animal, float age) {
    float sell = 0;
    float uprise = 0;
    ((age <= 0.5) ? uprise = 0.5: 0);
    ((age <= 4) ? uprise = 4: 0);
    ((age <= 14) ? uprise = 14: 0);
    for (int i = 0; i < zoo->habitats.size(); i++) {
        if (strcmp(zoo->habitats.at(i)->type_animal, type_animal) == 0) {
            for (int j = 0; j < zoo->habitats.at(i)->animaux.size(); j++) {
                if (zoo->habitats.at(i)->animaux.at(j)->age <= uprise) {
                    zoo->budget += sell;
                    zoo->habitats.at(i)->animaux.erase(zoo->habitats.at(i)->animaux.begin()+j);
                }
                if (uprise == 0) {
                    if (age == 20) {
                        zoo->budget += 20;
                        zoo->habitats.at(i)->animaux.erase(zoo->habitats.at(i)->animaux.begin()+j);
                    } if (age == 40) {
                        zoo->budget += 10;
                        zoo->habitats.at(i)->animaux.erase(zoo->habitats.at(i)->animaux.end());
                    } else if (age == 30) {
                        zoo->habitats.at(i)->animaux.erase(zoo->habitats.at(i)->animaux.begin(), zoo->habitats.at(i)->animaux.end());
                    }
                }
            }
        }
    }
}