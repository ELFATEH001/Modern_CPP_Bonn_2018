#include "image.h"
#include "io_tools.h"


 void igg::Image::print_CR(){
    std::cout << "row : "<< this->rows_ << ", col : "<< this->cols_ << std::endl;
 }

 int igg::Image::Rows() const
 {
   return this->rows_;
 };

 int igg::Image::Cols() const { return this->cols_; };

 int igg::Image::Data_size() const
 {
  return this->data_.size();
 }

 int& igg::Image::At(int row, int col)
 {
   int index = this->rows_ * row + col;
   return this->data_[index];
 };

 bool igg::Image::FillFromPgm(const std::string& filename)
 {
  bool fill_state = false;
  igg::io_tools::ImageData Image;
  Image = igg::io_tools::ReadFromPgm(filename);

  if (Image.rows == 0 || Image.cols == 0) {
    std::cerr << "Failed to read image: " << filename << std::endl;
    return false;
  }
  fill_state = true;
  this->rows_ = Image.rows;
  this->cols_ = Image.cols;
  this->data_ = Image.data;
  this->max_val_ = Image.max_val;
  return fill_state;
 };

 void igg::Image::WriteToPgm(const std::string& filename) const
 {
  igg::io_tools::ImageData Image{this->rows_,this->cols_,this->max_val_, this->data_};
  bool write_state = false;
  while (!write_state)
  {
    write_state = igg::io_tools::WriteToPgm(Image, filename);
  };

 };

 std::vector<float> igg::Image::ComputeHistogram(int bins) 
 {
  std::vector<float> pixel_bin_count(bins, 0.0f);
  // std::vector<float> pixel_bin;
  float bin_ratio = 1.0f / bins;
  // pixel_bin_count.resize(bins);
  // pixel_bin.resize(bins)


  for(auto &data: data_)
  {
    for (int i = 0 ; i<bins; i++){
      if( data < this->max_val_ *(i + 1) * bin_ratio)
      {
        pixel_bin_count[i] = pixel_bin_count[i] + (1.0f)/this->data_.size();
        // pixel_bin_count[i] = 5;
        break;
      };  
    };
  };

  return pixel_bin_count;
  
 };

  void igg::Image::DownScale(const int scale)
 {
  int new_rows = this->rows_ / scale;
  int new_cols = this->cols_ / scale;
  std::vector<int> new_data(new_cols * new_rows);

  for (int i=0; i < (this->rows_/scale); i++)
  {
    for (int j=0; j < (this->cols_/scale); j++)
    {
      new_data[i*scale + j] = this->data_[i * scale * this->cols_ + j * scale];
    }
  }
  this->rows_ = new_rows;
  this->cols_ = new_cols;
  this->data_ = new_data;
 }; 

 void igg::Image::UpScale(const int scale) 
 {
  int new_rows = this->rows_ * scale;
  int new_cols = this->cols_ * scale;
  std::vector<int> new_data(new_cols * new_rows);

  for (int i=0; i < (this->rows_); i++)
  {
    for (int j=0; j < (this->cols_); j++)
    {
      for (int new_box_row=0; new_box_row < scale; new_box_row++)
      {
        for (int new_box_col=0; new_box_col < scale; new_box_col++)
        {
          // int new_row = i * scale + new_box_row;
          // int new_col = j * scale + new_box_col;
          // new_data[new_row * new_cols + new_col] = this->data_[i * this->cols_ + j];
          new_data[(i * scale * new_cols + j * scale) + i * new_cols  + j] = this->data_[i * this->cols_ + j];
        }
      }

    }
  }
  this->rows_ = new_rows;
  this->cols_ = new_cols;
  this->data_ = new_data;

 };

  void igg::Image::PrintData()
  {
  for (int i = 0; i < data_.size() ;i++)
   {
      std::cout <<this->data_[i] <<  " "  << std::endl;
   }
}