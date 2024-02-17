#include <iostream>
#include <map>
#include <string>
#include <vector>

std::map<std::string, std::string> decorations = {
  {"b", "\033[1m"}, // Bold
  {"ul", "\033[4m"}, // Underline
  {"r", "\033[31m"}, // Red
  {"g", "\033[32m"}, // Green
  {"y", "\033[33m"}, // Yellow
};

std::string parseText(std::string text) {
  std::vector<std::string> tags;
  std::string parsedText = "";
  std::string currentTag = "";

  std::cout << "Text: " << text << '\n';
  for (int i = 0; i < text.size(); i++) {
    if (text[i] == '[') {
      i++;
      while (text[i] != ']') {
        currentTag += text[i];
        i++;
      }
      if (currentTag == "/") {
        tags.pop_back();
        parsedText += "\033[m";
        for (int i = 0; i < tags.size(); i++) {
          parsedText += decorations[tags[i]];
        }
      } else {
        tags.push_back(currentTag);
        parsedText += decorations[currentTag];
      }
      currentTag = "";
    } else {
      parsedText += text[i];
    }
  }
  return parsedText;
}


int main() {
  std::string r = parseText("[b]Hello[/], [ul][y]สวัสดี![/] Hello, [r][b]What[/][/] the[/]");
  std::cout << r << '\n';
  return 0;
}
