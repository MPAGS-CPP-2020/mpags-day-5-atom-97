#include "CipherFactory.hpp"
#include "CaesarCipher.hpp"
#include "PlayfairCipher.hpp"
#include "VigenereCipher.hpp"

std::unique_ptr<Cipher> cipherFactory( const CipherType& cipher, const std::string& key)
{
    switch (cipher)
    {
    case CipherType::Caesar:
        return std::make_unique<CaesarCipher>(key);
        break;
    case CipherType::Playfair:
        return std::make_unique<PlayfairCipher>(key);
        break;
    case CipherType::Vigenere:
        return std::make_unique<VigenereCipher> (key);
        break; 
    }
    return std::unique_ptr<CaesarCipher>(); // Default which will never be executed
}