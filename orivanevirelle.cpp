// ===========================
// VEILBOUND: A SHROUDED PATH
// ===========================
// A text-based adventure game with colored text effects

#include <iostream>
#include <fstream>
#include <chrono>
#include <thread>
#ifdef _WIN32
#include <windows.h>
#endif

using namespace std;

void setConsoleColor(int color) {
    #ifdef _WIN32
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
    #else
    string code = "\033[" + to_string(color) + "m";
    cout << code;
    #endif
}

void resetConsoleColor() {
    #ifdef _WIN32
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    #else
    cout << "\033[0m";
    #endif
}

void printWithDelay(const string& text, int delay = 50) {
    for (char c : text) {
        cout << c << flush;
        this_thread::sleep_for(chrono::milliseconds(delay));
    }
    cout << endl;
}

// ===========================
// TITLE SCREEN
// ===========================

void displayTitleScreen() {
    setConsoleColor(11); // Cyan for the title
    printWithDelay("\n  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    printWithDelay("    VEILBOUND: A SHROUDED PATH");
    printWithDelay("  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    resetConsoleColor();
    this_thread::sleep_for(chrono::milliseconds(500));
}
// ===========================
// SAVE SYSTEM
// ===========================

void saveGame(int alignment) {
    ofstream saveFile("savegame.txt");
    if (saveFile) {
        saveFile << alignment;
        saveFile.close();
    }
}

int loadGame() {
    ifstream saveFile("savegame.txt");
    int alignment = 0;
    if (saveFile) {
        saveFile >> alignment;
        saveFile.close();
    }
    return alignment;
}
// ===========================
// MAIN GAME LOGIC
// ===========================

void finalChoice(int& alignment) {
    setConsoleColor(14);
    printWithDelay("\nThe final choice awaits...");
    printWithDelay("Veylan steps forward, his expression unreadable.\n");
    printWithDelay("Veylan: 'You were always the favored one, Orivane. Grandfather's choice cost my father everything. I had no choice but to seek another path.'\n");
    printWithDelay("Orivane realizes the betrayal was deeper than he thought. Veylan had allied with the Council. But the dots connected and the council wants to eliminate Veylan too.\n");
    resetConsoleColor();

    setConsoleColor(9);
    printWithDelay("1. Confront Veylan - Demand answers and force him to see the true intentions of the Council.");
    printWithDelay("2. Walk away - Leave him to his fate and escape before the Council strikes.");
    printWithDelay("3. Try to save Veylan - Warn him of the Council's true intentions, despite his betrayal.");
    resetConsoleColor();

    int choice;
    cin >> choice;
    
   if (choice == 1) {
        setConsoleColor(11);
            printWithDelay("\nThe Just Heir: Orivane confronts Veylan, seeking the truth. Veylan hesitates, but before he can make a choice, the Council arrives. Did Veylan truly waver? Or was it all a ruse? Orivane is left with uncertainty, even as the Council falls.");
            resetConsoleColor();
      }
    else if (choice == 2) {
        alignment -= 1; // Villain path
        setConsoleColor(12);
            printWithDelay("\nThe Last Survivor: Orivane walks away, leaving Veylan and the Council to their fate. As he disappears into the unknown, he wonders - did he abandon justice, or did he escape a deeper trap? The world moves on, but something unseen lingers.");
            resetConsoleColor();
    }
        else if (choice == 3) {
        alignment += 1; // Heroic path
        setConsoleColor(10);
            printWithDelay("\nThe Doomed Pact: Orivane tries to save Veylan, but the Council strikes first. Veylan's eyes widen in realization - too late. As Orivane fights to survive, a final whisper from Veylan leaves him questioning everything. Did Veylan ever have a choice?");
            resetConsoleColor();
    }
 saveGame(alignment); 
}

void transitionChoice(int& alignment) {
    setConsoleColor(14); // Yellow for narration
    printWithDelay("\nThe confrontation weighs heavily on Orivane.");
    printWithDelay("Before facing Veylan, he must decide how to proceed.");
    resetConsoleColor();

    setConsoleColor(9); // Light blue for choices
    printWithDelay("1. Seek Virelle's guidance - Attempt to understand the deeper truth behind everything.");
    printWithDelay("2. Press forward alone - Rely on himself and confront the Council directly.");
    resetConsoleColor();

    int choice;
    cin >> choice;

    if (choice == 1) {
        setConsoleColor(10); // Green for Virelle's wisdom
        printWithDelay("\nVirelle appears, her presence calm yet firm.");
        printWithDelay("Virelle: 'This is not just about you, Orivane. The past, the present... all intertwine. You must see clearly before choosing your fate.'");
        resetConsoleColor();
    } else {
        setConsoleColor(12); // Red for Orivane's determination
        printWithDelay("\nOrivane clenches his fists. The time for guidance has passed. He must act.");
        resetConsoleColor();
    }

    finalChoice(alignment);
}

void fourthChoice(int& alignment) {
    setConsoleColor(14); // Yellow for narration
    printWithDelay("\nThe Council is closing in...");
    resetConsoleColor();

    if (alignment >= 0) { // Heroic Path
        setConsoleColor(13); // Purple for deep realization
        printWithDelay("The truth is now his. But as he prepares to act, a familiar face emerges from the shadows.");
        resetConsoleColor();
    } else { // Villainous Path
        setConsoleColor(13); // Purple for ominous power
        printWithDelay("The Veil of the Forgotten shrouds him, but even this power cannot hide him from one who knows his every move.");
        resetConsoleColor();
    }

    setConsoleColor(12); // Red for tension and betrayal
    printWithDelay("Veylan stands before him, his cousin - his closest friend. Or so he thought.");
    resetConsoleColor();

    transitionChoice(alignment);
}

void thirdChoice(int alignment) {
    setConsoleColor(14); // Yellow for narration
    printWithDelay("\nA new choice lies ahead...");
    resetConsoleColor();

    if (alignment >= 0) { // Heroic Path
        setConsoleColor(13); // Purple for hidden truths
        printWithDelay("Orivane now holds the truth of his lineage. But what will he do with it?");
        resetConsoleColor();

        setConsoleColor(9); // Light blue for choices
        printWithDelay("1. Seek Justice - Confront those who erased his family's honor.");
        printWithDelay("2. Walk Away - Accept the past and forge his own destiny.");
        resetConsoleColor();
    } else { // Villainous Path
        setConsoleColor(13); // Purple for mysterious power
        printWithDelay("Orivane wields the Veil of the Forgotten. But what will he use it for?");
        resetConsoleColor();

        setConsoleColor(9); // Light blue for choices
        printWithDelay("1. Use Power for Revenge - Strike down those responsible, even if their faces are lost to him.");
        printWithDelay("2. Seek Lost Memories - Try to undo the cost of his power and reclaim his past.");
        resetConsoleColor();
    }

    int choice;
    cin >> choice;

    if (choice == 1) {
        if (alignment >= 0) {
            alignment += 1; // Strengthening heroic path
            setConsoleColor(10); // Green for justice
            printWithDelay("\nOrivane steadies himself. The past must be answered. He will seek justice.");
            resetConsoleColor();
        } else {
            alignment -= 1; // Strengthening villainous path
            setConsoleColor(12); // Red for vengeance
            printWithDelay("\nOrivane's grip tightens. The past is his to rewrite, in blood if necessary.");
            resetConsoleColor();
        }
    } else {
        setConsoleColor(14); // Yellow for uncertainty
        printWithDelay("\nOrivane exhales. The past is done, but his future remains unwritten.");
        resetConsoleColor();
    }

    fourthChoice(alignment);
}

void secondChoice() {
    setConsoleColor(14); // Yellow for narration
    printWithDelay("\nInside the ruins, Orivane finds an ancient pedestal.");
    printWithDelay("Two paths are etched into the stone before him.");
    resetConsoleColor();

    setConsoleColor(9); // Light Blue for choices
    printWithDelay("\n1. Path of Knowledge: Solve the puzzle on the wall to unlock the truth about his lineage.");
    printWithDelay("2. Path of Power: Shatter the pendant, gaining the ability to control nature but losing an important memory.");
    resetConsoleColor();

    int choice;
    cin >> choice;

    if (choice == 1) { // Path of Knowledge
        setConsoleColor(10); // Green for revelations
        printWithDelay("\nOrivane studies the intricate symbols on the wall. As he deciphers them, visions of the past flood his mind...");
        printWithDelay("He sees his grandfather, Elarion, betrayed by the ruling council. They erased his name, but that was not enough.");
        printWithDelay("For decades, they kept watch, ensuring no heir would ever reclaim what was lost.");
        printWithDelay("When Orivane unknowingly drew too close to the truth, they acted.");
        printWithDelay("They drugged him, buried him in the forest, leaving him for dead.");
        printWithDelay("Yet, against all odds, he survived.");
        printWithDelay("Now, he knows why he was left to die. Now, he knows who is responsible.");
        resetConsoleColor();

        setConsoleColor(13); // Purple for mysterious guidance
        printWithDelay("\nAs he absorbs this knowledge, a familiar voice echoes in the chamber.");
        printWithDelay("Virelle: 'Truth can be a burden, Orivane. Are you certain this is what you seek?'");
        resetConsoleColor();

        thirdChoice(1);
    } else { // Path of Power
        setConsoleColor(12); // Red for danger and sacrifice
        printWithDelay("\nWith a deep breath, Orivane grips the pendant tightly and smashes it against the stone floor.");
        printWithDelay("A surge of energy courses through him, wrapping around him like a shadowy veil.");
        printWithDelay("His body feels lighter, as if reality itself struggles to grasp him. He felt the wings move with his own movement. The leaves were quick at being flown by the winds. He has gained the Veil of the Forgotten.");
        resetConsoleColor();

        setConsoleColor(14); // Yellow for loss and uncertainty
        printWithDelay("\nBut something is missing. As he tries to recall his past, it feels distant, like a dream slipping from memory.");
        printWithDelay("The face of his grandfather... gone. The details of his lineage... blurred.");
        printWithDelay("A piece of himself is lost, but in its place, he has gained something else—something powerful, yet isolating.");
        resetConsoleColor();

        setConsoleColor(13); // Purple for Virelle’s cryptic wisdom
        printWithDelay("\nA soft breeze swirls around him, and a whisper cuts through the silence.");
        printWithDelay("Virelle: 'Power has its price, Orivane. Will you pay it willingly?'");
        resetConsoleColor();

        thirdChoice(2);
    }
}
void introduction() {
    setConsoleColor(14); // Yellow for narration
    printWithDelay("Darkness... then a dull ache.");
    printWithDelay("Orivane's eyes flutter open to find himself half-buried in damp forest soil, the scent of moss thick in the air.");
    printWithDelay("His body feels heavy as he struggles to sit up, soil falling from his arms and chest.");
    
    printWithDelay("\nHe glances around - a dense forest, unfamiliar yet eerily silent.");
    printWithDelay("Why is he here? How did he get here? His memory is fragmented, blurry...");

    printWithDelay("\nStaggering to his feet, Orivane takes slow, unsure steps forward.");
    printWithDelay("Each breath feels like pulling air through fog. Then, something catches his eye.");
    resetConsoleColor();

    setConsoleColor(10); // Green for mystery
    printWithDelay("\nA faint glimmer in the dirt - a pendant, half-buried.");
    printWithDelay("As he kneels and brushes off the dirt, the pendant reveals an unfamiliar symbol etched into its surface.");
    printWithDelay("A chill runs through him.");
    resetConsoleColor();

    setConsoleColor(13); // Purple for mystical presence
    printWithDelay("\n'Orivane... do you seek the truth?'");
    printWithDelay("A melodic whisper, carried by the wind, barely audible yet clear as day.");
    resetConsoleColor();

    setConsoleColor(9); // Light blue for choices
    printWithDelay("\nWhat will Orivane do?");
    printWithDelay("1. Hold onto the pendant and say 'Yes, I must know.'");
    printWithDelay("2. Drop it and step back, feeling uneasy.");
    resetConsoleColor();
}

void pathOne() {
    setConsoleColor(14); // Yellow for narration
    printWithDelay("The wind picks up slightly, as if approving. The whisper lingers, waiting...");
    
    setConsoleColor(13); // Purple for Virelle’s presence
    printWithDelay("\n'Orivane... step forward.' The voice is clearer now, as if the wind itself speaks.");
    resetConsoleColor();

    setConsoleColor(14); // Yellow for environment
    printWithDelay("With hesitant steps, he moves toward a faint glow beyond the trees...");
    
    printWithDelay("\nAfter a short walk, he reaches a clearing where ancient ruins stand covered in vines.");
    printWithDelay("Carvings on the stone walls depict a scene... an ancestor betrayed, his name erased from history.");
    printWithDelay("It was his grandfather. The pieces start falling into place...");
    
    printWithDelay("\nA gust of wind sweeps through the ruins, and from the shadows, a soft light appears.");
    resetConsoleColor();

    setConsoleColor(13); // Purple for Virelle
    printWithDelay("Virelle, the whispering wind, finally reveals herself...");
    
    printWithDelay("\n'You are the one foretold, Orivane.'");
    printWithDelay("She speaks of an ancient prophecy erased from history, tied to his bloodline.");
    printWithDelay("A descendant would rise to uncover the truth and decide their fate.");
    printWithDelay("'But first, you must prove yourself,' she says, gesturing toward the ruins.");
    printWithDelay("Inside lies a hidden trial. If he succeeds, he will uncover his true past... and purpose.");
    resetConsoleColor();

    secondChoice();
}

void pathTwo() {
    setConsoleColor(12); // Red for unease
    printWithDelay("The whisper fades into silence, but the pendant remains in his hand. A feeling of unease lingers.");
    
    setConsoleColor(14); // Yellow for observation
    printWithDelay("\nJust as he turns to leave, his eyes catch something - symbols etched into the bark of a tree nearby.");
    printWithDelay("Though unfamiliar, they stir something within him... a distant memory trying to resurface.");
    
    setConsoleColor(10); // Green for symbols and revelation
    printWithDelay("\nTracing the symbols with his fingers, a flash of recognition strikes him.");
    printWithDelay("They match markings he had seen in old family heirlooms - secrets of his lineage kept hidden.");
    printWithDelay("As he stares, the wind stirs, carrying a familiar whisper once more.");
    resetConsoleColor();

    setConsoleColor(13); // Purple for Virelle’s presence
    printWithDelay("\"You have always known, Orivane... you only had to look.\"");
    
    printWithDelay("\nTurning around, he sees a soft glow forming in the distance. The fairy has come to him at last...");
    
    printWithDelay("\n'You were meant to find this,' Virelle whispers. 'The past cannot stay buried forever.'");
    printWithDelay("She reveals a prophecy erased from history - his lineage, the betrayal, the trial ahead.");
    printWithDelay("'If you wish to know your true purpose, the ruins hold your answer,' she says, eyes gleaming.");
    resetConsoleColor();

    secondChoice();
}

int main() {
    int alignment = loadGame();
    displayTitleScreen();  
    introduction();
    int choice;
    cin >> choice;
    if (choice == 1) {
        pathOne();
    } else {
        pathTwo();
    }
    return 0;
}
