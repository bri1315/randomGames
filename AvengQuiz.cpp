//This program is just a fun quiz to test an avengers fun on their movie knowledge
//There is an array to store to make sure that the question either has or has not been asked yet
//there are also vectors to store the questions that were wrong along with what the correct answer was
//And what was the wrong answer
//

# include <iostream>
#include <ctime>
#include <random>
#include <vector>

using namespace std;
//setting up global variables used for the whole program to keep track of
//which question the user is on out of the 15 questions
//and knowing how many correct they have and how many wrong questions they have
bool asked[15] = {true,true,true,true,true,true,true,true,true,true,true,true,true,true,true};
int questionNum = 1;
int correct = 0;
int wrong = 0;
string playerName;
//will store the questions the user got wrong
vector<string> wrongQuestion;
//stores the answer the user choice for that question
vector<string> userWrongAnswer;
//Stores the correct answer for that question
vector<string> correctWrongAnswer;

void displayQuestion();
void header();
void sendQuestion(string,char,string,string,string,string);
void AvengerResults();

int main(){
  system("clear");
  cout << "HELLO THERE! THIS IS A QUIZ TO TEST YOUR STRENGHT ON THE AVENGERS 2012 MOVIE\n"
       << "TO SEE IF YOU HAVE WHAT IT TAKES TO BE AN AVENGER\n"
       << "Now enter your name Mighty Agent to test if you will be an Avenger: ";
  cin >> playerName;

  header();
  return 0;
}

void header(){
  system("clear");
  cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n"
       << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n"
       << "\t\t" << playerName << " You're on Avenger question: " << questionNum << endl
       << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n";
  displayQuestion();
}


void sendQuestion(string question,char answer,string choiceA,string choiceB,string choiceC,string choiceD){
  char userAnswer;
  cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n"
       << question << endl
       << "A)" << choiceA
       << "\t\t\tC)" << choiceC <<endl
       << "B)" << choiceB
       << "\t\t\tD)" << choiceD << endl
       << "Enter your answer: ";
       cin >> userAnswer;
  while(userAnswer != 'A' && userAnswer != 'B' && userAnswer != 'C' && userAnswer != 'D') {
         cout << "Please make sure you are entering an option and it is capitalized\n: "
              << "Please Enter Again: ";
         cin >> userAnswer;
  }
  if(userAnswer == answer)
    correct++;
  else{
    wrong++;
    wrongQuestion.push_back(question);
    if(userAnswer =='A')
      userWrongAnswer.push_back(choiceA);
    else if(userAnswer =='B')
      userWrongAnswer.push_back(choiceB);
    else if(userAnswer =='C')
      userWrongAnswer.push_back(choiceC);
    else
      userWrongAnswer.push_back(choiceD);

    if(answer =='A')
      correctWrongAnswer.push_back(choiceA);
    else if(answer =='B')
      correctWrongAnswer.push_back(choiceB);
    else if(answer =='C')
      correctWrongAnswer.push_back(choiceC);
    else
      correctWrongAnswer.push_back(choiceD);
  }
  questionNum++;
  header();
}

void displayQuestion(){
  //generating the random number to pick a random question
  srand(time(0));

  bool isThereAQuestionLeft = false;
  for(int i = 0; i < 15 ; i++){
    if(asked[i]){
      //if its true that its been asked then itll skip
      isThereAQuestionLeft = true;
      break;
    }
  }
  //as long as there are still quesions it will go through
  while(isThereAQuestionLeft){
    int currentQuestion = rand()%15;
    if(asked[currentQuestion]){
          asked[currentQuestion] = false;
          switch(currentQuestion){
            case 0:
                sendQuestion("what nick name does Iron-Man give Thor?", 'D',
                             "captain Handsom","Rock of Ages", "Captain Handsom",
                             " Point Break");
                break;
            case 1:
                sendQuestion("Where did Natasha find Bruce?", 'B',
                             "Russia", "India", "Wakanda", "Sokovia");
                break;
            case 2:
                sendQuestion("What stone is inside Lokis secpter?", 'B',
                             "Power Stone", "Mind Stone", "Reality Stone",
                             "Space Stone");
                break;
            case 3:
                sendQuestion("Who flew the missle into space?", 'A',
                             "Iron Man","Chitauri army", "Loki", "Thor");
                break;
            case 4:
                sendQuestion("What army attacked New York?", 'D',
                             "Black Order", "Leviathans", "Sakaarans Army",
                             "Chitauri army");
                break;
            case 5:
                sendQuestion("Which Avenger was mind controlled by Loki?", 'A',
                             "Hawkeye", "Black Widow", "Captain America", "Hulk");
                break;
            case 6:
                sendQuestion("What game was the agent playing instead of working?", 'C',
                             "Tertrist","Snake", "Galaga", "Pac-Man");
                break;
            case 7:
                sendQuestion("Where did Nick Furry find Captain America?", 'B',
                             "In an ice cube", "Boxing Gym", "Captain America Musuem",
                             "Barbershop Quartet");
                break;
            case 8:
                sendQuestion("Who brought in Iron-Man?",'C',
                             "Nick Furry","Natasha Romanoff","Phil Coulson","Maria Hill");
                break;
            case 9:
                sendQuestion("Where did the Avengers first fight Loki?", 'C',
                             "Sokovia", "India", "Germany"," New York");
                break;
            case 10:
                sendQuestion("Whats hulks secrete?", 'A',
                             "He's always angry", "He's always happy",
                             "Avoiding Stress", "Yoga");
                break;
            case 11:
                sendQuestion("What does thor do when he first arrives?", 'C',
                             "Get coffee", "Visit Jane", "Kidnap Loki", "Fight hulk");
                break;
            case 12:
                sendQuestion("Who has limited edition Captain America trading cards?", 'B',
                             "Tony Stark", "Phil Coulson", "Maria Hill", "Agent Galaga");
                break;
            case 13:
                sendQuestion("Which avengers fight each other for Loki?", 'A',
                             "Thor,Captain America,Iron Man", "Hulk,BlackWidow",
                             "Hulk,BlackWidow,Hawkeye",
                             "Hawkeye,Captain America,BlackWidow");
                break;
            case 14:
                sendQuestion("Which Villan did they tease at the end of the Avengers?", 'A',
                             "Thanos"," Doctor Doom","Winter Soldier", "Ultron");
                break;
        }
      }
    }
  //once there is no more question
  AvengerResults();
}

void AvengerResults(){
  system("clear");
  cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n"
       << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n"
       << "The total Avenger Questions were: 15" << endl
       << "You got: " << correct << " Correct" << endl
       << "You got: " << wrong << " wrong" << endl;
  if(correct > wrong){
    cout << "Congrats you have been promoted to an avenger in training" << endl
         << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n";
  }
  else if(correct == wrong){
    cout <<"Since you got the same amount of correct and wrong you are on a probational basis" << endl
         << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n";
  }
  else{
    cout << "So sorry you are not an avenger in training. Try again next time " << endl
         << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n";
  }

  int size = wrongQuestion.size();
  for(int i = 0; i < size; i++){
    cout << "The question you got wrong was: " << wrongQuestion[i] << endl
         << "You had entered: " << userWrongAnswer[i] << endl
         << "The correct answer was: " << correctWrongAnswer[i] << endl
         << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n"
         << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n";
  }

}
