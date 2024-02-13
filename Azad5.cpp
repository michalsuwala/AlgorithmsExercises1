#include <iostream>
#include <string>

struct Actor
{
    std::string name;
    int f;
    Actor *next;

    Actor() {}
    Actor(std::string name, int f) : name(name), f(f) {}
    Actor(std::string name, int f, Actor *next) : name(name), f(f), next(next) {}
};

class Array
{
    Actor *head;
    int n;

public:
    Array() : n(0), head(nullptr) {}
    Array(Actor *head, int n) : head(head), n(n) {}
    ~Array()
    {
        Actor *actor = head;
        for (int i = 0; i < n; i++)
        {
            Actor *next = actor->next;
            delete actor;
            actor = next;
        }
    }

    std::string get(int p)
    {
        if (!head)
        {
            return "NIE\n";
        }
        Actor *a = head;
        Actor *pre = head;
        Actor *max = new Actor("z", -1);
        Actor *preMax = head;
        std::string result;
        bool res = 0;
        bool f = 1;
        int i = 0;
        int maxInd = 0;
        while (f)
        {
            if (a->f <= p && (a->f > max->f || (a->f == max->f && a->name < max->name)))
            {
                res = 1;
                max = a;
                preMax = pre;
                maxInd = i;
            }
            if (i < n - 1)
            {
                pre = a;
                a = a->next;
            }
            else
            {
                f = 0;
            }
            i++;
        }
        if (res)
        {
            result = max->name;
            if (maxInd < n)
            {
                preMax->next = max->next;
                if ((max->name == head->name && max->f == head->f))
                {
                    head = max->next;
                }
                else if ((preMax->name == head->name && preMax->f == head->f))
                {
                    head->next = max->next;
                }
            }
            else
            {
                preMax->next = nullptr;
                if ((preMax->name == head->name && preMax->f == head->f))
                {
                    head->next = nullptr;
                }
                if ((max->name == head->name && max->f == head->f))
                {
                    head = nullptr;
                }
            }

            max = nullptr;
            delete max;
            n--;
            return result + '\n';
        }
        return "NIE\n";
    }

    bool get(std::string name, int p)
    {
        if (!head)
        {
            return 0;
        }
        Actor *a = head;
        bool res = 0;
        bool f = 1;
        while (f)
        {
            if (a->f == p && a->name == name)
            {
                f = 0;
                res = 1;
            }

            else if (a->next)
            {
                a = a->next;
            }
            else
            {
                f = 0;
            }
        }
        return res;
    }

    void append(std::string name, int p)
    {
        Actor *v = new Actor(name, p);

        if (!head)
        {
            head = v;
        }
        else
        {
            v->next = head;
            head = v;
        }
        n++;
    }

    int size()
    {
        return n;
    }
};

int main()
{
    int n;
    int op;
    int max;
    int p;
    bool swapA;

    std::cin >> n;
    std::string temp;
    Array array;
    std::string res;

    for (int i = 0; i < n; i++)
    {
        std::cin >> op;
        swapA = 1;

        if (op == 1)
        {
            std::string name;
            int f;
            std::cin >> std::ws;
            std::getline(std::cin, name);
            std::cin >> f;
            swapA = array.get(name, f);
            if (!swapA)
            {
                array.append(name, f);
                std::cout << "TAK" << '\n';
            }

            else
                std::cout << "NIE" << '\n';
        }

        else if (op == 2)
        {
            std::cin >> p;
            std::cout << array.get(p);
        }
    }
    return 0;
}
