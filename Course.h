#pragma once

#include "Student.h"
#include "AVLTree.h"

class Course{
public:
    Course(int id, float point);

    Course(const Course& course) = delete;

    Course& operator=(const Course& course) = delete;

    ~Course() = default;

    int getId() const;

    float getPoints() const;

    bool enrollStudent(Student *student, int studentId);

    bool completeStudent(Student *student, int studentId);

    bool hasStudents() const;

private:
    const int id;
    const float points;
    AVLTree<int, Student*> students;
};