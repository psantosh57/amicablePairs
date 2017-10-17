/*----------------------------------------------------------------
Copyright (c) 2014 Author: Jagadeesh Vasudevamurthy
file: amicabletest.cpp

On linux:
g++ amicable.cpp amicabletest.cpp
valgrind a.out

-----------------------------------------------------------------*/

/*----------------------------------------------------------------
This file test amicable object 
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
All includes here
-----------------------------------------------------------------*/
#include "amicable.h"

/*----------------------------------------------------------------
initialization of static
-----------------------------------------------------------------*/
bool amicable::_display = true;

/*----------------------------------------------------------------
Nothing can be changed in this file
DO Not use some weird formulas from internet
MUST solve from fundamentals.

Only knowledge required to solve this problem is to 
compute factor and resuse computed factors.
-----------------------------------------------------------------*/
int main() {
#if 0
	clock_t start = clock();
	unsigned int n = 100000000;
	amicable a(n);
	clock_t end = clock();
	double d = double(end - start) / CLOCKS_PER_SEC;
	cout << "Run time for amicable for n = " << n << " is " << d << " secs" << endl;
	cout << "I will fail if you take more than 45 sec\n";
#endif // 0

	amicable ami(2);
	for (int i = 1; i < 25; i++) {

		ami.populateArray(i);

	}
	
	ami.displayArray(23, 0);
	ami.displayArray(23, 1);
	ami.displayArray(23, 2);
	ami.displayArray(23, 3);
	ami.displayArray(23, 4);
	ami.displayArray(23, 5);
	ami.displayArray(23, 6);

	ami.displayArray(23, 7);
#if 0
	ami.displayArray(23, 8);
	ami.displayArray(23, 9);
	ami.displayArray(23, 10);
	ami.displayArray(23, 11);
	ami.displayArray(23, 12);
#endif // 0







  return 0 ;
}

//EOF

