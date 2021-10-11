#pragma once

class SomeComponent
{
public:
	virtual ~SomeComponent();
	virtual void someOperation() const = 0;
};

class ConcreteComponent : public SomeComponent
{
public:
	virtual void someOperation() const override;
};

class Decorator : public SomeComponent
{
protected:
	SomeComponent* m_Component;
public:
	Decorator(SomeComponent* component) : m_Component(component) {};
	virtual void someOperation() const override;
};

class ConcreteDecorator1 : public Decorator
{
public: 
	ConcreteDecorator1(SomeComponent* component) : Decorator(component) {};
	virtual void someOperation() const override;
};

class ConcreteDecorator2 : public Decorator
{
public:
	ConcreteDecorator2(SomeComponent* component) : Decorator(component) {};
	virtual void someOperation() const override;
};


