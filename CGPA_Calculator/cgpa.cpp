#include <iostream>
using namespace std;

float getGradePoint(char grade) {
    switch(grade){
        case 'A' : return 5.0;
        case 'B' : return 4.0;
        case 'C' : return 3.0;
        case 'D' : return 2.0;
        case 'E' : return 1.0;
        default : return 0.0;
        }
}

int main(){
    int courses;
    float totalCredits = 0,
totalPoints = 0;

    cout << "Enter number of courses: ";
    cin >> courses;

    for(int i = 1; i <= courses; i++){
        char grade;
        float credit;

        cout << "Enter grade (A-E) for course " << i << " : " ;
        cin >> grade;

        cout << "Enter credit hours for course " << i << " : " ;
        cin >> credit;

        float gp = getGradePoint(grade);

        totalCredits += credit;
        totalPoints += gp * credit;

    }
    float cgpa = totalPoints / totalCredits;

    cout << "Your CGPA is:" << cgpa << endl;


    return 0;
}