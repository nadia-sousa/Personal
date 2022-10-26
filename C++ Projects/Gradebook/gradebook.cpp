#include "gradebook.h"
#include<fstream>
#include<iostream>
#include<iomanip>
#include<sstream>

//  Input Order **(Input as POINTS, NOT PERCENTAGES) (by line/row)
//    **(I think it may be easier to input grades as the points received rather than its percentage)
//  Line 0 = Lab Grades
//  Line 1 = Assignment Grades
//  Line 2 = Term Project
//  Line 3 = Review Project
//  Line 4 = Final Exam


//  Edits Made
//  ----------
//      -= Lab Grades Function =-
// Moved calculation for "Size" above "Max_score" so "Max_score" can be calculated in its definition
//      Figured you wanted to calculate the grades using assignments given rather than the total
//        over the full semester.
//      (If we did calculations using grades over whole semester, the "size" would remain constant)
//
//      -= Assignment Grades Function =-
// Function type may want to be int/double so we can save totals for Final Grade calculations.
//
// Changed "size" variable to be set to zero at each definition to prevent it from carrying over.


Gradebook::Gradebook(std::string f_name, std::vector<std::vector<double>> *grades) {
//  this->grades = new std::vector<std::vector<double>>;
    std::ifstream file(f_name);
    std::string str;

//  Takes input from file and enters sorted values into a 2D vector (type: double)
    while (std::getline(file, str)) {
       std::vector<double> new_row;

       std::istringstream ss(str);

       double token;

        while(ss >> token){
            new_row.push_back(token);
        }
        (*grades).push_back(new_row);
    }

//  Test to check that the input was correctly entered into the vector
    // for(int i = 0; i < grades->size(); i++){
    //     for(int j = 0; j < (*grades)[i].size(); j++){
    //        std::cout << (*grades)[i][j] << " ";
    //     }
    //     std::cout << std::endl;
    // }
}

void Gradebook::calculate_lab_grade(std::vector<std::vector<double>> *grades){
// Defining the weight of each assignment grade
    int grade_weight = 5;

//  Moved "size" above "max_score" to use it when calculating max score w/out needing to calc later
    int size = (*grades)[0].size();
    int max_score = 5*size;

//  Sum set to zero to prevent overflow from previous function
    double sum = 0;
    double percent;

//  Sums total grades
    for(int i = 0; i < size; i++){
        sum += (*grades)[0][i];
    }

// Commented out following "cout" line to prevent clutter in output (Can be reversed if needed)
    // std::cout << sum << "," << size << std::endl;

// Removed "size" since it was used earlier in the "max_score" definition
    percent = ((sum/max_score) * 100);
    // std::cout << "Your overall lab grade is " << percent << " % "<< std::endl;

//  Changed output to be:  (sum of received points) / (total possible points)
    // std::cout << "This translates to " << sum << "/" << size*grade_weight << " points"<< std::endl;

    possible_points += max_score;
    lab_grade = sum;
    std::cout << max_score << "\t" << possible_points << std::endl;
}

void Gradebook::calculate_assignment_grade(std::vector<std::vector<double>> *grades){
// Defining the weight of each assignment grade
    int grade_weight = 100;

//  Moved "size" above "max_score" to use it when calculating max score w/out needing to calc later
    int size = (*grades)[1].size();
    int max_score = 100*size;

//  Sum set to zero to prevent overflow from previous function
    double sum = 0;

//  Percent = Calculated Grade
    double percent;

//  Sums all grades from assignment row
    for(int i = 0; i < size; i++){
        sum += (*grades)[1][i];
    }

// Commented out following "cout" line to prevent clutter in output (Can be reversed if needed)
    // std::cout << sum << ", " << size << std::endl;

//  Percent only needed for output since we can use the point totals to save time
    percent = ((sum/max_score) * 100);
    // std::cout << "Your overall Assignment grade is " << percent << " % "<< std::endl;

//  Uses point totals so that less calculations are needed
    // std::cout << "This translates to " << sum << "/" << size*grade_weight << " points"<< std::endl;

    assignment_grade = sum;
    possible_points += max_score;
    std::cout << max_score << "\t" << possible_points << std::endl;
}

void Gradebook::term_project(std::vector<std::vector<double>> *grades) {
//  Grade weight is also max points
    int grade_weight = 350;

//  Variable to hold input grade
    double score = (*grades)[2][0];

//  Percentage grade
    double percent = ((score / grade_weight) * 100);
    // std::cout << std::fixed;
    // std::cout << "Your overall Term Project grade is " << std::setprecision(0) << percent << " % "<< std::endl;

//  Points reveived over points possible
    // std::cout << "This translates to " << score << "/" << grade_weight << " points"<< std::endl;

    term_project_grade = score;
    possible_points += grade_weight;
    std::cout << grade_weight << "\t" << possible_points << std::endl;
}


