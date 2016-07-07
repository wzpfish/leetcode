/*
 * 看了一下大致两种思路，一种是在insert的时候就处理好区间，一种是query的时候再merge区间，就看insert和query哪个频繁了..
 */
#include <iostream>
#include <vector>
#include <set>
#include <assert.h>
using namespace std;

struct Interval {
    int start;
    int end;
    const bool operator==(const Interval &rhs) const {
        return (start == rhs.start && end == rhs.end);
    }
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class SummaryRanges {
private:
    set<int> numbers_; 
public:
    /** Initialize your data structure here. */
    SummaryRanges() {

    }
    
    void addNum(int val) {
        numbers_.insert(val); 
    }
    
    vector<Interval> getIntervals() {
        vector<Interval> intervals;
        if (numbers_.size() == 0) return intervals; 
        auto it = numbers_.begin();
        auto it_next = numbers_.begin();
        ++it_next;
        int start = *it;
        int end = *it;
        for (; it_next != numbers_.end(); ++it, ++it_next) {
            if (*it_next == *it + 1) {
                end = *it_next;
            }
            else {
                intervals.push_back(Interval(start, end));
                start = *it_next;
                end = *it_next;
            }
        } 
        intervals.push_back(Interval(start, end));
        return intervals;
    }
};

void test() {
    SummaryRanges *obj = new SummaryRanges();
    obj->addNum(1);
    vector<Interval> intervals = obj->getIntervals();
    assert(intervals == vector<Interval>{Interval(1, 1)});
    
    obj->addNum(3);
    intervals = obj->getIntervals();
    assert(intervals == (vector<Interval>{Interval(1, 1), Interval(3, 3)}));

    obj->addNum(7);
    intervals = obj->getIntervals();
    assert(intervals == (vector<Interval>{Interval(1, 1), Interval(3, 3), Interval(7, 7)}));

    obj->addNum(2);
    intervals = obj->getIntervals();
    assert(intervals == (vector<Interval>{Interval(1, 3), Interval(7, 7)}));

    obj->addNum(6);
    intervals = obj->getIntervals();
    assert(intervals == (vector<Interval>{Interval(1, 3), Interval(6, 7)}));

    cout << "All Pass." << endl;
}

int main() {
    test();
    return 0;
}
