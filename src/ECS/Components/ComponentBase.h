#pragma once
#include <string>

class ComponentBase
{
public:
	ComponentBase(const std::string& componentName) :
        m_name(componentName){}
	std::string name()
	{
		return m_name;
	}
	virtual void readData(std::stringstream& l_stream) = 0;
    virtual ~ComponentBase() {}

private:
	std::string m_name;
};
