//! Unit Tests for MPAGSCipher CaesarCipher Class
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "VigenereCipher.hpp"


//change the output string
TEST_CASE("Vigenere Cipher encryption", "[playfair]") {
  VigenereCipher cc{"vigeneretest"};
  REQUIRE( cc.applyCipher("YOUDBETTERWORKORILLHAVETODEBUGTHISABOUTFIVETIMESIDMUCHRATHERHAVELUNCH", CipherMode::Encrypt) == "TWAHOIKXXVOHMSUVVPCLTZWMJLKFHKKLBWSUJCZJVZVXBQWLDLSYPLIEMLWKCIBIYYEGA");
}

TEST_CASE("Vigenere Cipher decryption", "[playfair]") {
  VigenereCipher cc{"vigeneretest"};
  REQUIRE( cc.applyCipher("TWAHOIKXXVOHMSUVVPCLTZWMJLKFHKKLBWSUJCZJVZVXBQWLDLSYPLIEMLWKCIBIYYEGA", CipherMode::Decrypt) == "YOUDBETTERWORKORILLHAVETODEBUGTHISABOUTFIVETIMESIDMUCHRATHERHAVELUNCH");
}