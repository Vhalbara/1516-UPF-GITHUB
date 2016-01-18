/*
 * Written by Thomas Stegen for the development in numerical analysis at the UPF
 */

#include "numerical_analysis.h"

/*
 * Input: first real (double), second real (double) and the precision (double)
 * Process: the first is compared to the second with precision given.
 * Output: the boolean value.
 */
int comparison_real (a, b, precision) 
{
	return (a - b) <= precision;
}
