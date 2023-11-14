#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <unordered_set>

//global variables...

std::string text;
std::string alphabeth = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};

int i;
int j;

 std::string text_for_decryption;

bool was_crypted = false;

//cls function for normal navigation inside the console...
void clrscr(){system("cls");}

void print_start(){

    std::cout << "\n        Cifrul Cezar\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n";
    std::cout << "1)Criptare 1 cheie\n2)Decriptare 1 cheie\n3)Criptare 2 chei\n4)Decriptare 2 chei\n5)Brute Force\n6)Iesire\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n";
    
}

int print_important_info(){
    int user_input;
    std::cout << "\r\n1)Alta optiune\r\n2)Esire "; std::cin >> user_input;

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

    std::cin.ignore();
    std::cout << "Introduceti textul dorit criptarii: "; std::getline(std::cin,text);

    std::transform(text.begin(),text.end(),text.begin(), ::toupper);

    std::string final_text = removeSpaces(text);

    std::cout << "Textul Introdus: " << final_text;

    int k;
    int current_number;
    int changer;

    std::cout << "\nIntroduceti cheia pentru criptare de la 1 pana la 25: "; std::cin >> k;

    if (k >= 1 && k <= 25){

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

    }else{

        std::cout << "\r\nCheia trebuie sa fie de la 1 pana la 25!!!";
    }

    std::cout << "\r\nTextul criptat:\n " << final_text;
    text_for_decryption = final_text;
    
    return final_text;
}

std::string decryption_cesar(){

//this variable in case if no user have a new encrypted text for us...
        int k;
        int current_number;
        int changer;
        

    if(was_crypted == true){
        
        std::cout << "\r\nDoriti sa decriptati textul criptat anterior: " << text_for_decryption << "\r\napasati 1 daca nu apasati 2 ";
        int chooser;
        std::cin >> chooser;

        if(chooser == 1){
            std::cout << "\r\nIntroduceti cheia necesa decriptarii: "; std::cin >> k;

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
            std::cout << "\r\nCheia trebuie sa fie de la 1 pana la 25!!!";
        }
            std::cout << "\r\nTextul decriptat este: " << text_for_decryption << "\n";
            print_important_info();

            }else if (chooser == 2){
                was_crypted = false;
            }
        }else if (was_crypted == false){

               std::cin.ignore();
               std::string textChanger;
        std::cout << "\r\nIntroduceti textul dorit decriptarii: "; std::getline(std::cin,textChanger);
        text_for_decryption = removeSpaces(textChanger);
         std::transform(text_for_decryption.begin(),text_for_decryption.end(),text_for_decryption.begin(), ::toupper);
        std::cout << "\r\nTextul pentru decriptare: " << text_for_decryption; 

        std::cout << "\r\nIntroduceti cheia de la 1 pana la 25: "; std::cin >> k;

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
            std::cout << "\r\nCheia trebuie sa fie de la 1 pana la 25!!!";
        }
            std::cout << "\r\nTextul decriptat este: " << text_for_decryption << "\n";
    }
    return text_for_decryption;
}

std::string cesar_encryption_brutte_force(std::string input,int k){

    std::string final_input = removeSpaces(input);
    std::transform(final_input.begin(),final_input.end(),final_input.begin(), ::toupper);

      if (k >= 1 && k <= 25){
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
        }else{
            std::cout << "\r\nCheia trebuie sa fie de la 1 pana la 25!!!";
        }
            std::cout << "\r\nTextul decriptat este: " << final_input << " Cheia utilizata este: " << k;

            return final_input;
}   
//Functiile pentru criptare si decriptare avansata a cifrului caesar cu 2 chei , una dintre care va face parte din alfabet fiind un cuvant secret...
std::string encryption_cesarAdvanced(){

    std::cin.ignore();
    std::cout << "Introduceti textul dorit criptarii: "; std::getline(std::cin,text);

    std::transform(text.begin(),text.end(),text.begin(), ::toupper);

    std::string final_text = removeSpaces(text);

    std::cout << "Textul Introdus: " << final_text;

    int k;
    int current_number;
    int changer;
    std::string keyWord;

    std::cout << "\nIntroduceti cheia pentru criptare de la 1 pana la 25: "; std::cin >> k;
    std::cin.ignore();
    std::cout << "\r\nIntroduceti cuvantul cheie format din literele alfabetului latin cu o lungime nu mai mica de 7";std::getline(std::cin,keyWord);
    std::transform(keyWord.begin(),keyWord.end(),keyWord.begin(), ::toupper);

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

    if (k >= 1 && k <= 25 && keyWord.length() > 7){

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
      std::cout << "\r\nTextul criptat:\n " << final_text;
        text_for_decryption = final_text;

    }else{

        std::cout << "\r\nCheia trebuie sa fie de la 1 pana la 25 si cuvantul cheie mai mare de 7 caractere";
    }

    
    return final_text;
}

std::string decryption_cesarAdvanced(){

//this variable in case if no user have a new encrypted text for us...
        int k;
        int current_number;
        int changer;
        std::string keyWord;
        

    if(was_crypted == true){
        
        std::cout << "\r\nDoriti sa decriptati textul criptat anterior: " << text_for_decryption << "\r\napasati 1 daca nu apasati 2 ";
        int chooser;
        std::cin >> chooser;

        if(chooser == 1){
            std::cout << "\r\nIntroduceti cheia necesa decriptarii: "; std::cin >> k;
             std::cin.ignore();
             std::cout << "\r\nIntroduceti cuvantul cheie\n";std::getline(std::cin,keyWord);
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
            std::cout << "\r\nCheia trebuie sa fie de la 1 pana la 25 si cuvantul cheie mai mare de 7 caractere";
        }
            std::cout << "\r\nTextul decriptat este: " << text_for_decryption << "\n";
            print_important_info();

            }else if (chooser == 2){
                was_crypted = false;
            }
        }else if (was_crypted == false){

               std::cin.ignore();
               std::string textChanger;
        std::cout << "\r\nIntroduceti textul dorit decriptarii: "; std::getline(std::cin,textChanger);
        text_for_decryption = removeSpaces(textChanger);
         std::transform(text_for_decryption.begin(),text_for_decryption.end(),text_for_decryption.begin(), ::toupper);
        std::cout << "\r\nTextul pentru decriptare: " << text_for_decryption; 

        std::cout << "\r\nIntroduceti cheia de la 1 pana la 25: "; std::cin >> k;
         std::cin.ignore();
             std::cout << "\r\nIntroduceti cuvantul cheie\n";std::getline(std::cin,keyWord);
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
            std::cout << "\r\nCheia trebuie sa fie de la 1 pana la 25 si cuvantul cheie mai mare de 7 caractere";
        }
            std::cout << "\r\nTextul decriptat este: " << text_for_decryption << "\n";
    }
    return text_for_decryption;
}


int main(void){

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
            std::cout << "\r\nIntrodu textul pentru brute force: ";
                std::cin.ignore(); std::getline(std::cin,text_brute);
        
            for(int i = 0; i<26; i++){
                cesar_encryption_brutte_force(text_brute,i);
            }
            break;
        case 6:exit(0); break;
            default:std::cout << "\nError!!!" ;break;
    }
}

    return EXIT_SUCCESS;
}
