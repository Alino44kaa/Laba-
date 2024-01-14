#include <iostream>
#include <list>
#include <initializer_list>

using namespace std;

template <class T>
class Deque
{
private:
    list<T> value;

public:
    Deque() {}

    Deque(initializer_list <T>&& c)
    {
        for (auto c1 : c)
        {
            pushBack(c1);
        }
    }

    Deque(T& data)
    {
        value.push_front(data);
    }

    T& operator[](int index)
    {
        list<T> tempList;
        tempList = this->value;
        for (int i = 0; i < index; i++)
        {
            tempList.pop_front();
        }
        int temp = tempList.front();
        return temp;
    }

    T front()
    {
        return value.front();
    }

    T back()
    {
        return value.back();
    }

    bool empty()
    {
        return value.empty();
    }

    int size()
    {
        return value.size();
    }

    void pushFront(const T& data)
    {
        value.push_front(data);
    }

    void pushBack(const T& data)
    {
        value.push_back(data);
    }

    T popFront()
    {
        T temp = value.front();
        value.pop_front();
        return temp;
    }

    T popBack()
    {
        T temp = value.back();
        value.pop_back();
        return temp;
    }

    void show()
    {
        list<T> temp = value;
        cout << endl;
        cout << "______________________________" << endl;
        cout << endl;
        do
        {
            cout << temp.front() << endl;
            temp.pop_front();
        } while (temp.size() != 0);
        cout << "______________________________" << endl;
    }

    void pushAt(int index, const T& data)
    {
        list<T> tempList;
        tempList = this->value;
        for (int i = 0; i < index; i++)
        {
            tempList.push_back(value.front());
            value.pop_front();
        }
        value.push_front(data);
        for (int i = 0; i < index; i++)
        {
            value.push_front(tempList.back());
            tempList.pop_back();
        }
    }

    void swap(int index, const T& data)
    {
        list<T> tempList;
        tempList = this->value;
        for (int i = 0; i < index; i++)
        {
            tempList.push_back(value.front());
            value.pop_front();
        }
        value.pop_front();
        value.push_front(data);
        for (int i = 0; i < index; i++)
        {
            value.push_front(tempList.back());
            tempList.pop_back();
        }
    }

    Deque(const Deque<T>& v)
    {
        this->value.resize(0);
        Deque v1;
        list<T> l1 = v.value;
        while (l1.size() != 0)
        {
            pushBack(l1.back());
            l1.pop_back();
        };
    };

    Deque& operator = (const Deque<T>& v)
    {
        if (&v == this)
            return *this;

        Deque v1;
        list<T> l1 = v.value;
        while (l1.size() != 0)
        {
            pushBack(l1.back());
            l1.pop_back();
        };

        return *this;
    }

    Deque(Deque<T>&& v) noexcept(true)
    {
        Deque v1;
        list<T> l1 = v.value;
        while (l1.size() != 0)
        {
            pushBack(l1.front());
            l1.pop_front();
        };
    }

    Deque& operator = (Deque<T>&& v) noexcept
    {
        if (&v == this)
            return *this;

        Deque v1;
        list<T> l1 = v.value;
        while (l1.size() != 0)
        {
            pushBack(l1.back());
            l1.pop_back();
        };

        return *this;
    }
};

template <class T>

Deque<T> foo(Deque<T> Deque) {
    return Deque;
};

int main()
{
    setlocale(LC_ALL, "");

    Deque<string> a;

    Deque<double> b;

    Deque<int> s1{ 1, 2, 3, 4, 5 };

    Deque <int> s2(s1);
    Deque <int> s3;

    s1.show();
    cout << "1 Deque" << endl;

    s3 = foo(s2);

    s2.popFront();
    s2.popFront();
    s2.popFront();

    s1.popFront();

    s3.show();
    cout << "3 Deque" << endl;
    s2.show();
    cout << "2 Deque" << endl;
    s1.show();
    cout << "1 Deque" << endl;

    cout << s2[1] << endl;
}