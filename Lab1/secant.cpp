#include <iostream>
#include <cmath>
using namespace std;

class SecantMethod
{
    float x0, x1, xnew, error;
    float fx0, fx1, newX;

public:
    SecantMethod() : error(2) {}

    void takeValues()
    {
        cout << "Enter value of x0 and x1: ";
        cin >> x0 >> x1;
    }

    float calculate()
    {
        while (error >= 0.005)
        {
            fx0 = sin(x0) + (x0 * x0) + 5 * x0 - 9;
            fx1 = sin(x1) + (x1 * x1) + 5 * x1 - 9;
            // xnew =
        }
    }
};

int main()
{

    return 0;
};