/*
 * Written by Thomas Stegen for the development in numerical analysis at the UPF
 */

#ifndef NUMERICAL_ANALYSIS_HEADER
#define NUMERICAL_ANALYSIS_HEADER

//MACRO
#define COMPARISON_REAL(a, b, precision) ({(a - b) <= precision;})

//FUNCTIONS
int comparison_real (double a,double b,double precision);

#endif
