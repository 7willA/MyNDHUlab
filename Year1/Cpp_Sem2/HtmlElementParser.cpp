#include <string>

class HTMLElement
{
private:
  std::string tagName;
  std::string content;

public:
  HTMLElement(std::string str)
  {
    size_t startTagOpen = str.find('<');
    size_t startTagClose = str.find('>');
    size_t endTagOpen = str.rfind("</");
    size_t endTagClose = str.rfind('>');

    if (startTagOpen != std::string::npos && startTagClose != std::string::npos &&
        endTagOpen != std::string::npos && endTagClose != std::string::npos &&
        startTagOpen == 0 && endTagOpen > startTagClose)
    {
      tagName = str.substr(startTagOpen + 1, startTagClose - startTagOpen - 1);
      content = str.substr(startTagClose + 1, endTagOpen - startTagClose - 1);
    }
    else
    {
      tagName = "";
      content = "";
    }
  }

  std::string getTagName()
  {
    return tagName;
  }
  std::string getContent()
  {
    return content;
  }
};

int main() {
  std::string str;
  getline(std::cin,str);
  HTMLElement html(str);
  std::cout<<html.getTagName()<<std::endl;
  std::cout<<html.getContent()<<std::endl;
  return 0;
}