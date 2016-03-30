#include "checkinput.h"

CheckInput* CheckInput::getInstance() {
	if (!instance) instance = new CheckInput();
	return instance;
}

//Check whether the input is a number between 1 and 9
int CheckInput::isValid(const string& s) {

	if (s.length() > 1) return -1;

	if (!isdigit(s[0])) return -1;

	return s[0] - '0' > 9 ? -1 : s[0] - '0';

}