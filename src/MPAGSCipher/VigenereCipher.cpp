// Standard library includes
#include <string>
#include <algorithm>
#include <iostream>

// Out project headers
#include "Alphabet.hpp"
#include "VigenereCipher.hpp"

VigenereCipher::VigenereCipher( const std::string& key)
{
    // Set the given key
    setKey(key);
}

void VigenereCipher::setKey( const std::string& key)
{
    // is this what we want here?
    key_=key;
}

std::string VigenereCipher::applyCipher( const std::string& inputText, const CipherMode& /*mode*/) const
{
    std::cerr << "[warning]: Vigenere cipher not applied yet, will return the original input" <<std::endl;
    return inputText;
}