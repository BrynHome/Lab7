#include "Course.hpp"

using namespace std;

Course::Course (string title, dayOfWeek day, unsigned int start_time, unsigned int finish_time) : title (title), day (day), start_time (start_time), finish_time (finish_time)
{
}
Course::Course (const Course & m) : title (m.title), day (m.day), start_time (m.start_time), finish_time (m.finish_time)
{
}

Course & Course::operator =(const Course & m) {
    //TODO implement the operator
    title = m.title;
    day = m.day;
    start_time = m.start_time;
    finish_time = m.finish_time;
    return *this;
}
bool Course::operator == (const Course & m) const {
    if(day == m.day) {
        if(start_time >= m.finish_time) {
            return false;
        } else {
            if(finish_time > m.start_time) {
                return true;
            }
        }
    }
    return (false);
}

bool Course::operator < (const Course & m) const
{
    //TODO implement the operator
    if(day == m.day) {
        return start_time < m.start_time;
    } else if(day < m.day) {
        return true;
    }
    return false;
}

ostream & operator << (ostream &os, const Course & m)
{
    //TODO implement the operator
    string a;
    switch (m.day){
        case 0:
            a = "M";
            break;
        case 1:
            a = "T";
            break;
        case 2:
            a = "W";
            break;
        case 3:
            a = "R";
            break;
        case 4:
            a = "F";
            break;

    }
    os << m.title << " " << a << " " << m.start_time << " " << m.finish_time << endl;
    return os;
}
ostream & operator << (ostream &os, const Course * m) {
    string a;
    switch (m->day){
        case 0:
            a = "M";
            break;
        case 1:
            a = "T";
            break;
        case 2:
            a = "W";
            break;
        case 3:
            a = "R";
            break;
        case 4:
            a = "F";
            break;

    }
    os << m->title << " " << a << " " << m->start_time << " " << m->finish_time;
    return os;
}
