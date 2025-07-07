using System;
using System.Drawing;
using System.IO;
using System.Runtime.Serialization.Formatters.Binary;
using System.Windows.Forms;
using WorldBuilder.Entities;

namespace WorldBuilder
{
    public partial class MainForm : Form
    {
        private Game game;
        public MainForm()
        {
            InitializeComponent();
            LoadParameters();
            game = new Game();
        }

        private void LoadParameters()
        {
            string path = Path.Combine("FILES", "PARAMETERS.txt");
            if (File.Exists(path))
            {
                // Load parameters (e.g., number of enemies) from file
                // For brevity, not implemented fully
            }
            else
            {
                MessageBox.Show("PARAMETERS.txt not found", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }

        private void SaveScore(string playerName, int score)
        {
            string path = Path.Combine("FILES", "SCORES.bin");
            try
            {
                using (FileStream fs = new FileStream(path, FileMode.Append))
                {
                    BinaryFormatter bf = new BinaryFormatter();
                    bf.Serialize(fs, new PlayerScore { Name = playerName, Score = score, Date = DateTime.Now });
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show($"Error saving score: {ex.Message}");
            }
        }
    }
}
