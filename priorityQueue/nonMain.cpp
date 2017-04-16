#include "nonMain.h"



nonMain::nonMain()
{
}


nonMain::~nonMain()
{
}



std::vector<std::string> getVStrFromFile(std::string filename, int vLength) {

	std::ifstream fs;
	fs.open(filename);
	std::string str;
	std::vector<std::string> vStr;

	for (int i = 0; i < vLength; i++) {
		std::getline(fs, str);
		vStr.push_back(str);
	}
	return vStr;


}
