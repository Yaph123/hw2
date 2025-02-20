
#include "product.h"
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;



  class Clothing : public Product{

    public:

    Clothing(const string& name, double price, int qty, 
             const string& size, const string& brand);

    set<string> keywords() const override;

    string displayString() const override;

    void dump(ostream& os) const override;

    string getSize();

    string getBrand();
    
    private:
    string size_;
    string brand_;
    
  };
