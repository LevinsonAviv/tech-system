#include "Course.h"

Course::Course(int id, int points) : id(id), points(points), students() {}

int Course::getId() const{
    return id;
}

int Course::getPoints() const{
    return points;
}

bool Course::enrollStudent(int studentId, std::shared_ptr<Student> student){
    bool succeded = students.insert(studentId, student);
    if(succeded){
        student->addCourse();
    }
    return succeded;
}

bool Course::completeStudent(int studentId){
    std::shared_ptr<Student> *studentPtr = students.find(studentId);
    if(studentPtr == nullptr){
        return false;
    }
    std::shared_ptr<Student> student = (*studentPtr);
    bool succeded = students.remove(studentId);
    if(succeded){
        student->completeCourse(this->points);
    }
    return succeded;
}

bool Course::hasStudents() const{
    return !students.isEmpty();
}