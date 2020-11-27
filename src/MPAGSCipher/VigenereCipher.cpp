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

    // Make sure the key is uppercase 
    std::transform( std::begin(key_), std::end(key_), std::begin(key_), ::toupper );

    // Check if the key is empty and replace with default if so
    if (key_.empty()) {
        std::cerr << "[warning]: no key supplied, will use the default option of 'DEFAULT'" << std::endl;
        key_="DEFAULT";
    }

    // Set the key length
    keySize_=key_.size();

    // loop over the chars in the key
    for ( char c: key_){
        // Find the letter position in the alphabet
        size_t pos = Alphabet::alphabet.find(c);

        // Create a Caesar cipher using this position as a key
        CaesarCipher caesar{pos};

        // Insert an std::pair of the letter and CaesarCipher into the lookup map
        charLookup_.insert( std::pair<char,CaesarCipher>(c,caesar) );
    }

}

std::string VigenereCipher::applyCipher( const std::string& inputText, const CipherMode& mode) const
{
    // Set up an output string as input is a const
    std::string outputText{""};

    // For each letter (char) of the input
    for (size_t i{0}; i < inputText.size(); i++){
        // Find the corresponding in the key repeating/truncating as required
        char key_char = key_[i%keySize_];

        // Find the Caesar cpher from the lookup map
        CaesarCipher subcipher = charLookup_.at(key_char);

        // Cast the manipulated char to string to allow for cipher handling
        std::string s{inputText[i]};

        // Run the decrytpion/encrytpion and add the result to the output
        outputText += subcipher.applyCipher(s, mode);
    }
    return outputText;
}