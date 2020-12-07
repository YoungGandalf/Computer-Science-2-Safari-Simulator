/*
File:    Elephant.cpp
Project: CMSC 202 Project 4, Fall 2018
Author:  Adam Hereth
Data:    11/15/2018
Section: 12
Email:   ahereth1@umbc.edu
*/
#include "Elephant.h"

// Default Constructor
// Preconditions: None
// Postconditions: None
Elephant::Elephant(): Herbivore(){}

// Overloaded Constructor
// Preconditions: Valid inputs
// Postconditions: None
Elephant::Elephant(Gender gender, int health, int age):Herbivore(gender, health, age){}

// breed() - if an animal successfully produces offspring it returns a pointer to it
// - If female and age > 2 there is a 40% chance
// - otherwise false
// Preconditions: all variables are set valid
// Postconditions: returns an pointer to a new animal or NULL
Animal* Elephant::breed()
{
  int randNum = 40;
  if (getGender() == 0 && (getAge() > 2))
    {
      if (randomPercentBased(randNum))
	{
	  Animal* newAnimal;
	  newAnimal = new Elephant();
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
string Elephant::toString()
{
  return "Elephant";
}

// graze() - Tests if animal successfully graze
// - 95% chance of success
// Preconditions: all variables are set valid
// Postconditions: returns an bool of whether animal successfully graze
bool Elephant::graze()
{
  if (randomPercentBased(95))
    return true;
  else
    return false;
}
