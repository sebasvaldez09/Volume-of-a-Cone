/////////////////////////////////////////////////////////////////////
//
// Name: Sebastian Valdez - Leal
// Due date: 2/21/24
// Class: CSCI 1370.04
// Semester: Spring 2024
// CSCI 1370 Instructor: Gustavo Dietrich
//
// Using your own words describe below what the program does 
// Program Description: Find the volume of a cone based on its height and radius
//
/////////////////////////////////////////////////////////////////////

#include <typeinfo>				// to be able to use operator typeid
// Include here the libraries that your program needs to compile
#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>

using namespace std;


// Ignore this; it's a little function used for making tests
inline void _test(const char* expression, const char* file, int line)
{
	cerr << "test(" << expression << ") failed in file " << file;
	cerr << ", line " << line << "." << endl << endl;
}
// This goes along with the above function...don't worry about it
#define test(EXPRESSION) ((EXPRESSION) ? (void)0 : _test(#EXPRESSION, __FILE__, __LINE__))

// Insert here the prototypes of the functions
double square(double x1);
double volume_cone(int radius, int height);
double round_off(double val, int dig);
void print_data(string name, int radius, int height, double volume);

// Declare a global constant variable called PI above main() that holds value 3.141592

const double PI = 3.141592;

int main()
{
// Declare a variable named name that holds text
    string name;

// Declares variables named height and radius that hold whole numbers
    int height;
    int radius;
    
// Declare a variable named volume that holds double precision real numbers
    double volume;
    
// Prompts the user "May I get your first name please?: "
    cout << "May I get your first name please?: ";
// Read the value from the keyboard and stores it in name
    cin >> name;
// Prompt the user "Thanks ", name, ", now enter radius and height of the cone please: "
    cout << endl << "Thanks " << name << ", now enter radius and height of the cone please: ";
// Read the values from the keyboard and stores them in radius and height respectively
    cin >> radius >> height;
// Call function volume_cone() to calculate the volume of the cone and assign the result to volume 
    volume = volume_cone(radius, height);
// Call function print_data() to print the values entered by the user and the volume of the cone
    print_data(name, radius, height, volume);





// Do NOT remove or modify the following statements
	cout << endl << "Testing your solution" << endl << endl;
	test(typeid(PI) == typeid(1.));							// Incorrect data type used for PI
	test(PI == 3.141592);									// Incorrect value used for PI
	test(typeid(name) == typeid(string));					// Incorrect data type used for name
	test(typeid(height) == typeid(1));						// Incorrect data type used for height
	test(typeid(radius) == typeid(1));						// Incorrect data type used for radius
	test(typeid(volume) == typeid(1.));						// Incorrect data type used for volume
	test(fabs(volume_cone(3,5) - 47.124) < 0.0001);			// Incorrect rounding of volume
	test(fabs(volume_cone(3, 4) - 37.699) < 0.0001);		// Incorrect rounding of volume

	return 0;
}


//************************  Function definition  *************************
// Read the handout carefully for detailed description of the functions that you have to implement

// Calculates the square of the value received

double square(double x1)
{
    double resultSquare;
    resultSquare = x1 * x1;
    return resultSquare;
} 

// Calculates the volume of the cone using the formula 1 / 3 x Pi x radius^2 x height

double volume_cone(int radius, int height)
{
    double volume_cone;
    static_cast<double>(radius);
    volume_cone = 1./3. * PI * square(radius) * height;
    volume_cone = round_off(volume_cone, 3);
    return volume_cone;
}

// Rounds the value received in the first parameter to the number of digits received in the second parameter

double round_off(double val, int dig)
{
    return round(val * pow(10., dig)) / pow(10., dig);
}

// Prints the volume of the cone
void print_data(string name, int radius, int height, double volume)
{
    cout << "\nOk " << name << endl;
    cout << "\nFor a radius: " << radius << " and a height: " << height << " the cone's volume is " << fixed << setprecision(3) << volume << endl;
}
