//Multiple inheritance

#include <iostream>
typedef int HANDS;

using namespace std;

enum COLOR { Red, Green, Blue, Yellow, White, Black, Brown };
enum BOOL { FALSE, TRUE };

class Animal
{
    public:
        Animal(int);
        virtual ~Animal() { cout << "Animal deconstructor\n"; }
        virtual int GetAge() const { return itsAge; }
        virtual void SetAge(int age) { itsAge = age; }
    private:
        int itsAge;
};

Animal::Animal(int age):
itsAge(age)
{
    cout << "Animal constructor\n";
}

class Horse : public Animal
{
    public:
        Horse(COLOR, HANDS, int);
        virtual ~Horse() { cout << "Horse deconstructor\n"; }
        virtual void Whinny() const { cout << "Whinny\n"; }
        virtual HANDS GetHeight() const { return itsHeight; }
        virtual COLOR GetColor() const { return itsColor; }
    protected:
        COLOR itsColor;
        HANDS itsHeight;
};

Horse::Horse(COLOR color, HANDS height, int age):
itsColor(color),
itsHeight(height),
Animal(age)
{
    cout << "Horse constructor\n";
}


class Bird : public Animal
{
    public:
        Bird(COLOR, BOOL, int);
        virtual ~Bird() { cout << "Bird deconstructor\n"; }
        virtual void Chirp() const { cout << "Chirp\n"; }
        virtual void Fly() const { cout << "I can fly\n"; }
        virtual COLOR GetColor()const { return itsColor; }
        virtual BOOL GetMigration() const { return itsMigration; }
    protected:
        COLOR itsColor;
        BOOL itsMigration;
};

Bird::Bird(COLOR color, BOOL migration, int age):
itsColor(color),
itsMigration(migration),
Animal(age)
{
    cout << "Bird constructor\n";
}

class Pegasus : public Horse, public Bird
{
    public:
        Pegasus(COLOR, HANDS, BOOL, long, int);
        ~Pegasus() { cout << "Pegasus deconstructor\n"; }
        void Chirp() const { Whinny(); }
        virtual long GetNumberBelievers() const { return itsNumberBelievers; }
        virtual COLOR GetColor() const { return Horse::GetColor(); }
        virtual int GetAge() const { return Horse::GetAge(); }

    private:
        long itsNumberBelievers;
};

Pegasus::Pegasus(
    COLOR color, 
    HANDS height, 
    BOOL migration, 
    long numBelievers,
    int age
    ):
Horse(color, height, age),
Bird(color, migration, age),
itsNumberBelievers(numBelievers)
{
    cout << "Pegasus constructor\n";
}

int main(){
    Pegasus* pPeg = new Pegasus(Red, 5, TRUE, 10, 2);
    pPeg->Fly();
    pPeg->Whinny();
    cout << "\nYour Pegasus is " << pPeg->GetHeight();
    cout << " hands tall and ";
    if (pPeg->GetMigration())   
        cout << "it does migrate.";
    else 
        cout << "it does not migrate.";
    cout << "\nA total of " << pPeg->GetNumberBelievers();
    cout << " believe it exists.\n";
    cout << pPeg->GetColor() << "\n";
    cout << pPeg->GetAge() << "\n";
    delete pPeg;
}