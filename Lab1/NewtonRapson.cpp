#include <iostream>
#include <math.h>
using namespace std;

class Findvalue
{
public:
    double xOld;
    double xNew;
    double func;
    double derivedFunc;
    double err;

    void askQsn()
    {
        cout << "Enter the starting point: ";
        cin >> xOld;
    }

    double fx(double x)
    {
        double func = sin(x * M_PI / 180) + (x * x) + 5 * x - 9;
        return func;
    }

    double fxx(double x)
    {
        double derivedFunc = cos(x * M_PI / 180) + (2 * x) + 5;
        return derivedFunc;
    }

    double findXNew()
    {
        xNew = xOld - (fx(xOld) / fxx(xOld));
        return xNew;
    }

    double error()
    {
        double err = (xNew - xOld) / xNew;
        xOld = xNew;
        return abs(err);
    }

    void calculate()
    {
        findXNew();
        while (error() >= 0.05)
        {
            findXNew();
        }
    }
};

int main()
{
    Findvalue f1;
    f1.askQsn();
    f1.calculate();
    cout << "The value with error is: " << f1.xNew;

    return 0;
};