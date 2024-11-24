#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Task {
private:
    string task_name; 
    string task_description; 
    string dueDate; 
    bool completed; 

public:
    Task(const string& task_name, const string& task_description,
         const string& dueDate)
        : task_name(task_name)
        , task_description(task_description)
        , dueDate(dueDate)
        , completed(false)
    {
    }

    string getName() const { return task_name; }

    string getDescription() const { return task_description; }

    string getDueDate() const { return dueDate; }

    bool isCompleted() const { return completed; }

    void setName(const string& name) { this->task_name = name; }

    void setDescription(const string& task_description)
    {
        this->task_description = task_description;
    }

    
    void setDueDate(const string& dueDate)
    {
        this->dueDate = dueDate;
    }

    void markCompleted() { completed = true; }

    void displayTask() const
    {
        cout << task_name << " ("
             << (completed ? "Completed" : "Pending")
             << ") - Due: " << dueDate << endl
             << "   Description: " << task_description << endl;
    }
};

class ToDoList {
private:
    vector<Task> tasks; 

public:
    void displayMenu()
    {
        cout
            << "\n---------- To-Do List Menu -----------\n";
        cout << "1. Add Task\n";
        cout << "2. Delete Task\n";
        cout << "3. Display Tasks\n";
        cout << "4. Mark Task as Completed\n";
        cout << "5. Edit Task\n";
        cout << "6. Exit\n";
        cout << "-----------------------------------------"
                "\n";
    }

    void addTask()
    {
        string task_name, task_description, dueDate;
        cout << "Enter task name: ";
        cin.ignore();
        getline(cin, task_name);
        cout << "Enter task description: ";
        getline(cin, task_description);
        cout << "Enter task due date (DD-MM-YYYY): ";
        getline(cin, dueDate);

        tasks.emplace_back(task_name, task_description, dueDate);
        cout << "Task added successfully!" << endl;
    }

    void deleteTask()
    {
        if (tasks.empty()) {
            cout << "No tasks to delete!" << endl;
            return;
        }
        cout << "Tasks:" << endl;
        for (int i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". " << tasks[i].getName()
                 << endl;
        }
        cout << "Enter the task number to delete: ";
        int taskNumber;
        cin >> taskNumber;
        if (taskNumber >= 1 && taskNumber <= tasks.size()) {
            tasks.erase(tasks.begin() + taskNumber - 1);
            cout << "Task deleted successfully!" << endl;
        }
        else {
            cout << "Invalid task number!" << endl;
        }
    }

    void displayTasks()
    {
        if (tasks.empty()) {
            cout << "No tasks to display!" << endl;
            return;
        }
        cout << "Tasks:" << endl;
        for (int i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". ";
            tasks[i].displayTask();
        }
    }

    void markTaskCompleted()
    {
        if (tasks.empty()) {
            cout << "No tasks to mark as completed!"
                 << endl;
            return;
        }
        cout << "Tasks:" << endl;
        for (int i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". " << tasks[i].getName()
                 << endl;
        }
        cout << "Enter the task number to mark as "
                "completed: ";
        int taskNumber;
        cin >> taskNumber;
        if (taskNumber >= 1 && taskNumber <= tasks.size()) {
            tasks[taskNumber - 1].markCompleted();
            cout << "Task marked as completed!" << endl;
        }
        else {
            cout << "Invalid task number!" << endl;
        }
    }

    void editTask()
    {
        if (tasks.empty()) {
            cout << "No tasks to edit!" << endl;
            return;
        }
        cout << "Tasks:" << endl;
        for (int i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". " << tasks[i].getName()
                 << endl;
        }
        cout << "Enter the task number to edit: ";
        int taskNumber;
        cin >> taskNumber;
        if (taskNumber >= 1 && taskNumber <= tasks.size()) {
            Task& task = tasks[taskNumber - 1];
            string task_name, task_description, dueDate;
            cout << "Enter new task name (current: "
                 << task.getName() << "): ";
            cin.ignore();
            getline(cin, task_name);
            cout << "Enter new task description (current: "
                 << task.getDescription() << "): ";
            getline(cin, task_description);
            cout << "Enter new task due date (current: "
                 << task.getDueDate() << "): ";
            getline(cin, dueDate);

            task.setName(task_name);
            task.setDescription(task_description);
            task.setDueDate(dueDate);
            cout << "Task updated successfully!" << endl;
        }
        else {
            cout << "Invalid task number!" << endl;
        }
    }

    void run()
    {
        int choice;
        do {
            displayMenu();
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
            case 1:
                addTask();
                break;
            case 2:
                deleteTask();
                break;
            case 3:
                displayTasks();
                break;
            case 4:
                markTaskCompleted();
                break;
            case 5:
                editTask();
                break;
            case 6:
                cout << "Exiting program!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again!"
                     << endl;
            }
        } while (choice != 6);
    }
};

int main()
{
    ToDoList toDoList;
    toDoList.run();
    return 0;
}