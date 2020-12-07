/*
File:    Carnivore.cpp
Project: CMSC 202 Project 4, Fall 2018
Author:  Adam Hereth
Data:    11/15/2018
Section: 12
Email:   ahereth1@umbc.edu
*/

#include "Carnivore.h"

// Default Constructor
// Preconditions: None
// Postconditions: None
Carnivore::Carnivore(){}

// Overloaded Constructor
// Preconditions: Valid inputs
// Postconditions: None
Carnivore::Carnivore(Gender gender, int health, int age):Animal(gender, health, age){}

// eat() - Tests if animal successfully ate.
// - if the hunt was a success or they are age 1 then true
// otherwise they have a 50% chance
// Preconditions: all variables are set valid
// Postconditions: returns an bool of whether animal ate or did not
//                 in the course of the year
bool Carnivore::eat()
{
  int randNum = 50;
  if (hunt() || getAge() == 1)
    return true;
  else if (randomPercentBased(randNum))
    return true;
  else
    return false;
}

