/*
File:    Gazelle.cpp
Project: CMSC 202 Project 4, Fall 2018
Author:  Adam Hereth
Data:    11/15/2018
Section: 12
Email:   ahereth1@umbc.edu
*/
#include "Gazelle.h"

// Default Constructor
// Preconditions: None
// Postconditions: None
Gazelle::Gazelle(): Herbivore(){}

// Overloaded Constructor
// Preconditions: Valid inputs
// Postconditions: None
Gazelle::Gazelle(Gender gender, int health, int age):Herbivore(gender, health, age){}

// breed() - if an animal successfully produces offspring it returns a pointer to it
// - If female and age > 1 there is a 30% chance
// - otherwise false
// Preconditions: all variables are set valid
// Postconditions: returns an pointer to a new animal or NULL
Animal* Gazelle::breed()
{
  int randNum = 30;
  if (getGender() == 0 && (getAge() > 1))
    {
      if (randomPercentBased(randNum))
	{
	  Animal* newAnimal;
	  newAnimal = new Gazelle();
	  return newAnimal;
	}
      else
	return NULL;
    }
  else
    return NULL;
}

// toString() - a string representation of the animal
// Preconditions: all variables are set valid
// Postconditions: returns a string of the name of the animal
string Gazelle::toString()
{
  return "Gazelle";
}

// graze() - Tests if animal successfully graze
// - if the age is not 5 than chance is health*15%
// - otherwise it is false
// Preconditions: all variables are set valid
// Postconditions: returns an bool of whether animal successfully graze
bool Gazelle::graze()
{
  if (getAge() != 5)
    {
      if (randomPercentBased(getHealth() * 15))
	return true;
      else
	return false;
    }
  else
    return false;
}

