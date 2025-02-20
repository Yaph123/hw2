
#include <string>
#include <set>
#include <vector>
#include <fstream>
#include "product.h"
#include "user.h"
#include "datastore.h"
#include "mydatastore.h"


myDataStore::myDataStore()
{

}

myDataStore::~myDataStore()
{
  for(Product* p : allProducts_){
    delete p;
  }
  for(User* u: allUsers_){
    delete u;
  }
}

void myDataStore::addProduct(Product* p)
{
  if(p == nullptr){
    return;
  }
  allProducts_.push_back(p);

  set<string> key_ = p->keywords();

  for(set<string>::iterator it = key_.begin(); it != key_.end(); ++it){
    keywords_to_product[*it].insert(p);
  }
}

void myDataStore::addUser(User* u)
{
  if(u == nullptr){
    return;
  }
  allUsers_.push_back(u);


}

vector<Product*> myDataStore::search(vector<string>& terms, int type)
{
     set<Product*> finalSet;
     lastSearch.clear();
     bool firstMatch = true;

  for(vector<string>::iterator it = terms.begin(); it != terms.end(); ++it){
        string lowerTerms = convToLower(*it);
      map<string, set<Product*>>::iterator search = keywords_to_product.find(lowerTerms);
      if(search == keywords_to_product.end()){
        continue;
      }
      set<Product*> match = search->second;

      if(firstMatch){
        finalSet = match;
        firstMatch = false;
      }
      else if (type == 0){
        finalSet = setIntersection(finalSet,match);
      }
      else if(type == 1){
        finalSet = setUnion(finalSet,match);
      } 
  }
      if(finalSet.empty()){
       return vector<Product*>();
      }

      lastSearch.assign(finalSet.begin(), finalSet.end());

   return lastSearch;

}

void myDataStore::dump(ostream& ofile)
{
  ofile << "<products>" << endl;
    for(size_t i = 0; i < allProducts_.size(); i++){
      (allProducts_[i])->dump(ofile);
  }
  ofile <<"</products>" << endl;
  ofile <<"<users>"<< endl;
  for(size_t i = 0; i < allUsers_.size(); i++){
          (allUsers_[i])->dump(ofile);
  }
  ofile<<"</users>" << endl;
}

void myDataStore::addToCart(const string& userName, Product* product)
{
  string lowerUserName = convToLower(userName);
  User* findUser = nullptr;

  for(User* user : allUsers_){
    if(convToLower(user->getName())== lowerUserName){
      findUser = user;
      break;
    }
  }

  if(!findUser || product == nullptr){
    cout << "Invalid request" << endl;
    return;
  }

  if(userCarts_.find(lowerUserName) == userCarts_.end()){
    userCarts_[lowerUserName] = vector<Product*>();
  }
  userCarts_[lowerUserName].push_back(product);
}

void myDataStore::viewCart(const string& userName)
{
  string lowUserName = convToLower(userName);
  User* findUser = nullptr;

  for(User* user : allUsers_){
      if(convToLower(user->getName()) == lowUserName){
        findUser = user;
        break;
      }
  }

  if(!findUser){
    cout << "Invalid Username" << endl;
    return;
  }

  vector<Product*>& cart = userCarts_[lowUserName];



  if(cart.empty()){
    cout << lowUserName <<"'s cart is empty" << endl;
    return;
  }
   
   for(size_t i = 0; i < cart.size(); i++){
    cout <<"Item " << i + 1 << ":" << endl;
    cout << cart[i]->displayString() << endl;
   }
}

void myDataStore::buyCart(const string& userName)
{


   string lowUserName = convToLower(userName);
   User* findUser = nullptr;

  for(size_t i = 0; i < allUsers_.size(); i++){
    if(convToLower(allUsers_[i]->getName()) == lowUserName){
       findUser = allUsers_[i];
        break;
    }
  }

  if(!findUser){
    cout <<"Invalid Username" << endl;
    return;
  }

  vector<Product*>& cart = userCarts_[lowUserName];
  vector<Product*> newCart;

  for(size_t i = 0; i < cart.size();){
    Product* product = cart[i];
  
    if(product->getQty() > 0 && findUser->getBalance() >= product->getPrice()){
      product->subtractQty(1);
      findUser->deductAmount(product->getPrice());

      cart.erase(cart.begin() + i);
    }
    else{
          i++;
    }
  }
}

void myDataStore::quit(const string& fileName){
    ofstream of(fileName);

    if(!of){
      return;
    }

    dump(of);
    of.close();
}


