%module parabolico

%{
#include "parabolico.h"
%}
%include "parabolico.h"
%include "std_string.i"
%include "std_vector.i"
namespace std {
    %template(vecObjecto) vector<Objeto>;
};
