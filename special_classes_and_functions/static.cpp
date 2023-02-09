#include <iostream>

using namespace std;

class Cat
{
private:
    static int HowManyCats;
public:
    Cat() { HowManyCats++; }
    ~Cat() { HowManyCats--; }
    static int GetCats() { return HowManyCats; }

};

int Cat::HowManyCats = 0;

int main(){

    Cat* cat1 = new Cat;
    Cat* cat2 = new Cat;
    Cat* cat3 = new Cat;
    cout << cat1->GetCats();

    cout << Cat::GetCats();
}  


