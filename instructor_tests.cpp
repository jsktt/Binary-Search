////////////////////////////////////////////////////////
// ECE 2574, Homework 1
//
// File name:   hw1_test.cpp
// Description: STARTER CODE
// Date:        1/2019  
//
#define CATCH_CONFIG_MAIN			// this line tells Catch to provide a main() function
#define CATCH_CONFIG_COLOUR_NONE	// this line avoids problems due to color-coding the output
#include "catch.hpp"
#include "hw3_function.h"


extern int funcCallCounter;

// The following set of tests needs to be expanded
TEST_CASE("Test Binary Count", "[binary]") {

	funcCallCounter = 0;

	int myArrayWithDuplication[10] = { -5, -5, 1, 5, 5, 10, 10, 11, 17, 25 };
	unsigned int count = binaryCount(myArrayWithDuplication, 0, 9, -5);
	CHECK(count == 2);
	REQUIRE(funcCallCounter > 1);

	funcCallCounter = 0;
	count = binaryCount(myArrayWithDuplication, 0, 9, 3);
	CHECK(count == 0);
	REQUIRE(funcCallCounter > 1);


	funcCallCounter = 0;
	count = binaryCount(myArrayWithDuplication, 0, 9, 100);
	CHECK(count == 0);
	REQUIRE(funcCallCounter > 1);

	funcCallCounter = 0;
	count = binaryCount(myArrayWithDuplication, 0, 9, -100);
	CHECK(count == 0);
	REQUIRE(funcCallCounter > 1);



}

TEST_CASE("Test Binary Successor", "[binary]") {

	funcCallCounter = 0;

	int myArrayWithNoDuplicate[10] = { -8, -6, -2, 1, 2, 5, 10, 11, 17, 25 };
	int successor = binarySuccessor(myArrayWithNoDuplicate, 0, 9, 10);
	CHECK(successor != -1);
	CHECK(successor < 10);
	if ((successor < 10) && (successor > -1)) {
		CHECK(myArrayWithNoDuplicate[successor] == 10);
	}
	else
	{
		CHECK(false); // force an error record.  
	}
	REQUIRE(funcCallCounter > 1); // must be recursive implementation. 

	funcCallCounter = 0;
	successor = binarySuccessor(myArrayWithNoDuplicate, 0, 9, -3);
	CHECK(successor != -1);
	CHECK(successor < 10);
	if ((successor < 10) && (successor > -1)) {
		CHECK(myArrayWithNoDuplicate[successor] == -2);
	}
	else
	{
		CHECK(false); // force an error record.  
	}
	REQUIRE(funcCallCounter > 1); // must be recursive implementation. 



	funcCallCounter = 0;
	successor = binarySuccessor(myArrayWithNoDuplicate, 0, 9, 100);
	CHECK(successor == -1);
	REQUIRE(funcCallCounter > 1);

	funcCallCounter = 0;
	successor = binarySuccessor(myArrayWithNoDuplicate, 0, 9, -100);
	CHECK(successor == 0);
	REQUIRE(funcCallCounter > 1);

}

TEST_CASE("Test Exponetiation", "[exp]") {

	funcCallCounter = 0;

	int result = expo(2, 10);
	CHECK(result == 1024);
	CHECK(funcCallCounter <= 5);
	CHECK(funcCallCounter > 2);
	REQUIRE(funcCallCounter > 1);

	funcCallCounter = 0;
	result = expo(2, 0);
	CHECK(result == 1);
	CHECK(funcCallCounter == 1);

	funcCallCounter = 0;
	result = expo(0, 2);
	CHECK(result == 0);
	CHECK(funcCallCounter == 1);

	funcCallCounter = 0;
	result = expo(-2, 13);
	CHECK(result == -8192);
	REQUIRE(funcCallCounter > 1);
	CHECK(funcCallCounter <= 8);
	CHECK(funcCallCounter > 2);

}

TEST_CASE("Test reverse", "[reverse]") {


	std::string s = "ab cd123";

	funcCallCounter = 0;
	std::string result = reverse(s, s.length());
	CHECK(result.compare("321dc ba") == 0);
	CHECK(funcCallCounter < 10);
	REQUIRE(funcCallCounter > 1);


	s = "";
	funcCallCounter = 0;
	result = reverse(s, s.length());
	CHECK(result.compare("") == 0);
	CHECK(funcCallCounter == 1);


}


TEST_CASE("Test  finding the minimum", "[minArray]") {

	funcCallCounter = 0;

	int myArray[10] = { -6, 25, 1, 2, 5, 10, -8, 11, 17, -2 };
	int minv = minArray(myArray, 0, 9);
	CHECK(minv == -8);
	CHECK(funcCallCounter > 3);
	REQUIRE(funcCallCounter > 1);

	funcCallCounter = 0;
	int anotherArray[1] = { 8 };
	minv = minArray(anotherArray, 0, 0);
	CHECK(minv == 8);
	CHECK(funcCallCounter == 1);

}

bool find(const std::vector<std::string>& pSet, const std::string target) {



	for (auto i = pSet.begin(); i < pSet.end(); i++) {
		std::string s = *i;
		if (target.length() == s.length())
		{
			bool stringmatch = true;
			for (unsigned int j = 0; j < target.length(); j++) {
				if (s.find(target.at(j)) == -1) stringmatch = false;
			}
			if (stringmatch == true) return true;
		}

	}
	return false;

}


TEST_CASE("Test PowerSet", "[PowerSet]") {

	std::string myString = "123";
	funcCallCounter = 0;
	std::vector<std::string> pSet;
	powerSet(pSet, myString);

	CHECK(pSet.size() == 8);
	CHECK(find(pSet, ""));
	CHECK(find(pSet, "1"));
	CHECK(find(pSet, "2"));
	CHECK(find(pSet, "3"));
	CHECK(find(pSet, "12"));
	CHECK(find(pSet, "23"));
	CHECK(find(pSet, "13"));
	CHECK(find(pSet, "321"));
	REQUIRE(funcCallCounter > 2);

	myString = "1234";
	funcCallCounter = 0;
	std::vector<std::string> pSet2;
	powerSet(pSet2, myString);

	CHECK(pSet2.size() == 16);
	CHECK(find(pSet2, ""));
	CHECK(find(pSet2, "1"));
	CHECK(find(pSet2, "2"));
	CHECK(find(pSet2, "3"));
	CHECK(find(pSet2, "12"));
	CHECK(find(pSet2, "23"));
	CHECK(find(pSet2, "13"));
	CHECK(find(pSet2, "321"));
	CHECK(find(pSet2, "4"));
	CHECK(find(pSet2, "41"));
	CHECK(find(pSet2, "42"));
	CHECK(find(pSet2, "43"));
	CHECK(find(pSet2, "412"));
	CHECK(find(pSet2, "423"));
	CHECK(find(pSet2, "413"));
	CHECK(find(pSet2, "4321"));

	REQUIRE(funcCallCounter > 2);



	myString = "";
	funcCallCounter = 0;
	std::vector<std::string> pSet3;
	powerSet(pSet3, myString);
	CHECK(pSet3.size() == 1);
	CHECK(find(pSet3, ""));
	REQUIRE(funcCallCounter == 1);
}