


#include "product.h"
#include "clothing.h"
#include "util.h"
#include <sstream>
#include <iomanip>

using namespace std;


Clothing::Clothing(const string& name, double price, int qty, 
              const string& size, const string& brand)
            :Product("clothing", name, price, qty)
             ,size_(size),brand_(brand){}

  set<string> Clothing::keywords() const{
  set<string>newWords;

  set<string>key1 = parseStringToWords(brand_);
  newWords.insert(key1.begin(),key1.end());

  string productName = getName();
  set<string> key2 = parseStringToWords(productName);

  newWords.insert(key2.begin(),key2.end());
  
  return newWords;
}

string Clothing::displayString()const{

  ostringstream ss;
  ss << getName() << "\n";
  ss << "Size: " << size_ << " Brand: " << brand_<< "\n";
  ss << fixed << setprecision(2) << getPrice() << " " << getQty() << " left." << endl;

  return ss.str();  
}

void Clothing::dump(ostream& os) const{
  os << "clothing\n";
  os << name_ << "\n";
  os << price_ << "\n";
  os << qty_ << "\n";
  os << size_ << "\n";
  os << brand_ << "\n";
}

string Clothing::getSize(){
  return size_;
}

string Clothing::getBrand(){
  return brand_;
}




