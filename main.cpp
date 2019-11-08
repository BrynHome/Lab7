#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <map>
#include "Course.hpp"

using namespace std;

/*
 * print schedule - outputs course schedule to the screen
 * @param - add any new parameters you need
 */
void printSchedule(vector<Course*> courses)
{
    ostream_iterator<Course*> out (cout, "\n");
    copy(courses.begin(), courses.end(), out);
    //TODO implement your print using the copy algorithm, 2 iterators, and an ostream_iterator
}
bool cmp(Course* a, Course* b) {
    return (*a < *b);
}

int main () {
    //TODO read from courses.txt
    vector<Course*> courses;
    fstream BLARGH{"courses.txt"};
    if(!BLARGH.is_open()) {
        cerr << "unable to open file" << endl;
        exit(1);
    } else {
        string c;
        string title;
        string day;
        int start;
        int end;
        int dayOf;
        while(getline(BLARGH, c)) {
            istringstream iss(c);
            iss >> title;
            iss.ignore();
            iss >> day;
            if(day == "M") {
                dayOf = 0;
            } else if(day == "T") {
                dayOf = 1;
            } else if(day == "W") {
                dayOf = 2;
            } else if(day == "R") {
                dayOf = 3;
            } else {
                dayOf = 4;
            }
            iss.ignore();
            iss >> start;
            iss.ignore();
            iss >> end;
            courses.push_back(new Course(title, static_cast<Course::dayOfWeek>(dayOf), start, end));
        }
    }
    sort(courses.begin(), courses.end(), cmp);
    multimap<Course*, Course*> conflicts;
    for(int i = 0; i < courses.size(); i++) {
        for(int o = i + 1; o < courses.size();o++) {
            if(*(courses[i]) == *(courses[o])) {
                conflicts.insert(make_pair(courses[i],courses[o]));
            }
        }
    }
    map <Course*, Course*>::iterator itBegin = conflicts.begin();
    map <Course*, Course*>::iterator itEnd = conflicts.end();
    for(itBegin;itBegin!=itEnd;++itBegin) {
        cout << "CONFLICT:" << endl;
        cout << *itBegin->first << *itBegin->second << endl;
    }
    printSchedule(courses);
    //TODO store data in an STL container
    //TODO sort your STL container with the sort algorithm
    //TODO implement code to determine schedule conflicts
    //TODO print out schedule conflicts
    //TODO print out schedule
    return 0;
}