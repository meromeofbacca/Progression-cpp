// **************************************************
//
// Title:       Week 2 in Review
//
// File:       Week2
//
// Description:   Provide a linked list demonstration program
//
// Classes:      PART - holds part numbers and potentially other
//                     information about parts
//
//               PartNode - acts as a node in a PartsList
//
//               PartsList - provides the mechanisms for a linked list                                                            Âof parts
//
// Author:      Jesse Liberty (jl)
//
// Developed:   486/66 32mb RAM  MVC 1.5
//
// Target:      Platform independent
//
// Rev History:  9/94 - First release (jl)
//
// **************************************************

#include <iostream>
using namespace std;

typedef unsigned long ULONG;
typedef unsigned short USHORT;


// **************** Part ************

// Abstract base class of parts
class Part
{
public:
    Part():itsPartNumber(1) {}
    Part(ULONG PartNumber):itsPartNumber(PartNumber){}
    virtual ~Part(){};
    ULONG GetPartNumber() const { return itsPartNumber; }
    virtual void Display() const =0;  // must be overridden
private:
    ULONG itsPartNumber;
};

// implementation of pure virtual function so that
// derived classes can chain up
void Part::Display() const
{
    cout << "\nPart Number: " << itsPartNumber << endl;
}

// **************** Car Part ************

class CarPart : public Part
{
public:
    CarPart():itsModelYear(94){}
    CarPart(USHORT year, ULONG partNumber);
    virtual void Display() const 
    { 
        Part::Display(); cout << "Model Year: ";
        cout << itsModelYear << endl;  
    }
private:
    USHORT itsModelYear;
};

CarPart::CarPart(USHORT year, ULONG partNumber):
    itsModelYear(year),
    Part(partNumber)
{}


// **************** AirPlane Part ************

class AirPlanePart : public Part
{
public:
    AirPlanePart():itsEngineNumber(1){};
    AirPlanePart(USHORT EngineNumber, ULONG PartNumber);
    virtual void Display() const
    { 
        Part::Display(); cout << "Engine No.: ";
        cout << itsEngineNumber << endl;  
    }
private:
    USHORT itsEngineNumber;
};

AirPlanePart::AirPlanePart(USHORT EngineNumber, ULONG PartNumber):
    itsEngineNumber(EngineNumber),
    Part(PartNumber)
{}

// **************** Part Node ************
class PartNode
{
public:
    PartNode (Part*);
    ~PartNode();
    void SetNext(PartNode * node) { itsNext = node; }
    PartNode * GetNext() const;
    Part * GetPart() const;
    private:
    Part *itsPart;
    PartNode * itsNext;
};

    // PartNode Implementations...

    PartNode::PartNode(Part* pPart):
    itsPart(pPart),
    itsNext(0)
    {}

    PartNode::~PartNode()
    {
    delete itsPart;
    itsPart = 0;
    delete itsNext;
    itsNext = 0;
    }

    // Returns NULL if no next PartNode
    PartNode * PartNode::GetNext() const
    {
        return itsNext;
    }

    Part * PartNode::GetPart() const
    {
    if (itsPart)
        return itsPart;
    else
        return NULL; //error
    }

// **************** Part List ************
class PartsList
{
public:
    PartsList();
    ~PartsList();
    // needs copy constructor and operator equals!
    Part*      Find(ULONG & position, ULONG PartNumber)  const;
    ULONG      GetCount() const { return itsCount; }
    Part*      GetFirst() const;
    static     PartsList& GetGlobalPartsList() 
    { 
        return  GlobalPartsList; 
    }
    void       Insert(Part *);
    void       Iterate(void (Part::*f)()const) const;
    Part*      operator[](ULONG) const;
private:
    PartNode * pHead;   
    ULONG itsCount; 
    static PartsList GlobalPartsList;   
};

PartsList PartsList::GlobalPartsList;

// Implementations for Lists...

PartsList::PartsList():
pHead(0),
itsCount(0)
{}

PartsList::~PartsList()
{
    delete pHead;
}
   
Part* PartsList::GetFirst() const
{
    if (pHead)
        return pHead->GetPart();
    else
        return NULL;  // error catch here
}
   
Part* PartsList::operator[](ULONG offSet) const
{
    PartNode* pNode = pHead;

    if (!pHead)
        return NULL; // error catch here

    if (offSet > itsCount)
        return NULL; // error

    for (ULONG i=0;i<offSet; i++)
        pNode = pNode->GetNext();

    return   pNode->GetPart();
}
   
Part* PartsList::Find(ULONG & position, ULONG PartNumber)  const
{
    PartNode * pNode = 0;
    for (pNode = pHead, position = 0;
            pNode!=NULL;
            pNode = pNode->GetNext(), position++)
    {
        if (pNode->GetPart()->GetPartNumber() == PartNumber)
            break;
    }
    if (pNode == NULL)
        return NULL;
    else
        return pNode->GetPart();
}
   
void PartsList::Iterate(void (Part::*func)()const) const
{
    if (!pHead)
        return;
    PartNode* pNode = pHead;
    do
        (pNode->GetPart()->*func)();
    while (pNode = pNode->GetNext());
}
   
void PartsList::Insert(Part* pPart)
{
    PartNode * pNode = new PartNode(pPart);
    PartNode * pCurrent = pHead;
    PartNode * pNext = 0;

    ULONG New =  pPart->GetPartNumber();
    ULONG Next = 0;
    itsCount++;

    if (!pHead)
    {
        pHead = pNode;
        return;
    }

    // if this one is smaller than head
    // this one is the new head
    if (pHead->GetPart()->GetPartNumber() > New)
    {
        pNode->SetNext(pHead);
        pHead = pNode;
        return;
    }

    for (;;)
    {
        // if there is no next, append this new one
        if (!pCurrent->GetNext())
        {
            pCurrent->SetNext(pNode);
            return;
        }

        // if this goes after this one and before the next
        // then insert it here, otherwise get the next
        pNext = pCurrent->GetNext();
        Next = pNext->GetPart()->GetPartNumber();
        if (Next > New)
        {
            pCurrent->SetNext(pNode);
            pNode->SetNext(pNext);
            return;
        }
        pCurrent = pNext;
    }
}
   
int main()
{
    PartsList pl = PartsList::GetGlobalPartsList();
    Part * pPart = 0;
    ULONG PartNumber;
    USHORT value;
    ULONG choice;

    while (1)
    {
        cout << "(0)Quit (1)Car (2)Plane: ";
        cin >> choice;

        if (!choice)
            break;

        cout << "New PartNumber?: ";
        cin >>  PartNumber;

        if (choice == 1)
        {
            cout << "Model Year?: ";
            cin >> value;
            pPart = new CarPart(value,PartNumber);
        }
        else
        {
            cout << "Engine Number?: ";
            cin >> value;
            pPart = new AirPlanePart(value,PartNumber);
        }

        pl.Insert(pPart);
    }
    void (Part::*pFunc)()const = Part::Display;
    pl.Iterate(pFunc);
    return 0;
}