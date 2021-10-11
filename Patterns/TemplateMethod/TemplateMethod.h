#pragma once


class TemplateMethod
{
public:
	void TemplateMethodExecute() const;

protected:
	void BaseOperation() const;
	virtual void SubClassOperation() const = 0;
};


class TemplateConcreteMethod1 : public TemplateMethod
{
protected:
	virtual void SubClassOperation() const override;
};

class TemplateConcreteMethod2 : public TemplateMethod
{
protected:
	virtual void SubClassOperation() const override;
};
