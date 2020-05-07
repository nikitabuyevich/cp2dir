#include <cmd/parse.h>
#include <cp/files.h>

int main(int argc, char** argv)
{
	auto[files, dir] = cmd::Parse(argc, argv);
	cp::Files(files, dir);
	return 0;
}
