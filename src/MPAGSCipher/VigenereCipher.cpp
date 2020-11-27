// Standard library includes
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
    // Store the key
    key_=key;

    // Remove non-alphabet characters
    key_.erase( std::remove_if( std::begin(key_), std::end(key_), [](char c){ return !std::isalpha(c); } ),
              std::end(key_) );

    // Make sure the key is uppercase 
    std::transform( std::begin(key_), std::end(key_), std::begin(key_), ::toupper );

    // Check if the key is empty and replace with default if so
    if (key_.empty()) {
        std::cerr << "[warning]: no key supplied, will use the default option of 'DEFAULT'" << std::endl;
        key_="DEFAULT";
    }

    // Set the key length
    keySize_=key_.size();

    // Clean up the lookup map
    charLookup_.clear();

    // Create char to ensure the map does not contain copies
    std::string processedLetters{""};

    // loop over the chars in the key
    for ( char c: key_){

        // skip if the letter was already processed and add to the list if it was not
        if (processedLetters.find(c)!=std::string::npos) continue;
        processedLetters += c;

        // Find the letter position in the alphabet
        size_t pos = Alphabet::alphabet.find(c);

        // Insert an std::pair of the letter and CaesarCipher into the lookup map
        charLookup_.insert( std::pair<char,size_t>(c,pos) );
    }

}

std::string VigenereCipher::applyCipher( const std::string& inputText, const CipherMode mode) const
{
    // Set up an output string as input is a const
    std::string outputText{""};

    // For each letter (char) of the input
    for (size_t i{0}; i < inputText.size(); i++){
        // Find the corresponding in the key repeating/truncating as required
        char key_char = key_[i%keySize_];

        // Find the Caesar cipher key from the lookup map and instantiate a method
        CaesarCipher subcipher {charLookup_.at(key_char)};

        // Cast the manipulated char to string to allow for cipher handling
        std::string s{inputText[i]};

        // Run the decrytpion/encrytpion and add the result to the output
        outputText += subcipher.applyCipher(s, mode);
    }
    return outputText;
}