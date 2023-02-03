#include <iostream>

using namespace std;

class Cat
{
    private:
        int *its_age;
        int *its_weight;
    public:
        Cat();
        Cat(int age, int weight);
        Cat(const Cat &rhs);
        ~Cat();
        Cat operator=(const Cat& rhs);
        int getAge() const;
        int getWeight() const;
        void setAge(int age);
        void setWeight(int weight);
};

Cat::Cat(){
    its_age = new int(5);
    its_weight = new int(10);  
}

Cat::Cat(int age, int weight){
    its_age = new int(age);
    its_weight = new int(weight);
}

Cat::Cat(const Cat &rhs){
    its_age = new int(rhs.getAge());
    its_weight = new int(rhs.getWeight());
}

Cat::~Cat()
{
    delete its_age;
    its_age = nullptr;
    delete its_weight;
    its_weight = nullptr;
}

Cat Cat::operator=(const Cat& rhs){
    if(this == &rhs){
        return *this;
    }
    // delete its_age;
    // delete its_weight;
    // its_age = new int;
    // its_weight = new int;
    *its_age = rhs.getAge();
    *its_weight = rhs.getWeight();
    return *this;
}

int Cat::getAge() const { 
    cout << its_age << endl;
    return *its_age; }

int Cat::getWeight() const { return *its_weight; }

void Cat::setAge(int age){ *its_age = age; }

void Cat::setWeight(int weight){ *its_weight = weight; }


int main(){
    Cat cat1 = Cat();
    cout << "Cat 1:" << endl;
    cout << "Age: " << cat1.getAge() << endl;
    cout << "Weight: " << cat1.getWeight() << endl << endl;

    Cat cat2 = Cat(20,20);
    cout << "Cat 2:" << endl;
    cout << "Age: " << cat2.getAge() << endl;
    cout << "Weight: " << cat2.getWeight() << endl << endl;

    Cat cat3 = Cat(cat2);
    cat3.setAge(30);
    cout << "Cat 3:" << endl;
    cout << "Age: " << cat3.getAge() << endl;
    cout << "Weight: " << cat3.getWeight() << endl << endl;

    Cat cat4;
    cout << "Cat 4:" << endl;
    cout << "Age: " << cat4.getAge() << endl;
    cout << "Weight: " << cat4.getWeight() << endl << endl;

    cat4 = cat3;
    cout << "Cat 4:" << endl;
    cout << "Age: " << cat4.getAge() << endl;
    cout << "Weight: " << cat4.getWeight() << endl << endl;

}
