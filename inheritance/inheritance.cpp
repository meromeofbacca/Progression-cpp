#include <iostream>

using namespace std;

enum BREED { YORKIE, CAIRN, DANDIE, SHETLAND, DOBERMAN, LAB };

class Mammal
{
    public:
        // constructors
        Mammal();
        Mammal(int age);
        ~Mammal();

        //accessors
        int GetAge() const { return itsAge; }
        void SetAge(int age) { itsAge = age; }
        int GetWeight() const { return itsWeight; }
        void SetWeight(int weight) { itsWeight = weight; }

        //Other methods
        void Sleep() const { cout << "shhh. I'm sleeping.\n"; }
        void Move() const { cout << "Mammal move one step\n"; }
        virtual void Speak() const { cout << "Mammal sound!\n"; }
        

    protected:
        int itsAge;
        int itsWeight;
};

class Dog : public Mammal
{
    public:
        // Constructors
        Dog();
        Dog(int age);
        Dog(int age, int weight);
        Dog(int age, BREED breed);
        Dog(int age, int weight, BREED breed);
        ~Dog();

        // Accessors
        BREED GetBreed() const { return itsBreed; }
        void SetBreed(BREED breed) { itsBreed = breed; }

        // Other methods
        void WagTail() { cout << "Tail wagging...\n"; }
        void BegForFood() { cout << "Begging for food...\n"; }
        void Speak() const { cout << "Woof!\n"; }
        void Move() const { cout << "Dog move 5 steps.\n"; }

    protected:
        BREED itsBreed;
};

class Cat : public Mammal
{
    public:
        void Speak() const { cout << "Meow!\n"; }
};

class Lion : public Mammal
{
    public:
        void Speak() const { cout << "Rawr!\n"; }
};

class Horse : public Mammal
{
    public:
        void Speak() const { cout << "Neigh!\n"; }
};

class Wolf : public Mammal
{
    public:
        void Speak() const { cout << "Awoo!\n"; }
};

Mammal::Mammal():
itsAge(1),
itsWeight(5)
{

}

Mammal::Mammal(int age):
itsAge(age),
itsWeight(5)
{

}

Mammal::~Mammal()
{

}

Dog::Dog():
Mammal(),
itsBreed(YORKIE)
{

}

Dog::Dog(int age):
Mammal(age),
itsBreed(YORKIE)
{

}

Dog::Dog(int age, int weight):
Mammal(age),
itsBreed(YORKIE)
{
    itsWeight = weight;
}

Dog::Dog(int age, BREED breed):
Mammal(age),
itsBreed(breed)
{

}

Dog::Dog(int age, int weight, BREED breed):
Mammal(age),
itsBreed(breed)
{
    itsWeight = weight;
    
}

Dog::~Dog()
{

}

int main(){
    Mammal* pMammal = new Lion;
    pMammal->Speak();

    Mammal* theArray[5];
    Mammal* ptr;
    int choice, i;
    for( i = 0; i<5; i++){
        cout << "Choose (1)Dog, (2)Cat, (3)Lion, (4)Horse, (5)Wolf: ";
        cin >> choice;
        switch (choice)
        {
        case 1: ptr = new Dog;
            break;
        case 2: ptr = new Cat;
            break;
        case 3: ptr = new Lion;
            break;
        case 4: ptr = new Horse;
            break;
        case 5: ptr = new Wolf;
            break;
        
        default: ptr = new Mammal;
            break;
        }
        theArray[i] = ptr;
    }
    for(i = 0; i < 5; i++){
        theArray[i]->Speak();
    }
}

