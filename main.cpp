
#include <iostream>
using namespace std;

#include "Node.h"
#include "Tree.h"
#include "constants.h"
#include "Functions.h"

int main() {

    Tree T;
    Node *location;
    Node *leftYes;
    Node *rightNo;
    short numOfQuestion = 1;
    bool userPlayAgain;


    do {

        cout << "Think of something..I'll try to guess" << endl;

        location = T.GetRoot();

        while ((location->IsLeaf() == false))
        {
            cout << "Question " << numOfQuestion << " - " << location->GetText() << ": ";

            leftYes = location->LChild();
            rightNo = location->RChild();

            if (answerIsYes()) {
                location = leftYes;
            } else {
                location = rightNo;
            }
            numOfQuestion++;
        }

        myGuess(location);

        if (answerIsYes()) {
            cout << "Yay! I win!\n" << endl;

        } else {
            string question;
            cout << "Type a question that results in 'no' for your answer, but 'yes' for mine:\n" << endl;
            getline(cin, question);
            cout << "What were you thinking of?" << endl;
            string actualAnswer;
            getline(cin, actualAnswer);
            location->AppendLeft(new Node(location->GetText()));
            location->StoreText(question);
            location->AppendRight(new Node(actualAnswer));
            cout << *location << endl;

        }

        location = T.GetRoot();
        numOfQuestion = 1;

        string ans2;
        cout << "Do you want to save this game? (Enter LOWERCASE 'y' or 'n')" << endl;
        getline(cin, ans2);
        if (ans2 == "y" or ans2 == "Y" or ans2 == "yes" or ans2 == "Yes")
        userPlayAgain = playAgain();
    } while (userPlayAgain);

    cout << "Done." << endl;
    return 0;
}
