namespace WorldBuilder.Entities
{
    public abstract class Character
    {
        public string Name { get; set; }
        public int Health { get; set; }
        protected Character(string name, int health = 3)
        {
            Name = name;
            Health = health;
        }
    }
}
