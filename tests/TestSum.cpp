#include <gtest/gtest.h>
#include "Sum.h"
#include "INode.h"
#include "Value.h"
#include "Variable.h"
#include "Sum.h"
#include "Subtraction.h"
#include "Division.h"
#include "Multiplication.h"

TEST(TestSum, SummationOfValues) {
  INode* testValue = new Value(4);
  INode* testValue2 = new Value(9);
  INode* testSum = new Sum(testValue,testValue2);
  
  EXPECT_DOUBLE_EQ(13, testSum->calc());
}

