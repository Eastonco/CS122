#include "Queue.h"

int main(void) {

	Queue myqueue;

	int num = 0;

	cout << "Enter a number of minutes for the simulation > 10: ";
	cin >> num;
	system("cls");

	myqueue.runapp(num);

	return 0;
}