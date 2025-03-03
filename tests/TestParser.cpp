#include <gtest/gtest.h>
#include "Lexer.h"
#include "Parser.h"
#include "INode.h"
#include "Value.h"
#include "Variable.h"
#include "Sum.h"
#include "Subtraction.h"
#include "Division.h"
#include "Multiplication.h"

TEST(TestParser, TestingCalcSums) {

    Parser parser = Parser("4+4");
    EXPECT_DOUBLE_EQ(8, parser.parseExpression()->calc());

    parser.setNewInput("4+2");
    EXPECT_DOUBLE_EQ(6, parser.parseExpression()->calc());
    
    parser.setNewInput("0+0+0+0+0+0");
    EXPECT_DOUBLE_EQ(0, parser.parseExpression()->calc());
}


TEST(TestParser, TestingCalcOperatorPrecedence) {

    Parser parser = Parser("4*4+4*4");
    EXPECT_DOUBLE_EQ(32,  parser.parseExpression()->calc());

    parser.setNewInput("4(4+4)");
    EXPECT_DOUBLE_EQ(32, parser.parseExpression()->calc());

    parser.setNewInput("4+4*4/2+4/2+4*2");
    EXPECT_DOUBLE_EQ(22,  parser.parseExpression()->calc());
    
    parser.setNewInput("4+4*4(2*2+4-1)-4");
    EXPECT_DOUBLE_EQ(112, parser.parseExpression()->calc());
}
TEST(TestParser, ValueInFrontOfParenthesisMultiplication) {

    Parser parser = Parser("4(3+3)");
    EXPECT_DOUBLE_EQ(24,  parser.parseExpression()->calc());
    parser.setNewInput("4(2(2(2+2)))");
    EXPECT_DOUBLE_EQ(64, parser.parseExpression()->calc());
}