

#include <string>
#include <set>
#include <vector>
#include <map>
#include "product.h"
#include "user.h"
#include "datastore.h"
#include "util.h"

using namespace std;

class myDataStore : public DataStore {
public:

  myDataStore();

 ~myDataStore();

  void addProduct(Product* p);

  void addUser(User* u);

  vector<Product*> search(vector<string>& terms, int type);

  void dump(ostream& ofile);

  void addToCart(const string& userName, Product* product);

  void viewCart(const string& userName);

  void buyCart(const string& userName);

  void quit( const string& fileName);

private:

  vector<Product*>allProducts_;
  vector<Product*>lastSearch;
  vector<User*>allUsers_;
  map<string, set<Product*>> keywords_to_product;
  map<string, vector<Product*>> userCarts_;

};