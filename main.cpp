#include "User.h"
#include "UserManager.h"
#include "Course.h"
#include "CourseManager.h"
#include "StudentUser.h"
#include "StudentManager.h"
#include "TeacherManager.h"
#include "UI.h"
#include "CourseFileReader.h"

int main() {
    UserManager userManager;
    CourseManager courseManager;
    StudentManager studentManager;
    TeacherManager teacherManager(courseManager);
    
    CourseFileReader courseFileReader;
    try {
        courseFileReader.readCourses(courseManager, "courses.csv");
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    
    UI ui(userManager, courseManager, studentManager, teacherManager);
    ui.start();

    return 0;
}
