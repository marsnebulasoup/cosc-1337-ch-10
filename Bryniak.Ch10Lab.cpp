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
const string DESCRIPTION = "This program prompts the user for the number of students surveyed and how many movies they watched, then computes the average number of movies watched per student.";
const string STUDENT_COUNT_PROMPT = "Enter the number of students surveyed: ";
const string STUDENT_MOVIES_PROMPT = "Enter the number of movies each watched by each student.";
const string STUDENT_MOVIES_ERROR = "Please enter an integer value greater than 0: ";
const string STUDENT_COUNT_ERROR = "Error: Too many students.";
const string OUTPUT_HEADER = "Number of Movies Watched\n------------------------";
const string OUTPUT_FOOTER = "---------\nAverage: ";

struct Student
{
  int moviesWatched;

  Student(int moviesWatched = 0)
  {
    this->moviesWatched = moviesWatched;
  }

  bool operator<(const Student &other)
  {
    return moviesWatched < other.moviesWatched;
  }
};

void getStudentData(int, Student*);
double computeAverage(int, Student*);
void display(int, Student*, double);

int main()
{
  int studentCount;
  double averageMoviesWatched;
  Student *studentData;

  cout << TITLE << endl
       << DESCRIPTION << endl
       << endl
       << STUDENT_COUNT_PROMPT;

  bool validStudentCount = true;
  do
  {
    input(studentCount, STUDENT_MOVIES_ERROR);
    studentData = new Student[studentCount];
    if (studentData == nullptr)
    {
      cout << STUDENT_COUNT_ERROR << endl;
      validStudentCount = false;
    }
  } while (!validStudentCount);

  getStudentData(studentCount, studentData);
  sort(studentData, studentData + studentCount);
  averageMoviesWatched = computeAverage(studentCount, studentData);
  display(studentCount, studentData, averageMoviesWatched);

  delete[] studentData;
  studentData = nullptr;

  return 0;
}

void input(int &inp, string onError)
{
  cin >> inp;
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

void getStudentData(int students, Student* studentData)
{
  cout << STUDENT_MOVIES_PROMPT << endl;
  for (int i = 0; i < students; i++)
  {
    cout << i + 1 << ": ";

    Student *pCurrStudent = studentData + i;
    input(pCurrStudent->moviesWatched, STUDENT_MOVIES_ERROR);
  }
}

double computeAverage(int students, Student* studentData)
{
  double average = 0;
  double total = 0;

  for (int i = 0; i < students; i++)
  {
    total += (studentData + i)->moviesWatched;
  }
  average = total / students;

  return average;
}

void display(int students, Student* studentData, double average)
{
  cout << endl
       << OUTPUT_HEADER << endl;
  for (int i = 0; i < students; i++)
  {
    cout << fixed << setprecision(1) << (studentData + i)->moviesWatched << endl;
  }
  cout << OUTPUT_FOOTER << average << endl;
}