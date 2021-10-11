/*
 * File: combinatorics.h
 * --------------
 * This file defines C(n, k) function and the P(n, k) function that concerned
 * with counting the ways objects can be combined in an area called
 * combinatorics.
 */

#include <iostream>

#ifndef _combinatorics_h
#define _combinatorics_h


/*
 * Function: permutations
 * Usage: permutations(n, k);
 * ------------------
 * 
 * A permutation of a set is, loosely speaking, an arrangement of its members
 * into a sequence or linear order, or if the set is already ordered, a
 * rearrangement of its elements. 
 * 
 * Choose k values from a set of n elements, which orders matters.
 * 
 */

int permutations(int n, int k);

/*
 * Function: combinations
 * Usage: combinations(n, k);
 * ------------------
 * 
 * A combination is a selection of items from a collection, such that the
 * order of selection does not matter (unlike permutations). 
 * 
 * Choose k values from a set of n elements, which orders does not matter.
 * 
 */
int combinations(int n, int k);



#endif /* !COMBINATORICS_H */