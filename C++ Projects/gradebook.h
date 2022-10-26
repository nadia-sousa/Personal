#include<vector>
#include<string>

class Gradebook{
    private:
       double lab_grade;
       double assignment_grade;
       double term_project_grade;
       double final_exam_grade;
       double take_final_exam = false;
       double possible_points;
       double final_grade;

//  Bonus points from review project
       double extra_points;

    public:
       Gradebook();
       Gradebook(std::string f_name, std::vector<std::vector<double>> *grades);
       void calculate_lab_grade(std::vector<std::vector<double>> *grades);
       void calculate_assignment_grade(std::vector<std::vector<double>> *grades);

// It's possible we may not need many calculations for categories with only 1 input
       void term_project(std::vector<std::vector<double>> *grades);
       void review_project(std::vector<std::vector<double>> *grades);
       void final_exam(std::vector<std::vector<double>> *grades);
       void overall_grade();
       void output_grades(std::vector<std::vector<double>> *grades);

};