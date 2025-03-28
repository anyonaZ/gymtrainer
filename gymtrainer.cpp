#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

//user profile class
class UserProfile {
    private:
        string name;
        int age;
        float height, weight;
        string experienceLevel;
        string goal;

    public:
        UserProfile(string n, int a, float h, float w, string exp, string g)
            : name(n), age(a), height(h), weight(w), experienceLevel(exp), goal(g) {}

        //BMI calculator
        float calculateBmi() {
            return weight / ((height / 100) * (height / 100));
        }

        //display the information on user profile
        void displayProfile() {
            cout << "\nUser Profile:" << endl;
            cout << "Name: " << name << endl;
            cout << "Age: " << age << " years old" << endl;
            cout << "Height: " << weight << " kg" << endl;
            cout << "Experience Level: " << experienceLevel << endl;
            cout << "Fitness Gaoal: " << goal << endl;
            cout << "BMI: " << calculateBmi() << endl;
        }

        string getExperienceLevel() {return experienceLevel;}
        string getGoal() {return goal;}
};

// workout plan class
class WorkoutPlan {
    public:
        virtual void suggestWorkout() = 0;
};

//bodybuilding plan class
class BodybuildingPlan : public WorkoutPlan {
    public:
        void suggestWorkout() override {
            cout << "\nRecommend Bodybuilding workout:" << endl;
            cout << "1. Squats - 4 sets for 8 reps" << endl;
            cout << "2. Bench Press - 4 sets for 8 reps" << endl;
            cout << "3. Deadlift - 4 sets for 6 reps" << endl;
            cout << "4. Overhead Press - 3 sets for 10 reps" << endl;
            cout << "5. Pull-ups - 3 sets for 12 reps" << endl;
        }
};

//lean fitness plan class
class LeanFitnessPlan : public WorkoutPlan {
    public:
        void suggestWorkout() override {
            cout << "\nRecommend lean fitness plan workout:" << endl;
            cout << "1. Running - 30 minutes" << endl;
            cout << "2. Jump rope - 15 minutes" << endl;
            cout << "3. Pushups - 3 sets for 15 reps" << endl;
            cout << "4. Walking lunges - 3 sets for 12 reps per leg" << endl;
            cout << "5. Planks - 3 sets for 1 minute" << endl;
        }
};

void displayBMI(float bmi) {
    cout << "Your BMI: " << bmi << endl;
}

void displayBMI(float bmi, string message) {
    cout << message << " Your BMI is: " << bmi << endl;
}

int main() {
    string name, experienceLevel, goal;
    int age;
    float height, weight;

    try {
        // user profile information input
        cout << "Enter your name; ";
        getline(cin, name);

        cout << "Enter your age: ";
        cin >> age;
        if (age <= 0) throw invalid_argument("Age must be a positive number.");

        cout << "Enter your height (cm): ";
        cin >> height;
        if (height <= 0) throw invalid_argument("Height must be a positive number.");

        cout << "Enter your weight (kg): ";
        cin >> weight;
        if (weight <= 0) throw invalid_argument("Weight must be a positive number.");

        cout << "Enter your experience level (Beginner/Intermediate/Advancec): ";
        getline(cin, experienceLevel);

        cout << "Enter your fitness goal (Bodybuilding/Lean fitness): ";
        getline(cin, goal);

        //object foe user profile
        UserProfile user(name, age, height, weight, experienceLevel, goal);
        user.displayProfile();

        float bmi = user.calculateBmi();
        displayBMI(bmi, "Health status based on your weight:");

        WorkoutPlan* workout;
        if (goal == "Bodybuilding") {
            workout = new BodybuildingPlan();
        } else if (goal == "Lean FIrness") {
            workout = new LeanFitnessPlan();
        } else {
            throw invalid_argument("Invalid fitness goal entered!!!");
        }
        workout->suggestWorkout();
    }
    catch (const invalid_argument& e) {
        cerr << "Error: " << e.what() << endl;
    }
    catch (...) {
        cerr << "An unxpected error occurred!!!" << endl;
    }

    return 0;
}