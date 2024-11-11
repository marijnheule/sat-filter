#include <stdio.h>
#include <stdlib.h>

int main (int argc, char** argv) {
   FILE *cnf, *assignment;

  cnf        = fopen (argv[1], "r");
  assignment = fopen (argv[2], "r");


  int nVar = 0, nCls = 0;
  int tmp;

  tmp = fscanf (cnf, " p cnf %i %i ", &nVar, &nCls);

  int* truth;

  truth = (int *) malloc (sizeof(int) * (nVar+1));

  for (int i = 1; i <= nVar; i++)
    truth[i] = 0;


  while (1) {
    int lit;
    tmp = fscanf (assignment, " %i ", &lit);
    if (lit > 0) truth[ lit] =  1;
    if (lit < 0) truth[-lit] = -1;

    if (tmp == EOF) break;
  }


  int size = 0, sat = 0;
  int* clause;
  clause = (int*) malloc (sizeof(int) * nVar);

  while (1) {
    int lit = 0;
    tmp = fscanf (cnf, " %i ", &lit);
    if (lit != 0) {
      clause[size++] = lit;
      if (lit > 0 && truth[ lit] ==  1) sat = 1;
      if (lit < 0 && truth[-lit] == -1) sat = 1;
    }
    if (lit == 0) {
      if (sat == 0) {
        for (int i = 0; i < size; i++)
          printf ("%i ", clause[i]);
        printf ("0\n");
      }
      sat  = 1;
      size = 0;
    }

    if (tmp == EOF) break;
  }


}
