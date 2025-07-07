using System.Collections.Generic;

namespace WorldBuilder.Entities
{
    public class Game
    {
        public Player Player { get; private set; }
        public List<World> Worlds { get; } = new List<World>();
        public WorldBuilderWorld TargetWorld { get; private set; }

        public Game()
        {
            Player = new Player("Vigilante del Equilibrio");
            Worlds.Add(new HumanWorld());
            Worlds.Add(new TechWorld());
            TargetWorld = new WorldBuilderWorld();
        }
    }
}
