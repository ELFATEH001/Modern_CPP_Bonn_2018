#include <iostream>
using std::cout;
using std::endl;

class Blah {
  public:
	void SomeFunc() {cout << "non const" << endl;}
	void SomeFunc() const { cout << "const" << endl; } // const conrrecteness!
};


int main(int argc, char const *argv[])
{
	Blah blah;
	blah.SomeFunc();

	const Blah& blah_ref = blah;
	blah_ref.SomeFunc();
	return 0;
}
