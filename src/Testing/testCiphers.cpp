//! Unit Tests for all MPAGSCipher *Cipher Classes
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "CaesarCipher.hpp"
#include "PlayfairCipher.hpp"
#include "VigenereCipher.hpp"
#include "CipherFactory.hpp"
#include <vector>

bool testCipher ( const std::unique_ptr<Cipher>& cipher, const CipherMode mode, const std::string& inputText, const std::string& outputText){
    return (cipher->applyCipher(inputText, mode)==outputText);
}

TEST_CASE("Test encryption/decryption for all three ciphers", "[cipher]"){
    std::vector<std::unique_ptr<Cipher>> ciphers;
    std::vector<std::string> plainText;
    std::vector<std::string> codedText;

    ciphers.push_back(cipherFactory(CipherType::Caesar, "10"));
    ciphers.push_back(cipherFactory(CipherType::Playfair, "hello"));
    ciphers.push_back(cipherFactory(CipherType::Vigenere, "vigeneretest"));

    plainText.push_back("HELLOWORLD");
    codedText.push_back("ROVVYGYBVN");
    plainText.push_back("BOBISSOMESORTOFJUNIORCOMPLEXXENOPHONEONEZEROTHING");
    codedText.push_back("FHIQXLTLKLTLSUFNPQPKETFENIOLVSWLTFIAFTLAKOWATEQOKPPA");
    plainText.push_back("YOUDBETTERWORKORILLHAVETODEBUGTHISABOUTFIVETIMESIDMUCHRATHERHAVELUNCH");
    codedText.push_back("TWAHOIKXXVOHMSUVVPCLTZWMJLKFHKKLBWSUJCZJVZVXBQWLDLSYPLIEMLWKCIBIYYEGA");
    std::vector<std::string> decodedText{plainText};
    decodedText[1]="BOBISXSOMESORTOFIUNIORCOMPLEXQXENOPHONEONEZEROTHINGZ";

    for (size_t i{0}; i<ciphers.size(); i++){
        REQUIRE( testCipher(ciphers[i], CipherMode::Encrypt, plainText[i], codedText[i]) );
        REQUIRE( testCipher(ciphers[i], CipherMode::Decrypt, codedText[i], decodedText[i]) );
    }

}
