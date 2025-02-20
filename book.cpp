
#include "product.h"
#include "book.h"
#include "util.h"
#include <sstream>
#include <iomanip>

using namespace std;


Book::Book(const string& name,double price, int qty, 
             const string& authorName, const string& isbn)
            :Product("book", name, price, qty)
             ,authorName_(authorName), isbn_(isbn){}

  set<string> Book::keywords() const
  {
  set<string>newWords;
  string productName = convToLower(getName());
  set<string> key1 = parseStringToWords(productName);


  newWords.insert(isbn_);
  set<string> key2 = parseStringToWords(convToLower(authorName_));
  newWords.insert(key2.begin(),key2.end());
  newWords.insert(key1.begin(),key1.end());

  return newWords;

}

string Book::displayString() const{

  ostringstream ss;
  ss << getName() << "\n";
  ss << "Author: " << authorName_ << " ISBN: " << isbn_<< "\n";
  ss << fixed << setprecision(2) << getPrice() << " " << getQty() << " left." << endl;

  return ss.str();  
}


void Book::dump(ostream& os)const{
  os << "book\n";
  os <<  getName() << "\n";
  os << fixed << setprecision(2) << getPrice() << "\n";
  os << getQty() << "\n";
  os << isbn_ << "\n";
  os << authorName_ << "\n";
}

string Book::getAUname(){
  return authorName_;
}

string Book::getISBN(){
  return isbn_;
}

