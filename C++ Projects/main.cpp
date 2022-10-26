//Nadia Sousa, Assignment 1, 9/16/22

//developed a command line tool to perform image binarization, given options provided by the user

#include <iostream>
using namespace std;
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cmath>

void ReadFile(std::string file_name, std::vector<std::vector<double>> &image_data){
    // Opens the file for reading
    std::ifstream file(file_name);

    // Creates a string to hold each line in temporarily
    std::string str;

    // Iterates over the file, storing one line at a time into `str`
    while (std::getline(file, str)) {
        // Create a temporary 1D Vector of doubles
       std::vector<double> new_row;

       // Create a stringstream object with our line of integers from the file
       std::istringstream ss(str);

       // Create a double that will hold our extracted value from the string
       double token;

        // While there are still numbers in this string, extract them as doubles
        while(ss >> token){
            // Push these doubles into our temp vector
            new_row.push_back(token);
        }

        // The line is empty, push our completed row into our 2D vector
        image_data.push_back(new_row);
    }
}

void WriteFile(std::string file_name, std::vector<std::vector<double>> &image_data){
    // Open our file with write permissions
    std::ofstream output_file(file_name);

    // Use an iterator to traverse the outer dimension
    for(std::vector<std::vector<double>>::const_iterator i = (image_data).begin(); i != (image_data).end(); ++i){
        // Use an interator to traverse the inner dimention
        for(std::vector<double>::const_iterator j = i->begin(); j != i->end(); ++j){
            // Output each element to the file with a space at the end
            output_file << *j << " ";
        }
        // Output a newline symbol to the file
        output_file << "\n";
    }
}

//creates binarized val file with global threshold
void global(std::string file_name, std::string new_file_name) {
    std::vector<std::vector<double>> image = {};
    std::vector<std::vector<double>> image_data;
    ReadFile(file_name, image_data);
    std::vector<double> temp = {};

    //creates copy of image_data vector, named temp
    for (double i = 0; i < image_data.size(); i++)
    {
        for (double j = 0; j < image_data[i].size(); j++)
        {
            temp.push_back(image_data[i][j]);
        }
    }

    //reorders temp from least to greatest
    sort(temp.begin(), temp.end());

    double median;
    
    //calcs median (tests to see if vector size is odd/even)
    if (temp.size() % 2 == 0)
    {
        int index1 = (temp.size() - 1) / 2;
        int index2 = index1 + 1;
        median = (temp[index1] + temp[index2]) / 2;
    } else {
        int index1 = (temp.size() - 1) / 2;
        median = temp[index1];
    }

    //compares meadian to vector element, replaces val with 0 or 255
    for (double i = 0; i < image_data.size(); i++){
        for (double j = 0; j < image_data[i].size(); j++)
        {
            if (image_data[i][j] < median){
                image_data[i][j] = 0;
            } else{
                image_data[i][j] = 255; 
            }
        }
    }

    //creates file with new binarized vals
    WriteFile(new_file_name, image_data);

}

//creates a new vector based on the neighborhood size for each pixel 
void new_vec(std::vector<std::vector<double>> &a, int x, int y, double bound, std::vector<double>& temp)
{
    double count = 0;
    //creates vector with staying in original image vector's bounds
    for (int i = x - bound ; i <= x + bound; i++ )
    {
        for (int j = y - bound; j <= y + bound; j++)
        {
            if (i >= 0 && i < a.size() && j >= 0 && j < a[i].size())
            {
                //adds vals to new vector
                temp.push_back(a[i][j]);
                count++;
            }
        }
    }
    
}

//calculates the mean of the vector's elements 
double calc_mean(std::vector<double> &temp)
{
    double total = 0;
    int count = 0;

    //finds sum of all elements
    for (int i = 0; i < temp.size(); i++)
    {
        total += temp[i];
        count++;
    }

    //calculates mean
    double mean = total / count;

    return mean; 
}

//calculates the standard deviation of the vector
double calc_sd(std::vector<double> &temp, double mean){
    
    double sum = 0;
    int count = 0;

    //calculates the sum of each element - mean, to the second power 
    for(int i = 0; i < temp.size(); i++)
    {
        sum += pow((temp[i] - mean), 2);
        count++;
    }

    //sqrts the sum/num of elements to find sd
    double stan_dev = sqrt(sum / count);

    return stan_dev;
}

//calculates local thresh for each pixel
double calc_thresh(std::vector<double> &temp, double mean, double sd, double p_min, double p_max)
{
    //calcs local thresh with mean, sd, image data vector's min/max
    double local_t = mean * (1 + (0.2 * ((sd/(0.5 * (p_max - p_min))) - 1)));
    return local_t;
}

//creates binarized val file with global threshold
void local (std::string file_name, std::string new_file_name, int neigh)
{
   // std::vector<std::vector<double>> image = {};
    std::vector<std::vector<double>> image_data;
    ReadFile(file_name, image_data);
    std::vector<std::vector<double>> local = image_data;
    
    //finds the bound size around each pixel 
    int bound = neigh / 2;

    std::vector<double> one_D = {};

    //new vector created as copy for image_data
    for (double i = 0; i < image_data.size(); i++)
    {
        for (double j = 0; j < image_data[i].size(); j++)
        {
            one_D.push_back(image_data[i][j]);
        }
    }

    //reorders new vector
    std::sort(one_D.begin(), one_D.end());

    //finds min/max of new vector
    double p_min = one_D[0];
    double p_max = one_D[one_D.size() - 1];

    //for each pixel, finds local thresh bin val
    for (double i = 0 ; i < image_data.size(); i++ )
    {
        for (double j = 0; j < image_data[i].size(); j++)
        {
            std::vector<double> temp = {};

            //creates new small vectors with bounds
            new_vec(image_data, i, j, bound, temp);

            //finds pixel mean
            double mean = calc_mean(temp);

            //finds stan dev for pixel
            double sd = calc_sd(temp, mean);

            //calc thresh 
            double local_thresh = calc_thresh(temp, mean, sd, p_min, p_max);

            //compares thresh val, new vec val either 0 or 255
            if(image_data[i][j] < local_thresh)
            {
                local[i][j] = 0;
            } else {
                local[i][j] = 255;
            }   
        }        
    }
    
    //creates new image bin file
    WriteFile(new_file_name, local);
}

int main(int argc, char *argv[]){
    std::string thresh = argv[1];
    std::string file_name = argv[2];
    std::string new_file_name = argv[3];
    
    //tests if thresh arg is either global or local
    if (thresh == "global")
    {
        //if global is thresh, calcs global thresh
        global(file_name, new_file_name);
    }
     else if (thresh == "local")
    {
        //if local is thresh, calcs local thresh
        int n_size = std::stoi(argv[4]);
        local(file_name, new_file_name, n_size);
    }
    
}