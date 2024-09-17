# ifndef ISAPPROX
# define ISAPPROX

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>

typedef struct {
    double atol;
    double rtol;
} Tols;

bool isapprox_base(double x, double y, double atol, double rtol);
bool isapprox_var(double x, double y, Tols in);
#define isapprox(x, y, ...) isapprox_var(x, y, (Tols){__VA_ARGS__})

# endif