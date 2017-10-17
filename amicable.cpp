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
	int mod = m % _a[i];
	int div = m;
	int count = 4;
	_array[n - 1][0] = m;

	if (n == 1) {

		_array[n - 1][1] = 0;

	}



	while (i < count && div > _a[i]) {

		mod = m % _a[i];
		div = m / _a[i];

		if (mod == 0 && div != 1) {

			_array[n - 1][j++] = _a[i];

			//p = m;
			int k = 0;
			
			m /= _a[i];
			if (_array[m - 1][k + 1] != 0) {
				
				k++;

				while (_array[m - 1][k] != 0) {

					int temp = _array[m - 1][k];

					if (!ifPresent((n - 1), j, temp)) {

						_array[n - 1][j++] = _array[m - 1][k];
					
					}
					
					temp = _a[i] * _array[m - 1][k++];
					
					if (!ifPresent((n - 1), j, temp)) {
					
						_array[n - 1][j++] = temp;

					}
						
				}

				break;

			}
			else {

				_array[n - 1][j++] = _array[m - 1][k++];
				break;
			}

			

#if 0
			while (p % _a[i] == 0 && p != 1) {


				p /= 2;

				//Add code to reuse factors





			}
#endif // 0

			//m = p;
			//m = m / _a[i];

		}


		i++;
	}
	
	_array[n - 1][j++] = 0;

	//cout << _array[n - 1][0] << endl;
	
}

	





#if 0




	//while (m >= _a[i]) {

		while (m / _a[i] != 0 && m != 1) {

			if (m % _a[i] == 0) {

				p = m;
				int k = 1;
				_array[n - 1][j++] = _a[i];
				p /= _a[i];
				while (_array[p - 1][k] != 0) {

					_array[n - 1][j++] = _array[p - 1][k++];
				}


				while (p % _a[i] == 0 && p != 1) {


					p /= 2;

					//Add code to reuse factors





				}


				//m = p;
				//m = m / _a[i];

			}


			i++;
		}

	//}

	

	cout << _array[4][0] << endl;
}

#endif // 0


void amicable::displayArray(int row, int col) {

	cout << _array[row][col] << endl;

}

void amicable::calcFactors(int n) {

	darray<int> sum;
	int i = 0, j = 0;

	while (_array[n - 1][i] != 0) {

		sum[j++] = _array[n - 1][i++];

	}

	i = 0;
	while (_array[n - 1][i + 1] != 0) {

		sum[j++] = _array[n - 1][i] * _array[n - 1][i + 1];
	}


}

bool amicable::ifPresent(int index, int limit, int n) {

	for (int i = 0; i < limit; i++) {

		if (_array[index][i] == n) {

			return true;
		}
	}

	return false;

}
