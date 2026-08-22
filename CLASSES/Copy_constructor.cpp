#include "iostream"
#include "map"
using namespace std;

class Base
{
    int *password;
    string UserName;
    std::map<string, int> UserData;

public:
    Base() : password(nullptr), UserName("NoUser") {}
    Base(int a, string name) : password(new int(a)), UserName(name) {}
    Base(const Base &tmp)
    {
        cout << "In copy constructor" << endl;
        if (tmp.password)
            password = new int(*tmp.password);
        else
            password = nullptr;
        UserName = tmp.UserName;
        UserData = tmp.UserData;
    }
    Base &operator=(const Base &tmp)
    {
        cout << "In Copy assignment operator" << endl;

        if (this != &tmp)
        {
            delete password;

            if (tmp.password)
                password = new int(*tmp.password);
            else
                password = nullptr;

            UserName = tmp.UserName;
            UserData = tmp.UserData;
        }

        return *this;
    }
    void UpdateTable()
    {
        if (password == nullptr)
        {
            cout << "No users found and Password not set!" << endl;
            return;
        }

        UserData[UserName] = *password;
    }
    void Display()
    {
        for (auto i : UserData)
        {
            cout << i.first << " " << i.second << endl;
        }
    }
};

int main()
{
    string str = "GangaBhavani";
    int pass = 13022006;
    Base obj(pass, str);
    Base b;
    obj.UpdateTable();
    obj.Display();
    b.UpdateTable();
    b.Display();
    //If already existed object we are using for copy then it will call the copy assignment operator
    b=obj;
    b.UpdateTable();
    b.Display();
    //If there is no existed object then it will call the copy constructor
    Base b2(b);
    b2.UpdateTable();
    b2.Display();
}