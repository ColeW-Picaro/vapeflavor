/*
  Filename: Main.cpp
  Author: Cole Vohs
  Description: A program that takes two random lines from two files and combines them
*/

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <iterator>
#include <string>
#include <vector>
#include <algorithm>
#include <random>

int
main (int argc, char** argv)
{
  // Get adjectives; put into vector
  std::vector<std::string> adjectives;
  std::ifstream adjectivesFile;
  adjectivesFile.open ("adjectives.txt");
  std::copy(std::istream_iterator<std::string> (adjectivesFile),
	    std::istream_iterator<std::string> (),
	    std::back_inserter (adjectives));
  
  // Get fruits; put into vector
  std::vector<std::string> fruits;
  std::ifstream fruitsFile;
  fruitsFile.open ("fruit.txt");
  std::copy(std::istream_iterator<std::string> (fruitsFile),
	    std::istream_iterator<std::string> (),
	    std::back_inserter (fruits));

  // Create Mersenne Twister and distribution objects for adjectives and fruits
  std::random_device rd;
  std::mt19937 gen (rd ());
  std::uniform_int_distribution<> adjDis (0, std::distance (adjectives.begin (),
							   adjectives.end ())); 
  std::uniform_int_distribution<> fruitDis (0, std::distance (fruits.begin (),
							      fruits.end ()));
  
  // Get a random adjective
  std::string adj = adjectives[adjDis (gen)];
  // Get a random fruit
  std::string fruit = fruits[fruitDis (gen)];

  std::cout << adj << " " << fruit << std::endl;
  
  return EXIT_SUCCESS;
}
