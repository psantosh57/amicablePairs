#include "amicablePairs.h"

void amicPr::calcPairs(int n) {

		int sum = 0;
		int num = _array[n];

		for (int i = 1; i <= (n / 2); ++i) {

			if (n % i == 0) {

				sum += i;

			}
		}
		//cout << "Sum of divisible factors is " << sum << endl;
		_array[n] = sum;

		if (sum < n) {

			if (_array[sum] == n) {

				cout << sum << " and " << n << " are amicable pairs!" << endl;
			}
		}


}

void amicPr::init() {

	for (int i = 1; i < _limit; ++i) {

		calcPairs(i);
	}

}
