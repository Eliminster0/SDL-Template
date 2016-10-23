#ifndef __GameObjectFactory__
#define __GameObjectFactory__

#include <map>
#include <iostream>
#include "GameObject.h"

class BaseCreator
{
    public:
    
		virtual GameObject* createGameObject() const = 0;
		virtual ~BaseCreator() {}
};

class GameObjectFactory
{
    public:
    
		static GameObjectFactory* Instance()
		{
			if(pInstance == 0)
			{
				pInstance = new GameObjectFactory();
			}
        
			return pInstance;
		}
    
		bool registerType(GameObject::ObjectType typeID, BaseCreator* pCreator)
		{
			std::map<int, BaseCreator*>::iterator it = m_creators.find(typeID);
        
			// if the type is already registered, do nothing
			if(it != m_creators.end())
			{
				delete pCreator;
			}
        
			m_creators[typeID] = pCreator;
        
			return true;
		}
    
		GameObject* create(int typeID)
		{
			std::map<int, BaseCreator*>::iterator it = m_creators.find(typeID);
        
			if(it == m_creators.end())
			{
				std::cout << "could not find type: " << typeID << "\n";
				return NULL;
			}
    
			BaseCreator* pCreator = (*it).second;
			return pCreator->createGameObject();
		}
    
    private:
    
		GameObjectFactory() {}
		~GameObjectFactory() {}
    
		std::map<int, BaseCreator*> m_creators;
    
		static GameObjectFactory* pInstance;
};

typedef GameObjectFactory TheGameObjectFactory;

#endif
