/*
* This class is the implementation of backtracking algorithm to generate permutations.
* This is the inherited class of Observer.
* @author Zhe Sun
*/
#ifndef _BTRACKINGOBSERVER_H
#define _BTRACKINGOBSERVER_H
#include "observer.h"
#include "subject.h"

class BTrackingObserver : public Observer {
    public:
    BTrackingObserver(Subject* sbj);
    void getPermutation(int n);
    
    private:
    void backTrackingPerm(vector<vector<int> >& result, vector<int>& solution,
            vector<int>& flag, vector<int>& nums, int step);
    void printVec(vector<vector<int> >& vec);
};

#endif