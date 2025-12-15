class FooBar {
    mutex mtx;
    condition_variable cv;
    bool flag;
    int n;
public:
    FooBar(int n) {
        this->n = n;
    }

    void foo(function<void()> printFoo) {
        unique_lock<mutex> lock(mtx);
        for (int i = 0; i < n; i++) {
            cv.wait(lock, [this](){return !flag;});
        	printFoo();
            flag = true;
            cv.notify_one();
        }
    }

    void bar(function<void()> printBar) {
        unique_lock<mutex> lock(mtx);
        for (int i = 0; i < n; i++) {
            cv.wait(lock, [this](){return flag;});
        	printBar();
            flag = false;
            cv.notify_one();
        }
    }
};
