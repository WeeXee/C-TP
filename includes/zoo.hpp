#include "animal.hpp"
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <vector>
using namespace std;
#define tigre 1
#define aigle 2
#define poule 3

class Habitat {
    public:
        char *type_animal;
        int nb_animal;
        int max;
        bool isSurpopulated;
        bool isFire;
        vector<Animal*> animaux;
        void addAnimal(Animal *animal, int nb_animal, vector<Animal*> animaux, float *budget);
        void deathAnimal(int nb_animal, vector<Animal*> animaux);
        void events(int nb_animal, int max, bool *isSurpopulated, bool *isFire, vector<Animal*> animaux);
        void eventsAnimal(vector<Animal*> animaux, vector<Habitat*> habitats, Nourriture *stock);
};

class Zoo {
    public:
        int mois = 0;
        int annee = 0;
        int nb_animal = 0;
        float budget = 8000;
        vector<Habitat*> habitats;
        Nourriture *nourriture;
        int countAnimals(vector<Habitat*> habitats);
        void addHabitat(int type, vector<Habitat*> habitats, float *budget);
        void sellHabitat(Zoo *zoo, char *who);
};