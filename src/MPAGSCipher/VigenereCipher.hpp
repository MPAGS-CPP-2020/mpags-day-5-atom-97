#ifndef MPAGSCIPHER_VIGENERECIPHER_HPP
#define MPAGSCIPHER_VIGENERECIPHER_HPP

// Standard library includes
#include <string>


// Our project headers
#include "CipherMode.hpp"

/**
 * \file VigenereCipher.hpp
 * \brief Contains the declaration of the VigenereCipher class
 */

/**
 * \class VigenereCipher
 * \brief Encrypt or decrypt text using the Vigenere (Bellaso) cipher with the given key
 */
class VigenereCipher {
  public:

    /**
     * Create a new VigenereCipher with the given key
     *
     * \param key the key to use in the cipher
     */
    VigenereCipher( const std::string& key );

    /**
     * Set the key to be used for the encryption/decryption
     *
     * \param key the key to use in the cipher
     */    
    void setKey( const std::string& key);

    /**
     * Apply the cipher to the provided text
     *
     * \param inputText the text to encrypt or decrypt
     * \param cipherMode whether to encrypt or decrypt the input text
     * \return the result of applying the cipher to the input text
     */
    std::string applyCipher( const std::string& inputText, const CipherMode& cipherMode ) const;

  private:
    /// The cipher key, essentially a constant shift to be applied
    std::string key_ = 0;
};

#endif