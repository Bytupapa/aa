using System.Collections.Generic;

namespace WorldBuilder.Entities
{
    public abstract class World
    {
        public string Name { get; }
        public List<Resource> Resources { get; } = new List<Resource>();
        public List<Enemy> Enemies { get; } = new List<Enemy>();
        public List<Ally> Allies { get; } = new List<Ally>();

        protected World(string name)
        {
            Name = name;
        }

        public abstract void Populate();
    }

    public class HumanWorld : World
    {
        public HumanWorld() : base("Humanized World")
        {
            Populate();
        }
        public override void Populate()
        {
            Resources.Add(new HumanSkill("Empatía"));
            Resources.Add(new HumanSkill("Ética"));
            Resources.Add(new HumanSkill("Adaptabilidad"));
            Enemies.Add(new Enemy("Indiferencia"));
            Enemies.Add(new Enemy("Aislamiento"));
            Enemies.Add(new Enemy("Egoísmo"));
        }
    }

    public class TechWorld : World
    {
        public TechWorld() : base("Tech World")
        {
            Populate();
        }
        public override void Populate()
        {
            Resources.Add(new TechResource("IA"));
            Resources.Add(new TechResource("Big Data"));
            Resources.Add(new TechResource("Energía Sostenible"));
            Enemies.Add(new Enemy("Fallos de Sistema"));
            Enemies.Add(new Enemy("Virus"));
            Enemies.Add(new Enemy("Sobrecarga"));
        }
    }

    public class WorldBuilderWorld : World
    {
        public int Completion { get; private set; }
        public WorldBuilderWorld() : base("New World")
        {
        }
        public void AddContribution(Resource resource)
        {
            Resources.Add(resource);
            Completion += 10; // placeholder contribution
        }
        public override void Populate() {}
    }
}
