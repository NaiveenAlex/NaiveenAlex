//When objects are slight modifications of a basic type.


#include <iostream>
#include <stdio.h>
#include <memory>

using namespace std;


struct Address
{
	string street, city;
	int suite;
	
	Address(const string& street, const string &city, int suite):
	street(street), city(city), suite(suite) {}
	
    Address(const Address& address):
    street(address.street), city(address.city), suite(address.suite)
    {}

	friend ostream &operator << (ostream &os, const Address &address)
	{
		os << " street: " << address.street << " city " << address.city << " suite " << address.suite << endl;
		return os;
	}
	
};

struct Contact
{
	string name;
	Address* address;
	
	Contact (const string &name, Address* address) :
	name (name), address (address)
	{}

	Contact (const Contact &other) :
	name (other.name), address (new Address(*other.address))
	{}

    ~Contact () {delete address;}

	friend ostream &operator << (ostream &os, const Contact &contact)
	{
		os << " name : " << contact.name << " address: " << *contact.address ;
		return os;
	}
};

struct EmployeeFactory
{
    //produce employees based of a 'prototype'

    static unique_ptr<Contact> new_main_office_employee(const string& name, 
                                                        const int suite)
    {
        static Contact p ("", new Address("1 East Dr", "London", 0));
        return new_employee(name, suite, p);
    }
    private:
    static unique_ptr<Contact> new_employee(const string& name, 
                                            const int suite, 
                                            const Contact& prototype)
    {
        auto reply = make_unique<Contact>(prototype);
        reply->name = name;
        reply->address->suite = suite;
        return reply;
    }
};

Contact Main {"Main", new Address("514 West Dr", "London", 678)};

int main()
{
	Contact john {"John Doe", new Address ("1 East Dr", "London", 123)};
	Contact jane {john};
	jane.name = "Jane";
	jane.address->suite = 314;
	cout << john << endl << jane << endl;

    //With prototype factory

    auto james = EmployeeFactory::new_main_office_employee("James", 456);
	cout << *james << endl;
	
}
