%module parabolico

%{
#include "parabolico.h"
#include <vector>
#include <cmath>
%}

%include "std_vector.i"
%include "parabolico.h"

%template(VectorObjeto) std::vector<Objeto>;
