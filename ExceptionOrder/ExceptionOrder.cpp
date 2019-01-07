#include <iostream>
#include <exception>
#include <Windows.h>

class CustomException : public std::exception
{
public:
	virtual const char* what() const throw()
	{
		return "Something went wrong!";
	}
};

void goesWrong()
{
	bool error1Detected = true;
	bool error2Detected = false;

	if (error1Detected)
		throw std::bad_alloc();

	if (error2Detected)
		throw std::exception();
}

void test()
{
	throw CustomException();
}


int main()
{
	try
	{
		goesWrong();
	}
	catch (std::bad_alloc &e) // Sub-class before parent - otherwise wrong catch is used (bad_alloc derived from exception)
	{
		std::cout << "Catching bad_alloc: " << e.what() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Catching exception: " << e.what() << std::endl;
	}

	try
	{
		test();
	}
	catch (std::exception &e)
	{
		std::cout << "Catching exception: " << e.what() << std::endl;
	}
	catch (CustomException &e)
	{
		std::cout << "Custom exception: " << e.what()  << std::endl;
	}

	for (;;)
	{
		if (GetAsyncKeyState(VK_ESCAPE))
			return 0;
	}
}