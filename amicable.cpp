#include "amicable.h"

void amicable::populateArray(int n) {
	
	int m = n;
	int j = 1;
	int i = 0;
	int fact = 2;
	//int mod = m % _a[i];
	int mod = m % fact;
	int div = m;
	int count = 4;
	_array[n - 1][0] = m;

	if (n == 1) {

		_array[n - 1][1] = 0;

	}

	//cout << "Number is " << n << endl;

	while (fact <= n/2 && div > fact) {

		//mod = m % _a[i];
		//div = m / _a[i];
		mod = m % fact;
		div = m / fact;

		if (mod == 0 && div != 1) {

			//_array[n - 1][j++] = _a[i];
			//cout << "Factor is " << fact << endl;
			_array[n - 1][j++] = fact;


			//p = m;
			int k = 0;
			
			//m /= _a[i];
			m /= fact;

			int temp = _array[m - 1][k];
			
			if (!ifPresent((n - 1), j, temp)) {
				//cout << "Factor is " << _array[m - 1][k] << endl;
				_array[n - 1][j++] = _array[m - 1][k];

			}

			if (_array[m - 1][k + 1] != 0) {
				
				k++;

				while (_array[m - 1][k] != 0) {

					temp = _array[m - 1][k];

					if (!ifPresent((n - 1), j, temp)) {
						//cout << "Factor is " << temp << endl;
						_array[n - 1][j++] = _array[m - 1][k];
					
					}
					
					//temp = _a[i] * _array[m - 1][k++];
					temp = fact * _array[m - 1][k++];
					
					if (!ifPresent((n - 1), j, temp)) {
						//cout << "Factor is " << temp << endl;
						_array[n - 1][j++] = temp;

					}
						
				}

				break;

			}

		}

		fact++;
	}
	
	_array[n - 1][j++] = 0;

}

void amicable::displayArray(int row, int col) {

	cout << _array[row][col] << endl;

}

bool amicable::ifPresent(int index, int limit, int n) {

	for (int i = 0; i < limit; i++) {

		if (_array[index][i] == n) {

			return true;
		}
	}

	return false;

}


int amicable::addFactors(int n) {

	if (n == 1) {

		return 1;
	}
	else {
		
		int sum = 1;
		int i = 1;

		while (_array[n - 1][i] != 0) {

			sum += _array[n - 1][i];
			i++;
		}

		return sum;

	}

	
}

void amicable::verifySums(int n) {

	int s1 = addFactors(n);
	//cout << "Sum of " << n << " is " << s1 << endl;
	if (s1 < n) {

		int s2 = addFactors(s1);
		//cout << "Sum of " << s1 << " is " << s2 << endl;

		if (s2 == n) {

			cout << _count << ": " << s1 << " and " << n << " are amicable pairs!" << endl;
			_count++;
		}
		else {

			//cout << "Not amicable pairs" << endl;
		}

	}
	

}