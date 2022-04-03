#pragma once
#include "types.h"

class CML {

public:

    CML():    
     _x()
    {};

    void fit(Matrix X, Vector b);

   Vector coefficient();
   Matrix predict(Matrix X);

private:

    Vector _x;    // _x será la solución del sistema A^T*A*x = A^T*b

};


