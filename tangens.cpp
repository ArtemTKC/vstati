#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double xDegrees = 60.0, res;
    // converting degree to radians and using tan() fucntion
    res = tan(xDegrees*3.14159/180);
    cout << "tan(x) = " << res << endl;
    return 0;
}