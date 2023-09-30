#include <iostream>
#include <vector>
#include <string>

using namespace std;

class ToDoList {
private:
    struct Task {
        string name;
        bool completed;
    };

    vector<Task> tasks;

public:
    void addTask(const string& taskName) {
        Task newTask = {taskName, false};
        tasks.push_back(newTask);
        cout << "Task '" << taskName << "' added." << endl;
    }

    void viewTasks() {
        if (tasks.empty()) {
            cout << "No tasks found." << endl;
        } else {
            cout << "Tasks:" << endl;
            for (size_t i = 0; i < tasks.size(); ++i) {
                string status = tasks[i].completed ? "Completed" : "Pending";
                cout << i + 1 << ". " << tasks[i].name << " - " << status << endl;
            }
        }
    }

    void markCompleted(size_t taskIndex) {
        if (taskIndex >= 1 && taskIndex <= tasks.size()) {
            tasks[taskIndex - 1].completed = true;
            cout << "Task '" << tasks[taskIndex - 1].name << "' marked as completed." << endl;
        } else {
            cout << "Invalid task index." << endl;
        }
    }

    void removeTask(size_t taskIndex) {
        if (taskIndex >= 1 && taskIndex <= tasks.size()) {
            cout << "Task '" << tasks[taskIndex - 1].name << "' removed." << endl;
            tasks.erase(tasks.begin() + taskIndex - 1);
        } else {
            cout << "Invalid task index." << endl;
        }
    }
};

int main() {
    ToDoList toDoList;

    while (true) {
        cout << "\nTo-Do List Manager" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. View Tasks" << endl;
        cout << "3. Mark Task as Completed" << endl;
        cout << "4. Remove Task" << endl;
        cout << "5. Exit" << endl;

        char choice;
        cin >> choice;

        switch (choice) {
            case '1': {
                string taskName;
                cout << "Enter the task name: ";
                cin.ignore();
                getline(cin, taskName);
                toDoList.addTask(taskName);
                break;
            }
            case '2':
                toDoList.viewTasks();
                break;
            case '3': {
                toDoList.viewTasks();
                size_t taskIndex;
                cout << "Enter the task index to mark as completed: ";
                cin >> taskIndex;
                toDoList.markCompleted(taskIndex);
                break;
            }
            case '4': {
                toDoList.viewTasks();
                size_t taskIndex;
                cout << "Enter the task index to remove: ";
                cin >> taskIndex;
                toDoList.removeTask(taskIndex);
                break;
            }
            case '5':
                cout << "Exiting the To-Do List Manager." << endl;
                return 0;
            default:
                cout << "Invalid! Please select a valid option." << endl;
        }
    }

    return 0;
}

