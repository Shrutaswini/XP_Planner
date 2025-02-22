#include <iostream>
#include <vector>
#include <fstream>
#include <string>

struct Task {
    std::string description;
    std::string difficulty;
    bool completed;
    int xpReward;
};

std::vector<Task> tasks;
int xp = 0;
int level = 1;
std::string title = "Beginner";

void updateLevel() {
    level = 1 + xp / 10;
    if (xp >= 100) title = "Task Ninja";
    else if (xp >= 50) title = "Master Organizer";
    else if (xp >= 20) title = "Task Master";
}

void displayAchievement(const std::string& achievement) {
    std::cout << "\n================================\n";
    std::cout << "🎉🎊 CONGRATULATIONS! 🎊🎉\n";
    std::cout << "  🏆 " << achievement << " 🏆\n";
    std::cout << "================================\n";
    std::cout << "     **********     \n";
    std::cout << "     *    *   *    *     \n";
    std::cout << "      *  *     *  *      \n";
    std::cout << "       **       **       \n";
    std::cout << "================================\n\n";
}

void addTask() {
    std::cout << "\n============================\n";
    std::cout << "Enter task description: ";
    std::string desc;
    std::cin >> std::ws;
    std::getline(std::cin, desc);
    
    std::cout << "Choose difficulty (Easy/Medium/Hard): ";
    std::string difficulty;
    std::getline(std::cin, difficulty);
    int xpReward = (difficulty == "Hard") ? 4 : (difficulty == "Medium" ? 3 : 2);
    
    tasks.push_back({desc, difficulty, false, xpReward});
    std::cout << "Task added!\n";
    std::cout << "============================\n";
}

void listTasks() {
    std::cout << "\n============================\n";
    if (tasks.empty()) {
        std::cout << "No tasks available\n";
    } else {
        std::cout << "Tasks:\n";
        for (size_t i = 0; i < tasks.size(); ++i) {
            std::cout << i + 1 << ". " << (tasks[i].completed ? "[X] " : "[ ] ") << tasks[i].description 
                      << " (" << tasks[i].difficulty << ")\n";
        }
    }
    std::cout << "============================\n";
}

void completeTask() {
    listTasks();
    std::cout << "Enter task number to complete: ";
    int index;
    std::cin >> index;
    if (index > 0 && index <= tasks.size()) {
        tasks[index - 1].completed = true;
        xp += tasks[index - 1].xpReward;
        updateLevel();
        std::cout << "\nTask completed! +" << tasks[index - 1].xpReward << " XP\n";
    } else {
        std::cout << "Invalid task number\n";
    }
    std::cout << "============================\n";
}

void removeTask() {
    listTasks();
    std::cout << "Enter task number to remove: ";
    int index;
    std::cin >> index;
    if (index > 0 && index <= tasks.size()) {
        tasks.erase(tasks.begin() + index - 1);
        xp = std::max(0, xp - 3);
        updateLevel();
        std::cout << "Task removed! -3 XP\n";
    } else {
        std::cout << "Invalid task number\n";
    }
    std::cout << "============================\n";
}

void showStats() {
    std::cout << "\n============================\n";
    std::cout << " Level: " << level << " | XP: " << xp << " | Title: " << title << "\n";
    if (xp >= 20) {
        displayAchievement("Task Master!");
    }
    if (xp >= 50) {
        displayAchievement("Productivity Guru!");
    }
    if (xp >= 100) {
        displayAchievement("Task Ninja!");
    }
    std::cout << "============================\n";
}

void showMenu() {
    int choice;
    do {
        std::cout << "\n============================\n";
        std::cout << "          XP PLANNER        \n";
        std::cout << "============================\n";
        std::cout << "1. Add Task\n2. View Tasks\n3. Complete Task\n4. Remove Task\n5. View Stats\n6. Exit\n";
        std::cout << "Choose an option: ";
        std::cin >> choice;
        std::cin.ignore();
        std::cout << "\n";
        switch (choice) {
            case 1:
                addTask();
                break;
            case 2:
                listTasks();
                break;
            case 3:
                completeTask();
                break;
            case 4:
                removeTask();
                break;
            case 5:
                showStats();
                break;
            case 6:
                std::cout << "Goodbye!\n";
                break;
            default:
                std::cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 6);
}

int main() {
    showMenu();
    return 0;
}
