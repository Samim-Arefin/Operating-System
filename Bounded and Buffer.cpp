#include<bits/stdc++.h>
using namespace std;

int Mutex = 1;
int full = 0;
int Empty = 100, x = 0;

void producer()
{
	--Mutex;
	++full;
	--Empty;
	x++;
	std::cout << "\nProducer produces item " << x;
	++Mutex;
}

void consumer()
{
	--Mutex;
	--full;
	++Empty;
	std::cout << "\nConsumer consumes item " << x;
	x--;
	++Mutex;
}

int main()
{
	int n;
	std::cout << "\n1.Producer\n2.Consumer\n3.Exit";
	for (int i = 1; i > 0; i++) {

		std::cout << "\n\nEnter Choice:";
		std::cin >> n;

		switch (n) {
		case 1:
			if ((Mutex == 1) && (Empty != 0)) {
				producer();
			}
			else {
				std::cout << "Buffer is full!";
			}
			break;

		case 2:
			if ((Mutex == 1) && (full != 0)) {
				consumer();
			}
			else {
				std::cout << "Buffer is empty!";
			}
			break;
		case 3:
			exit(0);
			break;
		}
	}
}
