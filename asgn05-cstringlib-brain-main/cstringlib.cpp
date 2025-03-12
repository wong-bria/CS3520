#include "cstringlib.hpp"

namespace cstring {
  
  size_t strlen(const char *str) {
    size_t length = 0;
    while (str[length] != '\0') {
      length++;
    }
    return length;
  }
  
  char *strncpy(char *destination, const char *source, size_t num) {
    size_t i = 0;
    // Copy characters from source to destination
    for (; i < num && source[i] != '\0'; i++) {
      destination[i] = source[i];
    }
    // If source is shorter than num, pad with '\0'
    for (; i < num; i++) {
      destination[i] = '\0';
    }
    return destination;
  }

  char *strncat(char *destination, const char *source, size_t num) {
    size_t dest_len = strlen(destination);
    size_t i = 0;
    // Append characters from source to destination
    for (; i < num && source[i] != '\0'; i++) {
      destination[dest_len + i] = source[i];
    }
    // Null-terminate the destination string
    destination[dest_len + i] = '\0';
    return destination;
  }

  int strcmp(const char *str1, const char *str2) {
    size_t i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
      if (str1[i] != str2[i]) {
        // Return the difference between the first unmatched characters
        return static_cast<unsigned char>(str1[i]) - static_cast<unsigned char>(str2[i]);
      }
      i++;
    }
    // If both strings ended, they are equal
    if (str1[i] == '\0' && str2[i] == '\0') {
      return 0;
    }
    // If str1 ended, it's less than str2
    if (str1[i] == '\0') {
      return -static_cast<unsigned char>(str2[i]);
    }
    // If str2 ended, str1 is greater
    return static_cast<unsigned char>(str1[i]);
  }

  const char *strchr(const char *str, int character) {
     char ch = static_cast<char>(character);
    size_t i = 0;
    while (str[i] != '\0') {
      if (str[i] == ch) {
        return str + i;
      }
      i++;
    }
    // Check for the null terminator
    if (ch == '\0') {
      return str + i;
    }
    return nullptr;
  }

  const char *strrchr(const char *str, int character) {
    char ch = static_cast<char>(character);
    // Find the length of the string
    size_t length = 0;
    while (str[length] != '\0') {
        length++;
    }

    // Start searching from the end of the string
    for (size_t i = length; i > 0; i--) {
        if (str[i - 1] == ch) {
            return str + (i - 1);
        }
    }

    // Check if the character is the null terminator
    if (ch == '\0') {
        return str + length;
    }

    return nullptr;
}


  const char *strstr(const char *str1, const char *str2) {
    if (*str2 == '\0') {
      return str1;
    }

    size_t len1 = strlen(str1);
    size_t len2 = strlen(str2);

    if (len2 > len1) {
      return nullptr;
    }

    for (size_t i = 0; i <= len1 - len2; i++) {
      size_t j = 0;
      while (j < len2 && str1[i + j] == str2[j]) {
        j++;
      }
      if (j == len2) {
        return str1 + i;
      }
    }

    return nullptr;
  }

  char *strtok(char *str, const char *delimiters) {
    (void) str; (void) delimiters; return nullptr; // OPTIONAL (remove this line after implementing)
  }

}
