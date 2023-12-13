#include <iostream>

int main(){
    std::string quizz[] = {
                            "1. What is the country with more gold: ",
                           "2. Who is the president of South Africa: ",
                           "3. Which rapper got the juice: ",
                           "4. How many years until next world cup: "};

    std::string options[][4] = {{"A. South Africa", "B. Namibia", "C. Mozabiqwe", "D. Gauteng"},
                               {"A. Julius Malema", "B. George Mabuza", "C. Herman", "D. Cyril Ramaphosa"},
                               {"A. Nasty C", "B. Cassper", "C. Emtee", "D. Areece"},
                               {"A. 3 years", "B. 4 years", "C. 7 years", "D. 5 years" }};

    char answerKey[] = {'C', 'B', 'C', 'D'};

    int size = sizeof(quizz)/sizeof(quizz[0]);
    char guess;
    int score;

    for(int i = 0; i < size; i++){
        std::cout << "################################"n\";
        std::cout << quizz[i] << "n\";
        std::cout << "####################################n\";
             

    }


    
    
    return 0;
}--