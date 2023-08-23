#include <stdio.h>
#include "TXLib.h"
#include <math.h>

// TODO: gh

// TODO: fix codestyle
int solve_square (double a, double b, double c, double *x1, double *x2);
int solve_linear (double b, double c, double *x);
int is_zero(double n);
int print_solutions(int nRoots, double x1, double x2);

// TODO: read about enums
/*const int INF_ROOTS = -1; */
enum numberofroots {INF_ROOTS = -1, ZERO_ROOTS, ONE_ROOT, TWO_ROOTS};
const double EPSILON = 0.000001;

int main()
    {
    // TODO: rewrite in eng
    printf("# Square equations solver\n"
           "# (ñ)Marina Kuchina, 2023\n\n");

    printf("Enter coefficients of the equation ax^2 + bx + c = 0\n");

    double a = 0, b = 0, c = 0;
    scanf("%lg %lg %lg", &a, &b, &c);
    // TODO: read_coeff

    double x1 = 0, x2 = 0;
    int nRoots = solve_square (a, b, c, &x1, &x2);
    print_solutions(nRoots, x1, x2);

    // TODO: print_solutions

    /*switch (nRoots)
        {
        case ZERO_ROOTS: printf("This equation doesn't have any roots\n");
                break;

        case ONE_ROOT: printf("x = %lg\n", x1);
                break;

        case TWO_ROOTS: printf("x1 = %lg, x2 = %lg\n", x1, x2);
                break;

        case INF_ROOTS: printf("This equation has infinite number of roots\n");
                break;

        default: printf ("main(): ERROR: nRoots =  %d\n",
                         nRoots);
                 return 1;
        }*/

    return 0;
    }

 int print_solutions(int nRoots, double x1, double x2)
     {
     switch (nRoots)
        {
        case ZERO_ROOTS: printf("This equation doesn't have any roots\n");
                return 0;
                break;

        case ONE_ROOT: printf("x = %lg\n", x1);
                return 0;
                break;

        case TWO_ROOTS: printf("x1 = %lg, x2 = %lg\n", x1, x2);
                return 0;
                break;

        case INF_ROOTS: printf("This equation has infinite number of roots\n");
                return 0;
                break;

        default: printf ("main(): ERROR: nRoots =  %d\n",
                         nRoots);
                 return 1;
        }
    }


int is_zero(double n)
    {
    return fabs(n) < EPSILON;
    }

int solve_linear (double b, double c, double *x)
    {
    if (is_zero(b))
        {
        return (is_zero(c)) ? INF_ROOTS : ZERO_ROOTS;
        }
    else
        {
        *x = -c/b;
        return ONE_ROOT;
        }
    }


// linear equation ???

int solve_square (double a, double b, double c, double *x1, double *x2)
    {
    if (is_zero(a))
        {
        int ans = solve_linear (b, c, x1);
        return ans;
        }
        /*{
        if (is_zero(b))
            {
            return (is_zero(c)) ? INF_ROOTS : ZERO_ROOTS;
            }
        else
            {
            *x1 = -c/b;
            // TODO: get rid of magic consts
            return ONE_ROOT;
            }
        }*/
    else
        {
        double d = b*b - 4*a*c;

        if (d < 0)
            {
            return ZERO_ROOTS;
            }
        if (is_zero(d))
            {
            *x1 = *x2 = -b / (2*a);
            return ONE_ROOT;
            }
        else
            {
            double sqrt_d = sqrt(d);

            *x1 = (-b + sqrt_d) / (2*a);
            *x2 = (-b - sqrt_d) / (2*a);

            return TWO_ROOTS;
            }
        }
    }


