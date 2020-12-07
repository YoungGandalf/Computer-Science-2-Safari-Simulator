/*
File:    Safari.cpp
Project: CMSC 202 Project 4, Fall 2018
Author:  Adam Hereth
Data:    11/15/2018
Section: 12
Email:   ahereth1@umbc.edu
*/

#include "Safari.h"
#include <iomanip>

// Default Constructor
// Preconditions: None
// Postconditions: None
Safari::Safari(){}

// Destructor
// Preconditions: m_animals is populated
// Postconditions: Deallocates animal object in memory
Safari::~Safari()
{
  for(unsigned int i=0; i<m_animals.size();i++)
    delete m_animals.at(i);
}

// Name: loadAnimals
// Desc - Loads each animals into m_animals from file
// Preconditions - Requires file with valid animal data
// Postconditions - m_animals is populated with animal pointers
void Safari::loadAnimals(char* filename)
{
  ifstream infile(filename);
  int type, gender, health, age;
  if (infile.is_open())
    {
      while (infile >> type >> gender >> health >> age)
	{
	  if (infile.peek() == '\n')
	      infile.ignore();
	    
	  Animal* newAnimal; //creates a new Animal* object
	  if (type == 0)
	    {
	      newAnimal = new Lion(Gender(gender), health, age);
	      m_animals.push_back(newAnimal);
	    }
	  if (type == 1)
	    {
	      newAnimal = new Gazelle(Gender(gender), health, age);
	      m_animals.push_back(newAnimal);
	    }
	  
	  if (type == 2)
	    {
	      newAnimal = new Elephant(Gender(gender), health, age);
	      m_animals.push_back(newAnimal);
	    }
	}
    }
  infile.close();
}

// Name: simulateYear()
// Desc - simulates a year in the safari for all the animals
// Preconditions - Requires a populated m_animals
// Postconditions - simulates a year in time each animal:
// 1. has a chance to breed. If they are successful their offspring
//    is added to m_animals
// 2. lives a year
void Safari::simulateYear()
{
  vector<Animal*> newVector;
  for (unsigned int i = 0; i < m_animals.size(); i++)
    {
      //Chooses the animal at index i and calls the breed function on that animal
      Animal* tempAnimal = m_animals.at(i)->breed();
      if (tempAnimal != NULL)
	{
	  //adds the new Animal to the Animal* vector
	  newVector.push_back(tempAnimal);
	  cout << setw(16) << left
	       << "Born: " << *tempAnimal << endl;
	}
      if (m_animals.at(i)->liveAYear())
	{
	  newVector.push_back(m_animals.at(i));
	  cout << setw(16) << left
	       << "Survived: " << *m_animals.at(i) << endl;
	}
      else
	{
	  cout << setw(16) << left
	       << "Died:" << *m_animals.at(i) << endl;
	  delete m_animals.at(i);
	  m_animals.at(i) = NULL;
	}
    }
  //updating the new vector for the next year
  m_animals = newVector;
}

// Name: MainMenu()
// Desc - Displays and manages menu
// Preconditions - m_animal has been populated
// Postconditions - exits if user entered 3
void Safari::mainMenu()
{
  int main;
  cout << "Welcome to the animal safari" << endl;
  do
    {
      cout << "What would you like to do?" << endl;
      cout << "1. Display Animals" << endl;
      cout << "2. Simulate" << endl;
      cout << "3. Exit" << endl;
      cin >> main;
      if (main == 1)
	displayAnimals();
      else if (main == 2)
	simulate();
    } while (main != 3);
}

// Name: simulate()
// Desc - gets number of years to simulate and simulates for that number
// Preconditions - m_animals is populated
// Postconditions - Has simulated that number years and m_animals reflects changes
void Safari::simulate()
{
  cout << "How many years would you like to simulate?" << endl;
  int sim;
  cin >> sim;
  for (int i = 0; i < sim; i++)
    {
      cout << "YEAR " << i+1 << endl;
      simulateYear();
    }
}

// Name: displayAnimals()
// Desc - Displays all animals in m_animals ina formated fashion
// Preconditions - m_animals is populated
// Postconditions - N/A
void Safari::displayAnimals()
{
  cout << setw(8) << "Animal" << setw(16) << "Gender"
       << setw(16) << "Age" << setw(16) << "Health" << endl;
  for (unsigned int i = 0; i < m_animals.size(); i++)
    {
      cout << i+1 << " " << *m_animals.at(i) << endl;
    }
}
