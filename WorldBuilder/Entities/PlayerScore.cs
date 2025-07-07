using System;

namespace WorldBuilder.Entities
{
    [Serializable]
    public class PlayerScore
    {
        public string Name { get; set; }
        public int Score { get; set; }
        public DateTime Date { get; set; }
    }
}
