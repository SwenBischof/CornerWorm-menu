/* 
 * File:   Properties.h
 * Author: hp
 *
 * Created on 30. April 2014, 15:04
 */

#ifndef PROPERTIES_H
#define	PROPERTIES_H
#include <SFML/Network/IpAddress.hpp>
#include <SFML/Graphics.hpp>

class Properties 
{
public:
    void setColor(sf::Color farbe);
    void setSpeed(float geschwindigkeit);
    void setUsername(sf::String name);
    void setIP(sf::String IP);
    
    sf::String getUsername();
    sf::Color getColor();
    sf::IpAddress getIpAdress();
    float getSpeed(void);
private:
    sf::Color color;
    sf::IpAddress ip;
    unsigned int speed;
    sf::String username;


};

#endif	/* PROPERTIES_H */

