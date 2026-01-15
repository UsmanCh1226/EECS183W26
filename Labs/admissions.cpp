/**
 * admissions.cpp
 *
 * <Usman Chaudhry, Connor Kubrak>
 * <usmanch, >
 *
 * EECS 183: Lab - College Admissions
 *
 * <Lab 1 of EECS 183: College Admissions Calculator>
 */
 
#include <iostream>
using namespace std;


/* TODO: WHEN COMPLETING THE REFLCTION FORM!
 * change the values for these variables
 * NOTE: in order for the program to work the values must all add up to a
 * number <= 1, otherwise you will get values greater than 100
*/
const double GPA_WEIGHT = 0.4;
const double SAT_WEIGHT = 0.3;
const double DEM_INTEREST_WEIGHT = 0.1;
const double CURRICULUM_STRENGTH_WEIGHT = 0.2;

int main() {
    cout << "College Admissions Calculator" << endl;

    // Ask user for input and store in variables
    double gpa = 0;
    cout << "Please enter your GPA out of 5.0: ";
    cin >> gpa;
    cout << endl;

    int sat = 0;
    cout << "Please enter your SAT score out of 1600: ";
    cin >> sat;
    cout << endl;

    int dem_interest = 0;
    cout << "Please enter your demonstrated interest out of 10: ";
    cin >> dem_interest;
    cout << endl;

    int curriculum_strength = 0;
    cout << "Please enter your high school curriculum strength out of 10: ";
    cin >> curriculum_strength;
    cout << endl;

    // Calculate the score (normalize each field, weight it, scale to 100)
    double score = GPA_WEIGHT * (gpa / 5.0) * 100.0
                 + SAT_WEIGHT * (sat / 1600.0) * 100.0
                 + DEM_INTEREST_WEIGHT * (dem_interest / 10.0) * 100.0
                 + CURRICULUM_STRENGTH_WEIGHT * (curriculum_strength / 10.0) * 100.0;

    // Round to nearest integer
    int rounded_score = static_cast<int>(score);


    // Output the final chance
    cout << "Expected chance of admission: " << rounded_score << "/100" << endl;

    return 0;
}