#include "product.h"
#include "movie.h"
#include "util.h"
#include <sstream>
#include <iomanip>

using namespace std;


Movie::Movie(const string& name, double price, int qty, 
             const string& genre, const string& rating)
            :Product("movie", name, price, qty)
            ,  genre_(genre), rating_(rating){}

  set<string> Movie::keywords() const{

  set<string>newWords;


  set<string> key = parseStringToWords(genre_);
  newWords.insert(key.begin(),key.end());

  set<string> key1 = parseStringToWords(getName());
  newWords.insert(key1.begin(),key1.end());

  return newWords;

}

string Movie::displayString() const{

  ostringstream ss;
  ss << getName() << "\n";
  ss << "Genre: " << genre_ << " Rating: " << rating_<< "\n";
  ss << fixed << setprecision(2) << getPrice() << " " << getQty() << " left." << endl;

  return ss.str();  

}

void Movie::dump(ostream& os) const{
  os << "movie\n";
  os << name_ << "\n";
  os << price_ << "\n";
  os << qty_ << "\n";
  os << genre_ << "\n";
  os << rating_ << "\n";
}

string Movie::getRating(){
  return rating_;
}

string Movie::getGenre(){
  return genre_;
}