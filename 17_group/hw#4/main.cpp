#include <iostream>
#include <vector>
using namespace std;

class Ingredient {
private:
    string name;
    int stock;

public:
    Ingredient(string name) : name(name), stock(3) {}

    void checkStock() const {
        for (int i = 0; i < stock; i++) {
            cout << "*";
        }
        cout << endl;
    }

    const string& getName() const {
        return name;
    }

    void useIngredient() {
        if (stock > 0) {
            stock--;
        }
        else {
            cout << "Out of " << name << endl;
        }
    }

    void refill() {
        stock = 3;
    }
};

class CoffeeMachine {
private:
    vector<Ingredient> ingredients;

public:
    void addIngredient(const Ingredient& ingredient) {
        ingredients.push_back(ingredient);
    }

    void showIngredients() const {
        for (const auto& ingredient : ingredients) {
            cout << ingredient.getName() << " ";
            ingredient.checkStock();
        }
    }

    void makeCoffee(const vector<int>& ingredientIndexes, const string& message) {
        cout << message << endl;
        for (int index : ingredientIndexes) {
            if (index >= 0 && index < ingredients.size()) {
                ingredients[index].useIngredient();
            }
        }
    }

    void fillIngredients() {
        cout << "��� ���� ä��ϴ�.~~" << endl;
        for (auto& ingredient : ingredients) {
            ingredient.refill();
        }
    }

    void run() {
        cout << "------��ǰ Ŀ�� ���Ǳ��մϴ�.------" << endl;
        showIngredients();
        int choice;
        while (true) {
            cout << "���� Ŀ��:0, ���� Ŀ��:1, �� Ŀ��:2, ä���:3, ����:4>> ";
            cin >> choice;
            switch (choice) {
            case 0:
                makeCoffee({ 0, 3, 4 }, "���ִ� Ŀ�� ���Խ��ϴ�~~");
                break;
            case 1:
                makeCoffee({ 0, 1, 3, 4 }, "���ִ� ���� Ŀ�� ���Խ��ϴ�~~");
                break;
            case 2:
                makeCoffee({ 0, 3, 4 }, "���ִ� �� Ŀ�� ���Խ��ϴ�~~");
                break;
            case 3:
                fillIngredients();
                break;
            case 4:
                return;
            default:
                cout << "�ٽ� �����ض� �Ӹ�" << endl;
            }
            showIngredients();
        }
    }
};

int main() {
    CoffeeMachine machine;
    machine.addIngredient(Ingredient("Coffee"));
    machine.addIngredient(Ingredient("Sugar"));
    machine.addIngredient(Ingredient("Cream"));
    machine.addIngredient(Ingredient("Water"));
    machine.addIngredient(Ingredient("Cup"));

    machine.run();
    return 0;
}