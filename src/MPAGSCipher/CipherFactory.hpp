#ifndef CIPHERFACTORY_HPP
#define CIPHERFACTORY_HPP

#include <memory>
#include "Cipher.hpp"
#include "CipherType.hpp"

/**
 * \file CipherFactory.hpp
 * \brief Contains the declaration of the cipherFactory function
 */

/**
 * \fn cipherFactory
 * \brief Creates an instance of a cipher and returns a unique pointer of the Cipher pABC 
 * 
 * \param type cipher type to be created
 * \param key cipher key to be used
 * \return unique pointer of the Cipher pABC
 */

std::unique_ptr<Cipher> cipherFactory(const CipherType& type, const std::string& key);

#endif