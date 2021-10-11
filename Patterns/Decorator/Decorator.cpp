#include "Decorator.h"
#include <iostream>

SomeComponent::~SomeComponent() {};

void ConcreteComponent::someOperation() const
{
	std::cout << "ConcreteComponent" << std::endl;
}

void Decorator::someOperation() const
{
	this->m_Component->someOperation();
}

void ConcreteDecorator1::someOperation() const
{
	std::cout << "ConcreteDecorator1( ";
	Decorator::someOperation();
	std::cout << " )" << std::endl;
}

void ConcreteDecorator2::someOperation() const
{
	std::cout << "ConcreteDecorator2( ";
	Decorator::someOperation();
	std::cout << " )" << std::endl;
}

void ClientCode(SomeComponent* component)
{
	component->someOperation();
}

void main()
{
	SomeComponent* simple = new ConcreteComponent();
	ClientCode(simple);

	SomeComponent* decorator1 = new ConcreteDecorator1(simple);
	SomeComponent* decorator2 = new ConcreteDecorator2(decorator1);
	ClientCode(decorator2);

	delete simple;
	delete decorator1;
	delete decorator2;
}
