/*
 * 1. simple solution，直接把nestedlist展开，easy but not reasonable
 */
class NestedIterator {
private:
    vector<int> nums_;
    size_t iter_;
    void flatten(const vector<NestedInteger> &nestedList) {
        for (size_t i = 0; i < nestedList.size(); ++i) {
            if (nestedList[i].isInteger()) {
                nums_.push_back(nestedList[i].getInteger());
            }
            else {
                flatten(nestedList[i].getList());
            }
        }
    }

public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        flatten(nestedList); 
        iter_ = 0;
    }

    int next() {
        return nums_[iter_++]; 
    }

    bool hasNext() {
        if (iter_ >= nums_.size()) return false;
        else return true;
    }
};

/*
 * 2. Discuss里的solution，维护当前遍历到的list的首尾指针，并通过stack来回溯。
 */
class NestedIterator {
private:
    stack<vector<NestedInteger>::iterator> begins, ends;
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        begins.push(nestedList.begin());
        ends.push(nestedList.end());
    }

    int next() {
       hasNext();
       return (begins.top()++)->getInteger();
    }

    bool hasNext() {
        while (begins.size()) {
            // 当前list遍历完了,则返回上层继续遍历.
            if (begins.top() == ends.top()) {
                begins.pop();
                ends.pop();
            }
            else {
                auto it = begins.top();
                if (it->isInteger()) return true;
                begins.top()++;
                begins.push(it->getList().begin());
                ends.push(it->getList().end());
            }
        } 
    }
};
