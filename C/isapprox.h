//
# ifndef ISAPPROX
# define ISAPPROX
# include <stdbool.h>

typedef struct {
    double atol;
    double rtol;
} Tols;

#define isapprox(x, y, ...) isapprox_var(x, y, (Tols){__VA_ARGS__})
bool isapprox_var(double x, double y, Tols in);

# endif