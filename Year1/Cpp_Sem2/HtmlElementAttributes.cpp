#include <iostream>
#include <string>
#include <map>
#include <list>
#include <sstream>
using namespace std;

// Do NOT redefine HTMLElement, it's already defined by the system

class HTMLElementWithAttributes : public HTMLElement
{
private:
    map<string, string> attributes;

public:
    HTMLElementWithAttributes(string input) : HTMLElement(input)
    {
        size_t startTagOpen = input.find('<');
        size_t startTagClose = input.find('>');

        if (startTagOpen == string::npos || startTagClose == string::npos)
            return;

        string openingTag = input.substr(startTagOpen + 1, startTagClose - startTagOpen - 1);

        size_t tagNameEnd = openingTag.find(' ');
        if (tagNameEnd == string::npos)
            return;

        string attrPart = openingTag.substr(tagNameEnd + 1);
        istringstream iss(attrPart);
        string token;
        while (iss >> token)
        {
            size_t eqPos = token.find('=');
            if (eqPos != string::npos)
            {
                string key = token.substr(0, eqPos);
                string value = token.substr(eqPos + 1);

                // If value doesn't end with a quote, continue reading
                while (value.back() != '"' && iss >> token)
                {
                    value += " " + token;
                }

                // Remove surrounding quotes
                if (!value.empty() && value.front() == '"') value.erase(0, 1);
                if (!value.empty() && value.back() == '"') value.pop_back();

                attributes[key] = value;
            }
        }
    }

    list<string> getAttributes()
    {
        list<string> keys;
        for (const auto &pair : attributes)
        {
            keys.push_back(pair.first);
        }
        return keys;
    }

    string operator[](string key)
    {
        auto it = attributes.find(key);
        return it != attributes.end() ? it->second : "";
    }
};

int main()
{
    string str;
    getline(cin, str);
    HTMLElementWithAttributes html(str);
    cout << html.getTagName() << endl;
    list<string> key = html.getAttributes();
    for (string k : key)
    {
        cout << html[k] << endl;
    }
    return 0;
}