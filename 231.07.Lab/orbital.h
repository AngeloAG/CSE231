/***********************************************************************
 * Header File:
 *    ORBITAL
 * Author:
 *    Angelo Arellano
 *    Connor Hopkins
 *    Jacob Mower
 * Summary:
 *    Orbital class.
 ************************************************************************/

#pragma once

#include "entity.h"
#include "velocity.h"
#include "angle.h"
#include "constants.h"
#include <list>
using std::list;

class TestOrbital;
class TestShip;
class TestGPS;
class TestHubble;
class TestSputnik;
class TestStarlink;
class TestCrewDragon;
class TestBullet;
class TestFragment;
class TestGame;

/*********************************************
* Orbital
* A single instance of an entity that orbits.
*********************************************/
class Orbital : public Entity
{
   friend TestOrbital;
   friend TestShip;
   friend TestGPS;
   friend TestHubble;
   friend TestSputnik;
   friend TestStarlink;
   friend TestCrewDragon;
   friend TestBullet;
   friend TestFragment;
   friend TestGame;

public:
   Orbital(Position* initialPos, int fragmentCount, double radius, 
           Velocity* initialVelocity, Angle* initialAngle);
   ~Orbital()                    { delete angle; delete vel; } // Prevent memory leaks
   double getRadius()      const { return radius * 128000.0; } /* 128km equals 1 pixel */
   int  getFragmentCount() const { return fragmentCount; }
   bool crashed()          const { return hasCrashed;    }

   void move(const Acceleration& accel, double time);
   virtual void detectCollisions(const list<Orbital*>& orbitals);

   virtual void destroy(list<Orbital*>& orbitals);
   virtual list<Orbital*> getParts() const = 0;
   virtual void draw(ogstream& ogstream) const {}
   virtual void update();

protected:
   Angle* angle; // For stubs
   Velocity* vel;
   bool useRandom = true;
   bool hasCrashed;
   double radius;

private:
   int fragmentCount;

   Acceleration getGravityAcceleration() const;
   double getCurrentHeight() const;
   double getGravityDirection() const;
   list<Orbital*> getFragments() const;
};

/*******************************************************************************
* INLINE :: GET GRAVITY FROM HEIGHT
*     Helper function to determine the force of gravity at a certain height.
*******************************************************************************/
inline double getGravityFromHeight(double currentHeight)
{
   double radiusAndHeight = EARTH_RADIUS / (EARTH_RADIUS + currentHeight);
   return GRAVITY_AT_SEA * (radiusAndHeight * radiusAndHeight);
};

/*********************************************
* DummyOrbital
* An dummy class to test the orbital.
*********************************************/
class DummyOrbital : public Orbital
{
public:
   DummyOrbital(Position* initialPos, int fragmentCount, double radius,
      Velocity* initialVelocity, Angle* initialAngle): 
            Orbital(initialPos, fragmentCount, radius,
                    initialVelocity, initialAngle) {  }

   list<Orbital*> getParts() const
   {
      list<Orbital*> emptyList;
      return emptyList;
   }
};

/*********************************************
* StubOrbital_OnePart
* An stub class to test the orbital.
*********************************************/
class StubOrbital_OnePart : public Orbital
{
public:
   StubOrbital_OnePart (Position* initialPos, int fragmentCount, double radius,
      Velocity* initialVelocity, Angle* initialAngle) :
      Orbital(initialPos, fragmentCount, radius,
         initialVelocity, initialAngle) {  }

   virtual list<Orbital*> getParts() const
   {
      list<Orbital*> singleOrbital;
      singleOrbital.push_back(new DummyOrbital(new DummyPosition(), 0, 0, new DummyVelocity(), new DummyAngle()));
      return singleOrbital;
   }
};

/*********************************************
* StubOrbital_NoParts
* A stub class to test the orbital.
*********************************************/
class StubOrbital_NoParts : public Orbital
{
public:
   StubOrbital_NoParts(Position* initialPos, int fragmentCount, double radius,
      Velocity* initialVelocity, Angle* initialAngle) :
      Orbital(initialPos, fragmentCount, radius,
         initialVelocity, initialAngle) {  }

   virtual list<Orbital*> getParts() const
   {
      list<Orbital*> singleOrbital;
      return singleOrbital;
   }
};

/*********************************************
* StubOrbital_ThreeParts
* A stub class to test the orbital.
*********************************************/
class StubOrbital_ThreeParts : public Orbital
{
public:
   StubOrbital_ThreeParts(Position* initialPos, int fragmentCount, double radius,
      Velocity* initialVelocity, Angle* initialAngle) :
      Orbital(initialPos, fragmentCount, radius,
         initialVelocity, initialAngle) {  }

   virtual list<Orbital*> getParts() const
   {
      list<Orbital*> singleOrbital;
      singleOrbital.push_back(new DummyOrbital(new DummyPosition(), 0, 0, new DummyVelocity(), new DummyAngle()));
      singleOrbital.push_back(new DummyOrbital(new DummyPosition(), 0, 0, new DummyVelocity(), new DummyAngle()));
      singleOrbital.push_back(new DummyOrbital(new DummyPosition(), 0, 0, new DummyVelocity(), new DummyAngle()));
      return singleOrbital;
   }
};

