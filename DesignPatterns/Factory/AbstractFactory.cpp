#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <memory>
#include <map>

//Maintain a family of products and a family of factories.
//Use inheritance to polymorphically call the product.

using namespace std;

struct HotDrink
{
    virtual ~HotDrink() = default;
    virtual void prepare(int volume) = 0;
};

struct Tea : HotDrink
{
    void prepare(int volume) override
    {
        cout << " Take tea bad, boil water, pour " << volume << "ml, add lemon" <<endl;
    }
};

struct Coffee : HotDrink
{
    void prepare(int volume) override
    {
      cout << "Grind beans, boil water, pour " << volume << " ml, add cream" << endl;
    }
};

struct HotDrinkFactory
{
    virtual unique_ptr<HotDrink> make() const = 0;
};

struct TeaFactory : HotDrinkFactory
{
    unique_ptr<HotDrink> make() const override
    {
       return make_unique<Tea>();
    }
};

struct CoffeeFactory : HotDrinkFactory
{
    unique_ptr<HotDrink> make() const override
    {
       return make_unique<Coffee>();
    }
};


class DrinkFactory
{
    map<string, unique_ptr<HotDrinkFactory>> hot_factories;
public:
    DrinkFactory()
    {
        hot_factories["coffee"] = make_unique<CoffeeFactory>();
        hot_factories["tea"]    = make_unique<TeaFactory>();
    }

    unique_ptr<HotDrink> make_drink(const string& name, int volume)
    {
        auto drink = hot_factories[name]->make();
	drink->prepare(volume);
	return drink;
    }
};

int main()
{
    DrinkFactory df;
    df.make_drink("coffee", 200);
    return 0;
}
