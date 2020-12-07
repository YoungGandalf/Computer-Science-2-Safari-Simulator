/*
File:    Herbivore.cpp
Project: CMSC 202 Project 4, Fall 2018
Author:  Adam Hereth
Data:    11/15/2018
Section: 12
Email:   ahereth1@umbc.edu
*/

#include "Herbivore.h"

// Default Constructor
// Preconditions: None
// Postconditions: None
Herbivore::Herbivore(){}

// Overloaded Constructor
// Preconditions: Valid inputs
// Postconditions: None
Herbivore::Herbivore(Gender gender, int health, int age):Animal(gender, health, age){}

// eat() - Tests if animal successfully ate.
// - if the graze was a success or they are age 1 then true
// otherwise they don't eat
// Preconditions: all variables are set valid
// Postconditions: returns an bool of whether animal ate or did not
//                 in the course of the year
bool Herbivore::eat()
{
  if (graze() || getAge() == 1)
    return true;
  else
    return false;
}

