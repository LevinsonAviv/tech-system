#include "Course.h"

Course::Course(int id, float points) : id(id), points(points), students() {};

int Course::getId() const{
    return id;
};

float Course::getPoints() const{
    return points;
};

bool Course::enrollStudent(Student *student, int studentId){
    bool succeded = students.insert(studentId, student);
    if(succeded){
        student->addCourse();
    }
    return succeded;
};

bool Course::completeStudent(Student *student, int studentId){
    bool succeded = students.remove(studentId);
    if(succeded){
        student->completeCourse(this->points);
    }
    return succeded;
};

bool Course::hasStudents() const{
    return !students.isEmpty();
};