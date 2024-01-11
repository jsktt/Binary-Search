////////////////////////////////////////////////////////
// ECE 2574, Project 3, Junsung Kim
// File name:   hw3_function.cpp
// Description: STARTER CODE
// Date:        11/2023  
//
#include "hw3_function.h"


int funcCallCounter = 0;  // Do not tounch this line of code.  
						//This is a global variable helping to count the number of times 
						//that a function is called


int expo(const int m, const unsigned int n) {
	
	funcCallCounter++;  // Do not tounch this line of code.  
						//This is a global variable helping to count the number of times 
						//that this function is called
	

	//Add your code..............

	//base cases
	if (n == 0) return 1; //n^0 = 1
	if (m == 0) return 0; // n^0 = 0

	//recursive case
	if (n % 2 == 0) {
		//even
		int halfPower = expo(m, n / 2);
		return halfPower * halfPower;
	}
	else {
		//n is odd
		int halfPower = expo(m, (n - 1) / 2);
		return m * halfPower * halfPower;
	}
}

std::string reverse(const std::string s, const unsigned int size) {
	funcCallCounter++;  // Do not tounch this line of code.  
						//This is a global variable helping to count the number of times 
						//that this function is called

	

	//Add your code..............

	if (size == 0) return "";
	return s[size - 1] + reverse(s, size - 1);

	return("place holder");

}

int minArray(const int anArray[], const  int first, const  int last) {
	funcCallCounter++;  // Do not tounch this line of code.  
						//This is a global variable helping to count the number of times 
						//that this function is called

	//Add your code..............
	if (first == last) return anArray[first];
	int mid = (first + last) / 2;
	return std::min(minArray(anArray, first, mid), minArray(anArray, mid + 1, last));

}

int binaryCount(const int anArray[], const  int first, const int last, const int target)
{
	funcCallCounter++;  // Do not tounch this line of code.  
						//This is a global variable helping to count the number of times 
						//that this function is called


	
	//Add your code..............

	if (first > last) return 0;
	int mid = (first + last) / 2;
	if (anArray[mid] == target)
		return 1 + binaryCount(anArray, first, mid - 1, target) + binaryCount(anArray, mid + 1, last, target);
	else if (anArray[mid] < target)
		return binaryCount(anArray, mid + 1, last, target);
	else
		return binaryCount(anArray, first, mid - 1, target);

	return 0;
}  


int binarySuccessor(const int anArray[], const  int first, const int last, const int target)
{
	funcCallCounter++;  // Do not tounch this line of code.  
						//This is a global variable helping to count the number of times 
						//that this function is called

	//Add your code..............
	//base case: invalid range
	if (first > last) {
		return -1;
	}

	int mid = first + (last - first) / 2;

	if (anArray[mid] >= target) {
		// check if first or previous element is smallest
		if (mid == first || anArray[mid - 1] < target) {
			return mid;
		}
		else {
			//searching left half
			return binarySuccessor(anArray, first, mid - 1, target);
		}
	}
	else {
		//searching right half
		return binarySuccessor(anArray, mid + 1, last, target);
	}
			
}





void powerSet(std::vector<std::string>& pSet, const std::string bSet, 
	const std::string current, const size_t index) {

	funcCallCounter++;  // Do not tounch this line of code.  
							//This is a global variable helping to count the number of times 
							//that this function is called

	//Add your code..............
	if (index == bSet.length()) {
		pSet.push_back(current);
		return;
	}

	// Include the current character
	powerSet(pSet, bSet, current + bSet[index], index + 1);

	// Exclude the current character
	powerSet(pSet, bSet, current, index + 1);
}



