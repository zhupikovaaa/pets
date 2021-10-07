#pragma once
#include <mutex>

class Singleton
{
public:
	static Singleton* getInstance();

	Singleton(Singleton& s) = delete;
	void operator=(const Singleton s) = delete;

private:
	static Singleton* pInstance;
	static std::mutex mtx;

protected:
	std::string adress;

	Singleton(const std::string value);
	~Singleton() {};

};

