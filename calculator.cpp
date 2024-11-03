# CODSOFT
#include <iostream>

using namespace std;

int main()
{

    int a, b, c;

    cout << "Enter first no. ";

    cin >> a;

    cout << "Enter second no. ";

    cin >> b;

    while (c != 5)
    {

        cout << "1. Addition" << endl;

        cout << "2. Subtraction" << endl;

        cout << "3. Multiplication" << endl;

        cout << "4. Division" << endl;

        cout << "5. Exit" << endl;

        cin >> c;

        switch (c)
        {

        case 1:
            cout << a + b << endl;

            break;

        case 2:
            cout << a - b << endl;

            break;

        case 3:
            cout << a * b << endl;

        break ;

            case 4:
            cout << a / b << endl;
            break;
        default:
        cout<<"Invalid number ";
        break;
        }
    }
    return 0;
}
