#include "gtest/gtest.h"
#include "../headers/graph/edge.h"
#include "../headers/maxFlowProblem/maxFlowCalculation.h"

class FordFulkersonTest : public ::testing::Test {
protected:
    List<Edge> easyGraphForTest;

// easy lvl
//         B
// 8(10)/     \8(8)
//     A       D
// 2(15)\    / 2(2)
//        C

    List<Edge> hardGraphForTest;

};

TEST_F(FordFulkersonTest,testCalculatePathFunction1){

    easyGraphForTest.push_back(Edge("A", "B", 10));
    easyGraphForTest.push_back(Edge("A", "C", 15));
    easyGraphForTest.push_back(Edge("B", "D", 8));
    easyGraphForTest.push_back(Edge("C", "D", 2));

    double maximumPath = findMaxFlow(easyGraphForTest, "A", "D");

    GTEST_ASSERT_EQ(maximumPath, 10.0);

}

TEST_F(FordFulkersonTest,testCalculatePathFunction2){

    hardGraphForTest.push_back(Edge("S", "O", 3));
    hardGraphForTest.push_back(Edge("S", "P", 3));
    hardGraphForTest.push_back(Edge("O", "Q", 3));
    hardGraphForTest.push_back(Edge("O", "P", 2));
    hardGraphForTest.push_back(Edge("P", "R", 2));
    hardGraphForTest.push_back(Edge("Q", "R", 4));
    hardGraphForTest.push_back(Edge("Q", "T", 2));
    hardGraphForTest.push_back(Edge("R", "T", 3));

    double maximumPath = findMaxFlow(hardGraphForTest, "S", "T");

    GTEST_ASSERT_EQ(maximumPath, 5.0);

}