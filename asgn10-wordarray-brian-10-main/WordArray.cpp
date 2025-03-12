#include "WordArray.hpp"
#include <cstring>
using namespace std;



size_t
WordArray::countWords(char * words)
{
  if (!words || *words == '\0') return 0;
    size_t count = 0;
    bool inWord = false;
    for (char *p = words; *p != '\0'; ++p) {
        if (*p != ' ' && !inWord) {
            inWord = true;
            ++count;
        } else if (*p == ' ') {
            inWord = false;
        }
    }
    return count;
}

void
WordArray::initialize(size_t maxWords)
{
  m_maxWords = maxWords;
    m_numWords = 0;

    // allocate memory for the array
    m_array = new char*[m_maxWords];
    
    for (size_t i = 0; i < m_maxWords; ++i) {
        m_array[i] = nullptr;
    }
}

void
WordArray::appendWords(char * words)
{
  if (!words) return;

    char *token = strtok(words, " ");
    while (token != nullptr) {
        if (m_numWords < m_maxWords) {
            m_array[m_numWords] = new char[strlen(token) + 1];
            strcpy(m_array[m_numWords], token);
            ++m_numWords;
        } else {
            // m_numWords exceeds m_maxWords, so resize the array
            increaseMaxWords(m_numWords + 1);
            m_array[m_numWords] = new char[strlen(token) + 1];
            strcpy(m_array[m_numWords], token);
            ++m_numWords;
        }
        token = strtok(nullptr, " "); // move to next word
    }
}


void
WordArray::increaseMaxWords(size_t newMax)
{
    if (newMax <= m_maxWords) return;
    
    // allocate new memory and copy existing words
    char **newArray = new char*[newMax];

    // copy current words into the new array
    for (size_t i = 0; i < m_numWords; ++i) {
        newArray[i] = m_array[i];
    }

    // make new slots nullptr
    for (size_t i = m_numWords; i < newMax; ++i) {
        newArray[i] = nullptr;
    }

    delete[] m_array;
    m_array = newArray;
    m_maxWords = newMax;
}





WordArray::WordArray(size_t maxWords)
{
    m_maxWords = maxWords;
    m_numWords = 0;
    m_array = new char*[m_maxWords];
    for (size_t i = 0; i < m_maxWords; ++i) {
        m_array[i] = nullptr;
    }
}

WordArray::WordArray(const char * words)
{
  if (!words) {
        m_maxWords = 0;
        m_numWords = 0;
        m_array = nullptr;
        return;
    }

    char *temp = new char[strlen(words) + 1];
    strcpy(temp, words);
    m_maxWords = countWords(temp);
    m_numWords = 0;

    m_array = new char*[m_maxWords];
    for (size_t i = 0; i < m_maxWords; ++i) {
        m_array[i] = nullptr;
    }

    appendWords(temp); 
    delete[] temp;
}

WordArray::~WordArray()
{
  // TODO
  for (size_t i = 0; i < m_numWords; ++i) {
    delete[] m_array[i];
  } 
  delete[] m_array;
}

std::ostream &
WordArray::print(std::ostream & os) const
{
  for (size_t i = 0; i < m_numWords; ++i) {
    os << m_array[i];
    if (i < m_numWords - 1) {
      os << " ";
    }
  }
  os << "\n";
  return os;
}

const char *
WordArray::findFirst(const char * word) const
{
  for (size_t i = 0; i < m_numWords; ++i) {
        if (strcmp(m_array[i], word) == 0) {
            return m_array[i];
        }
    }
    return nullptr;
}

size_t
WordArray::removeAll(const char * word)
{
  size_t removedCount = 0;
    for (size_t i = 0; i < m_numWords; ) {
        if (strcmp(m_array[i], word) == 0) {
            delete[] m_array[i];
            for (size_t j = i; j < m_numWords - 1; ++j) {
                m_array[j] = m_array[j + 1];
            }
            m_array[m_numWords - 1] = nullptr;
            --m_numWords;
            ++removedCount;
        } else {
            ++i;
        }
    }
    return removedCount;
}

void
WordArray::append(const WordArray & src)
{
  if (src.m_numWords == 0) return;

    size_t newNumWords = m_numWords + src.m_numWords;

    // ensure there's enough space for the new words
    if (newNumWords > m_maxWords) {
        increaseMaxWords(newNumWords);
    }

    appendArray(src.m_array, src.m_numWords);
}

void
WordArray::appendArray(char const * const * array, size_t num)
{
  if (m_numWords + num > m_maxWords) {
        increaseMaxWords(m_numWords + num);
    }

    for (size_t i = 0; i < num; ++i) {
      const char * word = array[i];

      char * wordCopy = new char[strlen(word) + 1];
      strcpy(wordCopy, word);

      m_array[m_numWords] = wordCopy;
      ++m_numWords;
    }

}
