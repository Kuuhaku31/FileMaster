
#include "FileMaster.hpp"

int main()
{
	std::cout << "Hello, World!" << std::endl;

	std::string path;
	if (getPath(path))
	{
		NameFiles(path);
	}
	else
	{
		std::cout << "No folder selected." << std::endl;
	}

	return 0;
}
