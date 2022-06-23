#include <iostream>
#include <string>
#include <regex>//redular expressions
#include <map>//method of keeping

using namespace std;

//questions and answers
map<string, string> questions_answers{
    {"Hello", "Hi, How are you"},
    {"What is your name", "My name is Albina"},
    {"How.*do.*you.*do", "I'm bored"},
    {"What are you bored","Unswering stupid questions"},
    {".*What.*are you doing","Unswering stupid questions"}
    //{"What the weather like in (:city:\w+)","Too complicated, lol"}
};


//function for bot-speaking
string bot_reply(string input_text){
    //item includes (question + answer)-paar
    for (auto item : questions_answers)
    {
        regex pattern = regex(".*" + item.first + ".*", regex_constants::icase);

        //regex pattern = regex(".*hello.*", regex_constants::icase);//any symbol numbers + hello + any symbol numbers
                                        //ignore all exept "hello" 
        //if (input_text == "Hello"){
        if (regex_match(input_text, pattern)){
            //return "Nice to see you!";
            return item.second;
        }

    }
    return "Fuck off hooman";
}

int main(){

    cout << "Hello Skillbox, my name is Albina!" << endl;
    cout << "I'm your smart Chat Bot :" << endl;

    string user_text;

    while(user_text != "exit")
    {
        getline(cin, user_text);//to read from cin to user_text
        cout << bot_reply(user_text) << endl;//function for bot-speaking is running
    }


    cout << user_text;

    return 0;
}