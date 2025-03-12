#include "Document.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;



string tolower(const string & str) {
  // TODO
  std::string result;
  result.reserve(str.size());
  for (std::string::const_iterator it = str.begin(); it != str.end(); ++it) {
    //result += std::tolower(*it); // might not be allowed to use tolower and must do manually
    char lowerChar = *it;
        if (lowerChar >= 'A' && lowerChar <= 'Z') {
            lowerChar = lowerChar + ('a' - 'A'); // Convert to lowercase
        }
        result += lowerChar;
  }
  return result;
}

void read_documents(const vector<DocumentName> & documentNames, vector<Document> & documents) {
  // TODO
  // (void) documentNames;
  // (void) documents;
  for (std::vector<DocumentName>::const_iterator it = documentNames.begin(); it != documentNames.end(); ++it) {
        Document doc;
        if (read_document(*it, doc)) {
            documents.push_back(doc);
        }
    }
}

bool read_document(const DocumentName & documentName, Document & document) {
  // TODO
  // (void) documentName;
  // (void) document;
  // return false;
  std::string filePath = "doc/" + documentName + ".txt";
  std::ifstream file(filePath.c_str());

  if (!file.is_open()) {
      return false;
  }

  document.documentName = documentName;
  std::string line;

  // Read the document line by line
  while (std::getline(file, line)) {
       // Skip lines that are comments
      if (!line.empty() && line[0] == '#') {
          continue;
      }
      
      std::istringstream lineStream(line);
      std::string word;
      // Extract each word, convert to lowercase, and store it
      while (lineStream >> word) {
          document.words.push_back(tolower(word));
      }
  }

  return true;
}

void display_document(const Document & document) {
  // TODO
  // (void) document;
  std::cout << "document: " << document.documentName << std::endl;
  for (std::vector<Word>::const_iterator it = document.words.begin(); it != document.words.end(); ++it) {
      std::cout << "word: " << *it << std::endl;
  }
}
