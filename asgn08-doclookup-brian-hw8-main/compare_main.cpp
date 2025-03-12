#include "Document.hpp"
#include "Lookup.hpp"
#include <string>
using namespace std;



// TODO: change these as needed
const DocumentName docname = "primes_small";
const int iterations = 1000;
//const DocumentName docname = "primes_large";
//const int iterations = 1;
const Word nonexistent_word = "bbbbbbbbbbbbrrrrrrrrrrrriannn";



void use_vector(const Document & doc) {
  for (int ii = 0; ii < iterations; ++ ii) {
    // TODO
    VectorCollection collection;
    add_document(doc, collection);
    lookup_word(nonexistent_word, collection);
  }
}

void use_list(const Document & doc) {
  for (int ii = 0; ii < iterations; ++ ii) {
    // TODO
    ListCollection collection;
    add_document(doc, collection);
    lookup_word(nonexistent_word, collection);
  }
}

void use_map(const Document & doc) {
  for (int ii = 0; ii < iterations; ++ ii) {
    // TODO
    MapCollection collection;
    add_document(doc, collection);
    lookup_word(nonexistent_word, collection);
  }
}



int main() {
  Document document;
  read_document(docname, document);

  use_vector(document);
  use_list(document);
  use_map(document);
}
