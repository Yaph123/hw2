
#include "product.h"
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;



class Book : public Product{

  public:

  Book(const string& name,double price, int qty, const string& authorName, const string& isbn);

  set<string> keywords() const override ;

  string displayString() const override;

  void dump(ostream& os) const override;

  string getAUname();

  string getISBN();
  
  private:
  string authorName_;
  string isbn_;
  
};
