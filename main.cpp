/*
** Created by Victor Lucas
*/

#include <SFML/Graphics.hpp>
#include <cstring>
#include <vector>
#include <iostream>
#include "sfml/Box.hpp"
#include "ncurse/hostname_username.hpp"
#include "ncurse/DateTime.hpp"
#include "ncurse/OperatingSystem.hpp"
#include "ncurse/Kernel.hpp"
#include "ncurse/Ram.hpp"
#include <string>
#include <sstream>
#include "sfml/GetBoxes.hpp"
#include "ncurse/CPU.hpp"
#include "launch.hpp"
#include <cstdlib>

void drawBoxes(sf::RenderWindow &window, std::vector<BoxSF> &boxes,
	       int size, sf::Font font, sf::Color C)
{
	int i = 0;
	while (i < size) {
		sf::Text text(boxes[i].getText(), font);
		text.setCharacterSize(21);
		text.setColor(C);
		text.setPosition(boxes[i].getTextPos());
		window.draw(text);
		window.draw(boxes[i].getRectangle());
		i += 1;
	}
}

std::vector<BoxSF> &getBoxes(std::vector<BoxSF> &boxes)
{
	boxes = getHostBox(boxes);
	boxes = getDateTimeBox(boxes);
	boxes = KernelBox(boxes);
	boxes = getOsBox(boxes);
	boxes = getRamBox(boxes);
	boxes = getTitleBox(boxes);
	boxes = getCPUBox(boxes);
	boxes = getNetworkBox(boxes);
	boxes = getInformationsBox(boxes);

	return boxes;
}


int randColor()
{
	int i = 0;

	i = rand() % 255;
	return i;
}

void launchSFML()
{
	sf::RenderWindow window(sf::VideoMode(1200, 800),
				"Victor le bg", sf::Style::Titlebar
				| sf::Style::Close);
	bool screen = false;
	sf::Font font;
	font.loadFromFile("Ubuntu-C.ttf");
	sf::Texture texture;
	std::vector<BoxSF> boxList;
	sf::Color swap = sf::Color(233, 233, 233);
	texture.loadFromFile("img.jpg");
	sf::Sprite background(texture);
	int i = 0;

	while (window.isOpen())
	{
		if (i % 99 == 0) {
			boxList.clear();
			boxList = getBoxes(boxList);
		}
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.key.code == sf::Keyboard::Escape)
				window.close();
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.key.code == sf::Keyboard::LShift)
				screen == false ?
					(texture.loadFromFile("secret.jpg"),
					 screen = true) :
					(texture.loadFromFile("img.jpg"),
					 screen = false);
			if (event.key.code == sf::Keyboard::C)
				swap = sf::Color(randColor(),
						 randColor(), randColor());
		}
		window.clear();
		window.draw(background);
		drawBoxes(window, boxList, 9, font, swap);
		window.display();
		i++;
	}
}

void printUsage()
{
	std::cout << "USAGE : ./monitor ([--text][-t] || [--graphical][-g])"
		  << std::endl;
}

int main(int ac, char **av)
{
	if (ac != 2){
		printUsage();
		return 0;
	}
	if (std::strcmp(av[1], "--text") == 0 ||
	    std::strcmp(av[1], "-t") == 0)
		launchNcurse();
	else if (std::strcmp(av[1],"--graphical") == 0 ||
		 std::strcmp(av[1], "-g") == 0)
		launchSFML();
	else
		printUsage();
	return 0;
}
