#include "amicable.h"
#if 0

void amicable::calcPairs(int n) {

	int sum = 1;
	int num = _array[n];
	int i = 0;
	bool isOdd = false;

	if (n % 2 != 0) {
		i = 3;
		isOdd = true;
	}
	else {

		i = 2;
	}

	while (i <= n / 2) {

		if (n % i == 0) {

			sum += i;

		}

		if (isOdd) {

			i += 2;
		}
		else {

			i++;
		}


	}

#if 0
	for (int i = 1; i <= (n / 2);) {

		if (n % i == 0) {

			sum += i;

		}
}
#endif // 0

	//cout << "Sum of divisible factors is " << sum << endl;
	_array[n] = sum;

	if (sum < n) {

		if (_array[sum] == n) {

			cout << sum << " and " << n << " are amicable pairs!" << endl;
		}
	}


}



void amicable::init() {

	for (int i = 1; i < _limit; ++i) {

		calcPairs(i);
	}

}

#endif // 0

void amicable::populateArray(int n) {
	
	int m = n;
	int j = 1;
	int i = 0;
	int p = 0;

	_array[m - 1][0] = m;

	while (m >= _a[i]) {

		while (m / _a[i] != 0 && m != 1) {

			if (m % _a[i] == 0) {

				p = m;

				while (p % _a[i] == 0 && p != 1) {

					_array[n - 1][j++] = _a[i];
					p /= 2;

				}
				m = p;
				//m = m / _a[i];

			}


			i++;
		}

	}

		

	cout << _array[4][0] << endl;
}

