#include <iostream>
#include <vector>
#include <string>
#include <fstream> // برای کار با فایل

using namespace std;

// تعریف کلاس‌ها
class Examination {
public:
    Examination(string Name, int NumOfQ, int TotalScore, int TotalTime) 
        : examName(Name), numberOfQuestions(NumOfQ), totalScore(TotalScore), totalTime(TotalTime) {}

    // تابع‌های getter
    string getName() const { return examName; }
    int getNumberOfQuestions() const { return numberOfQuestions; }
    int getTotalScore() const { return totalScore; }
    int getTotalTime() const { return totalTime; }

    void print() const { /* اجرای عملیات چاپ */ }

private:
    string examName;
    int numberOfQuestions;
    int totalScore;
    int totalTime;
};

class User {
public:
    User(string Name, string Pass) : username(Name), password(Pass) {}
    virtual char getType() const = 0;

protected:
    string username;
    string password;
};

class Student;
class StudentList;

class Professor : public User {
public:
    Professor(string Name, string Pass) : User(Name, Pass) {}
    char getType() const override { return 'P'; }
    void createExam(string Name, int NumOfQ, int TotalScore, int TotalTime);
    void showAllExams() const;
    void addStudentToExam(int examIndex, Student* student);
    void gradeExam(int examIndex, vector<int>& grades);
    void sendNotification(string message);
    void createStudentList(User* Person[]);
    void printStudentList() const;
    Examination& getExam(int examIndex);

private:
    vector<Examination> ExamList;
    vector<StudentList> List;
};

class Student : public User {
public:
    Student(string Name, string Pass) : User(Name, Pass) {}
    char getType() const override { return 'S'; }
    void takeExam(Examination& exam, vector<int>& answers);
    void viewGrades() const;

private:
    vector<int> grades;
};

class StudentList {
public:
    StudentList(User* Person[]) { /* ایجاد لیست دانشجوها */ }
    void addStudent(User* student);
    void removeStudent(string username);
    void printStudentList() const;

private:
    vector<User*> studentList;
};

// توابع کلاس Professor
void Professor::createExam(string Name, int NumOfQ, int TotalScore, int TotalTime) {
    Examination TempExam(Name, NumOfQ, TotalScore, TotalTime);
    ExamList.push_back(TempExam);
}

void Professor::showAllExams() const {
    if (ExamList.size() != 0) {
        for (int i = 0; i < ExamList.size(); i++) {
            cout << "\nExam " << i + 1 << " : ("
                << " Number of Questions: " << ExamList[i].getNumberOfQuestions()
                << ",  " << " Total score: " << ExamList[i].getTotalScore()
                << ",  " << " Total time: " << ExamList[i].getTotalTime() << " )\n";
            ExamList[i].print();
        }
    } else {
        cout << "No Items Found.\n";
    }
    cout << endl;
}

void Professor::addStudentToExam(int examIndex, Student* student) {
    // کد پیاده‌سازی اضافه کردن دانشجو به لیست دانشجویان امتحان
}

void Professor::gradeExam(int examIndex, vector<int>& grades) {
    // کد پیاده‌سازی تصحیح امتحان و وارد کردن نمرات
}

void Professor::sendNotification(string message) {
    // کد پیاده‌سازی ارسال پیام به دانشجوها
}

void Professor::createStudentList(User* Person[]) {
    StudentList Temp(Person);
    if (Temp.studentList.capacity() != 0) {
        List.push_back(Temp);
    }
}

void Professor::printStudentList() const {
    if (List.size() != 0) {
        cout << "Number of Lists : " << List.size() << endl
            << "====================================\n";
        for (int i = 0; i < List.size(); i++) {
            if (List[i].studentList.capacity() != 0) {
                cout << " #" << i + 1 << " List :\n";
                List[i].printStudentList();
                cout << "-----------------------------------------\n";
            }
        }
    } else {
        cout << "\nNo List founded !\n";
    }
}

// توابع کلاس Student
void Student::takeExam(Examination& exam, vector<int>& answers) {
    // کد پیاده‌سازی بخش گرفتن امتحان توسط دانشجو
}
void Student::viewGrades() const {
    // کد پیاده‌سازی بخش مشاهده نمرات توسط دانشجو
}

// توابع کلاس StudentList
void StudentList::addStudent(User* student) {
    // کد پیاده‌سازی اضافه کردن دانشجو به لیست
}

void StudentList::removeStudent(string username) {
    // کد پیاده‌سازی حذف دانشجو از لیست
}

void StudentList::printStudentList() const {
    // کد پیاده‌سازی چاپ لیست دانشجویان
}

// تابع main
int main() {
    Professor prof("professor_username", "professor_password");
    Student student1("student1_username", "student1_password");
    Student student2("student2_username", "student2_password");

    // ایجاد امتحان توسط استاد
    prof.createExam("Exam1", 10, 100, 90);

    // چاپ تمام امتحان‌ها توسط استاد
    cout << "All Exams:" << endl;
    prof.showAllExams();

    // اضافه کردن دانشجو به لیست دانشجویان امتحان
    prof.addStudentToExam(0, &student1);

    // بررسی و چاپ لیست دانشجویان هر امتحان
    prof.printStudentList();

    return 0;
}
