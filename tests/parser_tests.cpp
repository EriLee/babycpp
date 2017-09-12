#include "catch.hpp"
#include <parser.h>

using babycpp::lexer::Lexer;
using babycpp::lexer::NumberType;
using babycpp::lexer::Token;
using babycpp::parser::Parser;

TEST_CASE("Testing number parser", "[parser]") {
  Lexer lex;
  Parser parser(&lex);
  lex.initFromStr("1.0");
  //getting first token
  lex.gettok();
    
  auto* node = parser.parseNumber();

  REQUIRE(node->val.type == NumberType::FLOAT);
  REQUIRE(node->val.floatNumber == Approx(1.0));
}

TEST_CASE("Testing function call", "[parser]") {
	Lexer lex;
	lex.initFromStr("testFunction ();");
	Parser parser(&lex);

	lex.gettok();
	auto* p = parser.parseIdentifier();
	REQUIRE(p != nullptr);

	auto * p_casted = dynamic_cast<babycpp::parser::CallExprAST*>(p);
	REQUIRE(p_casted != nullptr);
	REQUIRE(p_casted->callee == "testFunction");
	REQUIRE(p_casted->args.size() == 0) ;

	lex.initFromStr("functionWithWeirdName__324_NOW (    )  ;");
	lex.gettok();
	p = parser.parseIdentifier();
	REQUIRE(p != nullptr);

	p_casted = dynamic_cast<babycpp::parser::CallExprAST*>(p);
	REQUIRE(p_casted != nullptr);
	REQUIRE(p_casted->callee == "functionWithWeirdName__324_NOW");
	REQUIRE(p_casted->args.size() == 0) ;

}