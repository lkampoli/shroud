
%module cstruct
%{
#include "struct.h"
%}

struct Cstruct1 {
  int ifield;
  double dfield;
};
typedef struct Cstruct1 Cstruct1;

int passStructByValue(Cstruct1 arg);

