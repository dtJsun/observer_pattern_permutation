/*
* This class is the implementation of input check.
* The valid inputs are numbers 1~9.
* @author Zhe Sun
*/

#ifndef _CHECKINPUT_H
#define _CHECKINPUT_H
#include <string>
using namespace std;

class CheckInput {

public:
	static CheckInput* getInstance();
	int isValid(const string& s);

private:
	static CheckInput* instance;
	CheckInput () {}
	CheckInput (const CheckInput&);
	CheckInput& operator=(const CheckInput&);
};

#endif