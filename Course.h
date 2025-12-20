#pragma once

#include "Student.h"
#include "AVLTree.h"
#include <memory>

/**
 * @brief class of a course
*/
class Course{
public:
    /**
     * @brief constructor that creates a course with the given id and points.
     * 
     * @param id the id of the new course.
     * @param points the points of the new course.
    */
    Course(int id, int points);

    // delete copy constructor
    Course(const Course& course) = delete;

    // delete assignment operator
    Course& operator=(const Course& course) = delete;

    /**
     * @brief destructor that deletes all memory allocated to the Course.
    */
    ~Course() = default;

    /**
     * @brief returns the id of the course.
     * 
     * @return the id of the course.
    */
    int getId() const;

    /**
     * @brief returns the points of the course.
     * 
     * @return the points of the course.
    */
    int getPoints() const;

    /**
     * @brief enrolls a new student to the course.
     * 
     * @param studentId the id of the student to enroll.
     * @param student the shared_ptr containing the student to enroll.
     * 
     * @return true if the enrollment suceeded or false otherwise.
    */
    bool enrollStudent(int studentId, std::shared_ptr<Student> student);

    /**
     * @brief completes the course for a student and giving him the course points.
     * 
     * @param studentId the id of the student that completed the course.
     * 
     * @return true if the completion suceeded or false otherwise.
    */
    bool completeStudent(int studentId);

    /**
     * @brief checks if there are students enrolled to the course.
     * 
     * @return true if there are students enrolled to the course or false otherwise.
    */
    bool hasStudents() const;

private:
    /**
     * @brief the id of the course.
    */
    const int id;

    /**
     * @brief the points of the course.
    */
    const int points;

    /**
     * @brief an AVL tree of the shared_ptr of the students enrolled to the course.
    */
    AVLTree<int, std::shared_ptr<Student>> students;
};