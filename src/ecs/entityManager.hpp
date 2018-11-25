#ifndef ENTITY_MANAGER_HPP
#define ENTITY_MANAGER_HPP

#include <unordered_map>
#include <vector>
#include <functional>
#include <memory>

#include "../utils/primitives/bitmask.hpp";

namespace Basen {

	using EntityId = unsigned int;
	using EntityIdList = std::vector<EntityId>;

	using Component = std::unique_ptr<Component>;
	using ComponentContainer = std::vector<Component>;
	using EntityData = std::pair<Bitmask, ComponentContainer>;
	using EntityContainer = std::unordered_map<EntityId, EntityData>;
	using EntityTypes = std::unordered_map<EntityId, std::string>;
	using ComponentFactory = std::unordered_map<Component, std::function<C_Base*(void)>>;

	class EntityManager : public MapLoadee {
	public:
		EntityManager(SystemManager* t_sysMgr, TextureManager* t_textureMgr);
		~EntityManager();

		int addEntity(const Bitmask& t_mask);
		int addEntity(const std::string& t_entityFile);
		bool removeEntity(const EntityId& t_id);

		int findEntityAtPoint(const sf::Vector2f& t_point, unsigned int t_elevationMin = 0, unsigned int t_elevationMax = Sheet::Num_Layers - 1) const;

		void readMapLine(const std::string& t_type, std::stringstream& t_stream);
		void saveMap(std::ofstream& t_fileStream);

		bool addComponent(const EntityId& t_entity, const Component& t_component);

		template<class T>
		void addComponentType(const Component& t_id);

		template<class T>
		T* getComponent(const EntityId& t_entity, const Component& t_component);

		bool removeComponent(const EntityId& t_entity, const Component& t_component);
		bool hasComponent(const EntityId& t_entity, const Component& t_component) const;

		void purge();

	private:
		unsigned int		m_idCounter;
		EntityContainer		m_entities;
		EntityTypes			m_entityTypes;
		ComponentFactory	m_cFactory;

		SystemManager*		m_systems;
		TextureManager*		m_textureManager;
	};
}


#endif // ENTITY_MANAGER_HPP