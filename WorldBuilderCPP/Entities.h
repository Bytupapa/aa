#pragma once

using namespace System;
using namespace System::Collections::Generic;

namespace WorldBuilderCPP {
namespace Entities {

public ref class Resource abstract
{
public:
    String^ Name;
    Resource(String^ name) { Name = name; }
};

public ref class TechResource : public Resource
{
public:
    TechResource(String^ name) : Resource(name) {}
};

public ref class HumanSkill : public Resource
{
public:
    HumanSkill(String^ name) : Resource(name) {}
};

public ref class Character abstract
{
public:
    String^ Name;
    int Health;
    Character(String^ name, int health)
    {
        Name = name;
        Health = health;
    }
};

public ref class Player : public Character
{
public:
    List<Resource^>^ Inventory;
    Player(String^ name) : Character(name, 3)
    {
        Inventory = gcnew List<Resource^>();
    }
    void Collect(Resource^ res)
    {
        Inventory->Add(res);
    }
};

public ref class Enemy : public Character
{
public:
    Enemy(String^ name) : Character(name, 1) {}
};

public ref class Ally : public Character
{
public:
    Ally(String^ name) : Character(name, 1) {}
};

public ref class World abstract
{
public:
    String^ Name;
    List<Resource^>^ Resources;
    List<Enemy^>^ Enemies;
    List<Ally^>^ Allies;
    World(String^ name)
    {
        Name = name;
        Resources = gcnew List<Resource^>();
        Enemies = gcnew List<Enemy^>();
        Allies = gcnew List<Ally^>();
    }
    virtual void Populate() = 0;
};

public ref class HumanWorld : public World
{
public:
    HumanWorld() : World("Humanized World")
    {
        Populate();
    }
    virtual void Populate() override
    {
        Resources->Add(gcnew HumanSkill("Empat\xEDa"));
        Resources->Add(gcnew HumanSkill("\xC9tica"));
        Resources->Add(gcnew HumanSkill("Adaptabilidad"));
        Enemies->Add(gcnew Enemy("Indiferencia"));
        Enemies->Add(gcnew Enemy("Aislamiento"));
        Enemies->Add(gcnew Enemy("Ego\xEDsmo"));
    }
};

public ref class TechWorld : public World
{
public:
    TechWorld() : World("Tech World")
    {
        Populate();
    }
    virtual void Populate() override
    {
        Resources->Add(gcnew TechResource("IA"));
        Resources->Add(gcnew TechResource("Big Data"));
        Resources->Add(gcnew TechResource("Energ\xEDa Sostenible"));
        Enemies->Add(gcnew Enemy("Fallos de Sistema"));
        Enemies->Add(gcnew Enemy("Virus"));
        Enemies->Add(gcnew Enemy("Sobrecarga"));
    }
};

public ref class WorldBuilderWorld : public World
{
public:
    int Completion;
    WorldBuilderWorld() : World("New World")
    {
        Completion = 0;
    }
    void AddContribution(Resource^ res)
    {
        Resources->Add(res);
        Completion += 10;
    }
    virtual void Populate() override {}
};

public ref class Game
{
public:
    Player^ PlayerInst;
    List<World^>^ Worlds;
    WorldBuilderWorld^ TargetWorld;
    Game()
    {
        PlayerInst = gcnew Player("Vigilante del Equilibrio");
        Worlds = gcnew List<World^>();
        Worlds->Add(gcnew HumanWorld());
        Worlds->Add(gcnew TechWorld());
        TargetWorld = gcnew WorldBuilderWorld();
    }
};

public ref class PlayerScore
{
public:
    String^ Name;
    int Score;
    DateTime Date;
};

} // namespace Entities
} // namespace WorldBuilderCPP
