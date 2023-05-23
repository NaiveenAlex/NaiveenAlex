#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class HtmlBuilder;

class HtmlElement
{
    string name, text;
    vector<HtmlElement> elements;
    const size_t indent_size = 2;

    HtmlElement() {}

    HtmlElement(const string& name, const string& text) : name(name), text(text) {}

    friend class HtmlBuilder;

public:
    string str(int indent = 0) const
    {
        ostringstream oss;
        string i(indent_size * indent, ' ');

        oss << i << "<" << name << ">" << endl;
        if (text.size() > 0)
            oss << string(indent_size * (indent + 1), ' ') << text << endl;

        for (const auto& e : elements)
            oss << e.str(indent + 1);
        oss << i << "</" << name << ">" << endl;

        return oss.str();
    }

    static HtmlBuilder create(string root_name);
};

class HtmlBuilder
{
    HtmlElement root;
    friend class HtmlElement;

    HtmlBuilder(string root_name)
    {
        root.name = root_name;
    }

public:
    HtmlBuilder& add_child(string child_name, string child_text)
    {
        HtmlElement e{child_name, child_text};
        root.elements.emplace_back(e);
        return *this;
    }

    string str() const { return root.str(); }
    operator HtmlElement() const
    {
        return root;
    }
};

HtmlBuilder HtmlElement::create(string root_name)
{
    return HtmlBuilder(root_name);
}

int main()
{
    auto element = HtmlElement::create("ul").add_child("li", "hello").add_child("li1", "world").add_child("li2", "dp");

    cout << element.str();

    return 0;
}
