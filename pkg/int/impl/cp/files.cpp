#include <cp/files.h>
#include <exception>
#include <filesystem>
#include <sstream>

namespace fs = std::filesystem;

void cp::Files(const std::vector<std::string>& files, std::string_view dir)
{
	try
	{
		// Recursively create target directory if not existing.
		fs::create_directories(dir);

		for (const auto& f : files)
		{
			std::stringstream dirFile;
			fs::path srcFile = f;
			dirFile << dir << "/" << srcFile.filename().string();
			fs::copy_file(f, dirFile.str(), fs::copy_options::overwrite_existing);
		}
	}
	catch (std::exception& e)
	{
		std::cout << e.what();
		std::exit(1);
	}
}

