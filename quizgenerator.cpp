#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Quiz {
private:
    char ch[20];
    char fh[20];
    int marks_count;
    int line_count;
    int i;

public:
    Quiz() : ch{'C', 'A', 'B', 'C', 'C', 'B', 'C', 'B', 'A', 'B', 'C', 'C', 'C', 'A', 'A', 'A', 'C', 'C', 'B', 'C'},
             fh{'c', 'a', 'b', 'c', 'c', 'b', 'c', 'b', 'a', 'b', 'c', 'c', 'c', 'a', 'a', 'a', 'c', 'c', 'b', 'c'},
             marks_count(0), line_count(1), i(0) {}

    void startQuiz(const string& filename) {
        ifstream file;
        string s;
        char a;

        file.open(filename.c_str());

        if (!file.is_open()) {
            cerr << "Error opening file '" << filename << "'. Check if the file exists and is accessible." << endl;
            return;
        }

        while (getline(file, s)) {
            cout << s << endl;

            if (line_count % 2 == 0) {
                cout << "Choose an option: ";
                cin >> a;

                if (a == ch[i] || a == fh[i]) {
                    marks_count++;
                }
                i++;
            }

            line_count++;
        }

        cout << endl << endl;
        displayResult();

        if (file.bad()) {
            cerr << "Error occurred while reading the file." << endl;
        }

        file.close();
    }

private:
    void displayResult() {
        if (marks_count >= 15) {
            cout << "    .........................................." << endl;
            cout << "    . You have got " << marks_count << " out of 20, congrats!!  . " << endl;
            cout << "    .........................................." << endl;
        } else if (marks_count >= 10 && marks_count < 15) {
            cout << "    .........................................." << endl;
            cout << "    . You have got " << marks_count << " out of 20, level Up!!  . " << endl;
            cout << "    .........................................." << endl;
        } else {
            cout << "    .........................................." << endl;
            cout << "    . You have got " << marks_count << " out of 20, work hard!!  . " << endl;
            cout << "    .........................................." << endl;
        }
    }
};

int main() {
    Quiz quiz;
    quiz.startQuiz("quizstore.txt");
    return 0;
}

