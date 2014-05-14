/* 
 * File:   Properties.cpp
 * Author: hp
 * 
 * Created on 30. April 2014, 15:04
 */

#include "Properties.h"

sf::Color Properties::getColor()
{
    return color;
}

void Properties::setColor(sf::Color farbe)
{
    color=farbe;
}

sf::IpAddress Properties::getIpAdress()
{
    return ip;
}
float Properties::getSpeed()
{
    return speed;
}
void Properties::setSpeed(float geschwindigkeit)
{
    speed=geschwindigkeit;
}
sf::String Properties::getUsername()
{
    return username;
}

void Properties::setUsername(sf::String name)
{
    username=name;
}
void Properties::setIP(sf::String IP)
{
        sf::IpAddress newip(IP);
        ip = newip;
}


