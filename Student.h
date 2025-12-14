#pragma once

class Student{
public:
    Student(int id, int currentBonus);

    Student(const Student& student) = delete;

    Student& operator=(const Student& student) = delete;

    ~Student() = default;

    int getId() const;

    void addCourse();

    void completeCourse(int points);

    bool hasCourses() const;

    int getPoints() const;

private:
    const int id;
    int coursesNum;
    int points;
};