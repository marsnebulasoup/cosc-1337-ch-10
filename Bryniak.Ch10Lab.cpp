/*
Movie Statistics
Author: Kevin Bryniak
Status: Incomplete
Completed: N/A
This program prompts the user for the number of students surveyed and how many movies they watched,
then computes the average number of movies watched per student.
*/

#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

const string TITLE = "Movie Statistics Calculator";
const string STUDENT_COUNT_PROMPT = "Enter the number of students surveyed: ";
const string STUDENT_MOVIES_PROMPT = "Enter the number of movies each watched by each student.";
 
struct Student {
  int moviesWatched;

  Student(int moviesWatched = 0) {
    this->moviesWatched = moviesWatched;
  }  
};

int main()
{
  return 0;
}