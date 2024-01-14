#include <iostream>
#include <math.h>

using namespace std;

class CustomException
{
private:
    int error_code;
    string error_message;

public:

    CustomException(int error_code, string error_message)
    {
        this->error_code = error_code;
        this->error_message = error_message;
    }

    int getErrorCode()
    {
        return error_code;
    }

    string getErrorMessage()
    {
        return error_message;
    }

};

void checkCorrectNumberBiggerOrEqualThenTwo(float m)
{
    if (m < 2)
    {
        //CustomException CCNBOETT(001, "Number is too small, requaires a number greater or equal 2");
        throw CustomException(001, "Number is too small, requaires a number greater or equal 2");
    }
}

float equationZ1(float m)
{
    try
    {
        checkCorrectNumberBiggerOrEqualThenTwo(m);
    }
    catch (CustomException error)
    {
        cout << m << endl;
        cout << error.getErrorCode() << endl;
        cout << error.getErrorMessage() << endl;
        return error.getErrorCode();
    }
    float z1 = (((m + 2) / (sqrt(2 * m))) + ((2) / (m - sqrt(2 * m))) - ((m) / (sqrt(2 * m) + 2))) * ((sqrt(m) - sqrt(2)) / (m + 2));
    return z1;
}

float equationZ2(float m)
{
    try
    {
        checkCorrectNumberBiggerOrEqualThenTwo(m);
    }
    catch (CustomException& error)
    {
        cout << m << endl;
        cout << error.getErrorCode() << endl;
        cout << error.getErrorMessage() << endl;
        return error.getErrorCode();
    }
    float z2 = 1 / (sqrt(m) + sqrt(2));
    return z2;
}

int main()
{
    float m;
    cout << "m = ";
    cin >> m;

    cout << equationZ1(m) << endl;
    cout << equationZ2(m) << endl;
}