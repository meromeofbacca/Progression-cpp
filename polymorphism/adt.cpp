//Abstract data types
#include <iostream>

using namespace std;

class Shape
{
    public:
        Shape() {}
        virtual ~Shape() {}
        virtual long GetArea() const = 0;   //pure virtual functions
        virtual long GetPerim() const = 0;
        virtual void Draw() = 0;
};

void Shape::Draw()
{
    cout << "Added functionality!\n";
}

class Circle : public Shape
{
    private:
        int itsRadius;
        int itsCircumference;
    public:
        Circle(int radius):itsRadius(radius) { }
        virtual ~Circle() { }
        virtual long GetArea() const { return 3 * itsRadius * itsRadius; }
        virtual long GetPerim() const { return 9 * itsRadius; }
        virtual void Draw();
};

void Circle::Draw()
{
    cout << "Circle drawing routine\n";
    Shape::Draw();
}

class Rectangle : public Shape
{
    private:
        int itsLength;
        int itsWidth;
    public:
        Rectangle(int length, int width):itsLength(length), itsWidth(width) { }
        virtual ~Rectangle() { }
        virtual long GetArea() const { return itsLength * itsWidth; }
        virtual long GetPerim() const { return itsLength*2 + itsWidth*2; }
        virtual long GetLength() const { return itsLength; }
        virtual long GetWidth() const { return itsWidth; }
        virtual void Draw();
};

void Rectangle::Draw()
{
    for (int i = 0; i<itsLength; i++)
    {
        for (int j = 0; j<itsWidth; j++)
            cout << "x ";

        cout << "\n";
    }
    Shape::Draw();
}

class Square : public Rectangle
{    
    public:
        Square(int length):Rectangle(length,length) { }
        ~Square() { }
};

int main(){
    int choice;
    bool quit = false;
    Shape* sp;

    while(1)
    {
        cout << "(1)Circle, (2)Rectangle, (3)Square, (0)Quit: \n";
        cin >> choice;
        switch (choice)
        {
            case 1:
                sp = new Circle(12);
                break;
            case 2:
                sp = new Rectangle(4,6);
                break;
            case 3:
                sp = new Square(7);
                break;
            
            default:
                quit = true;
                break;
        }
        if (quit) break;

        sp->Draw();
        cout << "\n";
    }

}



