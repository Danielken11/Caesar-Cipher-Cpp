#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <unordered_set>
#include <cctype>
#include <Windows.h>

std::string text;
std::string alphabeth = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};

int i;
int j;

 std::string text_for_decryption;

bool was_crypted = false;

//Cls function...
void clrscr(){system("cls");}

void print_start(){

    std::cout << "\n        Caesar Cipher\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n";
    std::cout << "1)Encryption\n2)Decryption\n3)Encryption 2 keys\n4)Decryption 2 keys\n5)Brute Force\n6)Exit\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n";
    
}

int print_important_info(){

    int user_input;
    std::cout << "\r\n1)Other Option\r\n2)Exit "; std::cin >> user_input;

    if(user_input == 1){
        clrscr();
        was_crypted = false;
        return 0;
    }else if (user_input == 2){
        exit(0);
    }else{
        std::cout << "\r\nError!!!";
        clrscr();
        return 0;
    }
}

std::string removeSpaces(const std::string &input) {
    std::string result = input;
    
    result.erase(std::remove(result.begin(), result.end(), ' '), result.end());
    
    return result;
}

std::string encryption_cesar(){

    int k;
    int current_number;
    int changer;
    std::string final_text;
    bool latinChars;

    while(true){
    latinChars = true;
    std::cin.ignore();
    std::cout << "Insert the text for encryption:\n"; std::getline(std::cin,text);

    std::transform(text.begin(),text.end(),text.begin(), ::toupper);

    final_text = removeSpaces(text);

    std::cout << "Inserted text: " << final_text;

       for(char chars : final_text){
        if(!std::isalpha(chars)){
            latinChars = false;
            break;
        }
       }

        if(latinChars == true){
             break;
        }else{
            std::cout << "\r\nThe word must contain letters of the Latin alphabet and must not contain numbers\nType Enter for another try...\n";
        }
    }

    while(true){
         std::cout << "\nInsert the key for the encryption from 1 to 25...\n";
         std::cin >> k;

            if( k >= 1 && k <= 25){
                break;
            }else{
                std::cout << "The key must be from 1 to 25\r\n Try again...\n";
            }

    }

    for ( i = 0; i < final_text.length(); i++){
        for ( j = 0; j < alphabeth.length(); j++ ){

            if(final_text[i] == alphabeth[j]){
                break;
            }
        }

         if (j != alphabeth.length()) {
            int current_number = j;
            int changer = (current_number + k) % alphabeth.length();

            final_text[i] = alphabeth[changer];
            was_crypted = true;
        
        }
    }

    std::cout << "\r\nAlphabeth used for encryption: \n";
    std::cout << alphabeth << "\n";
    std::cout << "\r\nEncrypted text:\n " << final_text;
    text_for_decryption = final_text;
    
    return final_text;
}

std::string decryption_cesar(){

        int k;
        int current_number;
        int changer;
        
    if(was_crypted == true){
        
        std::cout << "\r\nDo you want to decrypt the previous text? " << text_for_decryption << "\r\nType 1 if no type 2";
        int chooser;
        std::cin >> chooser;

        if(chooser == 1){
            std::cout << "\r\nInsert the key for decryption\n"; std::cin >> k;

            if (k >= 1 && k <= 25){
            for(i = 0; i < text_for_decryption.length(); i++){

                for (j = 0; j < alphabeth.length(); j++){
                     if(text_for_decryption[i] == alphabeth[j]){
                         break;
                    }   
                }

                 if (j != alphabeth.length()) {
                     int current_number = j;
                        int changer = (current_number - k + alphabeth.length()) % alphabeth.length();

                    text_for_decryption[i] = alphabeth[changer];
                }
            }

        }else{
            std::cout << "\r\nThe key must be from 1 to 25";
        }
            std::cout << "\r\nDecrypted text " << text_for_decryption << "\n";
            print_important_info();

            }else if (chooser == 2){
                was_crypted = false;
            }
        }else if (was_crypted == false){

               std::cin.ignore();
               std::string textChanger;
        std::cout << "\r\nInsert the text for decryption: "; std::getline(std::cin,textChanger);

        text_for_decryption = removeSpaces(textChanger);

         std::transform(text_for_decryption.begin(),text_for_decryption.end(),text_for_decryption.begin(), ::toupper);

        std::cout << "\r\nText for encryption: " << text_for_decryption; 

        std::cout << "\r\nInsert the key from 1 to 25: "; std::cin >> k;

        if (k >= 1 && k <= 25){
            for(i = 0; i < text_for_decryption.length(); i++){

                for (j = 0; j < alphabeth.length(); j++){
                     if(text_for_decryption[i] == alphabeth[j]){
                         break;
                    }   
                }
                 if (j != alphabeth.length()) {
                     int current_number = j;
                        int changer = (current_number - k + alphabeth.length()) % alphabeth.length();

                    text_for_decryption[i] = alphabeth[changer];
                }
            }
        }else{
            std::cout << "\r\nThe key must be from 1 to 25";
        }
            std::cout << "\r\nDecrypted text: " << text_for_decryption << "\n";
    }
    return text_for_decryption;
}

