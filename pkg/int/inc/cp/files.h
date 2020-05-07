#ifndef CP_FILE_H_
#define CP_FILE_H_

#include <iostream>

// Perform basic operations around copying.
namespace cp
{
	// Copy files to a directory.
	void Files(const std::vector<std::string>& files, std::string_view dir);
}

#endif //CP_FILE_H_
