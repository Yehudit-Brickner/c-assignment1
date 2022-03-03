/**
 * An example of how to write unit tests.
 * Use this as a basis to build a more complete Test.cpp file.
 * 
 * IMPORTANT: Please write more tests - the tests here are only for example and are not complete.
 *
 * AUTHORS: <Yehudit Brickner>
 * 
 * Date: 2021-02
 */

#include "doctest.h"
#include "mat.hpp"
using namespace ariel;

#include <string>
#include <algorithm>
using namespace std;

/**
 * Returns the input string without the whitespace characters: space, newline and tab.
 * Requires std=c++2a.
 */
string nospaces(string input) {
	std::erase(input, ' ');
	std::erase(input, '\t');
	std::erase(input, '\n');
	std::erase(input, '\r');
	return input;
}


TTEST_CASE("tiny"){
	CHECK(nospaces(mat(1, 1, '@', '-')) == nospaces("@"));
	
	CHECK(nospaces(mat(1, 1, '&', '*')) == nospaces("&&&"));
	
	CHECK(nospaces(mat(1, 1, '&', '*')) == nospaces("&\n
													 &\n
													 &"));

}

TEST_CASE("small square"){
	CHECK(nospaces(mat(3, 3, '+', '*')) == nospaces("+++\n
													 +*+\n
													 +++"));

	CHECK(nospaces(mat(5, 5, '^', '%')) == nospaces("^^^^^\n
													 ^$$$^\n
													 ^$^$^\n
													 ^$$$^\n
													 ^^^^^"));	
}

TEST_CASE("big square"){
	CHECK(nospaces(mat(19, 19, '@', '-')) == nospaces("@@@@@@@@@@@@@@@@@@@\n
													   @-----------------@\n
													   @-@@@@@@@@@@@@@@@-@\n
													   @-@-------------@-@\n
													   @-@-@@@@@@@@@@@-@-@\n
													   @-@-@---------@-@-@\n
													   @-@-@-@@@@@@@-@-@-@\n
													   @-@-@-@-----@-@-@-@\n
													   @-@-@-@-@@@-@-@-@-@\n
													   @-@-@-@-@-@-@-@-@-@\n
													   @-@-@-@-@@@-@-@-@-@\n
													   @-@-@-@-----@-@-@-@\n
													   @-@-@-@@@@@@@-@-@-@\n
													   @-@-@---------@-@-@\n
													   @-@-@@@@@@@@@@@-@-@\n
													   @-@-------------@-@\n
													   @-@@@@@@@@@@@@@@@-@\n
													   @-----------------@\n
													   @@@@@@@@@@@@@@@@@@@\n"));
	
}

TEST_CASE("small rectangel") {
	CHECK(nospaces(mat(9, 7, '@', '-')) == nospaces("@@@@@@@@@\n
													 @-------@\n
													 @-@@@@@-@\n
													 @-@---@-@\n
													 @-@@@@@-@\n
													 @-------@\n
													 @@@@@@@@@"));
	
	CHECK(nospaces(mat(5, 11, '&', '-')) == nospaces("&&&&&&&&&&&\n
													  &---------&\n
													  &-&&&&&&&-&\n
													  &---------&\n
													  &&&&&&&&&&&\n"));
}

TEST_CASE("big rectangel"){
	CHECK(nospaces(mat(25, 15, '*', '!')) == nospaces("*************************\n
													   *!!!!!!!!!!!!!!!!!!!!!!!*\n
													   *!*********************!*\n
													   *!*!!!!!!!!!!!!!!!!!!!*!*\n
													   *!*!*****************!*!*\n
													   *!*!*!!!!!!!!!!!!!!!*!*!*\n
													   *!*!*!*************!*!*!*\n
													   *!*!*!*!!!!!!!!!!!*!*!*!*\n
													   *!*!*!*************!*!*!*\n
													   *!*!*!!!!!!!!!!!!!!!*!*!*\n
													   *!*!*****************!*!*\n
													   *!*!!!!!!!!!!!!!!!!!!!*!*\n
													   *!*********************!*\n
													   *!!!!!!!!!!!!!!!!!!!!!!!*\n
													   *************************"));
}

TEST_CASE("bad input even") {
    CHECK_THROWS(mat(10, 5, '$', '%'));
    
	CHECK_THROWS(mat(7, 2, '$', '%'));

	CHECK_THROWS(mat(6, 2, '$', '%'));
}

TEST_CASE("bad input zero") {
    CHECK_THROWS(mat(0, 5, '$', '%'));
    
	CHECK_THROWS(mat(7, 0, '$', '%'));

	CHECK_THROWS(mat(0, 0, '$', '%'));
}

TEST_CASE("bad input negative") {
    CHECK_THROWS(mat(-7, 5, '$', '%'));
    
	CHECK_THROWS(mat(7, -2, '$', '%'));

	CHECK_THROWS(mat(-9, -2, '$', '%'));
}

TEST_CASE("bad input same symbol") {
    CHECK_THROWS(mat(10, 5, '%', '%'));
}

TEST_CASE("more then 1 problem in the input"){
	CHECK_THROWS(mat(-7, 5, '$', '$')); // negative and same symbol
    
	CHECK_THROWS(mat(0, -2, '$', '%')); // zero and negative

	CHECK_THROWS(mat(4, 0, '$', '%')); // zero and even

	CHECK_THROWS(mat(0, 0, '$', '$')); // zero and same symbol
}

TEST_CASE("wrong parameters"){
	CHECK_THROWS(mat(3.5, 7, '$', '%'));	//  first variable not an int

	CHECK_THROWS(mat(5, 1.4, '$', '%'));	//  second variable not an int
}
