#pragma once
#include <iostream>
#include <initializer_list>

using namespace std;

template <class T>
class Stack
{
private:
    struct Node
    {
        T value;
        Node* next;
    };

    typedef Node* PNode;

    PNode SPN;

public:

    void isEmpty(PNode pn)
    {
        if (pn == NULL)
        {
            throw "Stack empty";
        }
    }

    Stack()
    {
        SPN = NULL;
    }

    Stack(initializer_list <T>&& c)
    {
        for (auto c1 : c)
        {
            push(c1);
        }

    }
    void push(const T& data)
    {
        PNode s1;
        s1 = SPN;
        SPN = new Node;
        SPN->value = data;
        SPN->next = s1;
    }
    T pop()
    {
        PNode s1;
        s1 = SPN;
        T data;

        try
        {
            isEmpty(SPN);
        }
        catch (const char* error_message)
        {
            cout << error_message << endl;
        }

        data = SPN->value;
        SPN = SPN->next;
        delete(s1);
        return data;
    }

    T get()
    {
        return SPN->value;
    }

    void see()
    {
        PNode s1;
        s1 = SPN;
        if (SPN == NULL)
        {
            cout << "Стек не создан" << endl;
            return;
        }
        cout << endl;
        cout << "______________________________" << endl;
        cout << endl;
        do
        {
            cout << s1->value << endl;
            s1 = s1->next;
        } while (s1 != NULL);
        cout << "______________________________" << endl;
        cout << "вывод стека закончен" << endl;
    }

    Stack(const Stack<T>& s)
    {
        SPN = NULL;
        Stack s1;
        PNode s2 = s.SPN;
        do
        {
            s1.push(s2->value);
            s2 = s2->next;
        } while (s2 != NULL);
        do
        {
            push(s1.pop());
        } while (s1.SPN != NULL);
    };

    Stack& operator = (const Stack<T>& s)
    {
        if (&s == this)
            return *this;

        Stack s1, s3;
        PNode s2 = s.SPN;
        do
        {
            s1.push(s2->value);
            s2 = s2->next;

        } while (s2 != NULL);
        do
        {
            push(s1.pop());
        } while (s1.SPN != NULL);
        return *this;
    }

    Stack(Stack<T>&& s) noexcept(true)
    {
        SPN = NULL;
        Stack s1;
        PNode s2 = s.SPN;
        do
        {
            s1.push(s2->value);
            s2 = s2->next;
        } while (s2 != NULL);
        do
        {
            push(s1.pop());
        } while (s1.SPN != NULL);
    };

    Stack& operator = (Stack<T>&& s) noexcept
    {
        if (&s == this)
            return *this;

        Stack s1;
        PNode s2 = s.SPN;
        do
        {
            s1.push(s2->value);
            s2 = s2->next;

        } while (s2 != NULL);
        do
        {
            push(s1.pop());
        } while (s1.SPN != NULL);
        return *this;
    }

    T& operator[](int index)
    {
        PNode s1;
        s1 = SPN;
        for (int i = 0; i < index; i++)
        {
            s1 = s1->next;
        }
        return s1->value;
    }
};

template <class T>

Stack<T> foo(Stack<T> stack) {
    return stack;
};

