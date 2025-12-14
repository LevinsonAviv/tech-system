// You can edit anything you want in this file.
// However you need to implement all public StudentCourseManager function, as provided below as a template

#include "TechSystem26a1.h"

TechSystem::TechSystem(): students(), courses(), deansBonus(0){}

TechSystem::~TechSystem(){}

StatusType TechSystem::addStudent(int studentId)
{
    try{
        if(!isValidInput(studentId)){
            return StatusType::INVALID_INPUT;
        }
        if(students.insert(studentId,std::make_shared<Student>(studentId, deansBonus))){
            return StatusType::SUCCESS;
        }
        return StatusType::FAILURE;
    }catch(std::bad_alloc& e){
        return StatusType::ALLOCATION_ERROR;
    }
}

StatusType TechSystem::removeStudent(int studentId)
{
    try{
        if(!isValidInput(studentId)){
            return StatusType::INVALID_INPUT;
        }
        std::shared_ptr<Student> *studentPtr = students.find(studentId);
        if(studentPtr == nullptr || (*studentPtr)->hasCourses() || !students.remove(studentId)){
            return StatusType::FAILURE;
        }
        return StatusType::SUCCESS;
    }catch(std::bad_alloc& e){
        return StatusType::ALLOCATION_ERROR;
    }
}

StatusType TechSystem::addCourse(int courseId, int points)
{
    try{
        if(!isValidInput(courseId) || !isValidInput(points)){
            return StatusType::INVALID_INPUT;
        }
        if(courses.insert(courseId, std::make_shared<Course>(courseId, points))){
            return StatusType::SUCCESS;
        }else{
            return StatusType::FAILURE;
        }
    }catch(std::bad_alloc& e){
        return StatusType::ALLOCATION_ERROR;
    }
}

StatusType TechSystem::removeCourse(int courseId)
{
    try{
        if(!isValidInput(courseId)){
            return StatusType::INVALID_INPUT;
        }
        std::shared_ptr<Course> *coursePtr = courses.find(courseId);
        if(coursePtr == nullptr || (*coursePtr)->hasStudents() || !courses.remove(courseId)){
            return StatusType::FAILURE;
        }
        return StatusType::SUCCESS;
    }catch(std::bad_alloc& e){
        return StatusType::ALLOCATION_ERROR;
    }
}

StatusType TechSystem::enrollStudent(int studentId, int courseId)
{
    try{
        if(!isValidInput(studentId) || !isValidInput(courseId)){
            return StatusType::INVALID_INPUT;
        }
        std::shared_ptr<Student> *studentPtr = students.find(studentId);
        std::shared_ptr<Course> *coursePtr = courses.find(courseId);
        if(studentPtr == nullptr || coursePtr == nullptr || !(*coursePtr)->enrollStudent(studentId, (*studentPtr))){
            return StatusType::FAILURE;
        }else{
            return StatusType::SUCCESS;
        }
    }catch(std::bad_alloc& e){
        return StatusType::ALLOCATION_ERROR;
    }
}

StatusType TechSystem::completeCourse(int studentId, int courseId)
{
    try{
        if(!isValidInput(studentId) || !isValidInput(courseId)){
            return StatusType::INVALID_INPUT;
        }
        std::shared_ptr<Course> *coursePtr = courses.find(courseId);
        if(coursePtr == nullptr || !(*coursePtr)->completeStudent(studentId)){
            return StatusType::FAILURE;
        }
        return StatusType::SUCCESS;
    }catch(std::bad_alloc& e){
        return StatusType::ALLOCATION_ERROR;
    }
}

StatusType TechSystem::awardAcademicPoints(int points)
{
    try{
        if(!isValidInput(points)){
            return StatusType::INVALID_INPUT;
        }
        deansBonus += points;
        return StatusType::SUCCESS;
    }catch(std::bad_alloc& e){
        return StatusType::ALLOCATION_ERROR;
    }
}

output_t<int> TechSystem::getStudentPoints(int studentId)
{
    try{
        if(!isValidInput(studentId)){
            return StatusType::INVALID_INPUT;
        }
        std::shared_ptr<Student> *studentPtr = students.find(studentId);
        if(studentPtr == nullptr){
            return output_t<int>(StatusType::FAILURE);
        }
        return output_t<int>((*studentPtr)->getPoints() + deansBonus);
    }catch(std::bad_alloc& e){
        return StatusType::ALLOCATION_ERROR;
    }
}

bool TechSystem::isValidInput(int input) const{
    return input > 0;
}