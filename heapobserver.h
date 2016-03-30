/*
* This class is the implementation of Heap's algorithm to generate permutations.
* This is the inherited class of Observer
* @author Zhe Sun
*/

#ifndef _HEAPOBSERVER_H
#define _HEAPOBSERVER_H
#include "observer.h"
using namespace std;

class Subject;

class HeapObserver : public Observer {
    
    public:
    HeapObserver(Subject* sbj);
    void getPermutation(int n);
    
    private:
    void heapPermute (vector<vector<int> >& result,
            vector<int>& nums, int n);
    void printVec(vector<vector<int> >& vec);
};

#endif