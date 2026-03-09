#pragma once

#include <vector>
#include <iostream>

namespace igg {

class Image {
 public:
  ///////////////////// Create the public interface here ///////////////////////
 Image(){};
 Image(int rows, int cols): rows_(rows),cols_(cols)
 {
    data_.resize(rows_*cols_);
 };
 int& At(int row, int col);
 void print_CR() const;
 int Rows() const;
 int Cols() const;
 int Data_size() const;
 bool FillFromPgm(const std::string& filename);
 void WriteToPgm(const std::string& filename) const;
 std::vector<float> ComputeHistogram(const int bins) const;
 void DownScale(const int scale);
 void UpScale(const int scale);
 void PrintData();

 private:
  int rows_ = 0;
  int cols_ = 0;
  int max_val_    = 255;
  std::vector<int> data_;
};

}  // namespace igg
