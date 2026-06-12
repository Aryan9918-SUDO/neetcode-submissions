class MyCircularQueue {
private:
    vector<int> q;
    int frontIdx;
    int rearIdx;
    int count;
    int capacity;

public:
    MyCircularQueue(int k) {
        capacity = k;
        q.resize(k);
        frontIdx = 0;
        rearIdx = -1;
        count = 0;
    }

    bool enQueue(int value) {
        if (isFull()) return false;

        rearIdx = (rearIdx + 1) % capacity;
        q[rearIdx] = value;
        count++;
        return true;
    }

    bool deQueue() {
        if (isEmpty()) return false;

        frontIdx = (frontIdx + 1) % capacity;
        count--;
        return true;
    }

    int Front() {
        if (isEmpty()) return -1;
        return q[frontIdx];
    }

    int Rear() {
        if (isEmpty()) return -1;
        return q[rearIdx];
    }

    bool isEmpty() {
        return count == 0;
    }

    bool isFull() {
        return count == capacity;
    }
};