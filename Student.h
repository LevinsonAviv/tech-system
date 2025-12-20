#pragma once

/**
 * @brief class of a student
*/
class Student{
public:
    /**
     * @brief constructor that creates a student with the given id when there was a current points bonus.
     * 
     * @param id the id of the new student.
     * @param currentBonus the current points bonus.
    */
    Student(int id, int currentBonus);

    // delete copy constructor
    Student(const Student& student) = delete;

    // delete assignment operator
    Student& operator=(const Student& student) = delete;

    /**
     * @brief destructor that deletes all memory allocated to the Course.
    */
    ~Student() = default;

    /**
     * @brief returns the id of the student.
     * 
     * @return the id of the student.
    */
    int getId() const;

    /**
     * @brief adds one to the courses count of the student.
    */
    void addCourse();

    /**
     * @brief subtructs one from the courses count of the student and adding him points.
     * 
     * @param points the points to add.
    */
    void completeCourse(int points);

    /**
     * @brief checks if the student is enrolled to courses.
     * 
     * @return true if the student is enrolled to courses or false otherwise.
    */
    bool hasCourses() const;

    /**
     * @brief returns the points of the student minus the bonus when he was added.
     * 
     * @return the points of the student minus the bonus when he was added.
    */
    int getPoints() const;

private:
    /**
     * @brief the id of the student.
    */
    const int id;

    /**
     * @brief the number of courses the student is enrolled to.
    */
    int coursesNum;

    /**
     * @brief the points of the student minus the bonus when he was added.
    */
    int points;
};