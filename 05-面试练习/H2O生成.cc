class H2O {
    mutex mtx;
    condition_variable cv;
    int h = 0; //氢原子数
    int o = 0; //氧原子数
public:
    void hydrogen(function<void()> releaseHydrogen) {
        unique_lock<mutex> lock(mtx);
        cv.wait(lock, [this](){return h < 2;});
        releaseHydrogen();
        ++h;
        if(h == 2 && o == 1) h = o = 0;
        cv.notify_all();
    }

    void oxygen(function<void()> releaseOxygen) {
        unique_lock<mutex> lock(mtx);
        cv.wait(lock, [this](){return o < 1;});
        releaseOxygen();
        ++o;
        if(h == 2 && o == 1) h = o = 0;
        cv.notify_all();
    }
};
