#include <stdio.h>
#include <math.h>
#include <assert.h>

#include "TXLib.h"

const double EPSILON = 0.000001;

enum NumberOfRoots {
     INF_ROOTS  = -1,
     ZERO_ROOTS = 0,
     ONE_ROOT   = 1,
     TWO_ROOTS  = 2
};

// TODO: arrays -> structs

// fix
struct SquareEquation {
    double a;
    double b;
    double c;
    double x1;
    double x2;
    };  //

int solve_square (SquareEquation *equat);
int solve_linear (SquareEquation *equat);
int is_zero(double n);
int print_solutions(int nRoots, double x1, double x2);
int read_coeff(double *n);
int clear_line();

int main()
    {
    printf("# Square equations solver\n"
           "# (ñ)Marina Kuchina, 2023\n\n");



    SquareEquation equation = {0, 0, 0, 0, 0};

    // read_coeff
    // clear_buffer
    // getchar
    printf("Enter coefficients of the equation ax^2 + bx + c = 0\n");
    read_coeff(&equation.a);
    read_coeff(&equation.b);
    read_coeff(&equation.c);



    int nRoots = solve_square (&equation);
    print_solutions(nRoots, equation.x1, equation.x2);

    return 0;
    }


int clear_line()
    {
    while (getchar() != '\n')
        {
        }
    return 0;
    }



int read_coeff(double *n)
    {
    int right_ans = 0;
    while (right_ans == 0)
        {
        double current = 0;
        int i = scanf("%lg", &current);
        if (i == 0)
        {
            clear_line();
            printf("Incorrect input. Try again\n");
        }
        else
        {
            *n = current;
            right_ans += 1;
        }
        }
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


int solve_linear (SquareEquation *equation)
    {
    if (is_zero(equation->b))
        {
        return (is_zero(equation->c)) ? INF_ROOTS : ZERO_ROOTS;
        }
    else
        {
        equation->x1 = -equation->c/equation->b;
        return ONE_ROOT;
        }
    }


int solve_square (SquareEquation *equation)
    {

    assert(equation->x1 != NAN);
    assert(equation->x2 != NAN);
    assert(&equation->x1 != NULL);
    assert(&equation->x2 != NULL);
    assert(&equation->x1 != &equation->x2);
    assert(isfinite(equation->a));
    assert(isfinite(equation->b));
    assert(isfinite(equation->c));

    if (is_zero(equation->a))
        {
        return solve_linear (equation);
        }
    else
        {
        double d = equation->b*equation->b - 4*equation->a*equation->c;

        if (d < 0)
            {
            return ZERO_ROOTS;
            }
        if (is_zero(d))
            {
            equation->x1 = equation->x2 = -equation->b / (2*equation->a);
            return ONE_ROOT;
            }
        else
            {
            double sqrt_d = sqrt(d);

            equation->x1 = (-equation->b + sqrt_d) / (2*equation->a);
            equation->x2 = (-equation->b - sqrt_d) / (2*equation->a);

            return TWO_ROOTS;
            }
        }
    }
