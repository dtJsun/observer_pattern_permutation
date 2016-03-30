#include "btrackingobserver.h"
#include "subject.h"
#include <fstream>
#include <time.h>

BTrackingObserver::BTrackingObserver(Subject* sbj){
    sbj->addObserver(this);
    cout << "BTrackingObserver registered" << endl;
}

//Initialize data and generate permutations by calling backTrackingPerm
void BTrackingObserver::getPermutation(int n){
    
    long begin = clock();

    if (n == 0) return;
    
    vector<vector<int> > permutations;

    vector<int> nums; // Generate numbers 1 to n
    for (int i = 1; i <= n; i++)
        nums.push_back(i);
    
    vector<int> flag(n, 0);
    vector<int> solution;
    
    backTrackingPerm(permutations, solution, flag, nums, 0);
    long end = clock();
    cout << "Backtracking runtime: " << (double)(end - begin)/CLOCKS_PER_SEC << " s" << endl;
    printVec(permutations);
}

//Generate the permutations of number 1 to n through backtracking algorithm
void BTrackingObserver::backTrackingPerm(vector<vector<int> >& result, 
            vector<int>& solution, vector<int>& flag, 
            vector<int>& nums, int step){
     
    if (step == nums.size()){
        result.push_back(solution);
        return;
    }

    for (int i = 0; i < nums.size(); i++){
        if (flag[i] == 0){
            flag[i] = 1;
            solution.push_back(nums[i]);
            backTrackingPerm(result, solution, flag, nums, step+1);
            solution.pop_back();
            flag[i] = 0;
        }
    }
}

//Output the results in a local file
void  BTrackingObserver::printVec(vector<vector<int> >& vec){

    ofstream out("output_Backtracking");

    out << "Backtracking algorithm:\n";

    for (int i = 0; i < vec.size(); i++){
        out << "[ ";
        for (int j = 0; j < vec[i].size(); j++){
            out << vec[i][j] << " ";
        }
        out << "] ";
        if ((i + 1) % 4 == 0) out << "\n";
    }
}



