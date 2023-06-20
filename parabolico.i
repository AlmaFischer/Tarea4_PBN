%module parabolico

%{
#include "parabolico.h"
%}

%include "std_vector.i"

namespace std {
    %template(VectorObjeto) vector<Objeto>;
}
%include "parabolico.h"
