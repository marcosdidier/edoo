#include <iostream>
#include <string>

using namespace std;

int main() {
    // Initialize the strings
    string s1 = "As time by ...";
    string s2 = "goes";

    // Output the initial string
    cout << "Initial string s1: " << s1 << endl;

    // Find the position of "by" in s1
    size_t pos = s1.find("by");
    if (pos != string::npos) {
        // Insert string s2 before "by"
        s1.insert(pos, s2 + " ");
        cout << "After inserting 'goes' before 'by': " << s1 << endl;
    }

    // Find the position of "by" in the modified string s1
    pos = s1.find("by");
    if (pos != string::npos) {
        // Erase everything after "by"
        s1.erase(pos + 2); // +2 to remove "by" and everything after it
        cout << "After erasing the remainder of the string after 'by': " << s1 << endl;
    }

    // Replace "time" with "Bill" in s1
    pos = s1.find("time");
    if (pos != string::npos) {
        s1.replace(pos, 4, "Bill"); // Replace "time" (4 characters) with "Bill"
        cout << "After replacing 'time' with 'Bill': " << s1 << endl;
    }

    return 0;
}