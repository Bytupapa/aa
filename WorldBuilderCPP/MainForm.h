#pragma once
#include "Entities.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace System::IO;
using namespace System::Runtime::Serialization::Formatters::Binary;

namespace WorldBuilderCPP {

public ref class MainForm : public Form
{
public:
    MainForm()
    {
        InitializeComponent();
        LoadParameters();
        game = gcnew Entities::Game();
    }

protected:
    ~MainForm()
    {
        if (components)
            delete components;
    }

private:
    Entities::Game^ game;
    Label^ lblStatus;
    Timer^ gameTimer;
    System::ComponentModel::Container^ components;

    void InitializeComponent(void)
    {
        this->components = gcnew System::ComponentModel::Container();
        this->lblStatus = gcnew System::Windows::Forms::Label();
        this->gameTimer = gcnew System::Windows::Forms::Timer(this->components);
        // 
        // lblStatus
        // 
        this->lblStatus->AutoSize = true;
        this->lblStatus->Location = System::Drawing::Point(13, 13);
        this->lblStatus->Name = L"lblStatus";
        this->lblStatus->Size = System::Drawing::Size(100, 15);
        this->lblStatus->TabIndex = 0;
        this->lblStatus->Text = L"Bienvenido";
        // 
        // gameTimer
        // 
        this->gameTimer->Interval = 1000;
        this->gameTimer->Tick += gcnew System::EventHandler(this, &MainForm::GameTick);
        // 
        // MainForm
        // 
        this->AutoScaleDimensions = System::Drawing::SizeF(7, 15);
        this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
        this->ClientSize = System::Drawing::Size(800, 450);
        this->Controls->Add(this->lblStatus);
        this->Name = L"MainForm";
        this->Text = L"World Builder";
    }

    void LoadParameters()
    {
        String^ path = Path::Combine("FILES", "PARAMETERS.txt");
        if (!File::Exists(path))
        {
            MessageBox::Show("PARAMETERS.txt not found", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
    }

    void SaveScore(String^ playerName, int score)
    {
        String^ path = Path::Combine("FILES", "SCORES.bin");
        try
        {
            FileStream^ fs = gcnew FileStream(path, FileMode::Append);
            BinaryFormatter^ bf = gcnew BinaryFormatter();
            Entities::PlayerScore^ ps = gcnew Entities::PlayerScore();
            ps->Name = playerName;
            ps->Score = score;
            ps->Date = DateTime::Now;
            bf->Serialize(fs, ps);
            fs->Close();
        }
        catch (Exception^ ex)
        {
            MessageBox::Show("Error saving score: " + ex->Message);
        }
    }

    void GameTick(Object^ sender, EventArgs^ e)
    {
        lblStatus->Text = String::Format("Inventario: {0} recursos", game->PlayerInst->Inventory->Count);
    }
};

}
