#include <iostream>
using namespace std;

//stripped down class
class SimpleCat{
    public:
        SimpleCat() { 
            cout << "Default constructor called. \n";
            catAge = 1;
            catName = "Unamed";
        };
        SimpleCat(int age, std::string name){
            cout << "Paramaterized constructor called. \n";
            catAge = age;
            catName = name;
        };
        ~SimpleCat(){
            cout << "Destructor called. \n";
        };
        void getAge(){
            cout << "Age of " << catName << " is: " << catAge << endl;
        };
        void getName(){
            cout << "The name of the cat is: " << catName << endl;
        };
    private:
        int catAge;
        std::string catName;
};

int main(){
    //Frodo is created on the stack
    SimpleCat Frodo; 
    //Biscuit and Banana are created on the heap  
    SimpleCat *Biscuit = new SimpleCat;
    SimpleCat *Banana = new SimpleCat(6, "Banana");
    //get age and names
    cout << "Frodo info: \n";
    Frodo.getName(); 
    Frodo.getAge();  
    cout << "Biscuit info: \n";
    Biscuit->getName(); 
    Biscuit->getAge();  
    cout << "Banana info: \n";
    Banana->getName(); 
    Banana->getAge();

    //delete heap ptrs
    delete Biscuit;
    Biscuit = NULL;
    delete Banana;
    Banana = NULL;
    //When function ends, Frodo goes out of scope and destructor is called
}