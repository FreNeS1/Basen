#include <iostream>

#include <SFML/Graphics.hpp>

#include "config/config.hpp"
#include "except/IOException.hpp"
#include "utils/serviceHandler.hpp"
#include "utils/logger.hpp"

int main()
{
	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(shape);
		window.display();
	}

	

	try {
		Basen::ServiceHandler::setLogger(new Basen::Logger(Basen::config::app::VERSION, "log.log"));

		Basen::Logger& logger = Basen::ServiceHandler::getLogger();
		logger.writeLog(Basen::Logger::logType::LOG_INFO, "Logger is working");
		logger.writeLog(Basen::Logger::logType::LOG_INFO, "Logger is working");
		logger.writeLog(Basen::Logger::logType::LOG_INFO, "Logger is working");
		logger.writeLog(Basen::Logger::logType::LOG_INFO, "Logger is working");
		logger.writeLog(Basen::Logger::logType::LOG_INFO, "Logger is working");
		logger.writeLog(Basen::Logger::logType::LOG_WARNING, "Surprise!");
		logger.writeLog(Basen::Logger::logType::LOG_INFO, "Logger is working");
	}
	catch (Basen::IOException e) {
		bool exceptionsWorking = true;
	}

	return 0;
}
