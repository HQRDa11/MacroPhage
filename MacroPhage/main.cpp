///////SFML_STATIC//////////////////////
#ifdef SFML_STATIc
#endif
//////////////////////////////////////////

////////BiBLIOTHEQUES/////////////////
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
///////////////////////////////////////////

////////Headers//////////////////////////
#include "Shape.h"
///////////////////////////////////////////

/////DECLARATION DES OBJETS//////////

    sf::RenderWindow app;
    sf::CircleShape ship;
     sf::CircleShape asteroid;
     sf::RectangleShape medium;
     sf::RectangleShape hard;

////////////////////////////////////////////

//////////VARIABLES ET FONCTIONS//////

     int score = 0;
     int q = 0;
     int s = 7;
     int v;
     int a = 1;

    int asteroid_Move(int a_Move);
    int ship_Move(int ship_Speed);

/////////////////////////////////////////////

////FONCTION PRINCIPALE//////////////////
int main()
{
//CREATION ET ANIMATION DE LA FENETRE/

    app.create(sf::VideoMode(600, 600), "MacroPhagus");
    app.setFramerateLimit(60);


    sf::Font font;
    font.loadFromFile("/home/hydrogen/Téléchargements/arial.ttf");

        std::cout<<"Lancement du jeu"<<std::endl;//Déclaration

//CARACTERES//////////////////////////////

        sf::Text med("MEDIUM", font);
        med.setCharacterSize(25);
        med.setFillColor(sf::Color(255,255,255));
        med.setPosition(sf::Vector2f(10,4));

        sf::Text ard("HARD", font);
        ard.setCharacterSize(25);
        ard.setFillColor(sf::Color(255,255,255));
        ard.setPosition(sf::Vector2f(10,38));

///////////////////////////////////////////////

//RECUPERATION DES FONCTIONS///////////

        ship = ship_Shape(350,550,15,3);
        asteroid = asteroid_Shape(350,0,10,20);
        medium = difficult_Med();
        hard = difficult_Hard();

////////////////////////////////////////////////

///// ANIMATION DE LA FENETRE /////////////
    while (app.isOpen())
    {

////ACTIVATION DES EVENEMENTS///////////
        sf::Event event;
        while (app.pollEvent(event))
        {
////FERMETURE DE FENETRE/////////////////

            if (event.type == sf::Event::Closed)
                app.close();
        }

///////////////////////////////////////////////////

////////ALEATOIRE//////////////////////////////

        srand (time(0));
        int rand_Pos = rand() %573+10;

///////////////////////////////////////////////////

/////DETECTION DES COLLISIONS ET SCORE////////////

         if ((std::abs((ship.getPosition().x+10)-(asteroid.getPosition().x+10)) <= 17) && (std::abs((ship.getPosition().y+10)-(asteroid.getPosition().y+10)) <= 17))
            {
                    score++;

                    std::cout<<score<<std::endl;
                    asteroid.setPosition(sf::Vector2f(rand_Pos, 0));

                if (score == 10*a )
                {
                    std::cout<<"Niveau "<<10*a<<std::endl;
                    v++;
                    s++;
                    a++;
                }
            }

///////////////////////////////////////////////////

//DIRIGER LE VAISSEAU///////////////////

            ship_Move(s);

///////////////////////////////////////////////

//POSITION DE LA FENETRE/////////////////

    int appPox = app.getPosition().x;
    int appPoy = app.getPosition().y;

//////////////////////////////////////////////

//////DIFFICULTE////////////////////////////////

            int xpos = sf::Mouse::getPosition().x;
            int ypos = sf::Mouse::getPosition().y;

            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                    if ((xpos<= appPox+153)&&(ypos<= appPoy+34)&&(ypos > appPoy + 0)&&(xpos > appPox + 0))
                    {
                        switch(q)
                        {
                            case 0: q++; v = 5; break;
                            case 1: v = 5; break;
                            case 2: q--; v = 5; break;
                        }
                    }
                    if (( xpos <= appPox + 153 )&&( ypos >= appPoy + 36 )&&( ypos <= appPoy + 73 )&&(xpos > appPox + 0))
                    {
                        switch (q)
                        {
                            case 0: q+=2; s++;  v = 7;break;
                            case 1: q++; s++; v = 7; break;
                            case 2: v = 7; break;
                        }
                    }
            }

            switch (q)
            {
                case 1: asteroid_Move(v); break;
                case 2: asteroid_Move(v); break;
            }

///////////////////////////////////////////////

/////DEFAITE/////////////////////////////////

    if (asteroid.getPosition().y>583)
    {
        asteroid.setPosition(sf::Vector2f(350, 0));
        v = 0;
        score = 0;
        std::cout<<"PERDU"<<std::endl;
        ship.setPosition(sf::Vector2f(350, 550));
    }

//////////////////////////////////////////////

////AFFICHAGE DANS LA FENETRE/////////

            app.draw(medium);
            app.draw(hard);
            app.draw(med);
            app.draw(ard);
            app.draw( asteroid);
            app.draw(ship);

/////////////////////////////////////////////////

//AFFICHE LA FENETRE//////////////////////
        app.display();
//EFFACE L'ECRAN A CHAQUE FPS/////////
        app.clear();
//////////////////////////////////////////////////
    }

    return 0;
}
//////////////////////////////////////////////////

/////FONCTIONS///////////////////////////////

int asteroid_Move(int a_Move)
{
    asteroid.setPosition(sf::Vector2f(asteroid.getPosition().x,asteroid.getPosition().y+a_Move));
}


int ship_Move(int ship_Speed)
    {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            ship.move(0,-ship_Speed);
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            ship.move(0,ship_Speed);
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            ship.move(-ship_Speed,0);
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            ship.move(ship_Speed,0);
        }
        if(ship.getPosition().x<=0)
            ship.setPosition(sf::Vector2f(582,ship.getPosition().y));
        if(ship.getPosition().y<=0)
            ship.setPosition(sf::Vector2f(ship.getPosition().x, 0));
        if(ship.getPosition().x>=583)
            ship.setPosition(sf::Vector2f(0,ship.getPosition().y));
        if(ship.getPosition().y>=583)
            ship.setPosition(sf::Vector2f(ship.getPosition().x, 583));
    }

    //////////////////////////////////////////////////////////////////////////

