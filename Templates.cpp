#include <iostream>
#include <string>
using namespace std;


template<class T> void mySwap(T& a, T& b) {
	T temp;
	temp = a;
	a = b;
	b = temp;
}
template<class T> void mySort(T* Arr, size_t _count) {
	T temp;
	for (size_t i = 0; i < _count; i++)
	{
		for (size_t j = 0; j < _count - 1; j++)
		{
			if (Arr[j] > Arr[j + 1]) {
				temp = Arr[j];
				Arr[j] = Arr[j + 1];
				Arr[j + 1] = temp;
			}
		}
	}
}
template<class T> T myHighest(T* Arr, size_t _count) {
	return Arr[_count-1];
}
void main() {
	int x = 12, y = 14;
	cout << x << " " << y << endl;
	mySwap(x, y);
	cout << x << " " << y << endl;

	string a = "Hello", b = "Goodbye";
	cout << a << " " << b << endl;
	mySwap(a, b);;
	cout << a << " " << b << endl;

	int intergarArr[10] = { 1,54,5,12,3,41,84,1,12,3 };
	string Arr[10] = { "a" , "b" , "d" , "c" , "a" , "f" , "z" , "e" , "t" , "f" };
	mySort(Arr,sizeof(Arr) / sizeof(string));
	mySort(intergarArr, sizeof(intergarArr)/sizeof(	int) );
	for (size_t i = 0; i < 10; i++)
	{
		cout << Arr[i] << " ";
		cout << intergarArr[i] << " ";
	}

	a = myHighest(Arr, 10);
	cout << a << endl;
	
}