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
#include <limits>

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

void input(int*, string);

int main()
{
  return 0;
}

void input(int *inp, string onError)
{
  cin >> *inp;
  if (cin.fail())
  {
    cout << onError;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    input(inp, onError);
  }

  cin.clear();
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
}