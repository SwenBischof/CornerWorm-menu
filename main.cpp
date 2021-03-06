/* 
 * File:   main.cpp
 * Author: Swen Bischof
 *
 * Created on 21. März 2014, 20:19
 */

#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <iostream>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Window/Mouse.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Config.hpp>
#include <SFML/Graphics/Image.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Network/IpAddress.hpp>
#include "Properties.h"
#include <vector>

std::vector<sf::Event> MenuEvents;
int main() 
{
    std::size_t Position;
    sf::RenderWindow window(sf::VideoMode(1024,768,32),"my window");
    Properties properties;
    sf::Vector2f Color_size(25,25);
    bool erase;
    
    sf::RectangleShape Rot;
    sf::RectangleShape Blau;
    sf::RectangleShape Gruen;
    sf::RectangleShape Gelb;
    sf::RectangleShape Select_color;
    
    Rot.setSize(Color_size);
    Blau.setSize(Color_size);
    Gelb.setSize(Color_size);
    Gruen.setSize(Color_size);
    Select_color.setSize(sf::Vector2f(25,25));

    
    Rot.setPosition(350,609);
    Blau.setPosition(390,609);
    Gelb.setPosition(430,609);
    Gruen.setPosition(470,609);
    Select_color.setPosition(347,608);

    
    Rot.setFillColor(sf::Color::Red);
    Blau.setFillColor(sf::Color::Blue);    
    Gelb.setFillColor(sf::Color::Yellow);
    Gruen.setFillColor(sf::Color::Green);
    Select_color.setFillColor(sf::Color::Magenta);

    
    //Alle Textfelder 
    sf::RectangleShape IP_Textfeld;
    sf::RectangleShape Benutzernamen_Textfeld;
    IP_Textfeld.setSize(sf::Vector2f(200,50));
    IP_Textfeld.setPosition(775,500);
    IP_Textfeld.setFillColor(sf::Color::White);
    IP_Textfeld.setOutlineColor(sf::Color::Black);
    IP_Textfeld.setOutlineThickness(1);
    
    Benutzernamen_Textfeld.setSize(sf::Vector2f(200,50));
    Benutzernamen_Textfeld.setPosition(775,400);
    Benutzernamen_Textfeld.setFillColor(sf::Color::White);
    Benutzernamen_Textfeld.setOutlineColor(sf::Color::Black);
    Benutzernamen_Textfeld.setOutlineThickness(1);
    
    //Alle Schriftzüge                
    sf::Font font;
    font.loadFromFile("arial.ttf");
       
    sf::Text IP;
    sf::String IP_eingabe;
    bool ip=0;
    IP.setCharacterSize(25);
    IP.setStyle(sf::Text::Regular);
    IP.setFont(font);
    IP.setColor(sf::Color::Black);
    IP.setPosition(sf::Vector2f(795,510));
    
    sf::Text Benutzernamen;
    sf::String Benutzernamen_eingabe;
    bool benutzernamen=0;
    Benutzernamen.setCharacterSize(25);
    Benutzernamen.setStyle(sf::Text::Regular);
    Benutzernamen.setFont(font);
    Benutzernamen.setColor(sf::Color::Black);
    Benutzernamen.setPosition(sf::Vector2f(795,410));
  
    sf::Text Titel_Benutzer;
    Titel_Benutzer.setCharacterSize(25);
    Titel_Benutzer.setStyle(sf::Text::Regular);
    Titel_Benutzer.setFont(font);
    Titel_Benutzer.setColor(sf::Color::Black);
    Titel_Benutzer.setPosition(sf::Vector2f(775,360));
    Titel_Benutzer.setString("Namen(9):");
    
    sf::Text Titel_IP;
    Titel_IP.setCharacterSize(25);
    Titel_IP.setStyle(sf::Text::Regular);
    Titel_IP.setFont(font);
    Titel_IP.setColor(sf::Color::Black);
    Titel_IP.setPosition(sf::Vector2f(775,460));
    Titel_IP.setString("IP-Adresse:");
    
    sf::Text Titel_Farbe;
    Titel_Farbe.setCharacterSize(25);
    Titel_Farbe.setStyle(sf::Text::Regular);
    Titel_Farbe.setFont(font);
    Titel_Farbe.setColor(sf::Color::Black);
    Titel_Farbe.setPosition(sf::Vector2f(50,600));
    Titel_Farbe.setString("Farbe ihrer Spielfigur:");
    
    sf::Text Titel_Speed;
    Titel_Speed.setCharacterSize(25);
    Titel_Speed.setStyle(sf::Text::Regular);
    Titel_Speed.setFont(font);
    Titel_Speed.setColor(sf::Color::Black);
    Titel_Speed.setPosition(sf::Vector2f(50,660));
    Titel_Speed.setString("Geschwindigkeit       :");
    
    sf::Text addresse;  
    addresse.setCharacterSize(20);
    addresse.setStyle(sf::Text::Regular);
    addresse.setFont(font);
    addresse.setColor(sf::Color::Black);
    addresse.setPosition(50,720.0f);
    addresse.setString(sf::IpAddress::getLocalAddress().toString());
    
    
    //Erstellen der Bilder+Laden+Kontrolle
    sf::Texture tex_start;
    sf::Texture tex_beenden;
    sf::Texture tex_neustarten;
    sf::Texture tex_zurueck;
    sf::Texture tex_langsam;
    sf::Texture tex_mittel;
    sf::Texture tex_schnell;
    sf::Texture texture;
    sf::Texture tex_select;
    
    if(texture.loadFromFile("background.png")==0)              //Laden aller Bilder für das Menü und ebenfalls wird gleich geprüft ob diese Erflogreich war
    {return 0;}
    if(tex_start.loadFromFile("starten.png")==0)     
    {return 0;}
    if(tex_beenden.loadFromFile("beenden.png")==0)
    {return 0;}
    if(tex_neustarten.loadFromFile("neustarten.png")==0)
    {return 0;}
    if(tex_zurueck.loadFromFile("zurueck.png")==0)
    {return 0;}
    if(tex_langsam.loadFromFile("langsam.png")==0)
    {return 0;}   
    if(tex_mittel.loadFromFile("mittel.png")==0)
    {return 0;}  
    if(tex_schnell.loadFromFile("schnell.png")==0)
    {return 0;}   
    if(tex_select.loadFromFile("select.png")==0)
    {return 0;}
 
    sf::Sprite background(texture);
    sf::Sprite start(tex_start);
    sf::Sprite neustarten(tex_neustarten);
    sf::Sprite zurueck(tex_zurueck);
    sf::Sprite beenden(tex_beenden);
    sf::Sprite langsam(tex_langsam);
    sf::Sprite mittel(tex_mittel);
    sf::Sprite schnell(tex_schnell);
    sf::Sprite select(tex_select);
   
    start.setPosition(50 ,340);
    beenden.setPosition(50,450);
    neustarten.setPosition(50,340);
    zurueck.setPosition(50,450);
    langsam.setPosition(340,650);
    mittel.setPosition(490,650);
    schnell.setPosition(640,650);
    select.setPosition(338,649);
    

    
    while(window.isOpen())                      //Solange das Fenster geöffnet ist wird die Schleife ausgeführt
    {
        sf::Event event;
        while(window.pollEvent(event))          //Hat das Fenster ein Event gemacht es werden alle Events in der List abgefragt deshalb eine While-Schlaufe
        {
            if(event.type == sf::Event::Closed) //Abfrage ob es ein Event vom Typ closed  gibt!!
            {
                window.close();
            }

            //Mausabfragen
            if(event.type == sf::Event::MouseButtonPressed) //Es wird abgefragt ob eine Maustaste geklickt wurde
            {
                if(event.mouseButton.button==sf::Mouse::Left)
                {
                    //Abfrage ob die Rechtecke den Ortsvektor der Maus enthalten
                    if(start.getGlobalBounds().contains(event.mouseButton.x,event.mouseButton.y))//Überprüft ob die Fläche den Punkt der Maus beeinhaltet 
                    {
                        //Anweisung
                    }

                    if(neustarten.getGlobalBounds().contains(event.mouseButton.x,event.mouseButton.y))//Überprüft ob die Fläche den Punkt der Maus beeinhaltet 
                    {
                        //Anweisung
                    } 
                    
                    if(zurueck.getGlobalBounds().contains(event.mouseButton.x,event.mouseButton.y))//Überprüft ob die Fläche den Punkt der Maus beeinhaltet 
                    {
                        //Anweisung
                    } 
                    
                    if(beenden.getGlobalBounds().contains(event.mouseButton.x,event.mouseButton.y))//Überprüft ob die Fläche den Punkt der Maus beeinhaltet 
                    {
                        window.close();
                    }
                                        
                    //Hier wird die Selektion des Textfeldes gemacht
                    if(IP_Textfeld.getGlobalBounds().contains(event.mouseButton.x,event.mouseButton.y))
                    {
                        benutzernamen=0;
                        ip=1;   //Hier wird das Bit gesetzt welche dann in der Texteingabe gebraucht wird
                    }
                 
                    if(Benutzernamen_Textfeld.getGlobalBounds().contains(event.mouseButton.x,event.mouseButton.y))
                    {
                        ip=0;
                        benutzernamen=1;   //Hier wird das Bit gesetzt welche dann in der Texteingabe gebraucht wird
                    }
                    
                    //Auswahl der Spielerfarbe
                    if(Blau.getGlobalBounds().contains(event.mouseButton.x,event.mouseButton.y))
                    {
                        properties.setColor(sf::Color::Blue);
                        Select_color.setPosition(387,608);//Macht die Auswahl sichtbar
                    }
                    if(Rot.getGlobalBounds().contains(event.mouseButton.x,event.mouseButton.y))
                    {
                        properties.setColor(sf::Color::Red);
                        Select_color.setPosition(347,608);//Macht die Auswahl sichtbar
                    }
                    if(Gelb.getGlobalBounds().contains(event.mouseButton.x,event.mouseButton.y))
                    {
                        properties.setColor(sf::Color::Yellow);
                        Select_color.setPosition(427,608);//Macht die Auswahl sichtbar
                    }
                    if(Gruen.getGlobalBounds().contains(event.mouseButton.x,event.mouseButton.y))
                    {
                        properties.setColor(sf::Color::Green);
                        Select_color.setPosition(467,608);//Macht die Auswahl sichtbar
                    }
                    //Auswahl der Spielgeschwindigkeit
                    if(schnell.getGlobalBounds().contains(event.mouseButton.x,event.mouseButton.y))
                    {
                        properties.setSpeed(100);
                        select.setPosition(638,649);
                    }
                    if(mittel.getGlobalBounds().contains(event.mouseButton.x,event.mouseButton.y))
                    {
                        properties.setSpeed(50);
                        select.setPosition(488,649);
                    }
                    if(langsam.getGlobalBounds().contains(event.mouseButton.x,event.mouseButton.y))
                    {
                        properties.setSpeed(20);
                        select.setPosition(338,649);
                    }                    
                }
             }
             //Tastenabfragen                
             if(event.type==sf::Event::KeyPressed)
             {
                if(event.key.code==sf::Keyboard::Escape)
                {
                    window.close();
                }
                if(event.key.code==sf::Keyboard::BackSpace)
                {
                    erase=1;
                }
             } 
            //Texteingaben
             if (event.type == sf::Event::TextEntered)
             {
                if (event.text.unicode < 128)// Handle ASCII characters only
                {
                    if(ip)//Wenn das Textfeld Ip angewählt ist
                    {   
                        if(((event.text.unicode <= 57)&&(event.text.unicode >= 48)||(event.text.unicode == 46))) //Es werden nur Zahlen akzeptiert
                        {
                            IP_eingabe += static_cast<char>(event.text.unicode);
                        }    
                        if(erase)
                        {
                            Position=IP_eingabe.getSize();      //Erfassen der Grösse des Strings                           
                            if((IP_eingabe.getSize()>0))
                            {
                                IP_eingabe.erase(Position-1);   //Löschen des letzten Zeichens
                            }
                            erase=0;
                        }
                        if((IP_eingabe.getSize()<16))            //Begrenzen der Zeichenzahl
                        {
                                IP.setString(IP_eingabe);        //Text wird gesetzt
                                properties.setIP(IP_eingabe);    //setzten der Propertie
                        }
                        
                        if(properties.getIpAdress().toInteger()==0)//Überprüfen ob die IP-Addresse gültig ist
                        {
                            IP_Textfeld.setFillColor(sf::Color::Red);
                        }
                        else
                        {
                            IP_Textfeld.setFillColor(sf::Color::White);
                        }
                    }   
                    
                    if(benutzernamen)//Textfeld für Benutzernamen ist ausgewählt
                    {   //Lässt nur Klein- und Grossbuchstaben zu  
                        if(((event.text.unicode <= 90)&&(event.text.unicode >= 65))||((event.text.unicode <= 122)&&(event.text.unicode >= 97))) 
                        {
                            Benutzernamen_eingabe += static_cast<char>(event.text.unicode);
                        }
                        if(erase)
                        {                            
                            Position=Benutzernamen_eingabe.getSize();           //Anzahl zeichen erfassen                             
                            if((Benutzernamen_eingabe.getSize()>0))             //Abfrage ob etwas eingegeben wurde 
                            {
                                Benutzernamen_eingabe.erase(Position-1);        //Löschen des letzten Buchstabens
                            }
                            erase=0;
                        }
                        if((Benutzernamen_eingabe.getSize()<10))                //Maximale Anzahl Zeichen 9
                        {
                                Benutzernamen.setString(Benutzernamen_eingabe); //Text wird gesetzt
                                properties.setUsername(Benutzernamen_eingabe);  //Setzten des Benutzernamens in den Einstellungen
                        }
                    }
                }
             }
        } 
        
        window.clear(sf::Color::Black);
        
        window.draw(background);
        window.draw(IP_Textfeld);
        window.draw(Benutzernamen_Textfeld);
        window.draw(IP);
        window.draw(Benutzernamen);
        window.draw(Titel_IP);
        window.draw(Titel_Benutzer);
        window.draw(Titel_Farbe);
        window.draw(Titel_Speed);
        
        //Buttons zeichnen
        window.draw(start);
        window.draw(beenden);
        //window.draw(zurueck);
        //window.draw(neustarten);
        window.draw(addresse);
        window.draw(select);
        window.draw(langsam);
        window.draw(mittel);
        window.draw(schnell);
        window.draw(Select_color);
        window.draw(Gelb);
        window.draw(Rot);
        window.draw(Gruen);
        window.draw(Blau);
        window.display();
    }
    return 0;
};

