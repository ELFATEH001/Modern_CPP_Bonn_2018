#include <gtest/gtest.h>
#include "image.h"
#include <iostream>

TEST(ImageTest, TestConstructor) {
    // Arrange
    int rows = 3;
    int cols = 4;
    
    // Act
    igg::Image test{rows,cols};
    
    // Assert
    EXPECT_EQ(rows, test.Rows());
    EXPECT_EQ(cols, test.Cols());
}

TEST(ImageTest, ConstructorWithZeroDimensions) {
   igg::Image test{0, 0};
   EXPECT_EQ(0, test.Rows());
   EXPECT_EQ(0, test.Cols());
}
   
TEST(ImageTest, ConstructorWithLargeDimensions) {
   igg::Image test{10000, 10000};
   EXPECT_EQ(10000, test.Rows());
   EXPECT_EQ(10000, test.Cols());
}

TEST(Scaling, UpScaleWithFactor) {
   int factor = 2;
   int row = 2;
   int col = 2;
   igg::Image test{row, col};
   test.UpScale(factor);
   // std::cout << "Real size:"<< test.Data_size() << std::endl;
   EXPECT_EQ(test.Data_size(), 16);
   EXPECT_EQ(test.Rows(), row * factor);
   EXPECT_EQ(test.Cols(), col * factor);
}

TEST(Scaling, DownScaleWithFactor) {
   int factor = 2;
   int row = 4;
   int col = 4;
   igg::Image test{row, col};
   test.DownScale(factor);
   // std::cout << "Real size:"<< test.Data_size() << std::endl;
   EXPECT_EQ(test.Data_size(), 4);
   EXPECT_EQ(test.Rows(), row / factor);
   EXPECT_EQ(test.Cols(), col / factor);
}


