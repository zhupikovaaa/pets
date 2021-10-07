#include "Singleton.h"


Singleton* Singleton::getInstance()
{
	std::lock_guard<std::mutex> lock(mtx);
	if (pInstance == nullptr)
	{
		pInstance = new Singleton("");
	}
	return pInstance;
}

Singleton::Singleton(std::string value) : adress(value) {}; 


