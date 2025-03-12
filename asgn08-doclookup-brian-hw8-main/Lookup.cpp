#include "Lookup.hpp"
using namespace std;



void
add_document(const Document & doc, VectorCollection & collection) {
  // TODO: go through each word in the document
  // TODO: see if the word already has an entry in the collection
  // TODO: if it is, update its entry to include the current document name
  // TODO: otherwise, make a new entry for the word (and current document name)
  for (vector<Word>::const_iterator word_it = doc.words.begin(); word_it != doc.words.end(); ++word_it) {
    Word lower_word = tolower(*word_it);
    bool found = false;

    for (VectorCollection::iterator entry_it = collection.begin(); entry_it != collection.end(); ++entry_it) {
      if (entry_it->word == lower_word) {
        entry_it->documentNames.insert(doc.documentName);
        found = true;
        break;
      }
    }

    if (!found) {
      Entry new_entry;
      new_entry.word = lower_word;
      new_entry.documentNames.insert(doc.documentName);
      collection.push_back(new_entry);
    }
  }
}

Results
lookup_word(const Word & word, const VectorCollection & collection) {
  Results ret;

  // TODO: see if the word has an entry in the collection
  // TODO: if so, add all of the entry's document names to the results
  Word lower_word = tolower(word);  // Convert the search word to lowercase


  for (VectorCollection::const_iterator entry_it = collection.begin(); entry_it != collection.end(); ++entry_it) {
    if (entry_it->word == lower_word) {
      ret.insert(ret.end(), entry_it->documentNames.begin(), entry_it->documentNames.end());
      break;
    }
  }

  return ret;
}



void
add_document(const Document & doc, ListCollection & collection) {
  // TODO
  for (std::vector<Word>::const_iterator word_it = doc.words.begin(); word_it != doc.words.end(); ++word_it) {
    Word lower_word = tolower(*word_it); // Convert each word to lowercase
    bool found = false;

    for (ListCollection::iterator entry_it = collection.begin(); entry_it != collection.end(); ++entry_it) {
      if (entry_it->word == lower_word) {
        entry_it->documentNames.insert(doc.documentName);
        found = true;
        break;
      }
    }

    if (!found) {
      Entry new_entry;
      new_entry.word = lower_word;
      new_entry.documentNames.insert(doc.documentName);
      collection.push_back(new_entry);
    }
  }
}

Results
lookup_word(const Word & word, const ListCollection & collection) {
  Results ret;

  // TODO
    Word lower_word = tolower(word);  // Convert the search word to lowercase

  for (ListCollection::const_iterator entry_it = collection.begin(); entry_it != collection.end(); ++entry_it) {
    if (entry_it->word == lower_word) {
      ret.insert(ret.end(), entry_it->documentNames.begin(), entry_it->documentNames.end());
      break;
    }
  }

  return ret;
}



void
add_document(const Document & doc, MapCollection & collection) {
  // TODO
  for (vector<Word>::const_iterator word_it = doc.words.begin(); word_it != doc.words.end(); ++word_it) {
    Word lower_word = tolower(*word_it);
    
    MapCollection::iterator map_it = collection.find(lower_word);
    if (map_it != collection.end()) {
      map_it->second.documentNames.insert(doc.documentName);
    } else {
      Entry new_entry;
      new_entry.word = lower_word;
      new_entry.documentNames.insert(doc.documentName);
      collection[lower_word] = new_entry;
    }
  }
}

Results
lookup_word(const Word & word, const MapCollection & collection) {
  Results ret;

  // TODO
    Word lower_word = tolower(word);  // Convert the search word to lowercase

  MapCollection::const_iterator map_it = collection.find(lower_word);
  if (map_it != collection.end()) {
    ret.insert(ret.end(), map_it->second.documentNames.begin(), map_it->second.documentNames.end());
  }

  return ret;
}
