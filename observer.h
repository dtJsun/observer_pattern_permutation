/*
* This class is the declaration of the abstract class Observer.
* The inherited classes are BTrackingObserver and HeapObserver.
* @author Zhe Sun
*/
#ifndef _OBSERVER_H_
#define _OBSERVER_H_
#include <iostream>
#include <vector>
using namespace std;

class  Observer{
    public:
    virtual ~Observer() {}
    virtual void getPermutation(int n) = 0;
};

#endif