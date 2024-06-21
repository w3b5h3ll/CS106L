/*
 * CS106L SimpleEnroll Assignment Part 1
 * Created by Fabio Ibanez
 * Please complete each STUDENT TODO in this file.
 *
 * Students must implement: parse_csv, write_courses_offered,
 * write_courses_not_offered
 */

// (FIRST) STUDENT TODO: change how variables are passed into the functions you
// must complete

#include <fstream>
#include <iostream>
#include <sstream>
#include <tuple>
#include <vector>
#include <algorithm>

// STUDENT TODO: add paths
std::string COURSES_OFFERED_CSV_PATH = "/home/c0r3dump/Workspace/CS106L/assignments/01_SimpleEnroll/simpleenroll_starter/student_output/courses_offered.csv";

std::string COURSES_NOT_OFFERED_CSV_PATH = "/home/c0r3dump/Workspace/CS106L/assignments/01_SimpleEnroll/simpleenroll_starter/student_output/courses_not_offered.csv";

struct Course
{
    // /* STUDENT TODO: ADD TYPE */ title;
    // /* STUDENT TODO: ADD TYPE */ number_of_units;
    // /* STUDENT TODO: ADD TYPE */ quarter;
    std::string title;
    std::string number_of_units;
    std::string quarter;

    // ignore this!
    bool operator==(const Course &other) const
    {
        return title == other.title && number_of_units == other.number_of_units &&
               quarter == other.quarter;
    }
};

// forward declarations
void delete_elem_from_vector(std::vector<Course> &v, Course &elem);
std::vector<std::string> split(std::string s, char delim);

/*
 * This function should populate the vector_of_courses with structs of type
 * Class We want to create these structs with the records in the courses.csv
 * file, where each line is a record!
 *
 * Hints:
 * 1) Take a look at the split function we provide
 * 2) Each LINE is a record! *this is important, so we're saying it again :>)*
 */
// using reference to modifiy the vector_of_courses
void parse_csv(std::string filename, std::vector<Course> &vector_of_courses)
{
    // STUDENT TODO: Implement this function
    std::ifstream inputFile(filename);
    if (inputFile.is_open())
    {
        std::cout << "Loading courses from " << filename << std::endl;
        /* code */
        std::string line;
        // 跳过第一行
        std::getline(inputFile, line);
        // 记录每一行信息
        while (std::getline(inputFile, line))
        {
            // std::cout << line << std::endl;
            std::vector<std::string> tokens = split(line, ',');
            Course course;
            course.title = tokens[0];
            course.number_of_units = tokens[1];
            course.quarter = tokens[2];

            // std::cout << "title: " + course.title + ", " + "number_of_units: " + course.number_of_units + ", " + "quarter: " + course.quarter << std::endl;
            vector_of_courses.push_back(course);
        }
        inputFile.close();
    }
}

/*
 * This function has TWO requirements.
 * 1) Write the courses that are offered to the file courses_offered.csv inside
 * the student_output folder
 *
 * 2) Delete classes that are offered from vector_of_courses.
 * IMPORTANT: do this after you write out to the file!
 *
 * HINTS:
 * 1) Keep track of the classes that you need to delete!
 * 2) Use the delete_elem_from_vector function we give you!
 */
void write_courses_offered(std::vector<Course> &vector_of_courses)
{
    // STUDENT TODO: implement this function
    std::ofstream outputFile(COURSES_OFFERED_CSV_PATH);
    if (outputFile.is_open())
    {
        /* code */
        for (auto &course : vector_of_courses)
        {
            if (course.quarter != "null")
            {
                outputFile << course.title << "," << course.number_of_units << "," << course.quarter << std::endl;
            }
        }
    }
    outputFile.close();
    // delete classes
    std::vector<Course> elements_to_delete;
    for (auto &course : vector_of_courses)
    {
        if (course.quarter != "null")
        {
            /* code */
            elements_to_delete.push_back(course);
        }
    }
    for (auto &course : elements_to_delete)
    {
        delete_elem_from_vector(vector_of_courses, course);
    }

    // print_vector(vector_of_courses);
    // std::cout << "vector_of_courses size: " << vector_of_courses.size() << std::endl;
}

/*
 * This function writes the courses NOT offered to the file
 * courses_not_offered.csv inside of the student_output folder
 *
 * This function is ALWAYS called after the write_courses_offered function.
 * vector_of_courses will trivially contain classes that are not offered
 * since you delete offered classes from vector_of_courses in the
 * 'write_courses_offered' function.
 *
 * HINT: This should be VERY similar to write_courses_offered
 */
void write_courses_not_offered(std::vector<Course> &vector_of_courses)
{
    // STUDENT TODO: implement this function
    std::ofstream outputFile(COURSES_NOT_OFFERED_CSV_PATH);
    if (outputFile.is_open())
    {
        /* code */
        for (auto &course : vector_of_courses)
        {
            if (course.quarter == "null")
            {
                outputFile << course.title << "," << course.number_of_units << "," << course.quarter << std::endl;
            }
        }
    }
    outputFile.close();
    // delete classes
    // 删除导致迭代器失效，尝试先收集待删除元素，后统一删除
    // 当从 std::vector 中删除元素时，指向该元素的迭代器和其后的所有迭代器都会失效。使用这些失效的迭代器可能会导致未定义行为。
    std::vector<Course> elements_to_delete;
    for (auto &course : vector_of_courses)
    {
        if (course.quarter == "null")
        {
            /* code */
            elements_to_delete.push_back(course);
        }
    }
    for (auto &course : elements_to_delete)
    {
        delete_elem_from_vector(vector_of_courses, course);
    }
}

/* ######## HEYA! DON'T MODIFY ANYTHING BEYOND THIS POINT THX ######## */

// TODO: ADD DOCUMENTATION COMMENTS
void print_vector(std::vector<Course> vector_of_courses)
{
    int line = 0;
    for (int i = 1; i < vector_of_courses.size(); ++i)
    {
        std::cout << line << ": "
                  << vector_of_courses[i].title << ","
                  << vector_of_courses[i].number_of_units << ","
                  << vector_of_courses[i].quarter << std::endl;
        line++;
    }
}

void delete_elem_from_vector(std::vector<Course> &v, Course &elem)
{
    auto it = std::find(v.begin(), v.end(), elem);
    v.erase(it);
}

std::vector<std::string> split(std::string s, char delim)
{
    std::vector<std::string> return_vec;
    std::stringstream ss(s);
    std::string token;
    while (getline(ss, token, ','))
    {
        return_vec.push_back(token);
    }
    return return_vec;
}
