#pragma once
#include <string>
#include <vector>

class Strategy
{
public:
	virtual ~Strategy() {};
	virtual void executeAlgorithm(std::string& data) const = 0;
};

class Context
{
private:
	Strategy* pStrategy;
public:
	Context(Strategy* strategy = nullptr);
	~Context();
	void setStrategy(Strategy* strategy);
	void doSomeLogic(std::string& data);
};
  
class ConcreteStrategyA : public Strategy
{
public:
	virtual void executeAlgorithm(std::string& data) const override;
};

class ConcreteStrategyB : public Strategy
{
public:
	virtual void executeAlgorithm(std::string& data) const override;
};

