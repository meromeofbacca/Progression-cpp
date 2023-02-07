//Multiple inheritance

#include <iostream>

using namespace std;

class Horse
{
    public:
        Horse():itsAge(5) { cout << "Horse constructor\n"; }
        virtual ~Horse() { cout << "Horse deconstructor\n"; }
        virtual void Whinny() const { cout << "Whinny\n"; }
    private:
        int itsAge;
};

class Bird
{
    public:
        Bird() { cout << "Bird constructor\n"; }
        virtual ~Bird() { cout << "Bird deconstructor\n"; }
        virtual void Chirp() const { cout << "Chirp\n"; }
        virtual void Fly() const { cout << "I can fly\n"; }
    private:
        int itsWeight;
};

class Pegasus : public Horse, public Bird
{
    public:
        Pegasus() { cout << "Pegasus constructor\n"; }
        ~Pegasus() { cout << "Pegasus deconstructor\n"; }
        void Chirp() const { Whinny(); }
};

const int MAGIC_NUMBER = 2;

int main(){
    Horse* Ranch[MAGIC_NUMBER];
    Bird* Aviary[MAGIC_NUMBER];
    Horse* pHorse;
    Bird* pBird;
    int choice, i;
    for(i = 0; i < MAGIC_NUMBER; i++)
    {
        cout << "\n (1)Horse, (2)Pegasus: ";
        cin >> choice;
        if(choice == 2)
            pHorse = new Pegasus;
        else
            pHorse = new Horse;
        Ranch[i] = pHorse;
    }
    
    for(i = 0; i < MAGIC_NUMBER; i++)
    {
        cout << "\n (1)Bird, (2)Pegasus: ";
        cin >> choice;
        if(choice == 2)
            pBird = new Pegasus;
        else
            pBird = new Bird;
        Aviary[i] = pBird;
    }

    cout << "\n";
    for(i = 0; i < MAGIC_NUMBER; i++)
    {
        cout << "\nRanch[" << i << "]: ";
        Ranch[i]->Whinny();
        delete Ranch[i];
    }

    for(i = 0; i < MAGIC_NUMBER; i++)
    {
        cout << "\nAviary[" << i << "]: ";
        Aviary[i]->Chirp();
        Aviary[i]->Fly();
        delete Aviary[i];
    }
}