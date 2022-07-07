#include "nourriture.hpp"
#include <vector>
#include <cstring>
using namespace std;

class Animal {
    public:
        string type_animal;
        char *name_animal;
        bool isFemale;
        bool isSick;
        bool isGross;
        bool isFeed;
        bool isSteal;
        int timeFeed = 0;
        int timeGross = 0;
        int timeage = 0;
        int egg = 0;
        int age;
        float needs;
        void addAge(vector<Animal*>Animaux);
        void defineAnimal(Animal *that, char *type_animal);
        void feedAnimal();
};