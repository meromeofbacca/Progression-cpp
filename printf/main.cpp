#include <iostream>

int main(){
    std::cout << "This is a string" << std::endl;
    float a = 10, b = 10;
    char ch = 'c';
    char str[7] = "Oh yes"; //notice length is 1 less than size
    std::string std_str = "Oh yes";
    printf("This is an int: %d \n", a);
    printf("This is a character: %c \n", ch);
    printf("This is a char string: %s \n", str);
    printf("This is a string: %s \n", std_str.c_str());
    printf("Setting width %*c \n", 5, ch);
    printf("%.3f / %.3f = %.3f \n", a, b, a / b);
}