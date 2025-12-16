#pragma once

#include "Student.h"
#include "AVLTree.h"
#include <memory>

class Course{
public:
    Course(int id, int points);

    Course(const Course& course) = delete;

    Course& operator=(const Course& course) = delete;

    ~Course() = default;

    int getId() const;

    int getPoints() const;

    bool enrollStudent(int studentId, std::shared_ptr<Student> student);

    bool completeStudent(int studentId);

    bool hasStudents() const;

private:
    const int id;
    const int points;
    AVLTree<int, std::shared_ptr<Student>> students;
};