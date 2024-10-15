#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>
#include <fstream>
#include "grade.h"
#include "Student_info.h"
#include "median.h"

using std::cin;
using std::cout;
using std::domain_error;
using std::endl;
using std::max;
using std::setprecision;
using std::sort;
using std::streamsize;
using std::string;

int main()
{
	Vec<Student_info> students;
	Student_info record;
	string::size_type maxlen = 0; // the length of the longest name

	// read and store all the students' data.
	// Invariant: 'students' contains all the student records read so far
	//			'maxlen' contains the length of the longest name in 'students'
	std::ifstream infile("grades");
	std::ofstream outfile("final");
	while (record.read(infile))
	{
		// find length of longest name
		maxlen = max(maxlen, record.name().size());
		students.push_back(record);
	}
	// alphabetize the student records
	sort(students.begin(), students.end(), compare);

	// write the names and grades
	for (Vec<Student_info>::size_type i = 0; i != students.size(); ++i)
	{
		// write the name, padded on the right to 'maxlen+1' characters
		cout << students[i].name()
			 << string(maxlen + 1 - students[i].name().size(), ' ');
		outfile << students[i].name()
				<< string(maxlen + 1 - students[i].name().size(), ' ');
		// compute and write the grade
		try
		{
			double final_grade = students[i].final_grade();
			string ltr_grd = letter_grade(final_grade);
			cout << ltr_grd;
			outfile << ltr_grd;
		}
		catch (domain_error e)
		{
			cout << e.what();
			outfile << e.what();
		}
		cout << endl;
		outfile << endl;
	}
	cout << endl;
	cout << "the following is the result of testing median function on array\nthe random array is:" << endl;
	outfile << "the following is the result of testing median function on array\nthe random array is:" << endl;
	srand(time(NULL));
	int *array = new int[11];
	for (int i = 0; i != 11; ++i)
		array[i] = rand() % 99 + 1;
	for (int i = 0; i != 11; ++i)
	{
		cout << array[i] << ' ';
		outfile << array[i] << ' ';
	}
	cout << endl;
	outfile << endl;
	cout << "the median of the array is: " << median(array, array + 11) << endl
		 << "after median function called, the array is unchanged:" << endl;
	outfile << "the median of the array is: " << median(array, array + 11) << endl
			<< "after median function called, the array is unchanged:" << endl;
	for (int i = 0; i != 11; ++i)
	{
		cout << array[i] << ' ';
		outfile << array[i] << ' ';
	}
	cout << endl;
	outfile << endl;
	delete[] array;

	return 0;
}
