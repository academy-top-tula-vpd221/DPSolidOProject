// DPSolidOProject.cpp 
//
#include <iostream>
#include <vector>

using namespace std;
/// <summary>
/// 
/// </summary>
class IRecipe
{
public:
    virtual void Make() = 0;
};

class PatatoMashRecipe : public IRecipe
{
public:
    void Make() override
    {
        cout << "Чистится картофель\n";
        cout << "Заливается водой\n";
        cout << "Ставим на огонь\n";
        cout << "Добавлдяем специи\n";
        cout << "Варка до готовности\n";
        cout << "Изготовление пюре\n";
    }
};

class SaladRecipe : public IRecipe
{
public:
    void Make() override
    {
        cout << "Режем помидоры\n";
        cout << "Режем огурцы\n";
        cout << "Режем редис\n";
        cout << "Заправляем сосусом\n";
        cout << "Добавляем зелень\n";
        cout << "Перемешиваем\n";
    }
};

class СhefCookStrategy
{
public:
    string Name;
    СhefCookStrategy(string name) : Name{ name } {}

    void MakeDinner(IRecipe* recipe)
    {
        recipe->Make();
    }
};

/// <summary>
/// 
/// </summary>
class RecipeBase
{
public:
    virtual void Prepare() = 0;
    virtual void Cook() = 0;
    virtual void Final() = 0;

    void Make()
    {
        Prepare();
        Cook();
        Final();
    }
};

class PatatoMashRecipe2 : public RecipeBase
{
    void Prepare() override
    {
        cout << "Чистится картофель\n";
        cout << "Заливается водой\n";
        
        
    }
    void Cook() override
    {
        cout << "Ставим на огонь\n";
        cout << "Добавляем специи\n";
        cout << "Варка до готовности\n";
        cout << "Изготовление пюре\n";
    }
    void Final() override
    {
        cout << "Добавляем масло, посыпаем зеленью\n";
    }
};

class SaladRecipe2 : public RecipeBase
{
public:
    void Prepare() override
    {
        cout << "Режем помидоры\n";
        cout << "Режем огурцы\n";
        cout << "Режем редис\n";
    }
    void Cook() override
    {
        cout << "Заправляем сосусом\n";
        cout << "Добавляем зелень\n";
        cout << "Перемешиваем\n";
    }
    void Final() override
    {
        cout << "Охлаждаем\n";
    }
};

class СhefCookTemplate
{
public:
    string Name;
    СhefCookTemplate(string name) : Name{ name } {}

    void MakeDinner(vector<RecipeBase*> menu)
    {
        for (RecipeBase* recipe : menu)
            recipe->Make();
    }
};

// 
//class СhefCookPro : public СhefCook
//{
//
//};

int main()
{
    setlocale(LC_ALL, "Russian");

    vector<RecipeBase*> menu;
    menu.push_back(new PatatoMashRecipe2());
    menu.push_back(new SaladRecipe2());

    СhefCookTemplate chef("Joe");
    chef.MakeDinner(menu);
}
