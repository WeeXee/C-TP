#ifndef __MY_HPP__
#define __MY_HPP__

#define capacity_poule 100
#define capacity_aigle 30
#define capacity_tigre 10

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <string.h>
#include "zoo.hpp"
#include "visiteur.hpp"


int zoo();
int prix(int action, Animal *animal, float *budget);
void addAge(int *age);
void defineAnimal(Animal *that, char *type_animal);
void birth(vector<Animal*> animaux, vector<Habitat*> habitats);
void isDead(vector<Animal*> animaux);
void addAnimal(Animal *animal, int nb_animal, vector<Animal*> animaux, float *budget);
void deathAnimal(int nb_animal, vector<Animal*> animaux);
void sellAnimal(Zoo *zoo, char *type_animal, float age);
void events(int nb_animal, int max, bool *isSurpopulated, bool *isFire, vector<Animal*> animaux);
void eventsAnimal(vector<Animal*> animaux, Nourriture *stock);
void feedAnimal(vector<Animal*> animaux, Nourriture *stock);
void addHabitat(int type, vector<Habitat*> habitats, float *budget);
void sellHabitat(Zoo *zoo, char *who);
void sellAnimal(Zoo *zoo, char *type_animal, float age);
void eventsAnimal(vector<Animal*> animaux, Nourriture *stock);
int menu(void);
int countAnimals(vector<Habitat*> habitats);
int vendrepoule(Zoo *zoo);
int vendreaigle(Zoo *zoo);
int achatanimal(Zoo *zoo);
int vendreanimal(Zoo *zoo);
int achattigre(Zoo *zoo, int type);
int achataigle(Zoo *zoo, int type);
int achatpoule(Zoo *zoo, int type);
int vendretigre(Zoo *zoo);
int achathabitat(Zoo *zoo);
int ventehabitat(Zoo *zoo);
int achatnourriture(Zoo *zoo);
Zoo *setZoo();

#endif