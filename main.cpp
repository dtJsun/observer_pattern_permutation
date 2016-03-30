/* This program is the implementation of two permutation generation algorithms, 
*  namely backtracking algorithm and Heap’s algorithm. For practice purpose, I 
*  use Singleton and Observer pattern to implement and organize the algorithms. 
*  
*  The class Subject accepts an input as string and checks its legitimacy. If 
*  the input is valid, Subject notifies the classes BTrackingObserver and 
*  HeapObserver to generate the permutations and write outputs into local files.
*  
*  @author Zhe Sun
*/
#include "subject.h"
#include "checkinput.h"

Subject* Subject::instance = NULL;
CheckInput* CheckInput::instance = NULL;

int main() {

	Subject* subject = Subject::getInstance();
	CheckInput* checkInput = CheckInput::getInstance();
	HeapObserver heapObs(subject);
	BTrackingObserver btObs(subject);

	while (true){
		cout << "Input a number n to get permutations from 1 to 9: ";
		string s;
		cin >> s;
		int n = checkInput->isValid(s);
		if (n == -1){
			cout << "Please input valid number" << endl;
			continue;
		}
		subject->getVal(n);
		cout << "The outputs are located at current directory" << endl;
	}

}
