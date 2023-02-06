#include <iostream>

using namespace std;

class Mammal
{
    public:
        Mammal():itsAge(1) { cout << "Mammal default constructor\n"; }
        virtual ~Mammal() { cout << "Mammal destructor\n"; }
        Mammal(const Mammal &rhs):itsAge(rhs.GetAge()) { cout << "Mammal copy constructor\n"; }

        //other functions
        virtual void Speak() const { cout << "Mammal sound\n"; }
        virtual Mammal* Clone() const { return new Mammal(*this); }

        //accessor
        int GetAge() const { return itsAge; }
    
    protected:
        int itsAge;
};

class Dog : public Mammal
{
    public:
        Dog() { cout << "Dog default constructor\n"; }
        virtual ~Dog() { cout << "Dog destructor\n"; }
        Dog(const Dog &rhs):Mammal(rhs) { cout << "Dog copy constructor\n"; }

        //other functions
        void Speak() const { cout << "Woof!\n"; }
        Mammal* Clone() const { return new Dog(*this); }
};

class Cat : public Mammal
{
    public:
        Cat() { cout << "Cat default constructor\n"; }
        virtual ~Cat() { cout << "Cat destructor\n"; }
        Cat(const Cat &rhs):Mammal(rhs) { cout << "Cat copy constructor\n"; }

        //other functions
        void Speak() const { cout << "Meow!\n"; }
        Mammal* Clone() const { return new Cat(*this); }
};

void SomeFunction(Mammal mammal){
    cout << "SOME FUNCTION\n";
}
enum ANIMALS { MAMMAL, DOG, CAT };
const int NUM_ANIMAL_TYPES = 3;

int main(){
    Mammal *theArray[NUM_ANIMAL_TYPES];
    Mammal *ptr;
    int choice, i;

    for(i = 0; i < NUM_ANIMAL_TYPES; i++){
        cout << "Choose (1)Dog, (2)Cat, (3)Mammal: ";
        cin >> choice;
        switch (choice)
        {
        case DOG: ptr = new Dog;
            break;
        case CAT: ptr = new Cat;
            break;
        
        default: ptr = new Mammal;
            break;
        }
        theArray[i] = ptr;
    }
    Mammal *otherArray[NUM_ANIMAL_TYPES];
    for(i = 0; i < NUM_ANIMAL_TYPES; i++){
        theArray[i]->Speak();
        otherArray[i] = theArray[i]->Clone();
    }
    for(i = 0; i < NUM_ANIMAL_TYPES; i++)
        otherArray[i]->Speak();

    Dog* dog = new Dog;
    Mammal* mammal = new Dog;
    SomeFunction(*mammal);

    delete dog;
    dog = nullptr;
    delete mammal;
    mammal = nullptr;

}