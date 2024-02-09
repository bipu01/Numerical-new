#include <iostream>
#include <cmath>
using namespace std;

class Bisection
{
public:
    float xl, xu, xm;
    float fl, fu, fm, error;
    float oldNum;

    Bisection() : error(2), xu(0), xl(0), oldNum(-99) {}
    void takeVal()
    {
        cout << "Enter two points in x: ";
        cin >> xu >> xl;
    }

    float findError(float newNum, float oldNum)
    {
        error = (newNum - oldNum) / newNum;
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
            fu = sin(xu) + (xu * xu) + 5 * xu - 9;
            fl = sin(xl) + (xu * xu) + 5 * xl - 9;
            xm = (xu + xl) / 2;
            fm = sin(xm) + (xu * xu) + 5 * xm - 9;

            if ((fu < 0 && fm < 0) || (fu > 0 && fm > 0) || (fm < 0))
            {
                if (oldNum == -99)
                {
                    xu = xm;
                    oldNum = xu;
                    continue;
                }
                findError(xm, oldNum);
                xu = xm;
                oldNum = xu;
            }
            else if (xm == 0)
            {
                return xm;
            }
            else if ((fl > 0 && fm > 0) || (fl < 0 && fm < 0) || (xm > 0))
            {
                if (oldNum == -99)
                {
                    xl = xm;
                    oldNum = xl;
                    continue;
                }
                findError(xm, oldNum);
                xl = xm;
                oldNum = xl;
            }
        }
        return xm;
    }

    ~Bisection(){};
};

int main()
{
    Bisection b1;
    b1.takeVal();
    cout << b1.calculate();
    return 0;
};