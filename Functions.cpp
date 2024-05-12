#include <iostream>
using namespace std;

#include "Node.h"
#include "Tree.h"
#include "constants.h"
#include "Functions.h"



bool answerIsYes() {
    string answerYes;
    getline(cin, answerYes);
    if( answerYes[0] == 'y' or answerYes[0] == 'Y' ) return true;
    else
        return false;
    }

bool playAgain() {
    string playAgain2;
    cout << "Do you want to play again? (ENTER LOWERCASE 'y' or 'n'): "; getline(cin, playAgain2);
    if ( playAgain2 == "Y" or playAgain2 == "y" )
        return true;
    else
        return false;
}

void myGuess(const Node* p) {
    cout << endl;
    cout << "Hmm... my guess is '"
         << p->GetText() << "'. Is my guess right? (Y/N): ";
}

void playGame(Node* currP, Tree &T) {
    currP = T.GetRoot();
    while (!currP->IsLeaf()) {
        cout << currP->GetText() << endl;
        if (answerIsYes()) {
            // currP = currP->YChild();
        } else {
            // currP = currP->NChild();
        }
    } // end while not at leaf node
    myGuess(currP);
    if (answerIsYes()) {
        cout << "Yay! I win!\n" << endl;
        // saveGame(T);
        playAgain();
    } else {

    }

}
