#include <string>
#include <vector>
#include <iostream>

using namespace std;

enum class Color {red, green, blue};
enum class Size  {small, medium, large};

struct Product
{
    string name;
    Color color;
    Size size;
};

struct ProductFilter
{
    typedef vector<Product*> Items;

    Items by_color (Items items, Color color)
    {
        Items result;
        for(auto &i : items)
            if(i->color == color)
                result.push_back(i);
        return result;
    }

    Items by_size (Items items, Size size)
    {
        Items result;
        for(auto &i : items)
            if(i->size == size)
                result.push_back(i);
        return result;
    }

    Items by_size_and_color (Items items, Size size, Color color)
    {
        Items result;
        for(auto &i : items)
            if(i->size == size && i->color == color)
                result.push_back(i);
        return result;
    }

};

/* Specification pattern*/

template <typename T> struct Specification
{
    virtual ~Specification() = default;
    virtual bool is_satisfied(T* item) const = 0;
};

template <typename T> struct Filter 
{
    virtual vector<T*> filter(vector<T*> items, Specification<T>& spec) = 0;
};

struct ColorSpecification : Specification<Product>
{
    Color color;
    ColorSpecification(Color color) : color(color) 
    {}
  
    bool is_satisfied(Product * item) const override
    {
        return item->color == color;
    }
};

struct SizeSpecification : Specification<Product>
{
    Size size;
    SizeSpecification(Size size) : size(size)
    {}
 
    bool is_satisfied(Product * item) const override
    {
        return item->size == size;
    }
};

struct BetterFilter : Filter<Product>
{
    vector<Product*> filter(vector<Product*> items, Specification<Product> &spec)
    {
        vector<Product*> result;
        for(auto &p : items)
            if(spec.is_satisfied(p))
                result.push_back(p);
        return result;
    }
};

template <typename T> struct AndSpecification : Specification <T>
{
    const Specification<T> & first;
    const Specification<T> & second;

    AndSpecification(const Specification<T> & first, const Specification<T> & second):
        first(first), second(second)
        {}
    
    bool is_satisfied(T *item) const override
    {
        return first.is_satisfied(item) && second.is_satisfied(item);
    }

};


int main()
{
    Product apple{"Apple", Color::green, Size::small};
    Product tree{"Tree", Color::green, Size::large};
    Product house{"House", Color::blue, Size::large};

    const vector<Product*> & all {&apple, &tree, &house};

    BetterFilter bf;
    ColorSpecification green(Color::green);
    auto green_things = bf.filter(all, green);

    for(auto& x : green_things)
        cout << x->name << " is green .\n";

    SizeSpecification large(Size::large);
    AndSpecification <Product> green_large(green, large);


    auto green_large_things = bf.filter(all, green_large);

    for(auto& x : green_large_things)
        cout << x->name << " is green and large.\n";

    return 0;
}
