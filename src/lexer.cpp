#include "lexer.h"
#include <iostream>

namespace babycpp {
namespace lexer {

int inline handleNoMatchFromRegex(const char* start)
{
    if ((*start == EOF) || (*start == 0)) {
      return tok_eof;
    }
    // log ERROR
    return tok_no_match;

}

int Lexer::gettok()
{
  //making sure the lexer is initialized
  if (start == nullptr) {
    return tok_empty_lexer;
  }

  bool gotMatch = std::regex_search(start, matcher, expr,
                               std::regex_constants::match_continuous);

  // handling case of not match
  if (!gotMatch) {
    return handleNoMatchFromRegex(start);
  }

  // for (uint32_t i = 1; i < m.size(); ++i) {
  //  if (m[i].matched) {
  //    std::cout << m[i] << std::endl;
  //    running += m.length();
  //    break;
  //  }
  //}
  return -1;
}

/*
//old int gettok(Database &D) {
  // now we skipp all the white spaces
  while (isspace(D.lastChar) != 0) {
    D.lastChar = D.getchar();
  }

   if (isalpha(D.lastChar) != 0) {
    D.identifierStr = static_cast<char>(D.lastChar);
    // reading next char
    D.lastChar = D.getchar();
    // supporting alphanumeric tokens and '_'
    while ((isalnum(D.lastChar) != 0) || (D.lastChar == '_')) {
      D.identifierStr += static_cast<char>(D.lastChar);
      // pulling in next char
      D.lastChar = D.getchar();
    }

    //if (D.identifierStr == "def") {
    //  return tok_def;
    //}
    if (D.identifierStr == "extern") {
      return tok_extern;
    }
    return tok_identifier;
  }
  return -1;
  // if ((isdigit(D.lastChar) != 0) || D.lastChar == '.') {
  //  std::string numStr;
  //  do {
  //    numStr += static_cast<char>(D.lastChar);
  //    D.lastChar = D.getchar();
  //  } while ((isdigit(D.lastChar) != 0) || D.lastChar == '.');

  //  D.numVal = strtod(numStr.c_str(), nullptr);
  //  return tok_number;
  //}

  // if (D.lastChar == '#') {
  //  // we eat until the end of the line
  //  do {
  //    D.lastChar = D.getchar();
  //  } while (D.lastChar != EOF && D.lastChar != '\n' && D.lastChar != '\r');

  //  if (D.lastChar != EOF) {
  //    return gettok(D);
  //  }
  //}

  //// only remaining things are operators
  // if (D.lastChar == EOF) {
  //  return tok_eof;
  //}

  //// return as asci value
  // int thisChar = D.lastChar;
  // D.lastChar = D.getchar();
  // return thisChar;
}
*/

} // namespace lexer
} // namespace babycpp
