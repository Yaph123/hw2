
#include "product.h"
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;



class Movie : public Product{

  public:

  Movie(const string& name, double price, int qty, 
        const string& genre, const string& rating);

  set<string> keywords() const override;

  string displayString() const override;

  void dump(ostream& os) const override;

  string getGenre();

  string getRating();
  
  private:
  string genre_;
  string rating_;
}
;
  