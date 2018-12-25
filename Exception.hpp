#pragma once 
#include <string> 

class Exception{ 
private: 
std::string message; 
public: 
explicit Exception(const std::string &message = "Exception"); 
const std::string& what() const; 
};
