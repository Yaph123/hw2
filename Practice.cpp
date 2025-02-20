
#include "product.h"
#include "util.h"
#include <string>
#include <iostream>
#include <set>
#include <fstream>
#include <iterator>
#include "Book.h"

using namespace std;

 int main(){


  ofstream of("outputFile.txt");

  Book* mybook = new Book("Harry Potter",1,1,"JK Rowling","12345");

  mybook->dump(of);

  delete mybook;

  return 0;

  }
