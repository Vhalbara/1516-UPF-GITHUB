/*
 * Written by Thomas Stegen for the development in numerical analysis at the UPF
 */

#ifndef NUMERICAL_ANALYSIS_HEADER
#define NUMERICAL_ANALYSIS_HEADER

//MACRO
#define COMPARISON_REAL(a, b, p) ({(a - b) <= p;})

//FUNCTIONS
int comparison_real (double a,double b,double p);

#endif
