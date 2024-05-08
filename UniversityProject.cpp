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
