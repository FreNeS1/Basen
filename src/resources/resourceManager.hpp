#ifndef RESOURCE_MANAGER_HPP
#define RESOURCE_MANAGER_HPP

#include <string>
#include <unordered_map>
#include <iostream>
#include <fstream>
#include <sstream>
#include <memory>
#include <SFML/System/Mutex.hpp>
#include <SFML/System/Lock.hpp>

#include "../utils/logger.hpp"

template<typename T>
using ResourcePair = std::pair<std::unique_ptr<T>, unsigned int>;
template<typename T>
using ResourceContainer = std::unordered_map<std::string, ResourcePair<T>>;
using PathContainer = std::unordered_map<std::string, std::string>;

namespace Basen {

	template<typename Derived, typename T>
	class ResourceManager {
	public:
		ResourceManager(const std::string& t_pathsFile, Logger* t_logger) : m_logger(t_logger) { loadPaths(t_pathsFile); }
		virtual ~ResourceManager() { purgeResources(); }

		T* getResource(const std::string& t_id)
		{
			sf::Lock lock(m_mutex);
			auto res = find(t_id);
			return(res ? res->first.get() : nullptr);
		}

		std::string getPath(const std::string& t_id)
		{
			sf::Lock lock(m_mutex);
			auto path = m_paths.find(t_id);
			return(path != m_paths.end() ? path->second : "");
		}

		bool requireResource(const std::string& t_id) 
		{
			sf::Lock lock(m_mutex);
			auto res = find(t_id);
			if (res) {
				++res->second;
				return true;
			}
			auto path = m_paths.find(t_id);
			if (path == m_paths.end()) { return false; }
			{
				std::unique_ptr<T> resource = std::make_unique<T>();
				if (!load(resource.get(), path->second))
				{
					return false;
				}
				m_resources.emplace(t_id, std::make_pair(std::move(resource), 1));
			}
			return true;
		}

		bool releaseResource(const std::string& t_id) {
			sf::Lock lock(m_mutex);
			auto res = find(l_id);
			if (!res) {
				return false;
			}
			--res->second;
			if (!res->second) {
				unload(l_id);
			}
			return true;
		}

		void purgeResources() {
			sf::Lock lock(m_mutex);
			m_logger.trace("Purging all resources");
			while (m_resources.begin() != m_resources.end()) {
				m_logger.trace("Removing: " + m_resources.begin()->first);
				m_resources.erase(m_resources.begin());
			}
			m_logger.trace("Purging finished");
		}

	protected:
		bool load(T* t_resource, const std::string& t_path);
		// TODO HERE

	private:
		ResourcePair<T>* find(const std::string& t_id);
		bool unload(const std::string& t_id);
		void loadPaths(const std::string& t_pathFile);

	protected:
		Logger* m_logger;

	private:
		ResourceContainer<T> m_resources;
		PathContainer m_paths;
		sf::Mutex m_mutex;
	};
}



#endif // RESOURCE_MANAGER_HPP
