#include <iostream>

using namespace std;

template <typename T>
class UPtr {
private:
    T* ptr;

public:
    UPtr()
    {
        this->ptr = NULL;
    }

    UPtr(T* ptr)
    {
        this->ptr = ptr;
    }

    ~UPtr() {
        reset();
    }

    UPtr(const UPtr&) = delete;
    UPtr& operator=(const UPtr&) = delete;

    UPtr(UPtr&& other) noexcept : ptr(other.release()) {}

    UPtr& operator=(UPtr&& other) noexcept {
        if (this != &other) {
            reset(other.release());
        }
        return *this;
    }

    void reset(T* newPtr = nullptr) {
        ptr = newPtr;
    }

    void swap(UPtr& other) {
        T* tmp = get();
        reset(other.release());
        other.reset(tmp);
    }

    T* get() const {
        return ptr;
    }

    T* release() {
        T* releasedPtr = ptr;
        ptr = nullptr;
        return releasedPtr;
    }

    T& operator*() const {
        return *ptr;
    }

    T* operator->() const {
        return ptr;
    }

    explicit operator bool() const {
        return ptr != nullptr;
    }
};

int main()
{
    int A = 2;
    int B = 3;
    string C = "fdg";
    double D = 2.2;
    UPtr<int> a(new int(A));
    UPtr<int> b(new int(B));
    UPtr<string> c(new string(C));
    UPtr<double> d(new double(D));

    cout << *a << endl;
    cout << a.get() << endl;
    cout << *b << endl;
    cout << b.get() << endl;
    a.swap(b);
    a.~UPtr();
    cout << *b << endl;
    cout << b.get() << endl;



    return 0;
}