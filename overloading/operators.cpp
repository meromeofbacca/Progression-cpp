#include <iostream>
#include <string>

typedef unsigned short USHORT;

using namespace std;

class Counter
{
    private:
        USHORT itsVal;   

    public:
        Counter();
        Counter(USHORT val);
        ~Counter();
        void Print(const string &name = "");
        USHORT getItsVal() const;
        void setItsVal(USHORT val);
        const Counter& operator++(); //prefix
        const Counter operator++(int); //postfix
        const Counter operator+(const Counter& rhs);
        operator unsigned short();
        

};

Counter::Counter():
itsVal(0)
{
}

Counter::Counter(USHORT val):
itsVal(val)
{
}

Counter::~Counter()
{
}

void Counter::Print(const string &name){
    cout << "The value of counter " << name << " is: " << itsVal << endl;
}

USHORT Counter::getItsVal() const { return itsVal; }

void Counter::setItsVal(USHORT val) { itsVal = val; }

const Counter& Counter::operator++(){ 
    itsVal++; 
    return *this;
}

const Counter Counter::operator++(int){ 
    Counter temp(*this);
    itsVal++; 
    return temp;
}

const Counter Counter::operator+(const Counter& rhs){
    return Counter(this->getItsVal() + rhs.getItsVal());
}

Counter::operator unsigned short(){
    return itsVal;
}

int main(){
    Counter i;
    i.Print("i");
    ++i;
    i.Print("i");

    //wants to set a counter a to i after it is incremented
    Counter a = ++i;
    i.Print("i");
    a.Print("a");

    Counter b = i++;
    i.Print("i");
    b.Print("b");

    Counter c(200);
    c.Print("c");

    Counter d = a + b;
    d.Print("d");

    Counter e = 5;
    e.Print("e");

    USHORT theShort = e;
    cout << "The short is: " << theShort << endl;
}