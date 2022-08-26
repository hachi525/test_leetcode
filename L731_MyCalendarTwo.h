//
// Created by admin on 2022/7/19.
//

#ifndef PROJECT_L731_MYCALENDARTWO_H
#define PROJECT_L731_MYCALENDARTWO_H


#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

/*实现一个 MyCalendar 类来存放你的日程安排。如果要添加的时间内不会导致三重预订时，则可以存储这个新的日程安排。
 * book(int start, int end)在 start 到 end 时间内增加一个日程安排,半开区间，即 [start, end)
 * start <= x < end。
 * 当三个日程安排有一些时间上的交叉时（例如三个日程安排都在同一时间内），就会产生三重预订。
 * 调用MyCalendar.book()时:
 *      如果可以将日程安排成功添加到日历中而不会导致三重预订，返回 true。
 *      否则，返回 false 并且不要将该日程安排添加到日历中。
 * 请按照以下步骤调用MyCalendar 类: MyCalendar cal = new MyCalendar(); MyCalendar.book(start, end)
*/
class L731_MyCalendarTwo {
private:
    vector<pair<int, int>> booked;
    vector<pair<int, int>> overlaped;
    map<int, int> cnt;
public:
    L731_MyCalendarTwo();
    bool book(int start, int end);
    bool book1(int start, int end);
    bool book2(int start, int end);
};


#endif //PROJECT_L731_MYCALENDARTWO_H