std::string cesar_encryption_brutte_force(std::string input,int k){

    std::string final_input = removeSpaces(input);
    std::transform(final_input.begin(),final_input.end(),final_input.begin(), ::toupper);

      
            for(i = 0; i < final_input.length(); i++){

                for (j = 0; j < alphabeth.length(); j++){
                     if(final_input[i] == alphabeth[j]){
                         break;
                    }   
                }
                 if (j != alphabeth.length()) {
                     int current_number = j;
                        int changer = (current_number - k + alphabeth.length()) % alphabeth.length();

                    final_input[i] = alphabeth[changer];
                }
            }
       
            std::cout << "\r\nDecrypted text: " << final_input << " Used Key: " << k;

            return final_input;
}   
//Advanced encrytion functions
std::string encryption_cesarAdvanced(){

    bool latinChars;
    int k;
    int current_number;
    int changer;
    std::string keyWord;
    std::string final_text;

    while(true){
        latinChars = true;

        std::cin.ignore();
        std::cout << "Insert the text for encryption: "; std::getline(std::cin,text);

        std::transform(text.begin(),text.end(),text.begin(), ::toupper);

        final_text = removeSpaces(text);

        std::cout << "Inserted text: " << final_text;

        for(char chars : final_text){
            if(!std::isalpha(chars)){
                latinChars = false;
                break;
            }
        }

        if(latinChars == true){
            break;
        }else{
             std::cout << "\r\nThe word must contain letters of the Latin alphabet and must not contain numbers\nPress enter to try again\n";
        }
    }

    while(true){
    
        std::cout << "\nInsert the key for encryption from 1 to 25: "; std::cin >> k;

        if(k >= 1 && k <= 25){
            break;
        }else{
            std::cout << "\r\nThe key must be from 1 to 25!!!\nTry again...\n";
        }
    }

    bool keyWordLatinChars;
    while (true){

    keyWordLatinChars = true;
    std::cin.ignore();
    std::cout << "\r\nInsert the key word that contains Latin letters with a length of 7 or higher \n";std::getline(std::cin,keyWord);
        std::transform(keyWord.begin(),keyWord.end(),keyWord.begin(), ::toupper);

        for(char chars : keyWord){
            if(!std::isalpha(chars)){
                keyWordLatinChars = false;
                break;
            }
        }

        if(keyWordLatinChars == true && keyWord.length() >= 7){
            break;
        }else{
            std::cout << "\r\nThe key word must contain Latin letters or to have a length of 7 or higher\nPress enter to try again\n";
        }
    }
    
    std::string advancedAlphabeth = keyWord + alphabeth;
    std::string alpha;
    std::unordered_set<char> char_counter;

    for(char character : advancedAlphabeth){
        if (char_counter.find(character) == char_counter.end())
        {
            alpha += character;
            char_counter.insert(character);
        }
    }

    for ( i = 0; i < final_text.length(); i++){
        for ( j = 0; j < alpha.length(); j++ ){

            if(final_text[i] == alpha[j]){
                break;
            }
        }

         if (j != alpha.length()) {
            int current_number = j;
            int changer = (current_number + k) % alpha.length();

            final_text[i] = alpha[changer];
            was_crypted = true;
        
        }
    }
      std::cout << "\r\nAlfabeth used for encryption: \n";
      std::cout << alpha << "\n";      
      std::cout << "\r\nEncrypted text:\n " << final_text;
        text_for_decryption = final_text;

    return final_text;
}

