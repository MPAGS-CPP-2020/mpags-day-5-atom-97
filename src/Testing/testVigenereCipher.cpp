//! Unit Tests for MPAGSCipher CaesarCipher Class
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "VigenereCipher.hpp"


//change the output string
TEST_CASE("Vigenere Cipher encryption", "[playfair]") {
  VigenereCipher cc{"hello"};
  REQUIRE( cc.applyCipher("THEVIGENRECIPHERISCORRECTLYIMPLEMENTEDONEZEROZEROPERCENT", CipherMode::Encrypt) == "FHIQXLTLKLTLSUFNPQPKETFENIOLVSWLTFIAFTLAKOWATEQOKPPA");
}

TEST_CASE("Vigenere Cipher decryption", "[playfair]") {
  VigenereCipher cc{"hello"};
  REQUIRE( cc.applyCipher("FHIQXLTLKLTLSUFNPQPKETFENIOLVSWLTFIAFTLAKOWATEQOKPPA", CipherMode::Decrypt) == "THEVIGENRECIPHERISCORRECTLYIMPLEMENTEDONEZEROZEROPERCENT");
}