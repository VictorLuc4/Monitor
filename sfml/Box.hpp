/*
** Created by Victor Lucas
*/
#include <SFML/Graphics.hpp>
#include "IMonitorDisplay.hpp"

#ifndef BOX_H
#define BOX_H
class BoxSF : public IMonitorDisplay {
public:
	BoxSF(sf::Vector2f pos, sf::Vector2f size);
	~BoxSF();
	void setColor(sf::Color newColor);
	sf::Color  getColor();
	void setPosition(sf::Vector2f pos);
	void setSize(sf::Vector2f size);
	void setTextWithString(const char *str, sf::Vector2f pos);
	sf::Vector2f getPos() const;
	sf::Vector2f getTextPos() const;
	sf::Vector2f getSize() const;
	sf::RectangleShape getRectangle();
	std::string getText() const;
private:
	sf::Color _color;
	sf::Vector2f _pos;
	sf::Vector2f _textPos;
	sf::Vector2f _size;
	sf::RectangleShape _rectangle;
	std::string _text;
};
#endif
