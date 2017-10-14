#include "amicablePairs.h"

int main() {

	clock_t start = clock();
	
	amicPr p1(100000000);

	clock_t end = clock();

	cout << "Run time for amicable" << double(end - start) / CLOCKS_PER_SEC << " secs" << endl;

	//p1.init();
	//p1.calcPairs(220);
	//p1.calcPairs(284);
	


	return 0;
}