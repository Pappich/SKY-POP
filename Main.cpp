#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include "Player.h"
#include "Game.h"
#include "starrr.h"
#include <sstream>
#include<windows.h>
#include<conio.h>
#include<stdio.h>
#define STD_OUTPUT_HANDLE ((DWORD)-11)

using namespace sf;

/*void setcolor(int fg, int bg)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, bg * 16 + fg);
}

void gotoxy(int x, int y) 
{
    COORD c = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

struct Star
{
    int x, y;
}star[20];

void draw_star(int x, int y)
{
    setcolor(6, 0);
    gotoxy(x, y);
    printf("*");
}*/

int main()
{
    RenderWindow window(VideoMode(1280, 720), "Game", Style::Titlebar | Style::Close);
    CircleShape shape(10.f);
    //shape.setFillColor(Color::Green);

    shape.setPosition(100, 100);

    sf::Texture pngplayer;
    pngplayer.loadFromFile("Player.PNG");
    sf::Sprite player;
    player.setTexture(pngplayer);
    player.setPosition(100, 100);

    sf::Texture pngtime2;
    pngtime2.loadFromFile("time2.PNG");
    sf::Sprite time2;
    time2.setTexture(pngtime2);
    time2.setPosition((rand() % (70 + 1 - 10)) + 10,300);
    
    sf::Texture pngitem;
    pngitem.loadFromFile("item.PNG");
    sf::Sprite item;
    item.setTexture(pngitem);
    item.setPosition(500 , (rand() % (70 + 1 - 10)) + 10);
 

    //score

    int score = 0;

    sf::Font puimek;
    puimek.loadFromFile("puimek.ttf");

    std::ostringstream ssScore;
    ssScore << "SCORE : " << score;

    sf::Text lblScore;
    lblScore.setCharacterSize(50);
    lblScore.setPosition({ 50,10 });
    lblScore.setFont(puimek);
    lblScore.setString(ssScore.str());
 
    while (window.isOpen())
    {
        Event ev;
        while (window.pollEvent(ev))
        {
        
           if (ev.type==sf::Event::KeyPressed)
            {
               if (ev.key.code == sf::Keyboard::A)
                   player.move(-10, 0);
               if (ev.key.code == sf::Keyboard::D)
                   player.move(10, 0);
               if (ev.key.code == sf::Keyboard::W)
                   player.move(0, -10);
               if (ev.key.code == sf::Keyboard::S)
                   player.move(0, 10);
            }
        }

       //Game game;
       //game.run();

        window.clear();
        //window.draw(shape);
        window.draw(player);
        window.draw(item);
        window.draw(time2);
        window.draw(lblScore);
        window.display();
    }
    return 0;
}