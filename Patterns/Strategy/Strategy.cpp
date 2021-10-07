#include "Strategy.h"
#include <iostream>

Context::Context(Strategy* strategy) : pStrategy(strategy) {};

Context::~Context()
{
	delete this->pStrategy;
}

void Context::setStrategy(Strategy* strategy)
{
	delete this->pStrategy;
	this->pStrategy = strategy;
}

void Context::doSomeLogic(std::string& data)
{
	pStrategy->executeAlgorithm(data);
}

void ConcreteStrategyA::executeAlgorithm(std::string& data) const
{
	std::cout << "ConcreteStrategyA: " << data << std::endl;
}

void ConcreteStrategyB::executeAlgorithm(std::string& data) const
{
	std::cout << "ConcreteStrategyB: " << data << std::endl;
}

void someCode()
{
	std::string input = "Hello!";
	Context* context = new Context(new ConcreteStrategyA);
	context->doSomeLogic(input);

	context->setStrategy(new ConcreteStrategyB);
	context->doSomeLogic(input);
}
