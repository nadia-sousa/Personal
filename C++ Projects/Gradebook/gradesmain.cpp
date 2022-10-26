#include<iostream>
#include"gradebook.h"

int main(int argc, char* argv[]){

    std::string f_name(argv[1]);

    std::vector<std::vector<double>> grades;

    Gradebook g(f_name, &grades);

//  Line breaks added to seperate functions in the output
    std::cout << std::endl;

    g.calculate_lab_grade(&grades);
//    std::cout << std::endl;

    g.calculate_assignment_grade(&grades);
//    std::cout << std::endl;

    g.term_project(&grades);
//    std::cout << std::endl;

    g.review_project(&grades);
//    std::cout << std::endl;

    g.final_exam(&grades);
//    std::cout << std::endl;

    g.overall_grade();
//    std::cout << std::endl;

    g.output_grades(&grades);
    std::cout << std::endl;

    return 0;
}