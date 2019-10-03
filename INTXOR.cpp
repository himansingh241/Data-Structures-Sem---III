/*
 * Author : Naveen Rohilla
 * Objective : INTXOR
 */
 
 
#include <iostream>
using namespace std;

void cycle4(int * & arr, int & start, int iteration) {
	while (iteration--) {
		int a, b, c, d;
		cout << "1 " << start << " " << start + 1 << " " << start + 2 << endl;
		cin >> a;
		cout << "1 " << start << " " << start + 1 << " " << start + 3 << endl;
		cin >> b;
		cout << "1 " << start << " " << start + 2 << " " << start + 3 << endl;
		cin >> c;
		cout << "1 " << start + 1 << " " << start + 2 << " " << start + 3 << endl;
		cin >> d;
		arr[start + 1] = a ^ d ^ b;
		arr[start + 2] = a ^ d ^ c;
		arr[start] = a ^ arr[start + 1] ^ arr[start + 2];
		arr[start + 3] = c ^ arr[start] ^ arr[start + 2];
		start += 4;
	}
}
void cycle5(int * & arr, int & start, int iteration) {
	while (iteration--) {
		int a, b, c, d, e;
		cout << "1 " << start << " " << start + 1 << " " << start + 2 << endl;
		cin >> a;
		cout << "1 " << start << " " << start + 1 << " " << start + 4 << endl;
		cin >> b;
		cout << "1 " << start << " " << start + 3 << " " << start + 4 << endl;
		cin >> c;
		cout << "1 " << start + 1 << " " << start + 2 << " " << start + 3 << endl;
		cin >> d;
		cout << "1 " << start + 2 << " " << start + 3 << " " << start + 4 << endl;
		cin >> e;
		arr[start + 3] = a ^ b ^ e;
		arr[start + 2] = b ^ c ^ d;
		arr[start] = d ^ e ^ b;
		arr[start + 1] = d ^ arr[start + 2] ^ arr[start + 3];
		arr[start + 4] = e ^ arr[start + 2] ^ arr[start + 3];
		start += 5;
	}
}
void cycle7(int * & arr, int & start, int iteration) {
	while (iteration--) {
		int a, b, c, d, e, f, g;
		cout << "1 " << start << " " << start + 1 << " " << start + 2 << endl;
		cin >> a;
		cout << "1 " << start << " " << start + 1 << " " << start + 6 << endl;
		cin >> b;
		cout << "1 " << start << " " << start + 5 << " " << start + 6 << endl;
		cin >> c;
		cout << "1 " << start + 1 << " " << start + 2 << " " << start + 3 << endl;
		cin >> d;
		cout << "1 " << start + 2 << " " << start + 3 << " " << start + 4 << endl;
		cin >> e;
		cout << "1 " << start + 3 << " " << start + 4 << " " << start + 5 << endl;
		cin >> f;
		cout << "1 " << start + 4 << " " << start + 5 << " " << start + 6 << endl;
		cin >> g;
		arr[start + 4] = a ^ b ^ e ^ f ^ g;
		arr[start + 3] = a ^ c ^ d ^ g ^ arr[start + 4];
		arr[start] = d ^ a ^ arr[start + 3];
		arr[start + 5] = f ^ arr[start + 3] ^ arr[start + 4];
		arr[start + 6] = g ^ arr[start + 4] ^ arr[start + 5];
		arr[start + 1] = b ^ arr[start] ^ arr[start + 6];
		arr[start + 2] = a ^ arr[start] ^ arr[start + 1];
		start += 7;
	}
}
void display(int * & arr, int & n) {
	cout << "2 ";
	for (int i = 1; i <= n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int * arr = new int [n + 1]{0};
		int start =  1;
		if (n % 4 == 0) {
			cycle4(arr, start, n / 4);
		}
		else if (n % 4 == 1) {
			cycle4(arr, start, n / 4 - 1);
			cycle5(arr, start, 1);
		}
		else if (n % 4 == 2) {
			cycle4(arr, start, n / 4 - 2);
			cycle5(arr, start, 2);
		}
		else if (n % 4 == 3) {
			cycle4(arr, start, n / 4 - 1);
			cycle7(arr, start, 1);
		}
		display(arr, n);
		int status;
		cin >> status;
		if (status == -1) {
			exit(0);
		}
	}
	return 0;
}

