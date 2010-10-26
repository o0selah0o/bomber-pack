#include "tokenize.h"
#include <sstream> 

std::vector<std::string> tokenize(const std::string& input,char separator)
{
	std::vector<std::string> output;
	std::string token;
	std::istringstream tokenizer(input);
	while(std::getline(tokenizer,token,separator))
	{
		output.push_back(token);
	}
	return output;
} 
