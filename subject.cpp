#include "subject.h"

Subject* Subject::getInstance() {
	if (!instance) instance = new Subject();
	return instance;
}