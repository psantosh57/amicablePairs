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
	unsigned int n = 10000000;
	amicable a(n);
	clock_t end = clock();
	double d = double(end - start) / CLOCKS_PER_SEC;
	cout << "Run time for amicable for n = " << n << " is " << d << " secs" << endl;
	cout << "I will fail if you take more than 45 sec\n";
#endif // 0
	clock_t start = clock();
	amicable ami(10000000);
	int count = 0;
#if 1
	for (int i = 2; i < 10000000; i++) {
		//cout << "Working for " << i << endl;
#if 0
		if (i == 220) {

			cout << "Wait here" << endl;
		}
#endif // 0

		int sum = ami.populateArray1(i);

		if (sum < i) {

			if (sum % 6 != 0 && ((sum % 2 == 0 && i % 2 == 0) || (sum % 2 != 0 && i % 2 != 0))) {

				if (ami.populateArray1(sum) == i) {

					cout << count << " : " << i << " and " << sum << " are amicable pairs!" << endl;
					count++;
				}

			}

		}

		
		
		
		//int temp = ami.addFactors(i);
		//if (temp < i) {

			//ami.verifySums(i);
		//}



	}

	clock_t end = clock();
	double d = double(end - start) / CLOCKS_PER_SEC;
	cout << "Run time for amicable for n = " << 10000000 << " is " << d << " secs" << endl;

#endif // 0

	//darray<darray<int>> a(1);
	//int i = 25;
	//cout << sqrt(i) << endl;

	return 0 ;
}

//EOF