std::string decryption_cesarAdvanced(){

//this variable in case if no user have a new encrypted text for us...
        int k;
        int current_number;
        int changer;
        std::string keyWord;
        

    if(was_crypted == true){
        
        std::cout << "\r\nDo you want to decrypt the previous text?: " << text_for_decryption << "\r\nType 1 if no type 2 ";
        int chooser;
        std::cin >> chooser;

        if(chooser == 1){
            std::cout << "\r\nInsert the key for decryption: "; std::cin >> k;
             std::cin.ignore();
             std::cout << "\r\nInsert the key word\n";std::getline(std::cin,keyWord);
                std::transform(keyWord.begin(),keyWord.end(),keyWord.begin(), ::toupper);

                std::string advancedAlphabeth = keyWord + alphabeth;
                std::string alpha;
                std::unordered_set<char> char_counter;

            for(char character : advancedAlphabeth){
                 if (char_counter.find(character) == char_counter.end()){
                        alpha += character;
                        char_counter.insert(character);
                    }
                }

            if (k >= 1 && k <= 25 && keyWord.length() > 7 ){
            for(i = 0; i < text_for_decryption.length(); i++){

                for (j = 0; j < alpha.length(); j++){
                     if(text_for_decryption[i] == alpha[j]){
                         break;
                    }   
                }

                 if (j != alpha.length()) {
                     int current_number = j;
                        int changer = (current_number - k + alpha.length()) % alpha.length();

                    text_for_decryption[i] = alpha[changer];
                }
            }

        }else{
            std::cout << "\r\nThe key must be from 1 to 25!!!";
        }
            std::cout << "\r\nDecrypted text: " << text_for_decryption << "\n";
            print_important_info();

            }else if (chooser == 2){
                was_crypted = false;
            }
        }else if (was_crypted == false){

               std::cin.ignore();
               std::string textChanger;
        std::cout << "\r\nInsert the text for decryption: "; std::getline(std::cin,textChanger);
        text_for_decryption = removeSpaces(textChanger);
         std::transform(text_for_decryption.begin(),text_for_decryption.end(),text_for_decryption.begin(), ::toupper);
        std::cout << "\r\nText for decryption: " << text_for_decryption; 

        std::cout << "\r\nInsert the key from 1 to 25: "; std::cin >> k;
         std::cin.ignore();
             std::cout << "\r\nInsert the key word\n";std::getline(std::cin,keyWord);
                std::transform(keyWord.begin(),keyWord.end(),keyWord.begin(), ::toupper);

                std::string advancedAlphabeth = keyWord + alphabeth;
                std::string alpha;
                std::unordered_set<char> char_counter;

            for(char character : advancedAlphabeth){
                 if (char_counter.find(character) == char_counter.end()){
                        alpha += character;
                        char_counter.insert(character);
                    }
                }

        if (k >= 1 && k <= 25 && keyWord.length() > 7){
            for(i = 0; i < text_for_decryption.length(); i++){

                for (j = 0; j < alpha.length(); j++){
                     if(text_for_decryption[i] == alpha[j]){
                         break;
                    }   
                }
                 if (j != alpha.length()) {
                     int current_number = j;
                        int changer = (current_number - k + alpha.length()) % alpha.length();

                    text_for_decryption[i] = alpha[changer];
                }
            }
        }else{
            std::cout << "\r\nThe key must contain Latin letters with a length of 7 or higher";
        }
            std::cout << "\r\nDecrypted text: " << text_for_decryption << "\n";
    }
    return text_for_decryption;
}


int main(void){

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);

    int userInput;
    std::string text_brute; 

    while(true){

        print_start();
        std::cin >> userInput;
        
        switch(userInput){

        case 1:clrscr();encryption_cesar();break;
        case 2:clrscr();decryption_cesar(); break;
        case 3:clrscr();encryption_cesarAdvanced();break;
        case 4:clrscr();decryption_cesarAdvanced();break;
        case 5:clrscr();
            std::cout << "\r\nInsert the text for brute force: ";
                std::cin.ignore(); std::getline(std::cin,text_brute);
        
            for(int i = 1; i<26; i++){
                cesar_encryption_brutte_force(text_brute,i);
            }
            break;
        case 6:exit(0); break;
            default:std::cout << "\nError!!!" ;break;
    }
}

    return EXIT_SUCCESS;
}

