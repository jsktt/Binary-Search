////////////////////////////////////////////////////////
// ECE 2574, Homework 3
// File name:   hw3_function.h
// Description: STARTER CODE
// Date:        11/11/2023  
//

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>



/** exponentiation by recursion. The function returns m^n. 
	@ pre   n is a non-negative value.  m is an integer. 
	@post  both m and n are not changed
	@param m: an integer as the base of the exponentiation
	@param n: a non-negative integer for the exponent
	@return  the integer value of m^n
*/
int expo(const int m, const unsigned int n);


/** reverse a string s and returned the reversed string. 
	@ pre   size is a non-negative integer that is the length of the input string. 
	@post  the input string s is not changed.  A new string that is a reverse of s is created and returned.
	@param s: the string to be reversed
	@param size: a non-negative integer for the size of string s
	@return a new string that is the reverse of the input string s
*/
std::string reverse(const std::string s, const unsigned int size);



/** Searches an array of integer anArray[first] through anArray[last]
	to find the minimum.
	There may be duplicated items in the array. The array is not sorted.
 @pre  0 <= first, last <= SIZE - 1, where SIZE is the
	maximum size of the array, and anArray[first] <=
	anArray[first + 1] <= ... <= anArray[last].
 @post  anArray, first, last are unchanged and the minmum integer is returned 
 @param anArray  The array to search.
 @param first  The low index to start searching from.
 @param last  The high index to stop searching at.
 @return  the minimum integer is returned
*/
int minArray(const int anArray[], const int first, const  int last);


/** Searches a sorted array anArray[first] through anArray[last]
	for the number of occurrence of a given value by using a binary search.
	There may be duplicated items in the array. The array is sorted in ascending
	order.
 @pre  0 <= first, last <= SIZE - 1, where SIZE is the
	maximum size of the array, and anArray[first] <=
	anArray[first + 1] <= ... <= anArray[last]. @post  anArray is unchanged and either anArray[index] contains
	the given value or index == -1.
 @param anArray  The array to search.
 @param first  The low index to start searching from.
 @param last  The high index to stop searching at.
 @param target  The search key.
 @return  the number of times that the target appears in the array. It should have a value in the range [0,last-first-1]
*/
int binaryCount(const int anArray[], const  int first, const int last, int target);



/** Searches the array anArray[first] through anArray[last]
	for the immediate successor of a given value by using a binary search.
 @pre  0 <= first, last <= SIZE - 1, where SIZE is the
	maximum size of the array, and anArray[first] <=
	anArray[first + 1] <= ... <= anArray[last].
 @post  anArray is unchanged and either anArray[index] contains
	the given value or index == -1.
 @param anArray  The array to search.
 @param first  The low index to start searching from.
 @param last  The high index to stop searching at.
 @param target  The search key.
 @return  Either index, such that anArray[index] == successor of the target, or -1.
*/
int binarySuccessor(const int anArray[], const  int first, const  int last, int target);


/** Find power set (i.e. all the subset) of a given set of characters, including the empty set and S itself.
You can add additional parameters to the powerSet function in your implementation.  However, those parameters need to have 
default initilization value. In this way, a user of the function only needs to provide pSet and bSet and no 
additional information is needed when calling  powerSet(). 
 @pre  bSet is the string that holds the given set of characters, pSet is used to store the power set of bSet in the form
 of a vector of strings. Each string in pSet is a subset of bSet.
 @post  all subset of the bSet input is stored in pSet, including the empty set and aSet itself. bSet is not modified. pSet 
        is changed to hold the powerSet.
 @param bSet  a string that holds a set of unique characters.
 @param pSet  a vector of strings that is used to store the created powerSet, where each item in the vector is a subset of bSet.
 @return  no returned value.
*/
void powerSet(std::vector<std::string>& pSet, const std::string bSet, 
	const std::string current = "", const size_t index = 0);

