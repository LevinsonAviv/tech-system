#pragma once

class Student{
public:
    Student(int id, int currentBonus);

    Student(const Student& student) = delete;

    Student& operator=(const Student& student) = delete;

    ~Student() = default;

    int getId() const;

    void addCourse();

    void completeCourse(float points);

    bool hasCourses() const;

    float getPoints() const;

private:
    const int id;
    int coursesNum;
    float points;
};