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

    for (auto orbital : orbitals)
        orbital->detectCollisions(orbitals);

    for (auto orbital : orbitals)
    {
        if (orbital->crashed())
        {
            orbital->destroy(orbitals);
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
    if (pUI->isSpace())
    {
        ship->input(SPACE);
    }
}
