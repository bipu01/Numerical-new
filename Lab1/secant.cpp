#include <iostream>
#include <cmath>
using namespace std;

class SecantMethod
{
    float x0, x1, xnew, error;
    float fx0, fx1, newX;

public:
    int iteration;
    SecantMethod() : error(2), iteration(0) {}

    void takeValues()
    {
        cout << "Enter value of x0 and x1: ";
        cin >> x0 >> x1;
    }
    float findError()
    {
        error = (xnew - x1) / xnew;
        if (error < 0)
        {
            error *= -1;
        }
        return error;
    }

    float calculate()
    {
        while (error >= 0.05)
        {
            fx0 = sin(x0) + (x0 * x0) + 5 * x0 - 9;
            fx1 = sin(x1) + (x1 * x1) + 5 * x1 - 9;
            xnew = x1 - (fx1 * (x1 - x0)) / (fx1 - fx0);
            iteration++;
            findError();
            x0 = x1;
            x1 = xnew;
        }
        return xnew;
    }
};

int main()
{
    SecantMethod s1;
    s1.takeValues();
    cout << s1.calculate();
    cout << "\nIteration: " << s1.iteration;
    return 0;
};