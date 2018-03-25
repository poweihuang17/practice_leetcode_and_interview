#include <iostream>
#include <thread>

void hello()
{
	std::cout<<"Hello Concureent World\n";
}

int main()
{
	std::thread t(hello);
	t.join();
}