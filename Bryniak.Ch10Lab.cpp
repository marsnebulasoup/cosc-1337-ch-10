/*
Movie Statistics
Author: Kevin Bryniak
Status: Complete
Completed: 13 July 2022
This program prompts the user for the number of students surveyed and how many movies they watched,
then computes the average number of movies watched per student.
*/

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <limits>

using namespace std;

// Program constants
const string TITLE = "Movie Statistics Calculator";
const string DESCRIPTION = "This program prompts the user for the number of students surveyed and how many movies they watched, then computes the average number of movies watched per student.";
const string STUDENT_COUNT_PROMPT = "Enter the number of students surveyed: ";
const string STUDENT_MOVIES_PROMPT = "Enter the number of movies each watched by each student.";
const string STUDENT_MOVIES_ERROR = "Please enter an integer value greater than 0: ";
const string STUDENT_COUNT_ERROR = "Error: Too many students.";
const string OUTPUT_HEADER = "Number of Movies Watched\n------------------------";
const string OUTPUT_FOOTER = "---------\nAverage: ";

// Struct for storing student data
struct Student
{
  int moviesWatched; // Number of movies watched by the student

  Student(int moviesWatched = 0) // Constructor
  {
    this->moviesWatched = moviesWatched;
  }

  bool operator<(const Student &other) // Overloaded less than operator (for sorting)
  {
    return moviesWatched < other.moviesWatched;
  }
};

// Function prototypes
void input(int &, string);
void getStudentData(int, Student *);
double computeAverage(int, Student *);
void display(int, Student *, double);

int main()
{
  int studentCount;            // Number of students surveyed
  double averageMoviesWatched; // Average number of movies watched per student
  Student *studentData;        // Array of student data

  // Prompt user for number of students surveyed
  cout << TITLE << endl
       << DESCRIPTION << endl
       << endl
       << STUDENT_COUNT_PROMPT;

  bool validStudentCount = true; // Flag for valid student count
  do                             // Prompt the user for a valid student count until one is given
  {
    input(studentCount, STUDENT_MOVIES_ERROR); // Prompt user for student count
    studentData = new Student[studentCount];   // Attempt to allocate memory for student data
    if (studentData == nullptr)                // If memory allocation failed, let the user know
    {
      cout << STUDENT_COUNT_ERROR << endl;
      validStudentCount = false;
    }
  } while (!validStudentCount);

  getStudentData(studentCount, studentData);                        // Prompt user for individual student data
  sort(studentData, studentData + studentCount);                    // Sort the student data array
  averageMoviesWatched = computeAverage(studentCount, studentData); // Compute the average number of movies watched per student
  display(studentCount, studentData, averageMoviesWatched);         // Display the results

  delete[] studentData;  // Free the memory allocated for the student data array
  studentData = nullptr; // Clean up dangling pointer

  return 0;
}

// Prompt the user for a value and store it in the variable provided
void input(int &inp, string onError)
{
  cin >> inp;     // Prompt the user for a value
  if (cin.fail()) // If the user did not enter a valid value, let the user know
  {
    cout << onError;                                     // Display the error message
    cin.clear();                                         // Clear the error flag
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore the rest of the line
    input(inp, onError);                                 // Prompt the user again
  }

  // After the user enters a valid value, clear the error flag and ignore the rest of the line
  cin.clear();
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Prompt the user for the number of movies watched by each student and store the data in the student data array
void getStudentData(int students, Student *studentData)
{
  cout << STUDENT_MOVIES_PROMPT << endl; // Prompt the user for the number of movies watched by each student
  for (int i = 0; i < students; i++)     // Loop through all students
  {
    cout << i + 1 << ": "; // Display the student number

    Student *pCurrStudent = studentData + i;                  // Point to the current student in the student data array
    input(pCurrStudent->moviesWatched, STUDENT_MOVIES_ERROR); // Prompt the user for the number of movies watched by the current student
  }
}

// Compute the average number of movies watched by each student and return the result
double computeAverage(int students, Student *studentData)
{
  double average = 0; // Average number of movies watched by each student
  double total = 0;   // Total number of movies watched by all students

  for (int i = 0; i < students; i++) // Loop through all students
  {
    total += (studentData + i)->moviesWatched; // Add the number of movies watched by the current student to the total
  }
  average = total / students; // Compute the average number of movies watched by each student

  return average;
}

// Display the results of the program
void display(int students, Student *studentData, double average)
{
  // Display output header
  cout << endl
       << OUTPUT_HEADER << endl;
  for (int i = 0; i < students; i++) // Loop through all students
  {
    cout << fixed << setprecision(1) << (studentData + i)->moviesWatched << endl; // Display the number of movies watched by the current student
  }
  cout << OUTPUT_FOOTER << average << endl; // Display the average number of movies watched by each student
}