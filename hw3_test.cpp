////////////////////////////////////////////////////////
// ECE 2574, Homework 3
// File name:   hw3_test.cpp
// Description: STARTER CODE
// Date:        2/2019  
//
#define CATCH_CONFIG_MAIN			// this line tells Catch to provide a main() function
#define CATCH_CONFIG_COLOUR_NONE	// this line avoids problems due to color-coding the output
#include "catch.hpp"
#include "hw3_function.h"


extern int funcCallCounter; // Do not tounch this line of code.  
						//This is a global variable helping to count the number of times 
						//that a function is called

// The following set of tests needs to be expanded

TEST_CASE("Test Binary Count", "[binaryCount]") {

	int arr1[] = { 1,2,2,2,3,4,4 };
	int arr2[] = { 5, 5, 5, 5, 5 };
	int arr3[] = { 1, 3, 5, 7 };

	REQUIRE(binaryCount(arr1, 0, 6, 2) == 3);
	REQUIRE(binaryCount(arr2, 0, 4, 5) == 5);
	REQUIRE(binaryCount(arr3, 0, 3, 4) == 0);
	
}

TEST_CASE("Test Binary Successor", "[binarySuccessor]") {

	int arr1[] = { 1,2,3,4,5 };
	int arr2[] = { 5,6,7,8,9 };
	int arr3[] = { 1,3,5,7 };

	SECTION("Successor present in the array") {
		REQUIRE(binarySuccessor(arr1, 0, 4, 3) == 2); // Successor of 3 is 4
		REQUIRE(binarySuccessor(arr2, 0, 4, 7) == 2); // Successor of 7 is 8
	}

	SECTION("Successor at the end of the array") {
		REQUIRE(binarySuccessor(arr1, 0, 4, 4) == 3); // Successor of 4 is 5 (last element)
	}

	SECTION("No successor in the array") {
		REQUIRE(binarySuccessor(arr3, 0, 3, 7) == 3); // No successor of 7
		REQUIRE(binarySuccessor(arr2, 0, 4, 10) == -1); // No successor of 10
	}

}

TEST_CASE("Test Exponetiation", "[expo]") {

	REQUIRE(expo(2, 3) == 8);
	REQUIRE(expo(5, 0) == 1);
	REQUIRE(expo(3, 2) == 9);

}

TEST_CASE("Test String Reverse", "[reverse]") {

	REQUIRE(reverse("hello", 5) == "olleh");
	REQUIRE(reverse("world", 5) == "dlrow");
	REQUIRE(reverse("", 0) == "");

}


TEST_CASE("Test finding the minimum", "[minArray]") {

	int arr1[] = { 3, 1, 4, 1, 5, 9 };
	int arr2[] = { 2, 2, 2, 2, 2 };

	REQUIRE(minArray(arr1, 0, 5) == 1);
	REQUIRE(minArray(arr2, 0, 4) == 2);
	
}



TEST_CASE("Test PowerSet", "[powerSet]") {
	
	std::vector<std::string> result;
	powerSet(result, "ab");
	std::vector<std::string> expected = { "", "a", "b", "ab" };

	REQUIRE(result.size() == expected.size());
	for (size_t i = 0; i < expected.size(); ++i) {
		REQUIRE(std::find(result.begin(), result.end(), expected[i]) != result.end());
	}

}