#include "heapobserver.h"
#include "subject.h"
#include <time.h>
#include <fstream>
using namespace std;

HeapObserver::HeapObserver(Subject* sbj){
        sbj->addObserver(this);
        cout << "HeapObserver registered" << endl;
    }

//Initialize data and generate permutations by calling heapPermute
void HeapObserver::getPermutation(int n){
    
    long begin = clock();

    if (n == 0) return;

    vector<int> nums; // Generate numbers 1 to n
    for (int i = 1; i <= n; i++)
        nums.push_back(i);
    
    vector<vector<int> > permutations;
     
    heapPermute(permutations, nums, n);

    long end = clock();
    cout << "Heap's algorithm runtime: " << (double)(end - begin)/CLOCKS_PER_SEC << " s" << endl;
    printVec(permutations);
}

//Generate permutation of numbers 1 to n through Heap's algorithm
void HeapObserver::heapPermute(vector<vector<int> >& result, vector<int>& nums, int n){
    if (n == 1) {
        result.push_back(nums);
        return;
    }
    
    for (int i = 0; i < n-1; i++){
        heapPermute(result, nums, n-1);
        if (n%2 == 0){
            swap(nums[i],nums[n-1]);
        } else {
            swap(nums[0],nums[n-1]);
        }
    }
    heapPermute(result, nums, n-1);
}

//output the results in a local file
void  HeapObserver::printVec(vector<vector<int> >& vec){

    ofstream out("output_Heap");

    out << "Heap's algorithm:\n";

    for (int i = 0; i < vec.size(); i++){
        out << "[ ";
        for (int j = 0; j < vec[i].size(); j++){
            out << vec[i][j] << " ";
        }
        out << "] ";
        if ((i + 1) % 4 == 0) out << "\n";
    }
}

