#include <iostream>
#include <math.h>
#include "bigint/BigIntegerLibrary.hh"

BigInteger abs(BigInteger x) {
    if (x < 0) {
        return x*-1;
    }
    else {
        return x;
    }
}

int startvalue(int x) {
    int n = 0;
    while (n*n <= x) {
        n++;
    }
    return (n-1);
}

double f(double y, int x) {
    return y*y-x;
}

double df(double y) {
    return 2*y;
}

double aprox_via_Newton_Raphson(int x) {
    double xi = startvalue(x);
    int iterations = 0;
    while (!(abs(xi*xi-x) <= PRECISION)) {
        xi = xi - f(xi,x) / df(xi);
        iterations++;
    }
    //Weggecomment omdat het anders irritant is in latere opdrachten.. uncomment even voor 3.1.3
    //cout << "\"Aproximate via Newton Raphson\" used " << iterations << " iterations!" << endl;
    return xi;
}