void Gradebook::review_project(std::vector<std::vector<double>> *grades){
//  Splits review project into both parts
    int part_one = (*grades)[3][0];
    int part_two = (*grades)[3][1];
    extra_points = 0;

//  Checks for pass/fail
    if(part_one == 1){
        extra_points += 2.5;
    }

    if(part_two == 1){
        extra_points += 1.5;
    }

    // std::cout << "You have recieved " << extra_points << " extra points from the review project." << std::endl;
}

void Gradebook::final_exam(std::vector<std::vector<double>> *grades) {
//  Total points possible
    int grade_weight = 100;

//  Inputed score
    double score = (*grades)[4][0];

//  Grade as a percentage
    double percent = ((score / grade_weight) * 100);
    // std::cout << std::fixed;
    // std::cout << "Your Final Exam grade is " << std::setprecision(0) << percent << " % "<< std::endl;

//  Points reveived over points possible
    // std::cout << "This translates to " << score << "/" << grade_weight << " points"<< std::endl;

    final_exam_grade = score;
}

void Gradebook::overall_grade(){
//  total(sum of other grades) and total percent(total over total points possible) variable
    double total;
    double total_percent;

//  Getting total points for all grades
    total = lab_grade + assignment_grade + term_project_grade;

//  Checks if input exam grade is equal to -1
//      if true, program will not add it to final
    if(final_exam_grade == -1) {
        take_final_exam = false;
    } else {
        take_final_exam = true;
    }

//  Checking for final exam exemption (exempt if total >= 90)
//      Find the final grade with the final exam
    if(((total / 900) * 100) < 90 || take_final_exam == 1) {
        total += final_exam_grade;
        possible_points += 100;
        total_percent = ((total / possible_points) * 100) + extra_points;
        // std::cout << "Your overall grade with the exam is " << total_percent << "%" << std::endl;

//      Finds the final grade without the exam
    } else{
        total_percent = ((total / possible_points) * 100) + extra_points;
        // std::cout << "Your overall grade is " << total_percent << "%" << std::endl;
        // std::cout << "Your grade is high enough to skip the Final Exam!" << std::endl;
    }

// Returns total rather than percentage so the bonus points can be added later
    final_grade = total;
}

void Gradebook::output_grades(std::vector<std::vector<double>> *grades) {
//  Orders and outputs all grades to terminal.
//      Divides individual sums by the size of their respective input vector

    std::cout << "Task\t\tPoints\t\tGrade" << std::endl;
    std::cout << "----\t\t-------\t\t-----" << std::endl; 
    std::cout << "Labs\t\t" << lab_grade << "/" << (5*(*grades)[0].size()) << "\t\t" <<(lab_grade/(5*(*grades)[0].size())) * 100 << " %" << std::endl;
    std::cout << "Assignments\t" << assignment_grade << "/" << (100*(*grades)[1].size()) << "\t\t" << (assignment_grade/(100*(*grades)[1].size())) * 100 << " %" << std::endl;
    std::cout << std::fixed;
    std::cout << std::setprecision(0) << "Term Project\t" << term_project_grade << "/350\t\t" << (term_project_grade/350) * 100 << " %" << std::endl;

// Only outputs exam grade if user has NOT been exempted
//      Then outputs final grade based on whether the exam should be included.
    if(take_final_exam == 1) {
        std::cout << "Final Exam\t" << final_exam_grade << "/100\t\t" << (final_exam_grade/100) * 100 << " %" << std::endl;
        std::cout << "Review Project\t+ " << extra_points << " to Final Grade" << std::endl;
        std::cout << "-------------------------------------" << std::endl;
        std::cout << "Final Grade\t(" << final_grade << "/" << possible_points << ")+4\t" << ((final_grade / possible_points)*100 + extra_points) << " %" << std::endl;

    } else {
        std::cout << "Final Exam" << "\tN/A\t" << "\tN/A" << std::endl;
        std::cout << "Review Project\t+ " << extra_points << " to Final Grade" << std::endl;
        std::cout << "-------------------------------------" << std::endl;
        std::cout << "Final Grade\t(" << final_grade << "/" << possible_points << ")+4\t" << ((final_grade / possible_points)*100 + extra_points) << " %" << std::endl;

    }
}