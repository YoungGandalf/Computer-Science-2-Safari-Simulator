/*
File:    Lion.cpp
Project: CMSC 202 Project 4, Fall 2018
Author:  Adam Hereth
Data:    11/15/2018
Section: 12
Email:   ahereth1@umbc.edu
*/
#include "Lion.h"

// Default Constructor
// Preconditions: None
// Postconditions: None
Lion::Lion(): Carnivore(){}

// Overloaded Constructor
// Preconditions: Valid inputs
// Postconditions: None
Lion::Lion(Gender gender, int health, int age):Carnivore(gender, health, age){}

// breed() - if an animal successfully produces offspring it returns a pointer to it
// - If female and age 3 or 4 there is a 50% chance
// - otherwise false
// Preconditions: all variables are set valid
// Postconditions: returns an pointer to a new animal or NULL
Animal* Lion::breed()
{
  int randNum = 50;
  if (getGender() == 0 && (getAge() == 3 || getAge() == 4))
    {
      if (randomPercentBased(randNum))
	{
	  Animal* newAnimal;
	  newAnimal = new Lion();
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
string Lion::toString()
{
  return "Lion";
}

// hunt() - Tests if animal successfully hunted
// - if the age > 1 than chance is health*10%
// - otherwise false
// Preconditions: all variables are set valid
// Postconditions: returns an bool of whether animal successfully hunted
bool Lion::hunt()
{
  if (getAge() > 1)
    {
      if (randomPercentBased(getHealth() * 10))
	return true;
      else
	return false;
    }
  return true;
}

