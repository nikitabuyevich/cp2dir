#include <iostream>
#include <tuple>
#include <vector>
#include <exception>
#include <boost/program_options.hpp>

namespace bpo = boost::program_options;

namespace cmd
{
	std::tuple<std::vector<std::string>, std::string> Parse(int argc, char** argv)
	{
		bpo::options_description
			desc
			("cp2dir: Copy a list of files to another directory."
			 "\nUsage");
		try
		{
			desc.add_options()
				("help,h", "Display usage.")
				("files,f",
					bpo::value<std::vector<std::string>>()->multitoken()->value_name("list of strings"),
					"List of files to copy contents from. Must be a full path.")
				("dir,d",
					bpo::value<std::string>()->value_name("string"),
					"Destination directory to copy contents to. Must be a full path");

			bpo::variables_map vm;
			bpo::store(bpo::parse_command_line(argc, argv, desc), vm);

			if (argc == 1 ||
				vm.count("help") ||
				!(vm.count("files") && vm.count("dir")))
			{
				std::cout << desc;
				std::exit(1);
			}

			return {
				vm["files"].as<std::vector<std::string>>(),
				vm["dir"].as<std::string>()
			};
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << "\n";
			std::cout << desc;
			std::exit(1);
		}
	}
}

