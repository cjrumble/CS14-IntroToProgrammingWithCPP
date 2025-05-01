#include<iostream>
#include<iomanip>
#include <fstream>
using namespace std;

int main ( )
{
    int num, high=0, low=100, average, sum, count=0;
    ifstream In;
    ofstream Out;

    In.open ( "Data.txt" );
    Out.open ( "Stat.txt" );

    if ( !In  )
    {
        cout << "Input file not found, program ends" << endl;
        return -1;
    }

    while ( cin >> num )
    {
        if (num >= 0 && num <= 100) {
            if (num < low)
                low = num;
            if (num > high)
                high = num;
            count++;
            sum += num;
        }
    }

    Out << "The high value is: " << high <<endl;
    Out << "The low value is: " << low << endl;
    Out << "There average is: " << average << endl;

In.close ();
Out.close ();
return 0;
}


