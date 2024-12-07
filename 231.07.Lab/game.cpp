/***********************************************************************
 * Source File:
 *    GAME
 * Author:
 *    Angelo Arellano
 *    Connor Hopkins
 *    Jacob Mower
 * Summary:
 *    Game class.
 ************************************************************************/

#include "game.h"

/*******************************************************************************
* GAME :: CONSTRUCTOR
*******************************************************************************/
Game::Game(Position* ptUpperRight)
{
    for (int i = 1; i < 7; i++)
        orbitals.push_back(new GPS(i));

    orbitals.push_back(new Hubble());
    orbitals.push_back(new Sputnik());
    orbitals.push_back(new Starlink());
    orbitals.push_back(new CrewDragon());
    orbitals.push_back(new Earth());
    this->ship = new Ship();

    // Stars
    for (int i = 0; i < NUMBER_OF_STARS; i++)
    {
        Position* pos = new Position(ptUpperRight->getMetersX() * random(-0.5, 0.5),
                                     ptUpperRight->getMetersY() * random(-0.5, 0.5));
        stars[i].setPos(pos);
        stars[i].setPhase(i);
    }
}

/*******************************************************************************
* GAME :: UPDATE
*   Updates the screen.
*******************************************************************************/
void Game::update()
{
    // For twinkling stars
    for (int i = 0; i < NUMBER_OF_STARS; i++)
        stars[i].incrementPhase();

    for (auto orbital : orbitals)
        orbital->update();

    ship->update();

    list<Orbital*> shipList = {ship};
    for (auto orbital : orbitals)
    {
       orbital->detectCollisions(orbitals);
       orbital->detectCollisions(shipList);
    }

    ship->detectCollisions(orbitals);

    for (auto it = orbitals.begin(); it != orbitals.end();)
    {
       if ((*it)->crashed())
       {
          // Use a temporary variable to hold the current orbital
          Orbital* orbital = *it;

          // erase the iterator and get a new one to the next item before modifying the list
          it = orbitals.erase(it);

          // Call the destroy method (this adds/removes elements safely)
          orbital->destroy(orbitals);
       }
       else
       {
          ++it; // Move to the next element if no crash
       }
    }
}

/*******************************************************************************
* GAME :: DRAW
*  Draws all objects to the screen.
*******************************************************************************/
void Game::draw(ogstream& og) const
{
    for (int i = 0; i < NUMBER_OF_STARS; i++)
        stars[i].draw(og);

    for (auto orbital : orbitals)
        orbital->draw(og);
    
    if(!ship->crashed())
       ship->draw(og);
}

/*******************************************************************************
* GAME :: INPUT
*  Handles user input.
*******************************************************************************/
void Game::input(const Interface* pUI)
{
    if (pUI->isDown())
    {
        ship->input(DOWN);
    }
    if (pUI->isLeft())
    {
        ship->input(LEFT);
    }
    if (pUI->isRight())
    {
        ship->input(RIGHT);
    }
    if (pUI->isSpace()) /* Fixed by doing && !ship->crashed(), but want to keep the easter egg*/
    {
       createBullet();
    }
}

/*******************************************************************************
* GAME :: CREATE BULLET
*  Adds a bullet to the game.
*******************************************************************************/
void Game::createBullet()
{
   // Create the position, velocity, and angle of the bullet
   Position* position = new Position(ship->getPos());
   Velocity* velocity = new Velocity(ship->getVelocity().getDX(), 
                                     ship->getVelocity().getDY());
   
   double speed = random(500, 900);
   Acceleration acceleration(ship->getAngle(), speed);
   
   // Move the bullet away from the ship so it doesn't collide on creation
   position->add(acceleration, *velocity, TIME_PER_FRAME);
   velocity->add(acceleration, TIME_PER_FRAME);

   Angle* angle = new Angle(ship->getAngle());

   // Add the bullet to the orbitals list
   orbitals.push_back(new Bullet(position, velocity, angle));
}