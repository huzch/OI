class ZeroEvenOdd {
    mutex mtx;
    condition_variable cv;
    int turn = 1;
    int n;
public:
    ZeroEvenOdd(int n) {
        this->n = n;
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        unique_lock<mutex> lock(mtx);
        for(int i=0; i<n; ++i) {
            cv.wait(lock, [this](){return turn == 1 || turn == 3;});
            printNumber(0);
            turn = turn == 1 ? 2 : 4;
            cv.notify_all();
        }
    }

    void even(function<void(int)> printNumber) {
        unique_lock<mutex> lock(mtx);
        for(int i=2; i<=n; i+=2) {
            cv.wait(lock, [this](){return turn == 4;});
            printNumber(i);
            turn = 1;
            cv.notify_all();
        }
    }

    void odd(function<void(int)> printNumber) {
        unique_lock<mutex> lock(mtx);
        for(int i=1; i<=n; i+=2) {
            cv.wait(lock, [this](){return turn == 2;});
            printNumber(i);
            turn = 3;
            cv.notify_all();
        }
    }
};
