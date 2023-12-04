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
        cout << "모든 통을 채웁니다.~~" << endl;
        for (auto& ingredient : ingredients) {
            ingredient.refill();
        }
    }

    void run() {
        cout << "------명품 커피 자판기켭니다.------" << endl;
        showIngredients();
        int choice;
        while (true) {
            cout << "보통 커피:0, 설탕 커피:1, 블랙 커피:2, 채우기:3, 종료:4>> ";
            cin >> choice;
            switch (choice) {
            case 0:
                makeCoffee({ 0, 3, 4 }, "맛있는 커피 나왔습니다~~");
                break;
            case 1:
                makeCoffee({ 0, 1, 3, 4 }, "맛있는 설탕 커피 나왔습니다~~");
                break;
            case 2:
                makeCoffee({ 0, 3, 4 }, "맛있는 블랙 커피 나왔습니다~~");
                break;
            case 3:
                fillIngredients();
                break;
            case 4:
                return;
            default:
                cout << "다시 선택해라 임마" << endl;
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