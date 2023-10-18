class SegmentTreeNode {
public:
    SegmentTreeNode *left, *right;
    int start, end;
    int overlap;

    SegmentTreeNode(int _start, int _end) {
        start = _start;
        end = _end;
        left = right = nullptr;
        overlap = 0;
    }
    int insert(int startTime, int endTime) {
        if(startTime >= endTime) return 0;
        if(startTime >= end) {
            if(right) return right->insert(startTime, endTime);
            right = new SegmentTreeNode(startTime, endTime);
        } else if(endTime <= start) {
            if(left) return left->insert(startTime, endTime);
            left = new SegmentTreeNode(startTime, endTime);
        } else {
            int x1 = min(startTime, start);
            int x2 = max(startTime, start);
            int y1 = min(endTime, end);
            int y2 = max(endTime, end);
            overlap++;
            int ret = overlap;
            if(end > endTime) {
                SegmentTreeNode *newRight = new SegmentTreeNode(y1, y2);
                newRight->overlap = overlap - 1;
                newRight->right = right;
                right = newRight;
            } else {
                ret = max(insert(y1, y2), ret);
            }
            if(start < startTime) {
                SegmentTreeNode *newLeft = new SegmentTreeNode(x1, x2);
                newLeft->overlap = overlap - 1;
                newLeft->left = left;
                left = newLeft;
            } else {
                ret = max(insert(x1, x2), ret);
            }
            start = x2;
            end = y1;
            return ret;
        }
        return 0;
    }
};
class MyCalendarThree {
public:
    SegmentTreeNode *root;
    int ret;

    MyCalendarThree() {
        root = new SegmentTreeNode(-1, INT_MAX);
        ret = 0;
    }
    int book(int startTime, int endTime) {
        SegmentTreeNode *node = new SegmentTreeNode(startTime, endTime);

        int overlap = root->insert(startTime, endTime);
        ret = max(ret, overlap);

        return ret;
    }
};
