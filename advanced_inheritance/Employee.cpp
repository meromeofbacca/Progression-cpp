#include "String.hpp"

class Employee
{   
public:
    Employee();
    Employee(const String&, const String&, const String&, long);
    ~Employee();
    Employee(const Employee&);

    //operators
    Employee & operator= (const Employee &);

    //accessors
    const String & GetFirstName() const { return itsFirstName; }
    const String & GetLastName() const { return itsLastName; }
    const String & GetAddress() const { return itsAddress; }
    long GetSalary() const { return itsSalary; }

    //setters
    void SetFirstName(const String & fName) { itsFirstName = fName; }
    void SetLastName(const String & lName) { itsLastName = lName; }
    void SetAddress(const String & address) { itsAddress = address; }
    void SetSalary(long salary) { itsSalary = salary; }
private:
    String itsFirstName;
    String itsLastName;
    String itsAddress;
    long   itsSalary;
};

Employee::Employee():
    itsFirstName(""),
    itsLastName(""),
    itsAddress(""),
    itsSalary(0)
{}

Employee::Employee(const String& firstName, const String& lastName,
    const String& address, long salary):
    itsFirstName(firstName),
    itsLastName(lastName),
    itsAddress(address),
    itsSalary(salary)
{}

Employee::Employee(const Employee & rhs):
    itsFirstName(rhs.GetFirstName()),
    itsLastName(rhs.GetLastName()),
    itsAddress(rhs.GetAddress()),
    itsSalary(rhs.GetSalary())
{}

Employee::~Employee() 
{}

Employee & Employee::operator= (const Employee & rhs)
{
    if (this == &rhs)
        return *this;
    itsFirstName = rhs.GetFirstName();
    itsLastName = rhs.GetLastName();
    itsAddress = rhs.GetAddress();
    itsSalary = rhs.GetSalary();
    return *this;
}

void PrintFunc(Employee);
void rPrintFunc(const Employee&);

int main()
{
    Employee Edie("Jane","Doe","1461 Shore Parkway", 20000);
    Edie.SetSalary(20000);
    Edie.SetFirstName("Edythe");
    String LastName("Levine");
    Edie.SetLastName(LastName);
    cout << "Constructor count: " ;
    cout << String::ConstructorCount << endl;
    rPrintFunc(Edie);
    cout << "Constructor count: ";
    cout << String::ConstructorCount << endl;
    PrintFunc(Edie);
    cout << "Constructor count: ";
    cout << String::ConstructorCount << endl;
}
   
void PrintFunc (Employee Edie)
{
    cout << "Name: ";
    cout << Edie.GetFirstName().GetString();
    cout << " " << Edie.GetLastName().GetString();
    cout << ".\nAddress: ";
    cout << Edie.GetAddress().GetString();
    cout << ".\nSalary: " ;
    cout << Edie.GetSalary();
    cout << endl;
}

void rPrintFunc (const Employee& Edie)
{
    cout << "Name: ";
    cout << Edie.GetFirstName().GetString();
    cout << " " << Edie.GetLastName().GetString();
    cout << "\nAddress: ";
    cout << Edie.GetAddress().GetString();
    cout << "\nSalary: " ;
    cout << Edie.GetSalary();
    cout << endl;
}  