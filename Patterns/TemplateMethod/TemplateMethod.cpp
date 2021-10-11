#include "TemplateMethod.h"
#include <iostream>

void TemplateMethod::TemplateMethodExecute() const
{
	this->BaseOperation();
	this->SubClassOperation();
}

void TemplateMethod::BaseOperation() const
{
	std::cout << "AbstractClass" << std::endl;
}

void TemplateConcreteMethod1::SubClassOperation() const
{
	std::cout << "TemplateConcreteMethod1" << std::endl;
}

void TemplateConcreteMethod2::SubClassOperation() const
{
	std::cout << "TemplateConcreteMethod2" << std::endl;
}

void ClientCode(TemplateMethod* instance)
{
	instance->TemplateMethodExecute();
}

void main()
{
	TemplateConcreteMethod1* concreteClass1 = new TemplateConcreteMethod1;
	ClientCode(concreteClass1);

	TemplateConcreteMethod2* concreteClass2 = new TemplateConcreteMethod2;
	ClientCode(concreteClass2);

	delete concreteClass1;
	delete concreteClass2;
}
