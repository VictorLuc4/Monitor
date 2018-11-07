/*
** Created by Victor Lucas
*/

#include "Box.hpp"
#include "IMonitorDisplay.hpp"
#include <iostream>

BoxSF::BoxSF(sf::Vector2f pos, sf::Vector2f size)
	: IMonitorDisplay()
{
	this->_pos = pos;
	this->_size = size;
        this->_color = sf::Color(255, 255, 255);
	this->_rectangle.setSize(size);
	this->_rectangle.setPosition(this->_pos);
	this->_rectangle.setFillColor(sf::Color::Transparent);
	this->_rectangle.setOutlineThickness(2);
	this->_rectangle.setOutlineColor(this->_color);
}

BoxSF::~BoxSF()
{
}

void BoxSF::setTextWithString(const char *str, sf::Vector2f pos)
{
	this->_text = str;
	this->_textPos = pos;
}

void BoxSF::setPosition(sf::Vector2f pos)
{
	this->_pos = pos;
	this->_rectangle.setPosition(this->_pos);
}

void BoxSF::setSize(sf::Vector2f size)
{
	this->_size = size;
	this->_rectangle.setSize(size);
}

void BoxSF::setColor(sf::Color newColor)
{
	this->_color = newColor;
}

sf::Color BoxSF::getColor()
{
	return this->_color;
}

sf::Vector2f BoxSF::getPos() const
{
	return this->_pos;
}

sf::Vector2f BoxSF::getTextPos() const
{
	return this->_textPos;
}

sf::Vector2f BoxSF::getSize() const
{
	return this->_size;
}

sf::RectangleShape BoxSF::getRectangle()
{
	return this->_rectangle;
}

std::string BoxSF::getText() const
{
	return this->_text;
}
