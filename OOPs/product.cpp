#include <iostream>
using namespace std;

// Product class

class Product
{
    int id;
    string name;
    int mrp;
    int selling_price;

public:
    // consructor
    Product()
    {
        cout << "Inside the constuctor" << endl;
    }

    // Parameterised constuctor
    Product(int id, string n, int mrp, int sp)
    {
        this->id = id;
        name = n;
        this->mrp = mrp;
        selling_price = sp;
    }

    

    void setname(string n)
    {
        name = n;
    }

    void setid(int prodid)
    {
        id = prodid;
    }

    void setMRP(int price)
    {
        mrp = price;
    }

    void setSP(int price)
    {
        if (price > mrp)
        {
            selling_price = mrp;
        }
        else
        {
            selling_price = price;
        }
    }

    void showdeets()
    {
        cout << "Name: " << name << endl;
        cout << "Id : " << id << endl;
        cout << "Mrp : " << mrp << endl;
        cout << "Selling Price : " << selling_price << endl;
    }
};

int main()
{
    // Product camera;
    Product camera2(101, "Nixon", 200, 100);
    // string n;
    // cin >> n;
    // camera.setname(n);
    // camera.setid(12244);

    // camera.setMRP(200);
    // camera.setSP(250);

    // camera.showdeets();
    camera2.showdeets();
    cout << endl;
    Product webcam(camera2);

    webcam.showdeets();

    return 0;
}