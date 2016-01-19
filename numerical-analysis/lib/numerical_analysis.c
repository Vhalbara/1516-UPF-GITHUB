/*
 * Written by Thomas Stegen for the development in numerical analysis at the UPF
 */

#include "numerical_analysis.h"

/*
 * Input: First real (double), second real (double) and the precision (double)
 * Process: The first is compared to the second with precision given.
 * Output: The boolean value.
 */
int comparison_real (double a,double  b,double  p) 
{
	return (a - b) <= p;
}
