//using pointers with const function
#include <iostream>

using namespace std;

class Rectangle{
    public:
        Rectangle();
        ~Rectangle();
        void SetLength(int length){ itsLength = length; }
        int GetLength() const { return itsLength; }

        void SetWidth(int width){ itsWidth = width; }
        int GetWidth() const {return itsWidth; }
    private:
        int itsLength;
        int itsWidth;
};

Rectangle::Rectangle():
itsLength(10),
itsWidth(5)
{}

Rectangle::~Rectangle()
{}

int main(){
    Rectangle* pRect = new Rectangle;
    //ptr to const Rect, can't change value
    const Rectangle* pConstRect = new Rectangle; 
    //const ptr to Rect, can't point to anything else 
    Rectangle* const pConstPtr = new Rectangle; 
    //const ptr to const Rect, can't change value + can't point to anything else
    const Rectangle* const pConstRectConstPtr = new Rectangle; 
    
    cout << "pRect width: " << pRect->GetWidth() << " feet\n";
    cout << "pConstRect width: " << pConstRect->GetWidth() << " feet\n";
    cout << "pConstPtr width: " << pConstPtr->GetWidth() << " feet\n";
    cout << "pConstRectConstPtr width: " << pConstRectConstPtr->GetWidth() << " feet\n";

    pRect->SetWidth(10);
    // pConstRect->SetWidth(10);
    pConstPtr->SetWidth(10);
    // pConstRectConstPtr->SetWidth(10);
    cout << "\n";
    cout << "pRect width: " << pRect->GetWidth() << " feet\n";
    cout << "pConstRect width: " << pConstRect->GetWidth() << " feet\n";
    cout << "pConstPtr width: " << pConstPtr->GetWidth() << " feet\n";
    cout << "pConstRectConstPtr width: " << pConstRectConstPtr->GetWidth() << " feet\n";
}