/*
File:    Animal.cpp
Project: CMSC 202 Project 4, Fall 2018
Author:  Adam Hereth
Data:    11/15/2018
Section: 12
Email:   ahereth1@umbc.edu
*/

#include "Animal.h"
#include <ctime>
#include <iomanip>

// Default Constructor
// Preconditions: None
// Postconditions: A simple object is created (like an animal was born)
Animal::Animal()
{
  if (randomPercentBased(50))
    m_gender = FEMALE;
  else
    m_gender = MALE;
  m_health = 1;
  m_age = 1;
}

// Overloaded Constructor
// Preconditions: Valid inputs
// Postconditions: None
Animal::Animal(Gender gender, int health, int age)
{
  m_gender = gender;
  m_health = health;
  m_age = age;
}

// getGender() - returns the gender of animal
// Preconditions: m_gender is set
// Postconditions: returns an enum Gender referring to which gender
Gender Animal::getGender()
{
  return Gender();
}

// getHealth() - returns the health of animal
// Preconditions: m_health is set
// Postconditions: returns an int referring to health 1 - MAX_health
int Animal::getHealth()
{
  return m_health;
}

// getAge() - returns the age of animal
// Preconditions: m_age is set
// Postconditions: returns an int referring to age 1- MAX_AGE
int Animal::getAge()
{
  return m_age;
}

// liveAYear() - changes parameters based on 1 year of life
// - 50% chance that health diminishes
// - if Eat() is false health diminishes
// - 50% chance of aging
// Preconditions: all variables are set valid
// Postconditions: returns an bool of whether animal lives
bool Animal::liveAYear()
{
  int randNum = 50;
  if (m_health == 0)
    return false;
  else
    {
      if (randomPercentBased(randNum))
	{
	  diminishHealth();
	}
      if (eat() == false)
	{
	  diminishHealth();
	}
      if (randomPercentBased(randNum))
	{
	 m_age = m_age + 1;
	}
    }
  if(m_health < 0 or m_age > 5)
    return false;
  else
    return true;
}

// diminishHealth() - take one from health
// Preconditions: all variables are set valid
// Postconditions: returns an bool of whether animal lives
bool Animal::diminishHealth()
{
  if (m_health != 0)
    {
      m_health = m_health - 1;
      return true;
    }
  else if(m_health ==0)
    return false;
  else
    return true;
}

// Overloaded << - Prints the credentials of an animal
// Preconditions: all variables are set valid
// Postconditions: returns an ostream with output of animal
ostream & operator<<(ostream& cout, Animal& myAnimal)
{
  cout << setw(16) << left << myAnimal.toString();
  cout << setw(16) << left;
  if(myAnimal.getGender() == 0)
    cout << "Female";
  else if(myAnimal.getGender() == 1)
    cout << "Male";
  cout << setw(16) << left;

  if(myAnimal.getHealth() == 0)
    cout << "Dead";
  else if(myAnimal.getHealth() == 1)
    cout << "Bad";
  else if(myAnimal.getHealth() == 2)
    cout << "Diminishing";
  else if(myAnimal.getHealth() == 3)
    cout << "Poor";
  else if(myAnimal.getHealth() == 4)
    cout << "Ok";
  else if(myAnimal.getHealth() == 5)
    cout << "Average";
  else if(myAnimal.getHealth() == 6)
    cout << "Good";
  else if(myAnimal.getHealth() == 7)
    cout << "Very Good";
  else if(myAnimal.getHealth() == 8)
    cout << "Great";
  else if(myAnimal.getHealth() == 9)
    cout << "Excellent";
  else if(myAnimal.getHealth() == 10)
    cout << "Perfect";
  cout << setw(4) << left;

  if (myAnimal.getAge() == 1)
    cout << "Very Young";
  else if(myAnimal.getAge() == 2)
    cout << "Young";
  else if(myAnimal.getAge() == 3)
    cout << "Prime";
  else if(myAnimal.getAge() == 4)
    cout << "Middle";
  else if(myAnimal.getAge() == 5)
    cout << "Old";
  cout << endl;
  return cout;
}

// randomPercentBased (Helper function)
// Precondition: Given int to "pass"
// Description: This function is used to see if a certain random event occurs
//              A random number 1-100 is compared to the int passed
//              If the random number is less than the passed value, return true
//              Else return false (30 = 30%, 70 = 70%)
// Postcondition: Returns boolean
bool Animal::randomPercentBased(int randNum)
{
  srand(time(NULL));
  if ((rand() % 100 + 1) < randNum)
    return true;
  else
    return false;
}
