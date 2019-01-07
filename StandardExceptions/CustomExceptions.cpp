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

class Test
{
public:
	void goesWrong()
	{
		throw CustomException();
	}	
};


int main()
{
	Test test;

	try
	{
		test.goesWrong();
	}
	catch (CustomException &e)
	{
		std::cout << "Caught exception: " << e.what() << std::endl;
	}

	for (;;)
	{
		if (GetAsyncKeyState(VK_ESCAPE))
			return 0;
	}
}