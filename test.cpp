/*  
	Alexander Howes
	820184866
	
	errorchecking: since we dont know the int array was dynamically allocated, or if it uses the <array> include, checking if size is correct is impossible. 
	this program does check if size is less than 3, because if so the routine is impossible.

	procedure: first i sort the data in place in acending order. then it enters a loop. it checks the current element and its successor for 0s, 1s, and duplicates.
	if there is a one and duplicate it automatically returns 1. if it detecs two 0s, then it also returns 0. if not, it ignores 1s and 0s in the calculations and 
	begins the process of seeing if the multiples exist. this process ignores all 1s and 0s because if the previous conditions are not met then they cannot effect the 
	outocome. the process saves all multiples in an array 'prods' which autosorts them in decending order. then on each pass it iterates
	through prods to check if that multiple has already existed and if the element in prods is smaller than the product, it exits the iteration for efficency.
	finally if all other conditions are not met, it simply iterates through the  array looking for matches of elements and new products that can exist. the algorithm
	and combined sorting of data are designed to over time have logarithmic growth with normal data.
	
	bugs:none know. works with 1s,0s,-1s.

	included: a main function that you can plug in numbers to test.
*/
#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;
int mul(int arr[], int size) {
	if (size < 3) {
		return 0;
	}
	typedef std::vector<int> ints;
	vector<int> prods;
	int i = 0, j, h,k, temp, zero=0, one, doub,flag;
	for (i = 0; i < size-1; i++) {
		for (j = 0; j < size-i-1; j++) {
			if (arr[j] > arr[j + 1]) {
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
	for (i = 0;i < size - 1;i++) {
		temp = 0;
		h = 1;
		if (arr[i] == 0) {
			while (arr[i] == 0) {
				i++; 
				zero++;
			}
		}
		if (arr[i] == 1) {
			one = 1;
			while (arr[i] == 1) {
				i++;
			}
		}
		if (zero > 1) {
			return 1;
		}
		if (arr[i] == arr[i + h]) {
			doub = 1;
		}
		if (one == 1 && doub == 1) {
			return 1;
		}
		if (arr[i + h] == 0 || arr[i + h] == 1) {
			while (arr[i + h] == 0 || arr[i + h] == 1) {
				h++;
			}
		}
		temp = arr[i] * arr[i + h];
		while (i+h<size) {
			flag = 0;
			for (j = 0;j < prods.size();j++) {
				if (prods[j] == temp) {
					flag = 1;
					h++;
					break;
				}
				if (prods[j] < temp) {
					break;
				}
			}
			if(flag==0) {
				for (j = i + 2;j < size;j++) {
					if (temp == arr[j]) {
						return 1;
					}
				}
				ints::iterator it = lower_bound(prods.begin(), prods.end(), temp, greater<int>());
				prods.insert(it, temp);
				h++;
			}
			if (arr[i] == arr[i + h]) {
				doub = 1;
			}
			if (one == 1 && doub == 1) {
				return 1;
			}
			if (arr[i + h] == 0|| arr[i + h] == 1) {
				while (arr[i + h] == 0 || arr[i + h] == 1) {
					h++;
				}
			}
			temp = arr[i] * arr[i + h];
		}
	}
	return 0;
}

int main() {
	int arr[] = {6,4,-3,-2,0,5};
	int size = 6;
	cout << mul(arr, size);
}
