#ifndef CIPHER_HPP
#define CIPHER_HPP

#include <string>
#include "CipherMode.hpp"

/**
 * \file Cipher.hpp
 * \brief Contains the declaration of the Cipher class
 */

/**
 * \class Cipher
 * \brief Enable handling of all the implemented ciphers through this purely abstract class
 */

class Cipher {
    public:

        // Set of default constructors and assignement operators
        Cipher() = default;
        Cipher(const Cipher& rhs) = default;
        Cipher(Cipher && rhs) = default;
        Cipher& operator=(const Cipher& rhs) = default;
        Cipher& operator=(Cipher&& rhs) = default;
        // Virtual destructor 
        virtual ~Cipher() = default;

    /**
     * A purely virtual handle for using the functions that apply specific ciphers  
     *
     * \param inputText the text to encrypt or decrypt
     * \param cipherMode whether to encrypt or decrypt the input text
     * \return the result of applying a cipher to the input text
     */
        virtual std::string applyCipher(const std::string& input, const CipherMode mode) const = 0; 
};
#endif