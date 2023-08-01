/*
    - One instance in the system
        - Database repository
        - Object factory
        - Single constructor
        - same instance provided to all
    - No additional copied created.
    - lazy instantiation, thread safety
*/

#include <iostream>
#include <cstdio>
#include <string>
#include <fstream>
#include <vector>
#include <memory>
#include <cmath>
#include <map>
#include <boost/lexical_cast.hpp>
using namespace std;
using namespace boost;

class SingletonDatabase
{
    SingletonDatabase()
    {
        cout << "Initializing database.\n ";
        ifstream ifs("capitals.txt");

        string s, s2;

        while(getline(ifs, s))
        {
            getline(ifs, s2);
            int pop = lexical_cast<int>(s2);
            capitals[s] = pop;
        }

    }

    map<string, int> capitals;

    public:
        //Instance Cannot be created, replicated or Copied
        SingletonDatabase(SingletonDatabase const&) = delete;
        void operator=(SingletonDatabase const&) = delete;
        static SingletonDatabase& get()
        {
            static SingletonDatabase db;
            return db;
        }

        int get_population(const string& name)
        {
            return capitals[name];
        }
};

int main()
{
    string city = "Tokyo";
    cout << " " << city << " has a population of " <<
    SingletonDatabase::get().get_population(city) << " people.\n"; 
}


