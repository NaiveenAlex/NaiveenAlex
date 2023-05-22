/*
Dependency inversion 

	- High level modules should not depend on low level modules, both should depend on abstractions.
	- Abstractions should not depend on details. Details should depend on abstractions.

*/

#include <iostream>
#include <vector>
#include <tuple>
#include <string>

using namespace std;


enum class Relationship
{
    parent,
    child,
    sibling
};

struct Person
{
    string name;
};

/*
struct Relationships	// low-level
{
    vector<tuple<Person, Person, Relationship>> relations;
    
    void add_parent_and_child(const Person& parent, const Person& child)
    {
        relations.push_back({parent, child, Relationship::parent});
        relations.push_back({child, parent, Relationship::child});
    }  
};


struct Research 		// high-level
{
    Research(const Relationships& relationships)
    {
        auto& relations = relationships.relations;
        for(auto&& [first, second, relation] : relations)
        {
            if(first.name == "John" && relation == Relationship::parent)
            {
                cout << "John has a child called " << second.name << endl;
            }
        }
    }
};
*/

//With Dependency Principle
//-------------------------
//New Relationship Browser interface
struct RelationshipBrowser
{
  virtual vector<Person> find_all_children_of(const string& name) = 0;
};

struct Relationships : RelationshipBrowser	// low-level
{
    vector<tuple<Person, Person, Relationship>> _relations;
    
    void add_parent_and_child(const Person& parent, const Person& child)
    {
        _relations.push_back({parent, child, Relationship::parent});
        _relations.push_back({child, parent, Relationship::child});
    } 

    vector<Person> find_all_children_of(const string& name) override
    {
        vector<Person> result;
        for(auto&& [first, second, relation] : _relations)
        {
            if(first.name == name && relation == Relationship::parent)
            {
                result.push_back(second);
            }
        }
        return result;
    }
};


struct Research 		// high-level
{
    Research(RelationshipBrowser& browser)
    {
        for(auto& child : browser.find_all_children_of("John"))
            cout << "John has a child called " << child.name << endl;
    }
};


int main()
{
    Person parent{"John"};
    Person child1{"Chris"};
    Person child2{"Matt"};

    Relationships relationships;
    relationships.add_parent_and_child(parent, child1);
    relationships.add_parent_and_child(parent, child2);

    Research r = Research(relationships);

  return 0;
}