/*********************************************
* Fragment
* pieces that break off from other satellites
*********************************************/
class Fragment: public Orbital
{
   friend TestFragment;
private:
   int lifespan;
   
public:
   Fragment(Position* initialPos,
            Velocity* initialVelocity, Angle* initialAngle) :
            Orbital(initialPos, 0, 2.0,
            initialVelocity, initialAngle), lifespan(0) {  }
      
   virtual list<Orbital*> getParts() const
   {
      return list<Orbital*> ();
   }
   
   virtual void draw(ogstream &ogstream) const 
   {
      ogstream.drawFragment(*this->pos, this->angle->getRadians());
   }
   
   
   virtual void update()
   {
      lifespan ++;
      Orbital::update();
      if (lifespan >=  80)
         hasCrashed = true;
   }
   
};

/*********************************************
* StubOrbital_ThreeFragmentThreeParts
* A stub class to test the orbital.
*********************************************/
class StubOrbital_ThreeFragmentThreeParts : public Orbital
{
public:
   StubOrbital_ThreeFragmentThreeParts(Position* initialPos,
      Velocity* initialVelocity, Angle* initialAngle) :
      Orbital(initialPos, 3, 2,
         initialVelocity, initialAngle) {  }

   
   virtual list<Orbital*> getParts() const
   {
      list<Orbital*> threeOrbitals;
      threeOrbitals.push_back(new DummyOrbital(new DummyPosition(), 0, 0, new DummyVelocity(), new DummyAngle()));
      threeOrbitals.push_back(new DummyOrbital(new DummyPosition(), 0, 0, new DummyVelocity(), new DummyAngle()));
      threeOrbitals.push_back(new DummyOrbital(new DummyPosition(), 0, 0, new DummyVelocity(), new DummyAngle()));
      return threeOrbitals;
   }
};

/*********************************************
* StubOrbital_ThreeFragmentZeroParts
* A stub class to test the orbital.
*********************************************/
class StubOrbital_ThreeFragmentZeroParts : public Orbital
{
public:
   StubOrbital_ThreeFragmentZeroParts(Position* initialPos,
      Velocity* initialVelocity, Angle* initialAngle) :
      Orbital(initialPos, 3, 2,
         initialVelocity, initialAngle) {  }

   
   virtual list<Orbital*> getParts() const
   {
      list<Orbital*> noOrbitals;
      return noOrbitals;
   }
};

/*********************************************
* StubOrbital_OneFragment
* A stub class to test the orbital.
*********************************************/
class StubOrbital_OneFragment : public Orbital
{
public:
   StubOrbital_OneFragment(Position* initialPos,
      Velocity* initialVelocity, Angle* initialAngle) :
      Orbital(initialPos, 1, 2,
         initialVelocity, initialAngle) {  }

   virtual list<Orbital*> getParts() const
   {
      list<Orbital*> emptyOrbital;
      assert(false);
      return emptyOrbital;
   }
};

/*********************************************
* StubOrbital_ZeroFragment
* A stub class to test the orbital.
*********************************************/
class StubOrbital_ZeroFragment : public Orbital
{
public:
   StubOrbital_ZeroFragment(Position* initialPos,
      Velocity* initialVelocity, Angle* initialAngle) :
      Orbital(initialPos, 0, 2,
         initialVelocity, initialAngle) {  }

   virtual list<Orbital*> getParts() const
   {
      list<Orbital*> emptyOrbital;
      assert(false);
      return emptyOrbital;
   }
};

/*********************************************
* StubOrbital_ThreeFragment
* A stub class to test the orbital.
*********************************************/
class StubOrbital_FourFragment : public Orbital
{
public:
   StubOrbital_FourFragment(Position* initialPos,
      Velocity* initialVelocity, Angle* initialAngle) :
      Orbital(initialPos, 4, 2,
         initialVelocity, initialAngle) {  }

   virtual list<Orbital*> getParts() const
   {
      list<Orbital*> emptyOrbital;
      assert(false);
      return emptyOrbital;
   }
};







/*********************************************
* Bullet
* Bullets that are fired from the ship
*********************************************/
class Bullet: public Orbital
{
   friend TestBullet;
private:
   int lifespan;
public:
   Bullet(Position* initialPos,
      Velocity* initialVelocity, Angle* initialAngle) :
      Orbital(initialPos, 0, 1.0,
         initialVelocity, initialAngle), lifespan(0) {  }
      
   virtual list<Orbital*> getParts() const
   {
      return list<Orbital*> ();
   }
   
   virtual void draw(ogstream &ogstream) const
   {
      ogstream.drawProjectile(*this->pos);
   }
   
   virtual void update() 
   {
      lifespan ++;
      Orbital::update();
      if (lifespan >=  70)
         hasCrashed = true;
   }
};
