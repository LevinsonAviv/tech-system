#include "Student.h"

Student::Student(int id, int currentBonus) : id(id), coursesNum(0), points(-currentBonus) {};

int Student::getId() const{
    return id;
}

void Student::addCourse(){
    coursesNum++;
}

void Student::completeCourse(int points){
    this->points += points;
    coursesNum--;
}

bool Student::hasCourses() const{
    return coursesNum != 0;
}

int Student::getPoints() const{
    return points;
}