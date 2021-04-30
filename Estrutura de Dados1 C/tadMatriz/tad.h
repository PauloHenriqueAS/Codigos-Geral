#include <stdlib.h>
#include <time.h>

typedef struct TMat2D TMat2D;

TMat2D *mat2D_create(int nrows, int ncolumns);
int mat2D_free(TMat2D *mat);

int mat2D_set_value(TMat2D *mat, int i, int j, double val);
int mat2D_get_value(TMat2D *mat, int i, int j, double *val);
int mat2D_randomize_number(TMat2D *mat);
int mat2D_add(TMat2D *pont, TMat2D *pont2, TMat2D *pont3, int lin, int col);
int mat2D_escalar(TMat2D *mat, int escalar);
int mat2D_prenencher(TMat2D *pont,double valor, int k);
double *mat2D_add_colunas(TMat2D *mat);
double *mat2D_add_linhas(TMat2D *mat);
double *mat2D_traco(TMat2D *mat, int *aux);

int mat2D_multiplying(int lin, int col, TMat2D *pont, TMat2D *pont2, TMat2D *pont3);

//void print_value(TMat2D *pont, double valPosi, int k);