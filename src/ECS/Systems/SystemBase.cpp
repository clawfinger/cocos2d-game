#include <algorithm>
#include "SystemBase.h"
#include "Utils/Logger.h"

SystemBase::SystemBase(std::string name): m_name(name)
{
}

SystemBase::~SystemBase()
{
}

bool SystemBase::fitsRequirements(const StringList & components)
{
	for (const std::string& req : m_requirements)
	{
		if (!components.contains(req))
			return false;
	}
	return true;
}

void SystemBase::addEntity(EntityId entity)
{
	if (!haseEntity(entity))
		m_entities.push_back(entity);
	else
		LOG("ERROR: Adding duplicate of entity " + std::to_string(entity) + " to system " + m_name);
}

bool SystemBase::haseEntity(EntityId entity)
{
	return (std::find(m_entities.begin(), m_entities.end(), entity) != m_entities.end());
}

void SystemBase::removeEntity(EntityId entity)
{
	auto entityIter = std::find_if(m_entities.begin(), m_entities.end(), [&entity](EntityId id)->bool {return id == entity;});
	if (entityIter != m_entities.end())
		m_entities.erase(entityIter);
	else
		LOG("ERROR: Adding duplicate of entity " + std::to_string(entity) + " from system " + m_name);
}

std::string & SystemBase::name()
{
	return m_name;
}
